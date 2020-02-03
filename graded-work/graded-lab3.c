/* graded lab3 */

/* ====== Makefile ====== */

waves: waves.h waves.c main_waves.c
	clang -Wall -lm -o waves waves.c main_waves.c

evidence_waves: waves.h waves.c evidence_waves.c
	clang -Wall -lm -o evidence_waves waves.c evidence_waves.c

/* ====== waves.h ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 3
 */

/* dist : finds the distance of two points */
double dist(double x0, double y0, double x1, double y1);

/* draw_waves : draws waves as per lab instructions*/
void draw_waves(int side_length, int x_offset, int y_offset);

/* ====== waves.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 3
 */

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
    int center = side_length / 2;
    x_offset = center + x_offset;
    y_offset = center + y_offset;
    int counter_horiz = 0;
    int counter_vert = 0; 
    /* Grader: your for loops should be switched (so that you iterate over the 
    vertical counter in the outer loop).  This is because you're printing pixel 
    RGB values in vertical order (starting with the top left pixel, then one 
    pixel below the top left pixel, etc.), but PPMs list pixels in horizontal 
    order.  So, when there is an offset given, you end up with an image that is 
    rotated 90 degrees from what it should be */
    for (counter_horiz = 0; counter_horiz < side_length; counter_horiz++) {
        for (counter_vert = 0; counter_vert < side_length; counter_vert++) {
            double num = dist(counter_horiz, counter_vert, x_offset, y_offset);
            num = (sin(num)) + 1.0;
            int b = (num * 255) / 2; 
            printf("0 0 %d\n", b);
        }
    }
}


/* ====== main_waves.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waves.h"

/* runs test for main */
int main(int argc, char *argv[])
{
  draw_waves(200, 0, 0);
  return 0;
}

/* ====== evidence_waves.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waves.h"

/* evidence_dist: test dist */
void evidence_dist() {
    printf("*** testing dist\n");
    printf("- expecting 5 %f: \n", dist(3, 4, 0, 0));
    printf("- expecting 5.099 %f: \n", dist(4, 3, 3, -2));
    printf("- expecting 11.4018 %f: \n", dist(-10, 0, 1, 3));
}

/* main: run the evidence function above */
int main(int argc, char *argv[])
{
  evidence_dist();
  return 0;
}

/* ====== evaluation ======  */

/* === correctness === */

/* dist:                               8 / 8 */
/* draw_waves:                         37 /40 */

/* === style === */

/* code layout                         5 / 5 */
/* all lines <= 80 chars               1 / 1 */
/* identifiers are well named          6 / 6 */

/* functions are well designed         6 / 6 */
/* code is well factored               6 / 6 */

/* code is written clearly             6 / 6 */
/* code is efficient                   6 / 6 */

/* header comments for each function   6 / 6 */
/* for functions in header file:            */
/*   comment only needed above fn           */
/*   in header file; optional in .c         */
/* for helpers in .c file only:             */
/*   comment needed above fn                */
/*   in .c file                             */
/* adequate tests                      6 / 6 */
/* svn used correctly                  4 / 4 */

/* _total-score_                       94 /100 */

/* Great job! :) */

/* graded by Tara Vogel */

=== Note: the scoring formula is given here.

The following scoring formula has the effect of scaling style by
correctness. This is so a student cannot, for example, write only one
function out of six and earn full style points.

Let c = correctness points.
Let p = correctness percentage.
Let s = style points.
The total score is (c + p*s), rounded to the nearest integer.

For example, if a student earns 32/64 correctness points and 24/36
style points, the total score is 32 + 0.5 * 24 = 32 + 12 = 44.
