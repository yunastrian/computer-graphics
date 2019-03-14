#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265

#define SCREEN_DIAGONAL 1000 // Jumlah maksimum titik yang ada pada diagonal layar

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
int canvas[800][600];

void draw_char(int x, int y, char c);
void draw_kata(int* x, int* y, char* kata);
void draw_spasi(int x, int y);
void draw_dot(int x, int y, color* c);
void draw_garis(int x0, int x1, int y0, int y1, color* c);
void clear_screen(int width, int height);
void refresh(int x0, int x1, int y0, int y1);
void jedug(int x0, int y0, int x1, int y1);
void line(int x0, int y0, int x1, int y1, int buf[SCREEN_DIAGONAL][2], int *length);
int isAnomali(int x, int y);
void draw_cursor(int x, int y, color* c);
void draw_paint(int x, int y, int z);
void render_canvas();
void render_navbar();
void navbar(int x);