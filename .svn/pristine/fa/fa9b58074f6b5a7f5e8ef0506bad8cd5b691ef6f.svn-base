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
