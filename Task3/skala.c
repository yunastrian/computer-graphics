#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


/*
    menghasil kan koordinat titik yang letaknya n kali dari letak awal
*/
void skala(int *x, int *y, float n) {
/*initial state:
    x dan y merupakan titik yang akan di skala ulang, dengan n kali dari ukuran awal
*/
    *x = round(*x * n);
    *y = round(*y * n);  
    return;
}    
int main() {
    int x,y;
    x=3;
    y=3;
    skala(&x,&y,0.5);
    printf("%d %d",x,y);

    return 0;
}
