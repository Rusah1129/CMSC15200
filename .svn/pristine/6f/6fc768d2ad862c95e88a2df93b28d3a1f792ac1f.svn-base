/* graded hw1 */

/* ====== Makefile ====== */

evidence_hw1: hw1.h hw1.c evidence_hw1.c
	clang -Wall -o evidence_hw1 hw1.c evidence_hw1.c

/* ====== hw1.h ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 1
 */

 /* GRADER: -1 (Function Headers)
  * PLease leave more descriptive function comments. A user who does not know
	* the assignment should be able to use the function from the description.
  * E.g. "Compute the antiderivative of the parabola ax^2 + bx + c at the given
  * x value with arbitrary constant term of 0"
  */

/* tens_letters : prints letters in multiples of ten */
unsigned int tens_letters(unsigned int num);

/* print_divisors : prints divisors of a number */
void print_divisors(unsigned int n);

/* babylonian_sqrt : finds a square root approximation */
double babylonian_sqrt(double n, double start, double precision);

/* integrate_parabola : finds the left-handed Riemann sum of a parabola  */
double integrate_parabola(double a, double b, double c, double left, double
right, unsigned int n);

/* antiderivative_parabola : finds the antiderivative of a parabola */
double antiderivative_parabola(double a, double b, double c, double x);

/* draw_parabola : draws a parabola */
void draw_parabola(int a, int b, int c);

/* ====== hw1.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 1
 */

#include <stdlib.h>
#include <stdio.h>
#include "hw1.h"

unsigned int tens_letters(unsigned int num) {
	/* GRADER: An unsigned int cannot be less than 0. If you pass in a number less
	 * than 0, the function will see a very large unsigned int. (So no need to
   * check whether an unsigned int < 0.) */
    if (num % 10 != 0 || num < 0 || num > 90) {
        fprintf(stderr, "tens_letters: must be a multiple of \
		ten between 0 and 90 \n");
	exit(1);
	/* GRADER: -1 (correctness)
	 * You should be using a switch statement here. It will make your code cleaner
	 * and clearer.
	 */
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

/* GRADER: -1 (correctness), -1 (efficiency)
 * Last digit in a line should have a newline after it
 *
 * Also note that you do not need to print a blank "": This prints nothing, but
 * takes time to print nothing.
 */
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
		/* GRADER: You'll probably want to check precision <= 0, since a negative
		 * precision will also cause problems. */
    } if (precision == 0) {
        fprintf(stderr, "babylonian_sqrt: precision must not be zero\n");
        exit(1);
		/* GRADER: -1 (Code design)
		 * You should use the fabs function here. It reduces to a single check
		 * fabs(start*start - n) > precision, rather than two in an "or", and it is
		 * easier to read/understand.
		 */

    } while ((start * start) > n + precision || \
        (start * start) < n - precision) {
        start = (start + (n / start)) / 2;
    } return start;
}

