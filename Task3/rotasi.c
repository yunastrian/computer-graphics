#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265
/*
    Menghasilkan semua titik yang ada di antara (x0, y0) dan (x1, y1),
    kemudian memasukkannya ke dalam buf. Jumlah titik dimasukkan ke length.
*/
void rotasi(int xp, int yp, int *x, int *y, int sudut) {
/*initial state:
    xp dan yp merupakan titik acuan untuk x dan y dalam melakukan rotasi
*/
    int x1, y1;//x1 dan y1 merupakan titik hasil rotasi
    double rad = PI * sudut / 180;
    x1 = xp + round(((*x - xp) * cos(rad)) - ((*y - yp)* sin(rad)));
    y1 = yp + round(((*x - xp) * sin(rad)) + ((*y - yp)* cos(rad)));
    *x=x1;
    *y=y1;

    return;
}    
int main() {
    int x,y;
    x=3;
    y=3;
    rotasi (0,0,&x,&y,180);
    printf("%d %d",x,y);

    return 0;
}
