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
