/* graded lab4 */

/* ====== Makefile ====== */

waves: waves.h waves.c main_waves.c
        clang -Wall -lm -o waves waves.c main_waves.c

evidence_waves: waves.h waves.c evidence_waves.c
        clang -Wall -lm -o evidence_waves waves.c evidence_waves.c
                                                                   

/* ====== waves.h ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 5
 */

/* dist : finds the distance of two points */
double dist(double x0, double y0, double x1, double y1);

/* draw_waves : draws waves as per lab instructions*/
void draw_waves(int side_length, double scale_red, double scale_green,
double scale_blue, int x_offset, int y_offset);

/* ====== evidence_waves.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 5
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



/* ====== main_waves.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 5
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "waves.h"

/* runs test for main */
int main(int argc, char *argv[])
{
    int i, s, x, y;
    double r, g, b;
    i = 1;
    s = 200;
    r = 1.0;
    g = 1.0;
    b = 1.0;
    x = 0;
    y = 0;

    for (i = 1; i < (argc - 1); i++) {
        
	if (!strcmp(argv[i], "-s")) {
            s = atof(argv[i + 1]);
            i++;
        } else if (!strcmp(argv[i], "-r")) {
            r = atof(argv[i + 1]);
            i++;
        } else if (!strcmp(argv[i], "-g")) {
            g = atof(argv[i + 1]);
            i++;
        } else if (!strcmp(argv[i], "-b")) {
            b = atof(argv[i + 1]);
            i++;
        } else if (!strcmp(argv[i], "-x")) {
            x = atoi(argv[i + 1]);
            i++;
        } else if (!strcmp(argv[i], "-s")) {
            y = atof(argv[i + 1]);;
            i++;
        }
    }
    draw_waves(s, r, g, b, x, y);
    return 0;
}      

/* ====== waves.c ====== */

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

/* ====== evaluation ======  */

/* === correctness === */

/* arg processing:                      27/30 */
/* image generation:                    /24 */

/* === style === */

/* code layout                          / 5 */
/* all lines <= 80 chars                / 1 */
/* identifiers are well named           / 6 */

/* functions are well designed          / 6 */
/* code is well factored                / 6 */

/* code is written clearly              / 6 */
/* code is efficient                    / 6 */

/* header comments for each fn in .h    / 6 */
/* for functions in header file:            */
/*   comment only needed above fn           */
/*   in header file; optional in .c         */
/* for helpers in .c file only:             */
/*   comment needed above fn                */
/*   in .c file                             */
/* svn used correctly                   / 4 */

/* _total-score_                        94/100 */

/* 
	GRADER: 
    - The Makefile is unsusable

    It should be exactly like this (check out the whitespaces):

waves: waves.h waves.c main_waves.c
    clang -Wall -lm -o waves waves.c main_waves.c

evidence_waves: waves.h waves.c evidence_waves.c
    clang -Wall -lm -o evidence_waves waves.c evidence_waves.c
    
    - There is a slight error in your arg processing at main_waves.c, 
        causing the center in a wrong position when you apply some offsets.

    This is the correct code:

  int s = 200;
  double r = 1.0, g = 1.0, b = 1.0;
  int x = 0, y = 0;
  if (argc > 1) {
    unsigned int i;
    for (i = 1; i < argc; i += 2) {
      if (!strcmp(argv[i], "-s")) {
        s = atoi(argv[i+1]);
      } else if (!strcmp(argv[i], "-r")) {
        r = atof(argv[i+1]);
      } else if (!strcmp(argv[i], "-g")) {
        g = atof(argv[i+1]);
      } else if (!strcmp(argv[i], "-b")) {
        b = atof(argv[i+1]);
      } else if (!strcmp(argv[i], "-x")) {
        x = atoi(argv[i+1]);
      } else if (!strcmp(argv[i], "-y")) {
        y = atoi(argv[i+1]);
      } 
    }
  }
  draw_waves(s, r, g, b, x, y);

*/


/* graded by Daniar H. Kurniawan */

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
