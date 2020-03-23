/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 5
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "waves.h"

double dist(double x0, double y0, double x1, double y1) {
   return sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
}

void draw_waves(int side_length, double scale_red, 
    double scale_green, double scale_blue, int x_offset, int y_offset) {
    printf("P3 \n");
    printf("%d %d \n", side_length, side_length);
    printf("255 \n");
    int center = side_length / 2;
    x_offset = center + x_offset;
    y_offset = center + y_offset;
    int counter_horiz = 0;
    int counter_vert = 0;
    for (counter_vert = 0; counter_vert < side_length; counter_vert++) {
        for (counter_horiz = 0; counter_horiz < side_length; counter_horiz++) {
            double d = dist(counter_horiz, counter_vert, x_offset, y_offset);
            double num_b = (sin(d * scale_blue));
            double num_r = (sin(d * scale_red));
            double num_g = (sin(d * scale_green));
            int b = ((num_b + 1.0) * 255) / 2;
            int r = ((num_r + 1.0) * 255) / 2;
            int g = ((num_g + 1.0) * 255) / 2;
            printf("%d %d %d \n", r, g, b);
        }
    }
}
