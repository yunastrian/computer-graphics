#include "kamus.h"

void testGetFile();

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
}

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

    clear_screen(800, 600);

    color bg = {0,0,0,0};
    color blue2 = {0,0,255,255};


    int xmin=11, xmax=60, ymin=11, ymax=60;
    int selector[50][50];
    //int view[200][200];
    int skala = 1;
    int nofile = 1;
    testGetFile(1,1);
    while (1) {
	
	set_mode(1);
	int x99 = 0;	
	for (int i=xmin; i<=xmax; i++) {
		int y99=0;
		for (int j=ymin; j<=ymax; j++) {
			selector[x99][y99] = buffer_r[i][j];
			y99++;
			color green = {0,244,0,255};
			if ((i == xmin) || (i == xmax)) {
				draw_dot(i,j, &green);
			} else if ((j == ymin) || (j == ymax)) {
				draw_dot(i,j,&green);
			}
		}
		x99++;
	}
    int view[200][200];
	resizePixels(50,50,200,200,selector,view);	

	for (int i=0;i<200;i++){
		for (int j=0;j<200;j++){
			buffer_r[500+i][200+j] = view[i][j];
			if (buffer_r[500+i][200+j] != 0) {
				draw_dot(500+i, 200+j, &blue2);
				//buffer_r[500+i][200+j] = 0;
			}
			color green = {0,244,0,255};
			if ((i == 0) || (i == 199)) {
				draw_dot(i+500,j+200, &green);
			} else if ((j == 0) || (j == 199)) {
				draw_dot(i+500,j+200,&green);
			}
		}
	}
	
	int c;
	if (c = get_key()) {
		if (c == 97) {
			if (xmin>10) { // a
				xmin-=10;
				xmax-=10;
			}
			//printf("%d\n", xmax);
		
			//skala++;
		} else if (c == 100) { // d
			//testGetFile(1);
			//skala--;
			if(xmax<181) {
				xmin+=10;
				xmax+=10;
			}
			//printf("pencet d = %d\n", xmax);
		} else if (c == 115) { // s
			if (ymax<225) {
				ymin+=10;
				ymax+=10;
			}
		} else if (c == 119) { // w
			if (ymin>10) {
				ymin-=10;
				ymax-=10;
			}
		} else if (c == 108) {
			nofile = 2;
		} else if (c == 107) {
			nofile = 1;
		} else if (c == 106) {
			nofile = 3;
		}
		testGetFile(skala, nofile);
	}
    }

    munmap(fb, screensize);
    close(fb_driver);
    return 0;
}


void testGetFile(int scale, int nofile) {
    // open file
    FILE *fp;
    if (nofile == 1) {
	fp = fopen("MAP_ITB.txt", "r");
    } else if (nofile == 2) {
	fp = fopen("MAP2.txt", "r");
    } else {
	fp = fopen("MAP3.txt", "r");
    }
    size_t len = 255;
    // need malloc memory for line, if not, segmentation fault error will occurred.
    char *line = malloc(sizeof(char) * len);
    // check if file exist (and you can open it) or not
    if (fp == NULL) {
        printf("can't open file input1.txt!");
        return;
    }

	refresh(0,800,0,600);    
	clear_screen(800,600);
    while(fgets(line, len, fp) != NULL) {
        //printf("%s", line);
        int jumlah = 0;
        int count = 0;
        int x1,x2,x3,x4,y1,y2,y3,y4;
        for(int i=0; i<strlen(line); i++) {
            char kar = line[i+1];
            if ((kar == ',') || (kar == '-') || (kar == ' ')) {
                jumlah += (int)line[i] - 48;
                if (count == 0) {
                    x1 = jumlah*scale; 
                    count++;
                } else if (count == 1) {
                    y1 = jumlah*scale;
                    count++;
                } else if (count == 2) {
                    x2 = jumlah*scale;
                    count++;
                } else if (count == 3) {
                    y2 = jumlah*scale;
                    count++;
                } else if (count == 4) {
                    x3 = jumlah*scale;
                    count++;
                } else if (count == 5) {
                    y3 = jumlah*scale;
                    count++;
                } else if (count == 6) {
                    x4 = jumlah*scale;
                    count++;
                } else if (count == 7) {
                    y4 = jumlah*scale;
                    count = 0;
                }
                jumlah = 0;
                i++;
                if (kar == '-') {
                    color blue = {0,0,255,255};
                    //printf ("%d,%d %d,%d %d,%d %d,%d\n",x1,y1,x2,y2,x3,y3,x4,y4);
                    draw_garis(x1, x2, y1, y2, &blue);
                    draw_garis(x2, x3, y2, y3, &blue);
                    draw_garis(x3, x4, y3, y4, &blue);
                    draw_garis(x4, x1, y4, y1, &blue);
                	break;
                }
            } else {
                jumlah += (int)line[i] - 48;
                jumlah *= 10;
            }
        }
    }
    // printf("\n");
    free(line);
}
