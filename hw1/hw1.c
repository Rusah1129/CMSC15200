/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 1
 */

#include <stdlib.h>
#include <stdio.h>
#include "hw1.h"

unsigned int tens_letters(unsigned int num) {
	if (num % 10 != 0 || num < 0 || num > 90) {
		fprintf(stderr, "tens_letters: must be a multiple of \
			ten between 0 and 90 \n");
		exit(1);
	} else if (num == 0) {
		return 4;
	} else if (num == 10) {
		return 3;
	} else if (num == 20 || num == 30 
		|| num == 80 || num == 90) {
		return 6;
	} else if (num == 40) {
		return 5;
	} else if (num == 50 || num == 60) {
		return 5;
	} else { 
		return 7;
	}
}

void print_divisors(unsigned int n) {
	if (n <= 0) {
		fprintf(stderr, "print_divisors: must be a positive number \n");
		exit(1);
	} else {
		unsigned int counter = 0;
		for (counter = 1; counter <= n; counter++) {
			if (n == counter) {
				printf("%d", counter);
			} else if (n % counter == 0) {
				printf("%d ", counter);
			} else {
				printf("");
			}
		}
	}
}
 
double babylonian_sqrt(double n, double start, double precision) {
	if (start <= 0 || n <= 0) {
        fprintf(stderr, "babylonian_sqrt: number and initial guess \
			must be positive\n");
        exit(1);
	} if (precision == 0) {
        fprintf(stderr, "babylonian_sqrt: precision must not be zero\n");
		exit(1);
	} while ((start * start) > n + precision || \
		(start * start) < n - precision) { 
		start = (start + (n / start)) / 2;
    }
	return start;
}

double integrate_parabola(double a, double b, double c, double left, 	
	double right, unsigned int n) {
	if (right < left) {
        fprintf(stderr, "integrate_parabola: right bound must be greater \
            than left bound\n");
        exit(1); }
    if (right == left) {
		return 0; }
	double rect_width = (right - left) / n;
	double x = left;
	double total_area = 0;
	unsigned int counter = 0;
	for (counter = 0; counter < n; counter++) {
		double rect_height = a * x * x + b * x + c;
		total_area += (rect_height * rect_width);
		x += rect_width;
	} return total_area;
}

double antiderivative_parabola(double a, double b, double c, double x) {
	return ((1.0/3.0) * a * x * x * x + (0.5) * b * x * x + c * x);
}

void draw_parabola(int a, int b, int c) {
    unsigned int counter = 0;
    unsigned int counter2 = 0;
    for (counter = 0; counter < 11; counter++) {
        for (counter2 = 0; counter2 < 11; counter2++) {
			if (a * counter2 * counter2 + b * counter2 + c == (10 - counter)) {
                printf("*");
            } else if (counter == 10 && counter2 == 0) {
                printf("L");
            } else if (counter2 == 0) {
                printf("|");
            } else if (counter == 10) {
                printf("-");
            } else {
                printf(" ");
            } if (counter2 == 10) {
                printf("\n");
            }
        }
    }
}
