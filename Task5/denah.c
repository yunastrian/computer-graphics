#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testGetFile();

int main() {
    printf("titiknya adalah: \n");
    testGetFile();

    return 0;
}


void testGetFile() {
    // open file
    FILE *fp = fopen("titik.txt", "r");
    size_t len = 255;
    // need malloc memory for line, if not, segmentation fault error will occurred.
    char *line = malloc(sizeof(char) * len);
    // check if file exist (and you can open it) or not
    if (fp == NULL) {
        printf("can't open file input1.txt!");
        return;
    }
    while(fgets(line, len, fp) != NULL) {
        //printf("%s", line);
        int jumlah = 0;
        int count = 0;
        for(int i=0; i<strlen(line); i++) {
            char kar = line[i+1];
            if ((kar == ',') || (kar == '-') || (kar == ' ')) {
                jumlah += (int)line[i] - 48;
                if (count == 0) {
                    printf("(%d,", jumlah);
                    count = 2;
                } else {
                    printf("%d)\n", jumlah);
                    count = 0;
                }
                jumlah = 0;
                i++;
                if (kar == '-') {
                	break;
                }
            } else {
                jumlah += (int)line[i] - 48;
                jumlah *= 10;
            }
        }
    }
    // printf("\n");
    free(line);
}