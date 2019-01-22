#include "kamus.h"

int main()
{
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

//=======================================================================================

    clear_screen(800, 600);
    int x = 25;
    int xjudul = 300;
    int cepetnaik = 5;
    //int endPoint = -500;


	color bg = {
        0,
        0,
        0,
        0
    };
    for (int y0=600; y0>=-600; y0--) {
//printf("%d\n", y0);
	int y = y0;
    	refresh(0, 800, y, 600);
	    draw_kata(&xjudul, &y,"Manly");
	int p, q;
	    for(p = 0; p < layarx; p++)
		for(q= 0; q < y; q++){
		    color c = {200,0,0,255};

	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }

		}
	    
	    y += 32;
	    int ytemp = y;
	    draw_kata(&x, &y,"Yoga      Belitung");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {130,100,233,100};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;
		    if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}
	    ytemp = y;
	    draw_kata(&x, &y,"Hafis     Padang");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {200,200,200,255};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}
	    ytemp = y;
	    draw_kata(&x, &y,"Husein    Klaten");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {200,200,0,255};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}

	    ytemp = y;
	    draw_kata(&x, &y,"Irfan     Bogor");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {200,0,200,255};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}
	    ytemp = y;
	    draw_kata(&x, &y,"Nandha    Kediri");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {0,200,200,255};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}
	    ytemp = y;
	    draw_kata(&x, &y,"Azka      MAN Insan Cendekia Serpong");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {0,0,200,255};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}
	    ytemp = y;
	    draw_kata(&x, &y,"Trian     Cimahi");
	    
	    for(p = 0; p < layarx; p++)
		for(q= ytemp; q < y; q++){
		    color c = {0,200,0,255};
		    if (q<0) q=0;
	            if(buffer_r[p][q] == 0)
	            	c = bg;

	            if (q < layary) {
	            draw_dot(p, q, &c);
		    }
		}

	    //y0 -= cepetnaik;
	    usleep(5000);
	}
    munmap(fb, screensize);
    close(fb_driver);
    return 0;

}
//End of main

//######################################################################################

