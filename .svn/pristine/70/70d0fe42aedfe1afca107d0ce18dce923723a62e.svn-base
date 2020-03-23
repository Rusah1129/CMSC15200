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

void evidence_split_at(char** s, char d) {
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
