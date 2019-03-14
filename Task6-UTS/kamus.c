#include "kamus.h"

char *fb = 0;
int fb_driver = 0;

int layarx = 800;
int layary = 600;

/*
void draw_char(int x, int y, char c){
	if((c == 'a') || (c == 'A')) draw_char_A(x, y);
  else if((c == 'b') || (c == 'B')) draw_char_B(x, y);
  else if((c == 'c') || (c == 'C')) draw_char_C(x, y);
  else if((c == 'd') || (c == 'D')) draw_char_D(x, y);
  else if((c == 'e') || (c == 'E')) draw_char_E(x, y);
  else if((c == 'f') || (c == 'F')) draw_char_F(x, y);
  else if((c == 'g') || (c == 'G')) draw_char_G(x, y);
  else if((c == 'h') || (c == 'H')) draw_char_H(x, y);
	else if((c == 'i') || (c == 'I')) draw_char_I(x, y);
  else if((c == 'k') || (c == 'K')) draw_char_K(x, y);
  else if((c == 'l') || (c == 'L')) draw_char_L(x, y);
  else if((c == 'm') || (c == 'M')) draw_char_M(x, y);
	else if((c == 'n') || (c == 'N')) draw_char_N(x, y);
  else if((c == 'o') || (c == 'O')) draw_char_O(x, y);
  else if((c == 'p') || (c == 'P')) draw_char_P(x, y);
  else if((c == 'r') || (c == 'R')) draw_char_R(x, y);
	else if((c == 's') || (c == 'S')) draw_char_S(x, y);
	else if((c == 't') || (c == 'T')) draw_char_T(x, y);
  else if((c == 'u') || (c == 'U')) draw_char_U(x, y);
  else if((c == 'y') || (c == 'Y')) draw_char_Y(x, y);
  else if((c == 'z') || (c == 'Z')) draw_char_Z(x, y);
	else if((c == ' ') || (c == ' ')) draw_spasi(x, y);
  else if(c == '1') draw_char_1(x, y);
  else if(c == '2') draw_char_2(x, y);
} */

void draw_kata(int* x, int* y, char* kata){
	int xx = *x;
	int yy = *y;
	int icrx = 32;
	int icry = 40;
	char curr = ' ';
	int i = 0;

	while(i < 24){
		curr = kata[i];
		if(curr == '\0') break;
		//draw_char(xx, yy, curr);
		xx += icrx;
		i++;
	}

	*y += icry;
}

void draw_spasi(int x, int y) {
	unsigned char a[24][24] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

	};

	int i, j;
	for(i = 0; i < 24; i++){
		for(j = 0; j < 24; j++){
        	if(y+i < layary && y+i > 0){
	        	buffer_r[x + j][y + i] = a[i][j];
	        	buffer_g[x + j][y + i] = a[i][j];
	        	buffer_b[x + j][y + i] = a[i][j];
        	}
		}
	}
}

void draw_dot(int x, int y, color* c){
	if((x<1) || (x>layarx)){
		return;
	}

    long int position = (x + var_info.xoffset) * (var_info.bits_per_pixel / 8) + (y + var_info.yoffset) * fix_info.line_length;
    if(var_info.bits_per_pixel == 32){
        *(fb + position) = c->b;
        *(fb + position + 1) = c->g;
        *(fb + position + 2) = c->r;
        *(fb + position + 3) = c->a;
    }else{
        int b = c->b;
        int g = c->g;
        int r = c->r;
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(fb + position)) = t;
    }
}

/*
    Menghasilkan semua titik yang ada di antara (x0, y0) dan (x1, y1),
    kemudian memasukkannya ke dalam buf. Jumlah titik dimasukkan ke length.
*/
void line(int x0, int y0, int x1, int y1, int buf[SCREEN_DIAGONAL][2], int *length) {
    int dx, dy, sx, sy, err, e2, i;

    dx = abs(x1-x0);
    dy = abs(y1-y0);

    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    if (dx > dy) {
        err = dx;
    } else {
        err = -dy/2;
    }

    for (i = 0; i < SCREEN_DIAGONAL; i++) {
        /* Mengisikan (x0, y0) ke elemen array ke-i */
        buf[i][0] = x0;
        buf[i][1] = y0;

        if (x0 == x1 && y0 == y1) {
            *length = i;
            break;
        }

        e2 = err;

        if (e2 > -dx) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy) {
            err += dx;
            y0 += sy;
        }
    }
}

