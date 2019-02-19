#include "kamus.h"
//#include "rotasi.c"

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

	// Author
	int x = 25;
	int xjudul = 300;

	int x1,x2,x3,x4,y1,y2,y3,y4;

	x1 = 20;
	y1 = 200;
	x2 = 70;
	y2 = 200;
	x3 = 20;
	y3 = 202;
	x4 = 70;
	y4 = 202;

	int x11,x12,x13,x14,y11,y12,y13,y14;
	x11 = 0;
	y11 = 194;
	x12 = 70;
	y12 = 194;
	x13 = 70;
	y13 = 208;
	x14 = 0;
	y14 = 208;

	int x21,x22,x23,x24,y21,y22,y23,y24;
	x21 = 5;
	y21 = 194;
	x22 = 10;
	y22 = 194;
	x23 = 10;
	y23 = 184;
	x24 = 5;
	y24 = 184;
	int x25,x26,x27,x28,y25,y26,y27,y28;
	x25 = 5;
	y25 = 208;
	x26 = 10;
	y26 = 208;
	x27 = 10;
	y27 = 218;
	x28 = 5;
	y28 = 218;

	int x31,x32,x33,x34,y31,y32,y33,y34;
	x31 = 35;
	y31 = 194;
	x32 = 55;
	y32 = 194;
	x33 = 55;
	y33 = 189;
	x34 = 35;
	y34 = 189;
	int x35,x36,x37,x38,y35,y36,y37,y38;
	x35 = 35;
	y35 = 208;
	x36 = 55;
	y36 = 208;
	x37 = 55;
	y37 = 213;
	x38 = 35;
	y38 = 213;

	int pp = 0;
    for (int pusatx=20; pusatx<750; pusatx++) {
		
		for(int p = 0; p < layarx; p++)
		for(int q= 0; q < layary; q++){
			color c = {200,0,0,255};
			if(buffer_r[p][q] != 1) {
				draw_dot(p, q, &bg);
				buffer_r[p][q] == 0;
			}
		}		
		refresh(0, 800, 0, 600);
		
		//clear_screen(800,600);
		color yellow = {0,255,255,255};
		color red = {255,0,0,255};
		color blue = {255,255,0,255};
		
		draw_garis(x11,x12,y11,y12,&yellow);
		draw_garis(x12,x13,y12,y13,&yellow);
		draw_garis(x13,x14,y13,y14,&yellow);
		draw_garis(x14,x11,y14,y11,&yellow);
	    
		draw_garis(x21,x22,y21,y22,&blue);
		draw_garis(x22,x23,y22,y23,&blue);
		draw_garis(x23,x24,y23,y24,&blue);
		draw_garis(x24,x21,y24,y21,&blue);

		draw_garis(x25,x26,y25,y26,&blue);
		draw_garis(x26,x27,y26,y27,&blue);
		draw_garis(x27,x28,y27,y28,&blue);
		draw_garis(x28,x25,y28,y25,&blue);

		draw_garis(x31,x32,y31,y32,&blue);
		draw_garis(x32,x33,y32,y33,&blue);
		draw_garis(x33,x34,y33,y34,&blue);
		draw_garis(x34,x31,y34,y31,&blue);

		draw_garis(x35,x36,y35,y36,&blue);
		draw_garis(x36,x37,y36,y37,&blue);
		draw_garis(x37,x38,y37,y38,&blue);
		draw_garis(x38,x35,y38,y35,&blue);

		draw_garis(x1,x2,y1,y2,&red);
		draw_garis(x3,x4,y3,y4,&red);

		rotasi(pusatx+25,201,&x1,&y1,-5);
		rotasi(pusatx+25,201,&x2,&y2,-5);
		rotasi(pusatx+25,201,&x3,&y3,-5);
		rotasi(pusatx+25,201,&x4,&y4,-5);		
		
		x1++;
		x2++;
		x3++;
		x4++;
		x11++;
		x12++;
		x13++;
		x14++;
		x21++;
		x22++;
		x23++;
		x24++;
		x25++;
		x26++;
		x27++;
		x28++;
		x31++;
		x32++;
		x33++;
		x34++;
		x35++;
		x36++;
		x37++;
		x38++;
		usleep(100);
	}

	munmap(fb, screensize);
	close(fb_driver);
	return 0;
}
