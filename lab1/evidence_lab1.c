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
