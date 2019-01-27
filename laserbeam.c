#include "kamus.h"

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
    for (int y0=600; y0>=-600; y0--) {
		int y = y0;
		refresh(0, 800, y, 600);
		draw_turret(388,576);
		int p, q;
		for(p = 388; p < 412; p++){
			for(q= 576; q < layary; q++){
				color c = {200,0,0,255};
				if(buffer_r[p][q] == 0) c = bg;
				if (q < layary) {
					draw_dot(p, q, &c);
				}
			}
		}

		int xpesawat = y + 100 - 24;
		int ypesawat = 0;
		draw_pesawat(xpesawat, ypesawat);
		for(p = xpesawat; p < xpesawat+24; p++){
			for(q = ypesawat; q < ypesawat+24; 1++){
				color c = {200,0,0,255};
				if(buffer_r[p][q] == 0) c = bg;
				if (q < layary){
					draw_dot(p,q,&c);
				}
			}
		}
		usleep(10000);
	}
	munmap(fb, screensize);
	close(fb_driver);
	return 0;
}