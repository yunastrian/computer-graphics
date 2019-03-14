#include "kamus.h"

void set_mode(int want_key)
{
	static struct termios old, new;
	if (!want_key) {
		tcsetattr(STDIN_FILENO, TCSANOW, &old);
		return;
	}
 
	tcgetattr(STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

int get_key()
{
	int c = 0;
	struct timeval tv;
	fd_set fs;
	tv.tv_usec = tv.tv_sec = 0;
 
	FD_ZERO(&fs);
	FD_SET(STDIN_FILENO, &fs);
	select(STDIN_FILENO + 1, &fs, 0, 0, &tv);
 
	if (FD_ISSET(STDIN_FILENO, &fs)) {
		c = getchar();
		set_mode(0);
	}
	return c;
}

/*
void resizePixels(int height, int width, int new_height, int new_width,
				  int matrix[height][width],
				  int new_matrix[new_height][new_width]) {
	int i, j, x, y;

	double x_ratio = (double)width / (double)new_width;
	double y_ratio = (double)height / (double)new_height;

	for (i = 0; i < new_height; i++) {
		for (j = 0; j < new_width; j++) {
			// x dan y pada matrix adalah nearest neighbor dari
			// i dan j pada new_matrix
			x = floor(j * x_ratio);
			y = floor(i * y_ratio);
			new_matrix[i][j] = matrix[y][x];
		}
	}
} */

int main() {
    // Membuka driver framebuffer
    fb_driver = open("/dev/fb0", O_RDWR);
    if (fb_driver == -1) {
        perror("Error: driver framebuffer tidak dapat dibuka");
        exit(1);
    }

    // Get fixed screen information
    if (ioctl(fb_driver, FBIOGET_FSCREENINFO, &fix_info) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fb_driver, FBIOGET_VSCREENINFO, &var_info) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    // Mapping framebuffer ke memori
    int screensize = var_info.xres * var_info.yres * var_info.bits_per_pixel / 8;
    fb = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_driver, 0);
    if((int)fb == -1){
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }

    for (int x=0; x<800; x++) {
    	for (int y=0; y<600; y++) {
    		canvas[x][y] = 0;
    	}
    }


    clear_screen(800, 600);
    color bg = {0,0,0,0};
    color green = {0,255,0,255};

    int cursorx = 50;
    int cursory = 50;

    navbar(0);
    render_navbar();
    int barselect = 0;

    while (1) {
    	set_mode(1);

    	// Draw Cursor
		//refresh(0, 800, 0, 600);    	
		render_canvas();
		draw_cursor(cursorx, cursory, &green);
    	// Read Key
		while (1) {
			int c;
			
			if (c = get_key()) {
				if (c == 97) {
					if (cursorx > 10) { // a
						cursorx -= 3;
					}
				} else if (c == 100) { // d
					if (cursorx < 790) {
						cursorx += 3;
					}
				} else if (c == 115) { // s
					if (cursory < 590) {
						cursory += 3;
					}
				} else if (c == 119) { // w
					if (cursory > 44) {
						cursory -= 3;
					}
				} else if (c == 108) { // l
					draw_paint(cursorx,cursory,1);
				} else if (c == 32) { // Space
					if (barselect == 1) {
						clear_screen(800,600);
						navbar(barselect);
    					render_navbar();
					} else if (barselect == 2) {
						FILE *f = fopen("paint.txt", "w");
						for (int i=0; i<800; i++) {
							for (int j=0; j<600; j++) {
								fprintf(f, "%d\n", canvas[i][j]);
							}
						}
						fclose(f);
					} else if (barselect == 3) {
						FILE *f = fopen("paint.txt", "r");

						size_t len = 255;
						char *line = malloc(sizeof(char) * len);

						int i=0;
						int j=0;

						while(fgets(line,len,f) != NULL) {
							canvas[i][j] = (int)line[0] - 48;
							j++;
							if (j>599) {
								j = 0;
								i++;
							}

						}
						
						fclose(f);
					}
				} else if (c == 9) { // tab
					clear_screen(800,40);
					barselect++;
					if (barselect > 3)
						barselect = 0;
					navbar(barselect);
    				render_navbar();
				}
				break;
			}
		}
    }

    munmap(fb, screensize);
    close(fb_driver);
    return 0;
}