double integrate_parabola(double a, double b, double c, double left,
    double right, unsigned int n) {
		/* GRADER: You should have returned 0 in this case, but that fact was
		buried on Piazza so I won't deduct points. */
    if (right < left) {
        fprintf(stderr, "integrate_parabola: right bound must be greater \
        than left bound\n");
        exit(1);
    } if (right == left) {
        return 0; }
    double rect_width = (right - left) / n;
    double x = left;
    double total_area = 0;
    unsigned int counter = 0;
    for (counter = 0; counter < n; counter++) {
        double rect_height = a * x * x + b * x + c;
				/* GRADER: Great choice of variable names. Clearest code I've seen. */
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

/* ====== evidence_hw1.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 1
 */

#include "hw1.h"
#include <stdlib.h>
#include <stdio.h>

/* evidence_tens_letters: test tens_letters */
void evidence_tens_letters() {
    printf("*** testing tens_letters\n");
    printf("- expecting 3: %d\n", tens_letters(10));
    printf("- expecting 6: %d\n", tens_letters(20));
    printf("- expecting 6: %d\n", tens_letters(30));
    printf("- expecting 5: %d\n", tens_letters(50));
    printf("- expecting 6: %d\n", tens_letters(80));
    printf("- expecting 6: %d\n", tens_letters(90));
}

/* evidence_print_divisors: test print_divisors */
void evidence_print_divisors() {
    printf("*** testing print_divisors\n");
    printf("- expecting 1 2 3 4 6 12:\n");
    print_divisors(12);
    printf("\n");
    printf("- expecting 1:\n");
    print_divisors(1);
    printf("\n");
    printf("- expecting 1 43:\n");
    print_divisors(43);
    printf("\n");
    printf("- expecting 1 2 3 6 43 86 127 129 \
	254 258 381 762 5461 10922 16383 32766:\n");
    print_divisors(32766);
    printf("\n");
}

/* evidence_babylonian_sqrt: test babylonian_sqrt */
void evidence_babylonian_sqrt() {
    printf("*** testing babylonian_sqrt\n");
    printf("- expecting a number near 5 with 0.001 precision: %lf\n", \
	babylonian_sqrt(25.0, 7.0, 0.001));
    printf("- expecting a number near 10 with 0.05 precision: %lf\n", \
        babylonian_sqrt(100, 57, 0.05));
    printf("- expecting a number near 57 with 0.3 precision: %lf\n", \
        babylonian_sqrt(3249, 3248, 0.3));
    printf("- expecting a number near 6 with 1 precision: %lf\n", \
        babylonian_sqrt(36, 22, 1));;
}

/* evidence_integrate_parabola: test integrate_parabola */
void evidence_integrate_parabola() {
    printf("*** testing integrate_parabola\n");
    printf("- expecting 51.75: %lf \n", \
        integrate_parabola(3, 7, 18, 0, 2, 4));
    printf("- expecting 11165: %lf \n", \
        integrate_parabola(108, 13, 2, -6, 4, 10));
    printf("- expecting -17.636: %lf \n", \
        integrate_parabola(-1, 0, 16, -7, 1.3, 6));
}

/* evidence_antiderivative_parabola: test antiderivative_parabola */
void evidence_antiderivative_parabola() {
    printf("*** testing antiderivative_parabola\n");
    printf("- expecting 58: %lf \n", \
	(antiderivative_parabola(3, 7, 18, 2) - \
	antiderivative_parabola(3, 7, 18, 0)));
    printf("- expecting 9970: %lf \n", \
        (antiderivative_parabola(108, 13, 2, 4) - \
	antiderivative_parabola(108, 13, 2, -6)));
    printf("- expecting 17.73: %lf \n", \
	(antiderivative_parabola(-1, 0, 16, 1.3) - \
	antiderivative_parabola(-1, 0, 16, -7)));
}

/* evidence_draw_parabola: test draw_parabola */
void evidence_draw_parabola() {
    printf("*** testing draw_parabola\n");
    printf("- expecting x^2:\n");
    draw_parabola(1, 0, 0);
    printf("\n");
    printf("- expecting x:\n");
    draw_parabola(0, 1, 0);
    printf("\n");
    printf("- expecting 2x:\n");
    draw_parabola(0, 2, 0);
    printf("\n");
    printf("- expecting 7:\n");
    draw_parabola(0, 0, 7);
    printf("\n");
    printf("- expecting -x^2 - 2x - 3:\n");
    draw_parabola(-1, -2, -3);
    printf("\n");
    printf("- expecting -x^2 + 2x + 9:\n");
    draw_parabola(-1, 2, 9);
    printf("\n");
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_tens_letters();
    evidence_print_divisors();
    evidence_babylonian_sqrt();
    evidence_integrate_parabola();
    evidence_antiderivative_parabola();
    evidence_draw_parabola();
    return 0;
}

/* ====== evaluation ====== */

/* === correctness === */

/* problem 1 (tens_letters)                */
/*   - general                         3 / 3 */
/*   - switch used to avoid long       0 / 1
 *     chain of conditionals? */
/*   - multiple cases in a row to      1 / 1
 *     simplify layout? */

/* for all remaining problems,
 * only iteration, not recursion,
 * must be used */

/* problem 2 (print_divisors)          5 / 6 */

/* problem 3 (babylonian_sqrt)         10/10 */

/* problem 4 (integrate_parabola)      10/10 */
/* problem 4 (antiderivative)          2 / 2 */

/* problem 5 (draw_parabola)           15/15 */

/* === style === */

/* code layout                         5 / 5 */
/* all lines <= 80 chars               1 / 1 */
/* identifiers are well named          6 / 6 */

/* functions are well designed         5 / 6 */
/* code is well factored               6 / 6 */

/* code is written clearly             6 / 6 */
/* code is efficient                   5 / 6 */

/* header comments for each function   5 / 6 */
/* for functions in header file:           */
/*   comment only needed above fn          */
/*   in header file; optional in .c        */
/* for helpers in .c file only:            */
/*   comment needed above fn               */
/*   in .c file                            */
/* adequate tests                      6 / 6 */
/* svn used correctly                  4 / 4 */

/* _total-score_                       93/100 */

/* graded by Jordan */

/* GRADER: Excellent work! There were a couple design choices that made your
 * code slightly less readable/efficient, but it was otherwise very well done.
 *
 * Correctness: 46/48
 * Style: 49/52
 * Total: 46 + 46/48 * 49 = 93
 */

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
