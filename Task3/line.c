#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SCREEN_DIAGONAL 1000 // Jumlah maksimum titik yang ada pada diagonal layar

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

void print_line(int buf[SCREEN_DIAGONAL][2], int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("(%d, %d)\n", buf[i][0], buf[i][1]);
    }
}

int main() {
    int kumpulan_titik[SCREEN_DIAGONAL][2];
    int jumlah_titik;

    line(0, 0, 5, 10, kumpulan_titik, &jumlah_titik);

    print_line(kumpulan_titik, jumlah_titik);

    return 0;
}
