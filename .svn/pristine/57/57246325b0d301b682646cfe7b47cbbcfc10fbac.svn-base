#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waves.h"

double dist(double x0, double y0, double x1, double y1) {
   return sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2)); 
}

void draw_waves(int side_length, int x_offset, int y_offset) {
    printf("P3 \n");
    printf("%d %d \n", side_length, side_length);
    printf("255 \n");
    int counter_horiz = 0;
    int counter_vert = 0;
    for (counter_horiz = 0; counter_horiz < side_length; counter_horiz++) {
        for (counter_vert = 0; counter_vert < side_length; counter_vert++) {
            int num = dist(counter_horiz, x_offset, counter_vert, y_offset);                num = sin(num) + 1;
            int b = (num * 255) / 2; 
            printf("0, 0, %d\n", b);
        }
    }
}

