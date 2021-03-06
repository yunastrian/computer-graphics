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

	// Author
	int x = 25;
	int xjudul = 300;

    for (int y0=600; y0>=-600; y0--) {
		int y = y0;
		refresh(0, 800, y, 600);
		draw_kata(&xjudul, &y,"Manly");
		int p, q;
		for(p = 0; p < layarx; p++)
		for(q= 0; q < y; q++){
			color c = {200,0,0,255};
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
	    
		y += 32;
		int ytemp = y;
		draw_kata(&x, &y,"Yoga   SMAN 1 Pemali");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {130,100,233,100};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
		ytemp = y;
		draw_kata(&x, &y,"Hafis  SMAN 1 Padang");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {200,200,200,255};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
		ytemp = y;
		draw_kata(&x, &y,"Husein SMAN 1 Klaten");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {200,200,0,255};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}

		ytemp = y;
		draw_kata(&x, &y,"Irfan  SMAN 1 Bogor");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {200,0,200,255};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
		ytemp = y;
		draw_kata(&x, &y,"Nandha SMAN 2 Kediri");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {0,200,200,255};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
		ytemp = y;
		draw_kata(&x, &y,"Azka   MAN Insan Cndekia");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {0,0,200,255};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
		ytemp = y;
		draw_kata(&x, &y,"Trian  SMAN 2 Cimahi");
	    
		for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
			color c = {0,200,0,255};
			if (q<0) q=0;
			if(buffer_r[p][q] == 0) c = bg;
			if (q < layary) {
				draw_dot(p, q, &c);
			}
		}
		usleep(1000);
	}

	// Turret & Plane
	int y1 = 500;
	int x2 = 475;
	int y2 = 535;
	int x3 = 325;
	int y3 = 535;

    for (int x=700; x>=-24; x--) {
		// START REFRESH
		int p, q;
		for(p=0; p < layarx; p++)
		for(q=0; q < layary; q++){
			if(buffer_r[p][q] == 0) {
				color c = bg;
				draw_dot(p, q, &c);
			} else if (buffer_r[p][q] == 15){
				color c = {0,200,0,255};
				draw_dot(p, q, &c);
				buffer_r[p][q] == 0;
				//printf("masuk\n");
			}
		}
		refresh(0, 800, 0, 600);
		// END REFRESH
		color warna = {0,200,0,255};
		draw_turret(&warna);

		color warnap = {0,200,0,255};

		draw_pesawat(x, 100, &warnap);

		color warnat1 = {200,0,0,255};
		color warnat2 = {0,0,200,255};
		color warnat3 = {200,200,200,255};		

		//tembak1
		draw_garis(399,401,y1-60,y1-60,&warnat3);
		draw_garis(398,402,y1,y1,&warnat3);
		draw_garis(399,399,y1,y1-60,&warnat3);
		draw_garis(401,401,y1,y1-60,&warnat3);

		// tembak2
		//draw_garis(x2,x2+10,y2,y2-60,&warnat3);

		// tembak3
		//draw_garis(x3,x3-10,y3,y3-60,&warnat3);

		jedug(1,1,799,599);

		for(p=0; p < layarx; p++)
		for(q=0; q < layary; q++){
			if (buffer_r[p][q] == 15){
				color c = {0,200,0,255};
				draw_dot(p, q, &c);
			}
		}
		
		x3--;
		y3--;
		x2++;
		y2--;
		y1--;
		if (y1 == 179) {
			color warnae = {200,0,0,255};
			for (int wait=0; wait < 1000; wait++) {
				draw_garis(340,400,120,60,&warnae);
				draw_garis(400,460,60,120,&warnae);
				draw_garis(460,400,120,180,&warnae);
				draw_garis(400,340,180,120,&warnae);
			}
			usleep(999999);

			for(int p = 340; p < 700; p++)
			for(int q= 60; q < 200; q++){
				draw_dot(p, q, &bg);
				buffer_r[p][q] = 0;
			}
			int aaa = 340;
			int bbb = 100;
			draw_kata(&aaa,&bbb,"BOOM");
	    
			for(int p = 340; p < 700; p++)
			for(int q= 60; q < 200; q++){
				if(buffer_r[p][q] == 0) {
					draw_dot(p, q, &bg);
				} else {
					draw_dot(p, q, &warnae);
				}
			}

			aaa += 50;
			bbb -= 50;
			usleep(999999);
			for(int p = 340; p < 700; p++)
			for(int q= 60; q < 200; q++){
				draw_dot(p, q, &bg);
				buffer_r[p][q] = 0;
			}
			for (int y0=bbb; y0<580; y0++) {
				int y = y0;
				refresh(0, 800, y, 600);
				int ytemp = y;
				draw_kata(&aaa, &y,"O");
				int p, q;
				for(p=0; p < layarx; p++)
				for(q=0; q < y; q++){
					color c = {200,0,0,255};
					if(buffer_r[p][q] == 0) c = bg;
					if (q < layary) {
						draw_dot(p, q, &c);
						buffer_r[p][q] = 0;
					}
				}
			}
			for (int y0=580; y0>500; y0--) {
				int y = y0;
				refresh(0, 800, y, 600);
				int ytemp = y;
				draw_kata(&aaa, &y,"O");
				int p, q;
				for(p=0; p < layarx; p++)
				for(q=0; q < y; q++){
					color c = {200,0,0,255};
					if(buffer_r[p][q] == 0) c = bg;
					if (q < layary) {
						draw_dot(p, q, &c);
						buffer_r[p][q] = 0;
					}
				}
			}
			for (int y0=500; y0<580; y0++) {
				int y = y0;
				refresh(0, 800, y, 600);
				int ytemp = y;
				draw_kata(&aaa, &y,"O");
				int p, q;
				for(p=0; p < layarx; p++)
				for(q=0; q < y; q++){
					color c = {200,0,0,255};
					if(buffer_r[p][q] == 0) c = bg;
					if (q < layary) {
						draw_dot(p, q, &c);
						buffer_r[p][q] = 0;
					}
				}
			}
			for (int y0=580; y0>560; y0--) {
				int y = y0;
				refresh(0, 800, y, 600);
				int ytemp = y;
				draw_kata(&aaa, &y,"O");
				int p, q;
				for(p=0; p < layarx; p++)
				for(q=0; q < y; q++){
					color c = {200,0,0,255};
					if(buffer_r[p][q] == 0) c = bg;
					if (q < layary) {
						draw_dot(p, q, &c);
						buffer_r[p][q] = 0;
					}
				}
			}
			for (int y0=560; y0<580; y0++) {
				int y = y0;
				refresh(0, 800, y, 600);
				int ytemp = y;
				draw_kata(&aaa, &y,"O");
				int p, q;
				for(p=0; p < layarx; p++)
				for(q=0; q < y; q++){
					color c = {200,0,0,255};
					if(buffer_r[p][q] == 0) c = bg;
					if (q < layary) {
						draw_dot(p, q, &c);
						buffer_r[p][q] = 0;
					}
				}
			}
			usleep(9999999);
			break;
		}

		usleep(10000);
	}

	munmap(fb, screensize);
	close(fb_driver);
	return 0;
}
