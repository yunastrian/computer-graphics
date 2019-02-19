#include "kamus.h"

void testGetFile();

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

    testGetFile();
    while(1) {

    }

    munmap(fb, screensize);
    close(fb_driver);
    return 0;
}


void testGetFile() {
    // open file
    FILE *fp = fopen("MAP_ITB.txt", "r");
    size_t len = 255;
    // need malloc memory for line, if not, segmentation fault error will occurred.
    char *line = malloc(sizeof(char) * len);
    // check if file exist (and you can open it) or not
    if (fp == NULL) {
        printf("can't open file input1.txt!");
        return;
    }
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
                    x1 = jumlah;
                    count++;
                } else if (count == 1) {
                    y1 = jumlah;
                    count++;
                } else if (count == 2) {
                    x2 = jumlah;
                    count++;
                } else if (count == 3) {
                    y2 = jumlah;
                    count++;
                } else if (count == 4) {
                    x3 = jumlah;
                    count++;
                } else if (count == 5) {
                    y3 = jumlah;
                    count++;
                } else if (count == 6) {
                    x4 = jumlah;
                    count++;
                } else if (count == 7) {
                    y4 = jumlah;
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