void draw_garis(int x0, int x1, int y0, int y1, color* c) {
	int kumpulan_titik[SCREEN_DIAGONAL][2];
    int jumlah_titik;

    line(x0, y0, x1, y1, kumpulan_titik, &jumlah_titik);

	int i;

    for (i = 0; i < jumlah_titik; i++) {
	buffer_r[kumpulan_titik[i][0]][kumpulan_titik[i][1]] = 1;
        draw_dot(kumpulan_titik[i][0], kumpulan_titik[i][1], c);
    }
}

void clear_screen(int width, int height){
    int x = 0;
    int y = 0;

    for(x=0; x<width; x++){
        for(y=0; y<height; y++){
            long int position = (x + var_info.xoffset) * (var_info.bits_per_pixel / 8) +
            	(y + var_info.yoffset) * fix_info.line_length;
            *(fb + position) = 0;
            *(fb + position + 1) = 0;
            *(fb + position + 2) = 0;
            *(fb + position + 3) = 0;
            canvas[x][y] = 0;
        }
    }
}

void refresh(int x0, int x1, int y0, int y1){
    int x = 0;
    int y = 0;

    for(x=x0; x<x1; x++){
        for(y=y0; y<y1; y++){
	        	buffer_r[x][y] = 0;
	        	buffer_g[x][y] = 0;
	        	buffer_b[x][y] = 0;
            color bg = {0,0,0,0};
            draw_dot(x,y, &bg);
        }
    }
}



int isAnomali(int x, int y){
  int anomali=0;
  int cb1=0 , cb2=0;
  if (buffer_r[x-1][y-1] != 0){
    cb1++;
  }
  if (buffer_r[x][y-1] != 0){
    cb1++;
  }
  if (buffer_r[x+1][y-1] != 0){
    cb1++;
  }
  if (buffer_r[x-1][y+1] != 0){
    cb2++;
  }
  if (buffer_r[x][y+1] != 0){
    cb2++;
  }
  if (buffer_r[x+1][y+1] != 0){
    cb2++;
  }
  if ((cb1 == 2) || (cb2 == 2)) {
    anomali = 1;
  } else{
    anomali = 0;
  }
  return anomali;
}


void jedug(int x0, int y0, int x1, int y1){
  //kasih ofset titik sejauh 1 pixel
  x0--;
  y0--;
  x1++;
  y1++;

  // asumsi status 0, kalo status 0 berarti diem, kalo statusnya 1 masukin angka 15 ke buffer
  for (int y=y0; y<=y1; y++){
	int status=0;
    for (int x=x0; x<=x1; x++){
      if(buffer_r[x][y] != 0){// cek apakah ketemu angka selain 0, kalo ada berarti dia ketemu titik
        //if (!isAnomali(x,y)) {
          if (status == 1){
            status=0;// ubah status dari 1 ke 0
          }else{
            status=1;// ubah status dari 0 ke 1
          }
        //}
      }
      if (status==1){// cek apakah statusnya angka 1 bukan, kalo iya gali, kalo bukan lewati
        buffer_r[x][y] = 15; // isi buffer dengan 15
      }
    }
  }
}

void draw_cursor(int x, int y, color* c) {
  draw_dot(x,y, c);
  draw_dot(x-1,y-1, c);
  draw_dot(x-1,y, c);
  draw_dot(x-1,y+1, c);
  draw_dot(x,y-1, c);
  draw_dot(x,y+1, c);
  draw_dot(x+1,y-1, c);
  draw_dot(x+1,y, c);
  draw_dot(x+1,y+1, c);
}

void draw_paint(int x, int y, int z) {
  canvas[x-1][y-1] = z;
  canvas[x-1][y] = z;
  canvas[x-1][y+1] = z;
  canvas[x][y-1] = z;
  canvas[x][y] = z;
  canvas[x][y+1] = z;
  canvas[x+1][y-1] = z;
  canvas[x+1][y] = z;
  canvas[x+1][y+1] = z;
}

