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

char* measurement_tos(struct measurement m) {
    char result[100];
    sprintf(result, "%f %s^%d\n", m.value, m.units, m.exponent);   
    char* res = strdup(result);
    return res;
}


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
