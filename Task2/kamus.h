#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>

typedef struct{
    int r,g,b,a;
} color;

struct fb_var_screeninfo var_info;
struct fb_fix_screeninfo fix_info;
extern char *fb; //pointer framebuffer
extern int fb_driver; //pointer framebuffer driver

extern int layarx;
extern int layary;

unsigned char buffer_r[800][600];
unsigned char buffer_g[800][600];
unsigned char buffer_b[800][600];

void draw_pesawat(int x, int y, color* c);
void draw_turret(color *c);
void draw_char_A(int x, int y);
void draw_char_B(int x, int y);
void draw_char_C(int x, int y);
void draw_char_D(int x, int y);
void draw_char_E(int x, int y);
void draw_char_F(int x, int y);
void draw_char_G(int x, int y);
void draw_char_H(int x, int y);
void draw_char_I(int x, int y);
void draw_char_J(int x, int y);
void draw_char_K(int x, int y);
void draw_char_L(int x, int y);
void draw_char_M(int x, int y);
void draw_char_N(int x, int y);
void draw_char_O(int x, int y);
void draw_char_P(int x, int y);
void draw_char_Q(int x, int y);
void draw_char_R(int x, int y);
void draw_char_S(int x, int y);
void draw_char_T(int x, int y);
void draw_char_U(int x, int y);
void draw_char_V(int x, int y);
void draw_char_W(int x, int y);
void draw_char_X(int x, int y);
void draw_char_Y(int x, int y);
void draw_char_Z(int x, int y);
void draw_char_1(int x, int y);
void draw_char_2(int x, int y);
void draw_char(int x, int y, char c);
void draw_kata(int* x, int* y, char* kata);
void draw_spasi(int x, int y);
void draw_dot(int x, int y, color* c);
void draw_garis(int x0, int x1, int y0, int y1, color* c);
void clear_screen(int width, int height);
void refresh(int x0, int x1, int y0, int y1);
void jedug(int x0, int y0, int x1, int y1);
//function
int isAnomali(int x, int y);