void render_canvas() {
  for (int i=0; i<800; i++) {
    for (int j=41; j<600; j++) {
      color warna;
  
	  if (canvas[i][j] == 1) {
	  	color wwarna = {255,0,0,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 2) {
	  	color wwarna = {255,140,0,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 3) {
	  	color wwarna = {255,255,0,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 4) {
	  	color wwarna = {0,255,0,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 5) {
	  	color wwarna = {0,0,255,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 6) {
	  	color wwarna = {75,0,130,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 7) {
	  	color wwarna = {128,0,128,255};
	  	warna = wwarna;
	  } else if (canvas[i][j] == 0) {
	  	color wwarna = {0,0,0,0};
	  	warna = wwarna;
	  } else {
	  	color wwarna = {255,255,255,255};
	  	warna = wwarna;
	  }
      draw_dot(i,j,&warna);
    }
  }
}

void render_navbar(int c) {
  color bg = {0,0,0,0};

  for (int i=0; i<800; i++) {
    for (int j=0; j<41; j++) {
      if (canvas[i][j] == 9) {
        draw_dot(i,j,&bg);
      }
    }
  }

  color warna;
  
  if (c == 1) {
  	color wwarna = {255,0,0,255};
  	warna = wwarna;
  } else if (c == 2) {
  	color wwarna = {255,140,0,255};
  	warna = wwarna;
  } else if (c == 3) {
  	color wwarna = {255,255,0,255};
  	warna = wwarna;
  } else if (c == 4) {
  	color wwarna = {0,255,0,255};
  	warna = wwarna;
  } else if (c == 5) {
  	color wwarna = {0,0,255,255};
  	warna = wwarna;
  } else if (c == 6) {
  	color wwarna = {75,0,130,255};
  	warna = wwarna;
  } else if (c == 7) {
  	color wwarna = {128,0,128,255};
  	warna = wwarna;
  } else if (c == 0) {
  	color wwarna = {0,0,0,0};
  	warna = wwarna;
  } else {
  	color wwarna = {255,255,255,255};
  	warna = wwarna;
  }

  for (int xtemp=107; xtemp<=117; xtemp++)
  	draw_garis(xtemp,xtemp,26,35,&warna);
}

void navbar(int x, int c) {
  color warna;
  
  if (c == 1) {
  	color wwarna = {255,0,0,255};
  	warna = wwarna;
  } else if (c == 2) {
  	color wwarna = {255,140,0,255};
  	warna = wwarna;
  } else if (c == 3) {
  	color wwarna = {255,255,0,255};
  	warna = wwarna;
  } else if (c == 4) {
  	color wwarna = {0,255,0,255};
  	warna = wwarna;
  } else if (c == 5) {
  	color wwarna = {0,0,255,255};
  	warna = wwarna;
  } else if (c == 6) {
  	color wwarna = {75,0,130,255};
  	warna = wwarna;
  } else if (c == 7) {
  	color wwarna = {128,0,128,255};
  	warna = wwarna;
  } else if (c == 0) {
  	color wwarna = {0,0,0,0};
  	warna = wwarna;
  } else {
  	color wwarna = {255,255,255,255};
  	warna = wwarna;
  }
  color white = {255,255,255,255};
  color black = {0,0,0,0};
  color grey = {128,128,128,255};

  draw_garis(1,799,1,1,&white);
  draw_garis(1,799,2,2,&white);
  draw_garis(1,799,3,3,&white);
  draw_garis(1,799,4,4,&white);
  draw_garis(1,799,5,5,&white);
  draw_garis(1,799,6,6,&white);
  draw_garis(1,799,7,7,&white);
  draw_garis(1,799,8,8,&white);
  draw_garis(1,799,9,9,&white);
  draw_garis(1,799,10,10,&white);
  draw_garis(1,799,11,11,&white);
  draw_garis(1,799,12,12,&white);
  draw_garis(1,799,13,13,&white);
  draw_garis(1,799,14,14,&white);
  draw_garis(1,799,15,15,&white);
  draw_garis(1,799,16,16,&white);
  draw_garis(1,799,17,17,&white);
  draw_garis(1,799,18,18,&white);
  draw_garis(1,799,19,19,&white);
  draw_garis(1,799,20,20,&white);
  draw_garis(1,799,21,21,&black);
  draw_garis(1,799,22,22,&white);
  draw_garis(1,799,23,23,&white);
  draw_garis(1,799,24,24,&white);
  draw_garis(1,799,25,25,&white);
  draw_garis(1,799,26,26,&white);
  draw_garis(1,799,27,27,&white);
  draw_garis(1,799,28,28,&white);
  draw_garis(1,799,29,29,&white);
  draw_garis(1,799,30,30,&white);
  draw_garis(1,799,31,31,&white);
  draw_garis(1,799,32,32,&white);
  draw_garis(1,799,33,33,&white);
  draw_garis(1,799,34,34,&white);
  draw_garis(1,799,35,35,&white);
  draw_garis(1,799,36,36,&white);
  draw_garis(1,799,37,37,&white);
  draw_garis(1,799,38,38,&white);
  draw_garis(1,799,39,39,&white);
  draw_garis(1,799,40,40,&white);

  if (x == 1) {
    for (int xtemp=3; xtemp<=30; xtemp++)
      draw_garis(xtemp,xtemp,22,40,&grey);
  } else if (x == 2) {
    for (int xtemp=32; xtemp<=67; xtemp++)
      draw_garis(xtemp,xtemp,22,40,&grey);
  } else if (x == 3) {
    for (int xtemp=69; xtemp<=103; xtemp++)
      draw_garis(xtemp,xtemp,22,40,&grey);
  } else if (x == 4) {
  	for (int xtemp=105; xtemp<=119; xtemp++)
      draw_garis(xtemp,xtemp,22,40,&grey);
  	for (int xtemp=107; xtemp<=117; xtemp++)
  	  draw_garis(xtemp,xtemp,26,35,&warna);
  }

  // P
  canvas[5][6] = 9;
  canvas[5][7] = 9;
  canvas[5][8] = 9;
  canvas[5][9] = 9;
  canvas[5][10] = 9;
  canvas[5][11] = 9;
  canvas[5][12] = 9;
  canvas[5][13] = 9;
  canvas[5][14] = 9;
  canvas[5][15] = 9;
  canvas[6][6] = 9;
  canvas[7][6] = 9;
  canvas[8][6] = 9;
  canvas[9][7] = 9;
  canvas[9][8] = 9;
  canvas[9][9] = 9;
  canvas[9][10] = 9;
  canvas[9][11] = 9;
  canvas[8][12] = 9;
  canvas[7][12] = 9;
  canvas[6][12] = 9;

  // A
  canvas[12][15] = 9;
  canvas[12][14] = 9;
  canvas[12][13] = 9;
  canvas[13][12] = 9;
  canvas[13][11] = 9;
  canvas[14][10] = 9;
  canvas[14][9] = 9;
  canvas[15][8] = 9;
  canvas[15][7] = 9;
  canvas[15][6] = 9;

  canvas[16][6] = 9;
  canvas[16][7] = 9;
  canvas[16][8] = 9;
  canvas[17][9] = 9;
  canvas[17][10] = 9;
  canvas[18][11] = 9;
  canvas[18][12] = 9;
  canvas[19][13] = 9;
  canvas[19][14] = 9;
  canvas[19][15] = 9;

  canvas[12][12] = 9;
  canvas[13][12] = 9;
  canvas[14][12] = 9;
  canvas[15][12] = 9;
  canvas[16][12] = 9;
  canvas[17][12] = 9;
  canvas[18][12] = 9;
  canvas[19][12] = 9;
  
  // I
  canvas[22][6] = 9;
  canvas[22][7] = 9;
  canvas[22][8] = 9;
  canvas[22][9] = 9;
  canvas[22][10] = 9;
  canvas[22][11] = 9;
  canvas[22][12] = 9;
  canvas[22][13] = 9;
  canvas[22][14] = 9;
  canvas[22][15] = 9;

  // N
  canvas[25][6] = 9;
  canvas[25][7] = 9;
  canvas[25][8] = 9;
  canvas[25][9] = 9;
  canvas[25][10] = 9;
  canvas[25][11] = 9;
  canvas[25][12] = 9;
  canvas[25][13] = 9;
  canvas[25][14] = 9;
  canvas[25][15] = 9;

  canvas[25][6] = 9;
  canvas[26][7] = 9;
  canvas[26][8] = 9;
  canvas[26][9] = 9;
  canvas[27][10] = 9;
  canvas[27][11] = 9;
  canvas[28][12] = 9;
  canvas[28][13] = 9;
  canvas[28][14] = 9;
  canvas[29][15] = 9;

  canvas[29][6] = 9;
  canvas[29][7] = 9;
  canvas[29][8] = 9;
  canvas[29][9] = 9;
  canvas[29][10] = 9;
  canvas[29][11] = 9;
  canvas[29][12] = 9;
  canvas[29][13] = 9;
  canvas[29][14] = 9;
  canvas[29][15] = 9;
  
  // T
  canvas[32][6] = 9;
  canvas[33][6] = 9;
  canvas[34][6] = 9;
  canvas[35][6] = 9;
  canvas[36][6] = 9;
  canvas[37][6] = 9;
  canvas[38][6] = 9;
  canvas[35][6] = 9;
  canvas[35][7] = 9;
  canvas[35][8] = 9;
  canvas[35][9] = 9;
  canvas[35][10] = 9;
  canvas[35][11] = 9;
  canvas[35][12] = 9;
  canvas[35][13] = 9;
  canvas[35][14] = 9;
  canvas[35][15] = 9;

  /*
  // File
  // F
  canvas[5][26] = 9;
  canvas[5][27] = 9;
  canvas[5][28] = 9;
  canvas[5][29] = 9;
  canvas[5][30] = 9;
  canvas[5][31] = 9;
  canvas[5][32] = 9;
  canvas[5][33] = 9;
  canvas[5][34] = 9;
  canvas[5][35] = 9;

  canvas[6][26] = 9;
  canvas[7][26] = 9;
  canvas[8][26] = 9;
  canvas[9][26] = 9;
  canvas[10][26] = 9;

  canvas[6][30] = 9;
  canvas[7][30] = 9;
  canvas[8][30] = 9;
  canvas[9][30] = 9;
  canvas[10][30] = 9;

  // I
  canvas[13][26] = 9;
  canvas[13][27] = 9;
  canvas[13][28] = 9;
  canvas[13][29] = 9;
  canvas[13][30] = 9;
  canvas[13][31] = 9;
  canvas[13][32] = 9;
  canvas[13][33] = 9;
  canvas[13][34] = 9;
  canvas[13][35] = 9;

  // L
  canvas[16][26] = 9;
  canvas[16][27] = 9;
  canvas[16][28] = 9;
  canvas[16][29] = 9;
  canvas[16][30] = 9;
  canvas[16][31] = 9;
  canvas[16][32] = 9;
  canvas[16][33] = 9;
  canvas[16][34] = 9;
  canvas[16][35] = 9;
  canvas[17][35] = 9;
  canvas[18][35] = 9;
  canvas[19][35] = 9;
  canvas[20][35] = 9;
  canvas[21][35] = 9;

  // E
  canvas[24][26] = 9;
  canvas[24][27] = 9;
  canvas[24][28] = 9;
  canvas[24][29] = 9;
  canvas[24][30] = 9;
  canvas[24][31] = 9;
  canvas[24][32] = 9;
  canvas[24][33] = 9;
  canvas[24][34] = 9;
  canvas[24][35] = 9;

  canvas[24][26] = 9;
  canvas[25][26] = 9;
  canvas[26][26] = 9;
  canvas[27][26] = 9;
  canvas[28][26] = 9;

  canvas[24][30] = 9;
  canvas[25][30] = 9;
  canvas[26][30] = 9;
  canvas[27][30] = 9;
  canvas[28][30] = 9;

  canvas[24][35] = 9;
  canvas[25][35] = 9;
  canvas[26][35] = 9;
  canvas[27][35] = 9;
  canvas[28][35] = 9;
  */

  // New
  // N
  canvas[5][26] = 9;
  canvas[5][27] = 9;
  canvas[5][28] = 9;
  canvas[5][29] = 9;
  canvas[5][30] = 9;
  canvas[5][31] = 9;
  canvas[5][32] = 9;
  canvas[5][33] = 9;
  canvas[5][34] = 9;
  canvas[5][35] = 9;

  canvas[5][26] = 9;
  canvas[6][27] = 9;
  canvas[6][28] = 9;
  canvas[6][29] = 9;
  canvas[7][30] = 9;
  canvas[7][31] = 9;
  canvas[8][32] = 9;
  canvas[8][33] = 9;
  canvas[8][34] = 9;
  canvas[9][35] = 9;

  canvas[9][26] = 9;
  canvas[9][27] = 9;
  canvas[9][28] = 9;
  canvas[9][29] = 9;
  canvas[9][30] = 9;
  canvas[9][31] = 9;
  canvas[9][32] = 9;
  canvas[9][33] = 9;
  canvas[9][34] = 9;
  canvas[9][35] = 9;

  // E
  canvas[12][26] = 9;
  canvas[12][27] = 9;
  canvas[12][28] = 9;
  canvas[12][29] = 9;
  canvas[12][30] = 9;
  canvas[12][31] = 9;
  canvas[12][32] = 9;
  canvas[12][33] = 9;
  canvas[12][34] = 9;
  canvas[12][35] = 9;

  canvas[12][26] = 9;
  canvas[13][26] = 9;
  canvas[14][26] = 9;
  canvas[15][26] = 9;
  canvas[16][26] = 9;

  canvas[12][30] = 9;
  canvas[13][30] = 9;
  canvas[14][30] = 9;
  canvas[15][30] = 9;
  canvas[16][30] = 9;

  canvas[12][35] = 9;
  canvas[13][35] = 9;
  canvas[14][35] = 9;
  canvas[15][35] = 9;
  canvas[16][35] = 9;

  // W
  canvas[19][26] = 9;
  canvas[19][27] = 9;
  canvas[19][28] = 9;
  canvas[19][29] = 9;
  canvas[20][30] = 9;
  canvas[20][31] = 9;
  canvas[21][32] = 9;
  canvas[21][33] = 9;
  canvas[21][34] = 9;
  canvas[21][35] = 9;

  canvas[22][34] = 9;
  canvas[22][33] = 9;
  canvas[22][32] = 9;
  canvas[23][31] = 9;
  canvas[23][30] = 9;
  canvas[23][29] = 9;

  canvas[24][29] = 9;
  canvas[24][30] = 9;
  canvas[24][31] = 9;
  canvas[25][32] = 9;
  canvas[25][33] = 9;
  canvas[25][34] = 9;

  canvas[26][35] = 9;
  canvas[26][34] = 9;
  canvas[26][33] = 9;
  canvas[26][32] = 9;
  canvas[27][31] = 9;
  canvas[27][30] = 9;
  canvas[28][29] = 9;
  canvas[28][28] = 9;
  canvas[28][27] = 9;
  canvas[28][26] = 9;

  // SAVE
  // S
  canvas[34][26] = 9;
  canvas[34][27] = 9;
  canvas[34][28] = 9;
  canvas[34][29] = 9;
  canvas[34][30] = 9;

  canvas[38][30] = 9;
  canvas[38][31] = 9;
  canvas[38][32] = 9;
  canvas[38][33] = 9;
  canvas[38][34] = 9;
  canvas[38][35] = 9;

  canvas[34][26] = 9;
  canvas[35][26] = 9;
  canvas[36][26] = 9;
  canvas[37][26] = 9;
  canvas[38][26] = 9;

  canvas[34][30] = 9;
  canvas[35][30] = 9;
  canvas[36][30] = 9;
  canvas[37][30] = 9;
  canvas[38][30] = 9;

  canvas[34][35] = 9;
  canvas[35][35] = 9;
  canvas[36][35] = 9;
  canvas[37][35] = 9;
  canvas[38][35] = 9;

  // A
  canvas[41][35] = 9;
  canvas[41][34] = 9;
  canvas[41][33] = 9;
  canvas[42][32] = 9;
  canvas[42][31] = 9;
  canvas[43][30] = 9;
  canvas[43][29] = 9;
  canvas[44][28] = 9;
  canvas[44][27] = 9;
  canvas[44][26] = 9;

  canvas[45][26] = 9;
  canvas[45][27] = 9;
  canvas[45][28] = 9;
  canvas[46][29] = 9;
  canvas[46][30] = 9;
  canvas[47][31] = 9;
  canvas[47][32] = 9;
  canvas[48][33] = 9;
  canvas[48][34] = 9;
  canvas[48][35] = 9;

  canvas[41][32] = 9;
  canvas[42][32] = 9;
  canvas[43][32] = 9;
  canvas[44][32] = 9;
  canvas[45][32] = 9;
  canvas[46][32] = 9;
  canvas[47][32] = 9;
  canvas[48][32] = 9;

  // V
  canvas[51][26] = 9;
  canvas[51][27] = 9;
  canvas[51][28] = 9;
  canvas[52][29] = 9;
  canvas[52][30] = 9;
  canvas[53][31] = 9;
  canvas[53][32] = 9;
  canvas[54][33] = 9;
  canvas[54][34] = 9;
  canvas[54][35] = 9;
  canvas[58][26] = 9;
  canvas[58][27] = 9;
  canvas[58][28] = 9;
  canvas[57][29] = 9;
  canvas[57][30] = 9;
  canvas[56][31] = 9;
  canvas[56][32] = 9;
  canvas[55][33] = 9;
  canvas[55][34] = 9;
  canvas[55][35] = 9;

  // E
  canvas[61][26] = 9;
  canvas[61][27] = 9;
  canvas[61][28] = 9;
  canvas[61][29] = 9;
  canvas[61][30] = 9;
  canvas[61][31] = 9;
  canvas[61][32] = 9;
  canvas[61][33] = 9;
  canvas[61][34] = 9;
  canvas[61][35] = 9;

  canvas[61][26] = 9;
  canvas[62][26] = 9;
  canvas[63][26] = 9;
  canvas[64][26] = 9;
  canvas[65][26] = 9;

  canvas[61][30] = 9;
  canvas[62][30] = 9;
  canvas[63][30] = 9;
  canvas[64][30] = 9;
  canvas[65][30] = 9;

  canvas[61][35] = 9;
  canvas[62][35] = 9;
  canvas[63][35] = 9;
  canvas[64][35] = 9;
  canvas[65][35] = 9;

  // Open
  // O
  canvas[75][26] = 9;
  canvas[74][27] = 9;
  canvas[73][28] = 9;
  canvas[72][29] = 9;
  canvas[71][30] = 9;
  canvas[71][31] = 9;
  canvas[72][32] = 9;
  canvas[73][33] = 9;
  canvas[74][34] = 9;
  canvas[75][35] = 9;

  canvas[76][26] = 9;
  canvas[77][27] = 9;
  canvas[78][28] = 9;
  canvas[79][29] = 9;
  canvas[80][30] = 9;
  canvas[80][31] = 9;
  canvas[79][32] = 9;
  canvas[78][33] = 9;
  canvas[77][34] = 9;
  canvas[76][35] = 9;  

  // P
  canvas[83][26] = 9;
  canvas[83][27] = 9;
  canvas[83][28] = 9;
  canvas[83][29] = 9;
  canvas[83][30] = 9;
  canvas[83][31] = 9;
  canvas[83][32] = 9;
  canvas[83][33] = 9;
  canvas[83][34] = 9;
  canvas[83][35] = 9;
  canvas[84][26] = 9;
  canvas[85][26] = 9;
  canvas[86][26] = 9;
  canvas[87][27] = 9;
  canvas[87][28] = 9;
  canvas[87][29] = 9;
  canvas[87][30] = 9;
  canvas[87][31] = 9;
  canvas[86][32] = 9;
  canvas[85][32] = 9;
  canvas[84][32] = 9;

  // E
  canvas[90][26] = 9;
  canvas[90][27] = 9;
  canvas[90][28] = 9;
  canvas[90][29] = 9;
  canvas[90][30] = 9;
  canvas[90][31] = 9;
  canvas[90][32] = 9;
  canvas[90][33] = 9;
  canvas[90][34] = 9;
  canvas[90][35] = 9;

  canvas[90][26] = 9;
  canvas[91][26] = 9;
  canvas[92][26] = 9;
  canvas[93][26] = 9;
  canvas[94][26] = 9;

  canvas[90][30] = 9;
  canvas[91][30] = 9;
  canvas[92][30] = 9;
  canvas[93][30] = 9;
  canvas[94][30] = 9;

  canvas[90][35] = 9;
  canvas[91][35] = 9;
  canvas[92][35] = 9;
  canvas[93][35] = 9;
  canvas[94][35] = 9;

  // N
  canvas[97][26] = 9;
  canvas[97][27] = 9;
  canvas[97][28] = 9;
  canvas[97][29] = 9;
  canvas[97][30] = 9;
  canvas[97][31] = 9;
  canvas[97][32] = 9;
  canvas[97][33] = 9;
  canvas[97][34] = 9;
  canvas[97][35] = 9;

  canvas[97][26] = 9;
  canvas[98][27] = 9;
  canvas[98][28] = 9;
  canvas[98][29] = 9;
  canvas[99][30] = 9;
  canvas[99][31] = 9;
  canvas[100][32] = 9;
  canvas[100][33] = 9;
  canvas[100][34] = 9;
  canvas[101][35] = 9;

  canvas[101][26] = 9;
  canvas[101][27] = 9;
  canvas[101][28] = 9;
  canvas[101][29] = 9;
  canvas[101][30] = 9;
  canvas[101][31] = 9;
  canvas[101][32] = 9;
  canvas[101][33] = 9;
  canvas[101][34] = 9;
  canvas[101][35] = 9;

}
