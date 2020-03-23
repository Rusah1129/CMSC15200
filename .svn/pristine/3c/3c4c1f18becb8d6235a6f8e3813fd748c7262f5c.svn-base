/* graded hw3 */

/* ====== Makefile ====== */

evidence_hw3: hw3.h hw3.c evidence_hw3.c
	clang -o evidence_hw3 -Wall -lm hw3.c evidence_hw3.c

/* ====== hw3.h ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 3
 */

char** split_at(char* s, char d);

typedef struct measurement measurement;

struct measurement {
    double value;
    char* units;
    unsigned int exponent;
};

typedef struct conversion conversions;

struct conversion {
    char *from, *to;
    double mult_by;
};

struct measurement add_measurements(struct measurement m1, \
    struct measurement m2);

struct measurement scale_measurements(struct measurement m, double lambda);

struct measurement multiply_measurements(struct measurement m1, \
    struct measurement m2);

char* measurement_tos(struct measurement m);

struct measurement convert_units(struct conversion* conversions,
                                 unsigned int n_conversions,
                                 struct measurement m,
                                 char* to);

typedef struct element element;

struct element {
    char* name;
    unsigned int weight;
};

typedef struct molecule molecule;

struct molecule {
    char* name;
    unsigned int nelements;
    struct element** elements;
    unsigned int* atoms;
 /* there are atoms[i] atoms of element elements[i] */
};

union chemical {
    struct element* element;
    struct molecule* molecule;
};

enum chemical_tag {
    ELEMENT, MOLECULE
};

typedef struct tagged_chemical tagged_chemical;

struct tagged_chemical {
    enum chemical_tag tag;
    union chemical chemical;
};

typedef struct mixture mixture;

struct mixture {
    char* name;
    unsigned int nchemicals;
    struct tagged_chemical* chemicals;
    double* moles;
/*  there are moles[i] moles of chemical chemicals[i] */
};

double mixture_weight(struct mixture* mixture);

/* ====== hw3.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "hw3.h"

int helper_length (char* s, char d, int i) {
    while (s[i] != '\0' && s[i] != d) {
        i++;
    }
    return i;
}

int helper_length_total (char* s, char d) {
    int j = 0;
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == d) {
            ++j;
        }
        ++i;
    }
    return j;
}

/* GRADER: -6 (correctness)
The code segfaults before running, and runs incorrectly when the segfault is
fixed. */
char** split_at(char* s, char d) {
    int k = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int total_length = helper_length_total(s, d);
    char **array = (char**) malloc (total_length * sizeof(char*));
    for (k = 0; k < total_length; k++) {
        int small_length = helper_length(s, d, c);
        char *small_array = (char*) malloc (small_length * sizeof(char*));
        c = small_length;
        for (a = 0; a < small_length; a++) {
            small_array[b] = s[b + c];
            b++;
        }
				/* GRADER: Needs to be array[k] = small_array (no dereferences) */
        *array[k] = *small_array;
        k++;
        c++;
        b = 0;
    }

    return array;
}

struct measurement add_measurements(struct measurement m1, \
    struct measurement m2) {

    struct measurement m3;
    /*
    if (m1.units != m2.units) {
        printf("Units must be the same. \n");
        exit(1);
    } else if (m1.exponent != m2.exponent) {
        printf("Exponents must be the same. \n");
        exit(1);
    }*/
    m3.value = m1.value + m2.value;
    m3.units = malloc(2 * sizeof(char));
    strcpy(m3.units, m1.units);
    m3.exponent = m1.exponent;
    return m3;
}

struct measurement scale_measurements(struct measurement m, double lambda) {
    struct measurement m4;

    m4.value = m.value * lambda;
    m4.units = malloc(2 * sizeof(char));
    strcpy(m4.units, m.units);
    m4.exponent = m.exponent;
    return m4;
}

struct measurement multiply_measurements(struct measurement m1, \
    struct measurement m2) {

    struct measurement m7;

    m7.value = m1.value * m2.value;
    m7.units = strdup(m1.units);
    m7.exponent = m1.exponent + m2.exponent;
    return m7;
}

/* GRADER: -1 (correctness)
Do not print ^1 */
char* measurement_tos(struct measurement m) {
    char result[100];
    sprintf(result, "%f %s^%d\n", m.value, m.units, m.exponent);
    char* res = strdup(result);
    return res;
}

/* GRADER: -3 (correctness)
Need output units to be "to"
Need to include exponent in multiplication
Exponent should not be identically 1. */

struct measurement convert_units(struct conversion* conversions, \
    unsigned int n_conversions, struct measurement m, char* to) {
    int i = 0;
    struct measurement m8;
    for (i = 0; i < n_conversions; i++) {
        if (!strcmp(conversions[i].from, m.units)) {
            m8.value = m.value * conversions[i].mult_by;
            m8.units = strdup(m.units);
            m8.exponent = 1;
        }
    }
    return m8;
}

