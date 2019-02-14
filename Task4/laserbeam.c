#include "kamus.h"

#include <termios.h>
#include <fcntl.h>

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
	/*
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
		usleep(0);
	}
	*/
	// Turret & Plane
	int y1 = 530;
	int x2 = 475;
	int y2 = 535;
	int x3 = 325;
	int y3 = 535;
	int y9 = 60;
	x = 700;
	int turetawal = 0;
	int turetawa = 0;
	int fire = 0;
	int jenis = 1;
	int mboh = 0;
    while (1) {
		set_mode(1);
		// START REFRESH
		int p, q;
		for(p=0; p < layarx; p++)
		for(q=0; q < layary; q++){
			if (q > 300) {
				if(buffer_r[p][q] == 0) {
					color c = bg;
					draw_dot(p, q, &c);
				} else if (buffer_r[p][q] == 15){
					color c = {0,200,0,255};
					draw_dot(p, q, &c);
					buffer_r[p][q] == 0;
					//printf("masuk\n");
				}
			} else {
				if(buffer_r[p][q] == 0) {
					color c = bg;
					draw_dot(p, q, &c);
				} else if (buffer_r[p][q] == 15){
					color c = {200,0,0,255};
					draw_dot(p, q, &c);
					buffer_r[p][q] == 0;
					//printf("masuk\n");
				}
			}
		}
		refresh(0, 800, 0, 600);
		// END REFRESH
		color warna = {0,200,0,255};
		draw_turret(&warna, turetawal);

		color warnap = {255,255,0,255};

		draw_pesawat_left(x, 100, &warnap);

		color warnat1 = {200,0,0,255};
		color warnat2 = {0,0,200,255};
		color warnat3 = {200,200,200,255};		

		//tembak1
		int c;
		if (c = get_key()) {
			if (c == 115) {
				if (fire == 0) turetawa = turetawal;
				fire = 1;
			} else if (c == 97) {
				if (turetawal > -295) {
					turetawal--;
				}
			} else if (c == 100) {
				if (turetawal < 295) {
					turetawal++;
				}
			}
		}
		//printf("%d\n", c);
		if (fire == 1) {
			if (y1<60){
				y9--;		
			}
			if (y1 > 0) {
				//draw_garis(turetawa+399,turetawa+399,y1-y9,y1-y9,&warnat3);
				//draw_garis(turetawa+400,turetawa+399,y1,y1,&warnat3);
				draw_garis(turetawa+399,turetawa+399,y1,y1-y9,&warnat3);
				draw_garis(turetawa+400,turetawa+400,y1,y1-y9,&warnat3);
			}
			y1--;
			if (y9 == 0) {
				y1 = 550;
				y9 = 60;
				fire = 0;
			}
			//c = 0;
		}
		jedug(1,400,799,599);

		for(p=0; p < layarx; p++)
		for(q=0; q < layary; q++){
			if (q > 300) {
				if (buffer_r[p][q] == 15){
					color c = {0,200,0,255};
					draw_dot(p, q, &c);
				}
			} else {
				if (buffer_r[p][q] == 15){
					color c = {200,0,0,255};
					draw_dot(p, q, &c);
				}
			}
		}
		
		x3--;
		y3--;
		x2++;
		y2--;
		
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
			for(int p = 0; p < 800; p++)
			for(int q= 0; q < 600; q++){
				draw_dot(p, q, &bg);
				buffer_r[p][q] = 0;
			}

			int xtemp = 400;
			int xtemo2 = 400;
			for (int y0 = bbb; y0<550; y0++) {
				
				color c = {255,0,0,255};
				draw_garis(xtemp,xtemp+80,y0,y0,&c);
				draw_garis(xtemp+80,xtemp+80,y0,y0+20,&c);
				draw_garis(xtemp+80,xtemp-22,y0+20,y0+20,&c);
				draw_garis(xtemp-20,xtemp,y0+20,y0,&c);

				draw_garis(xtemp-20,xtemp-25,y0+20,y0+15,&c);
				draw_garis(xtemp-25,xtemp-5,y0+15,y0-5,&c);
				draw_garis(xtemp,xtemp-5,y0,y0-5,&c);
				draw_garis(xtemp-5,xtemp+75,y0-5,y0-5,&c);
				draw_garis(xtemp+75,xtemp+80,y0-5,y0,&c);
				xtemp--;

				draw_garis(400+50,400+60,y0-25,y0-15,&c);
				draw_garis(400+50,400+30,y0-25,y0-5,&c);
				draw_garis(400+60,400+50,y0-15,y0-5,&c);
				draw_garis(400+60,400+60,y0-15,y0-10,&c);
				draw_garis(400+60,400+55,y0-10,y0-5,&c);
				draw_garis(400+30,400+60,y0-10,y0-10,&c);
				
				draw_garis(400+30,400+40,y0+15,y0+5,&c);
				draw_garis(400+40,400+60,y0+5,y0+25,&c);
				draw_garis(400+60,400+50,y0+25,y0+35,&c);
				draw_garis(400+50,400+30,y0+35,y0+15,&c);
				draw_garis(400+30,400+30,y0+15,y0+20,&c);
				draw_garis(400+30,400+50,y0+20,y0+40,&c);
				draw_garis(400+50,400+50,y0+40,y0+35,&c);
				draw_garis(400+50,400+60,y0+40,y0+30,&c);
				draw_garis(400+60,400+60,y0+30,y0+25,&c);

				draw_garis(xtemo2+80,xtemo2+85,y0+20,y0+15,&c);
				draw_garis(xtemo2+85,xtemo2+85,y0+15,y0-10,&c);
				draw_garis(xtemo2+85,xtemo2+80,y0-10,y0+5,&c);
				draw_garis(xtemo2+85,xtemo2+75,y0-10,y0-5,&c);
				draw_garis(xtemo2+80,xtemo2+75,y0+20,y0-5,&c);
				if (y0 % 2 == 0) xtemo2++;
				int y = y0;
				//refresh(0, 800, y, 600);
				int ytemp = y;
				//draw_kata(&aaa, &y,"O");
				int p, q;
				for(p=0; p < layarx; p++)
				for(q=0; q < 570; q++){
					color c = {200,0,0,255};
					if(buffer_r[p][q] == 0) c = bg;
					if (q < layary) {
						draw_dot(p, q, &c);
						buffer_r[p][q] = 0;
					}
				}
			}
			break;
		}
		
		usleep(10);
		if (x == 25) {
			jenis =2;
		} else if (x == 700) {
			jenis = 1;
		}

		if (mboh == 0) {
			if (jenis == 1) {
				x--;
			} else {
				x++;
			}
			mboh = 1;
		} else {
			mboh = 0;
		}
	}

	munmap(fb, screensize);
	close(fb_driver);
	return 0;
}
