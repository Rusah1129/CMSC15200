/* graded lab1 */

/* ====== Makefile ====== */

evidence_lab1: lab1.h lab1.c evidence_lab1.c
	clang -Wall -o evidence_lab1 lab1.c evidence_lab1.c

/* ====== lab1.h ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 1
 */

/* expt : linear time recursive exponentiation */
long int expt(int a, unsigned int n);

/* ss : exponentiation by successive squaring */
long int ss(int a, unsigned int n);

/* ssm : exponentiation modulo m by successive squaring */
int ssm(int a, unsigned int n, unsigned int m);

/* ====== lab1.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 1
 */ 

#include "lab1.h"

long int expt(int a, unsigned int n) {
    if (n == 0) {
		//GRADER: bad indentation here
	return 1;
    } else {
	return a * expt(a, n - 1);
    }
}

long int ss(int a, unsigned int n) {
    if (n == 0) {
	return 1;
    } else if(n % 2 == 0) {
	return ss(a, n / 2) * ss(a, n / 2); 	
    } else if(n % 2 == 1) {
        return a * ss(a, n - 1);
    } else {
        return 0;
    }
}

int ssm(int a, unsigned int n, unsigned int m) {
    if (n == 0) {
	return 1;
    } else if(n % 2 == 0) {
			// GRADER: seems % m inside the prentheses are redundant. 
	return ((ssm(a, n / 2, m) % m) * (ssm(a, n / 2, m) % m)) % m;
    } else {
				// GRADER: seems the last % m is redundant. 
        return (a * ssm(a, n - 1, m) % m) % m;
    }
}


/* ====== evidence_lab1.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 1
 */

#include <stdlib.h>
#include <stdio.h>
#include "lab1.h"

/* evidence_expt: test expt */
void evidence_expt()
{
    printf("*** testing expt\n");
    printf("- expecting 1: %ld\n", expt(2,0));
    printf("- expecting 8: %ld\n", expt(2,3));
    printf("- expecting -512: %ld\n", expt(-8,3));
    printf("- expecting 0: %ld\n", expt(0, 7));
    printf("- expecting -125: %ld\n", expt(-5, 3)); 
}

/* evidence_ss: test ss */
void evidence_ss()
{
    printf("*** testing ss\n");
    printf("- expecting 1: %ld\n", ss(2, 0));
    printf("- expecting 8: %ld\n", ss(2, 3));
    printf("- expecting 729: %ld\n", ss(3, 6));
    printf("- expecting -512: %ld\n", expt(-8,3));
    printf("- expecting 0: %ld\n", expt(0, 7));
    printf("- expecting -125: %ld\n", expt(-5, 3));
}

/* evidence_ssm: test ssm */ 
void evidence_ssm()
{
    printf("*** testing ssm\n");
    printf("- expecting 24: %d\n", ssm(2, 10, 1000));
    printf("- expecting 0: %d\n", ssm(0, 4, 50));
    printf("- expecting 9: %d\n", ssm(3, 7, 11));
    printf("- expecting 1: %d\n", ssm(50, 6, 9));
    printf("- expecting 1: %d\n", ssm(4, 6, 3));
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_expt();
    evidence_ss();
    evidence_ssm();
    return 0;
}

/* ====== evaluation ======  */

/* === correctness === */

/* Makefile :                           / 5/5 */
/* lab1.h   :                           / 5/5 */

/* expt     :                           /12/12 */
/* ss       :                           /13/13 */
/* ssm      :                           /13/13 */

/* === style === */

/* code layout                          / 4/5 */
/* all lines <= 80 chars                / 1/1 */
/* identifiers are well named           / 6/6 */

/* functions are well designed          / 6/6 */
/* code is well factored                / 6/6 */

/* code is written clearly              / 6/6 */
/* code is efficient                    / 6/6 */

/* header comments for each function    / 6/6 */
/* for functions in header file:            */
/*   comment only needed above fn           */
/*   in header file; optional in .c         */
/* for helpers in .c file only:             */
/*   comment needed above fn          */
/*   in .c file                            */
/* adequate tests                       / 6/6 */
/* svn used correctly                   / 4/4 */

/* _total-score_                        99/100 */

/* graded by zeweichu */

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