/* ====== evidence_hw3.c ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "hw3.h"

void help_read(char** s, int len) {
    int i = 0;
    int j = 0;
    for (i = 0; i < len; i++) {
        while (s[i][j] != '\0') {
            printf("%c", s[i][j]);
            j++;
        }
    }
}

/* GRADER: -1 (correctness)
Make sure you free the malloc'd strings and the char** array. */
void evidence_split_at() {
    printf("*** testing split_at\n");

    char *new_sentence1 = *split_at("The quick brown fox jumped over the \
        lazy dog", ' ');
    printf("- expecting Thequickbrownfoxjumpedoverthelazydog \n");
    help_read(&new_sentence1, 7);
    printf("\n");

    char *new_sentence2 = *split_at("remove all e's in this sentence.", 'e');
    help_read(&new_sentence2, 7);
    printf("- expecting rmov all 's in this sntnc.\n");
/*
    char *new_sentence3 = *split_at("foooooool!", "o");
    help_read(&new_sentence3, 2);
    printf("- expecting fl! \n");*/
}

void evidence_add_measurements() {
    struct measurement one;

    one.value = 10;
    one.units = malloc(2 * sizeof(char));
    strcpy(one.units, "in");
    one.exponent = 2;

    struct measurement two;

    two.value = 3;
    two.units = malloc(2 * sizeof(char));
    strcpy(two.units, "in");
    two.exponent = 2;

    struct measurement m3;

    m3 = add_measurements(one, two);
    printf("%f %s %d\n", m3.value, m3.units, m3.exponent);

    free(one.units);
    free(two.units);
    free(m3.units);
}

void evidence_scale_measurements() {
    struct measurement m;

    m.value = 5;
    m.units = malloc(2 * sizeof(char));
    strcpy(m.units, "in");
    m.exponent = 2;

    struct measurement m4;

    m4 = scale_measurements(m, 5);
    printf("%f %s %d\n", m4.value, m4.units, m4.exponent);

    free(m.units);
    free(m4.units);

}

void evidence_multiply_measurements() {

    struct measurement m5;

    m5.value = 4;
    m5.units = strdup("in");
    m5.exponent = 2;

    struct measurement m6;

    m6.value = 6;
    m6.units = strdup("in");
    m6.exponent = 3;

    struct measurement m7;
    m7 = multiply_measurements(m5, m6);
    printf("%f %s %d\n", m7.value, m7.units, m7.exponent);

    free(m6.units);
    free(m5.units);
    free(m7.units);
}

void evidence_measurement_tos() {

    struct measurement m8;

    m8.value = 9;
    m8.units = strdup("ft");
    m8.exponent = 5;

    char* str = measurement_tos(m8);
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
    free(m8.units);
}

void evidence_convert_units() {

    struct conversion c1;
    struct conversion c2;
    struct conversion c3;
    struct conversion c4;

    struct conversion conversions[4] = {
        {c1.from = strdup("m"), c1.to = strdup("ft"), \
            c1.mult_by = 0.3048},
        {c2.from = "ft", c2.to = "in", c2.mult_by = 12},
        {c3.from = strdup("lb"), c3.to = strdup("oz"), c3.mult_by = 16},
        {c4.from = strdup("min"), c4.to = strdup("sec"), c4.mult_by = 60}
    };

    struct measurement m8;

    m8.value = 3;
    m8.units = strdup("m");
    m8.exponent = 1;
    struct measurement m9;
    m9 = convert_units(conversions, 4, m8, "ft");
    printf("%f %s %d\n", m9.value, m9.units, m9.exponent);

}
/*
double mixture_weight(struct mixture* mixture) {

    struct element *el1;

    el1 -> name = {ptr1, ptr2};
    el1 -> weight = {ptr3, ptr4};

    char *ptr1 = strdup("Hydrogen");
    char *ptr2 = strdup("Chlorine");
    int ptr3 = 3.0;
    int ptr4 = 2.0;
    int *ptr5 = {1, 1};

    struct molecule ml1;
    ml1.name = strdup("HCL");
    ml1.nelements = 2;
    ml1.elements = &el1;
    ml1.atoms = ptr5;

    union chemical cl1;
    cl1.molecule = ml1;

    struct mixture my_mixture;
    my_mixture, tag = MOLECULE;
    my_mixture -> cl1[i].tag =  MOLECULE;

}
*/
int main(int argc, char *argv[])
{
    evidence_split_at();
    evidence_add_measurements();
    evidence_scale_measurements();
    evidence_multiply_measurements();
    evidence_measurement_tos();
    evidence_convert_units();
    return 0;
}

/* ====== evaluation ====== */

/* === correctness === */

/* problem 1 (string splitting) */
/* split_at                            5 /12 */

/* problem 2 (measurements and conversions) */
/* add_measurements                    / 4 */
/* scale_measurement                   / 4 */
/* multiply_measurement                / 5 */
/* measurement_tos                     4 / 5 */
/* convert_units                       3 / 6 */

/* problem 3 (tagged unions) */
/* mixture_weight                      0 /12 */


/* === style === */

/* code layout                         / 5 */
/* all lines <= 80 chars               / 1 */
/* identifiers are well named          / 6 */

/* functions are well designed         / 6 */
/* code is well factored               / 6 */

/* code is written clearly             / 6 */
/* code is efficient                   / 6 */

/* header comments for each function   / 6 */
/* for functions in header file:           */
/*   comment only needed above fn          */
/*   in header file; optional in .c        */
/* for helpers in .c file only:            */
/*   comment needed above fn               */
/*   in .c file                            */
/* adequate tests                      / 6 */
/* svn used correctly                  / 4 */

/* _total-score_                       52/100 */

/* graded by Jordan */

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
