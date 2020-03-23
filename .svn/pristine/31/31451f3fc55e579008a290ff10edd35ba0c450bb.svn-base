evidence_hw2: hw2.h hw2.c evidence_hw2.c
	clang -o evidence_hw2 -Wall -lm hw2.c evidence_hw2.c  
/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 2
 */

/* all_positive : returns 1 if all elements of the array a with length alen 
are positive and 0 if not */
int all_positive(int a[], unsigned int alen);

/* exists_positive : returns 1 if at least one element of a given array a with
length alen is positive and 0 if not */
int exists_positive(int a[], unsigned int alen);

/* first_positive : returns the index number of the first positive number of 
a given array a with length alen. If no positive number, returns -1. */
int first_positive(int a[], unsigned int alen);

/* number_positives : returns the number of positive numbers in an array of 
length alen. */
unsigned int number_positives(int a[], unsigned int alen);

/* negate : changes the sign of every element in an array of length alen, 
except for 0. */
void negate(int a[], unsigned int alen);

/* partial_sums : returns a new array containing partial sums over the provided
array. */
int* partial_sums(int a[], unsigned int alen);

/* rotate_right : modifies a passed-in array so each element appears at one 
greater index value than before */
void rotate_right(int a[], unsigned int alen);

/* concat_strings : concatenates a list of strings into one larger string. */   
char* concat_strings(char** strings, unsigned int num_strings); 

/* rle_encode : uses run-length encoding to compress integer data. */
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen);

/* rle_decode : uses run-length decoding to expand integer data. */
int* rle_decode(int* in, unsigned int inlen, unsigned int* outlen);
/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 2
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw2.h"

int all_positive(int a[], unsigned int alen) {
    int counter = 0;
    while (counter < alen) {
        if (a[counter] <= 0) {
            return 0;
        }  
        counter++;
    } 
    return 1;
}

int exists_positive(int a[], unsigned int alen) {
    int counter = 0;
    while (counter < alen) {
        if (a[counter] > 0) {
            return 1;
        }  
        counter++;
    }
    return 0;
}

int first_positive(int a[], unsigned int alen) {
    int counter = 0;
    while (counter < alen) {
        if (a[counter] > 0) {
            return counter; 
        } 
        counter++;
    }
    return -1;
}

unsigned int number_positives(int a[], unsigned int alen) {
    int counter = 0;
    int pos_count = 0;
    while (counter < alen) {
        if (a[counter] > 0) {
            pos_count++;
        }
        counter++;
    }
    return pos_count;
}

void negate(int a[], unsigned int alen) {
    int counter = 0;
    while (counter < alen) {
        if (a[counter] != 0) {
            a[counter] = - a[counter];
        } else {
            a[counter] = 0;
        } 
        counter++;
    }
    counter = 0;
    while (counter < alen) {
        printf("%d ", a[counter]);
        counter++;
    } 
}

int helper_partial_sums(int a[], unsigned int alen) {
    int counter, sum;
    sum = 0;
    for (counter = 0; counter <= alen; ++counter) {
        sum += a[counter];
    }
    return sum;
}

int* partial_sums(int a[], unsigned int alen) {
    int *ptr = (int*) malloc ((alen + 1) * sizeof(int)); 
    int i = 0;
    if (ptr == NULL) {
        printf("Memory is NULL. \n");
        exit(1);
    } else {
        for (i = 0; i <= (alen); ++i) {
            if (i == 0) {
                ptr[i] = 0;
            } else {
                ptr[i] = helper_partial_sums(a, i - 1);
            }
        }
    }
    return ptr;
}

void rotate_right(int a[], unsigned int alen) {
    int* ptr = (int*) malloc (alen * sizeof(int));
    if (ptr == NULL) {
        printf("Memory is NULL. \n");
        exit(1);
    }
    int i = 0;
    int counter = 0;
    if (ptr == NULL) {
        printf("Memory is NULL. \n");
        exit(1);
    } else {
        for (i = 0; i < alen; ++i) {
            if (i == 0) {
                ptr[0] = a[alen - 1];
            } else {
                ptr[i] = a[i - 1];
            }
        }
    }
    for (counter = 0; counter < alen; counter++) {
        printf("%d ", ptr[counter]);        
    }
}

/* helper that finds the length of the output array of rle_encode */ 
int rle_length(int* in, unsigned int inlen, unsigned int outlen) {
    int num = 0;
    int length = 0;
    int counter = 0;
    for (counter = 0; counter <= inlen; counter++) {
        if (counter == 0) {
            num = in[counter];
        } else if (num != in[counter]) {
            num = in[counter];
            length++;
        }
    }
    return (length * 2);
}

int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen) {
    int length = rle_length(in, inlen, *outlen);
    int *ptr = (int*) malloc (length * sizeof(int));
    if (ptr == NULL) {
        printf("Memory is NULL. \n");
        exit(1);
    }
    int index = 0;
    int length2 = 0;
    int num_storage = 0;
    int counter = 0;
    for (counter = 0; counter <= inlen; counter++) {
        if (counter == 0) {
            num_storage = in[counter];
            length2++;
        } else if (num_storage == in[counter]) {
            length2++;
        } else {
            ptr[index] = length2;            
            ptr[index + 1] = num_storage;
            num_storage = in[counter];
            index = index + 2;
            length2 = 1;
        }
    }
    return ptr; 
} 

/* helper that finds the length of the output array in rle_decode */
int rle_length_two(int* in, unsigned int inlen, unsigned int outlen) {
    int length = 0;
    int counter = 0;
    if (length % 2 != 0) {
        printf("length of input array must be an even number \n");
        exit(1);
    }
    for (counter = 0; counter <= inlen; counter++) {
        if (counter % 2 == 0) {
            length = length + in[counter];
        }
    }
    return length;
}

int* rle_decode(int* in, unsigned int inlen, unsigned int* outlen) {
    int length = rle_length_two(in, inlen, *outlen);    
    int *ptr = (int*) malloc (length * sizeof(int));
    if (ptr == NULL) {
        printf("Memory is NULL. \n");
        exit(1);
    }
    int counter = 0;
    int counter2 = 0;
    int index = 0;
    for (counter = 0; counter < inlen; counter++) {
        if (counter % 2 == 0) {
            if (in[counter] <= 0) {
                printf("Cannot have non-positive counts. \n");
                exit(1);
            }
            for (counter2 = 0; counter2 < in[counter]; counter2++) {
                ptr[index] = in[counter + 1];
                index++;
            }    
        }
    } 
    return ptr;
}

char* concat_strings(char** strings, unsigned int num_strings) {
    int i = 0;
    int length = 0;
    for (i = 0; i < num_strings; i++) {
        length = length + strlen(strings[i]);
    }
    char *str = (char*) malloc ((length + (num_strings)) * sizeof(char));
    if (str == NULL) {
        printf("Memory is NULL. \n");
        exit(1);
    }
    i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < num_strings; i++) { 
        for (j = 0; j < strlen(strings[i]); j++) {
            if (j == 0 && i != 0) {
                str[k] = ' ';
                k++;
            }
            if (strings[i][j] != '\0') {
                str[k] = strings[i][j];
                k++;
            }
        }
    } str[k] = '\0';
    return str; 
} 
/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 2
 */

#include <stdlib.h>
#include <stdio.h>
#include "hw2.h"

/* evidence_all_positive: test all_positive */
void evidence_all_positive() {
    printf("*** testing all_positive\n");
    int new_array1[3] = {3, 0, 3};
    printf("- expecting 0: %d \n", all_positive(new_array1, 3));
    int new_array2[5] = {-3, 8, 9, 2, -6};
    printf("- expecting 0: %d \n", all_positive(new_array2, 5));
    int new_array3[2] = {1, 100};
    printf("- expecting 1: %d \n", all_positive(new_array3, 2));
    int new_array4[0] = {};
    printf("- expecting 1: %d \n", all_positive(new_array4, 0));
}

/* evidence_exists_positive: test exists_positive */
void evidence_exists_positive() {
    printf("*** testing exists_positive\n");
    int array1[3] = {-3, -3, 1};
    printf("- expecting 1: %d \n", exists_positive(array1, 3));
    int array2[7] = {-12, -100, 0, 0, 0, -3, -478};
    printf("- expecting 0: %d \n", exists_positive(array2, 7));
    int array3[5] = {6, 8, 0, -5, 100};
    printf("- expecting 1: %d \n", exists_positive(array3, 5));  
    int new_array4[0] = {};
    printf("- expecting 0: %d \n", exists_positive(new_array4, 0));
}

/* evidence_first_positive: test first_positive */
void evidence_first_positive() {
    printf("*** testing first_positive\n");
    int array1[3] = {-3, -3, 1};
    printf("- expecting 2: %d \n", first_positive(array1, 3));
    int array2[7] = {-12, -100, 0, 0, 0, -3, -478};
    printf("- expecting -1: %d \n", first_positive(array2, 7));
    int array3[5] = {6, 8, 0, -5, 100};
    printf("- expecting 0: %d \n", first_positive(array3, 5));
}

/* evidence_number_positives: test number_positives */
void evidence_number_positives() {
    printf("*** testing number_positives\n");
    int array1[5] = {0, -8, 5, 3, 9};
    printf("- expecting 3: %d \n", number_positives(array1, 5));
    int array2[4] = {-53, -12, 0};
    printf("- expecting 0: %d \n", number_positives(array2, 3));
    int array3[4] = {3, 3, 3, 4};
    printf("- expecting 4: %d \n", number_positives(array3, 4));
}

/* evidence_negate: test negate */
void evidence_negate() {
    printf("*** testing negate\n");
    int array1[5] = {-5, -8, 10, 16, 0};
    printf("- expecting 5, 8, -10, -16, 0: \n");
    negate(array1, 5);
    printf("\n");
    int array2[5] = {3, 6, 12, 9, 27};
    printf("- expecting -3 -6 -12 -9 -27: \n");
    negate(array2, 5);
    printf("\n");
    int array3[3] = {0, 0, 0};
    printf("- expecting 0 0 0: \n");
    negate(array3, 3);
    printf("\n");
    int array4[4] = {-9, -56, -3};
    printf("- expecting 9 56 3: \n");
    negate(array4, 3);
    printf("\n");
}

/* helper_one : prints results of returned int array */
void helper_one(int a[], unsigned int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
}

/* helper_two : prints results of returned char array */
void helper_two(char a[], unsigned int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%c", a[i]);
    }
}

/* evidence_partial_sums : test partial_sums */
void evidence_partial_sums() {
    printf("*** testing partial_sums \n");
    
    int array1[7] = {-12, -100, 0, 0, 0, -3, -478};
    int *new_array1 = partial_sums(array1, 7);
    printf("- expecting 0 -12 -112 -112 -112 -112 -115 -593: \n");
    helper_one(new_array1, 8);
    printf("\n");

    int array2[5] = {-5, -8, 10, 16, 0};
    int *new_array2 = partial_sums(array2, 5);
    printf("- expecting 0 -5 -13 -3 13 13: \n");
    helper_one(new_array2, 6);
    printf("\n");

    int array3[3] = {0, 0, 0};
    int *new_array3 = partial_sums(array3, 3);
    printf("- expecting 0 0 0 0: \n");
    helper_one(new_array3, 4);
    printf("\n");

    int array4[0] = {};
    int *new_array4 = partial_sums(array4, 0);
    printf("- expecting : \n");
    helper_one(new_array4, 0);
    printf("\n");
}

/* evidence_rotate_right : test rotate_right */
void evidence_rotate_right() {
    printf("*** testing rotate_right\n");
    int array1[5] = {-5, -8, 10, 16, 0};
    printf("- expecting 0 -5 -8 10 16: \n");
    rotate_right(array1, 5);
    printf("\n");
    int array2[5] = {-3, 8, 9, 2, -6};
    printf("- expecting -6 -3 8 9 2: \n");
    rotate_right(array2, 5);
    printf("\n");
    int array3[7] = {-19, 15, 2, -8, 0, 4, -4};
    printf("- expecting -4 -19 15 2 -8 0 4: \n");
    rotate_right(array3, 7);
    printf("\n");
}

/* evidence_rle_encode : test rle_encode */
void evidence_rle_encode() {
    printf("*** testing rle_encode \n");
    unsigned int outlen = 0;

    int array1[7] = {1, 3, 3, 6, 5, 5, 9};
    int *new_array1 = rle_encode(array1, 7, &outlen);
    printf("- expecting 1 1 2 3 1 6 2 5 1 9 \n");
    helper_one(new_array1, 10);
    printf("\n");

    int array2[5] = {0, 0, 0, 0, 0};
    int *new_array2 = rle_encode(array2, 5, &outlen);
    printf("- expecting 5 0: \n");
    helper_one(new_array2, 2);
    printf("\n");

    int array3[3] = {8, 9};
    int *new_array3 = rle_encode(array3, 3, &outlen);
    printf("- expecting 1 8 1 9: \n");
    helper_one(new_array3, 4);
    printf("\n");

    int array4[0] = {};
    int *new_array4 = rle_encode(array4, 0, &outlen);
    printf("- expecting : \n");
    helper_one(new_array4, 0);
    printf("\n");

    free(new_array1);
    free(new_array2);
    free(new_array3);
    free(new_array4);
}

/* evidence_rle_decode : testing rle_decode */
void evidence_rle_decode() {
    printf("*** testing rle_decode \n");
    unsigned int outlen = 0;

    int array1[10] = {1, 1, 2, 3, 1, 6, 2, 5, 1, 9};
    int *new_array1 = rle_decode(array1, 10, &outlen);
    printf("- expecting 1 3 3 6 5 5 9 \n");
    helper_one(new_array1, 7);
    printf("\n");

    int array2[2] = {5, 0};
    int *new_array2 = rle_decode(array2, 2, &outlen);
    printf("- expecting 0 0 0 0 0: \n");
    helper_one(new_array2, 5);
    printf("\n");

    int array3[4] = {1, 8, 1, 9};
    int *new_array3 = rle_decode(array3, 4, &outlen);
    printf("- expecting 8 9: \n");
    helper_one(new_array3, 2);
    printf("\n");

    int array4[0] = {};
    int *new_array4 = rle_decode(array4, 0, &outlen);
    printf("- expecting : \n");
    helper_one(new_array4, 0);
    printf("\n");

    free(new_array1);
    free(new_array2);
    free(new_array3);
    free(new_array4);
}

/* evidence_concat_strings: test concat_strings */ 
void evidence_concat_strings() {
    printf("*** testing concat_strings\n");

    char *array1[3] = {"Hello", "World", "!"};
    char *new_array1 = concat_strings(array1, 3);
    printf("- expecting Hello World ! \n");
    helper_two(new_array1, 13);
    printf("\n");

    char *array2[6] = {"Am", "I", "doing", "this", "right", "?"};
    char *new_array2 = concat_strings(array2, 6);
    printf("- expecting Am I doing this right ? \n");
    helper_two(new_array2, 23);
    printf("\n");

    char *array3[4] = {"Pompeii", "is", "interesting", "."};
    char *new_array3 = concat_strings(array3, 4);
    printf("- expecting Pompeii is interesting . \n");
    helper_two(new_array3, 24);
    printf("\n");

    free(new_array1);
    free(new_array2);
    free(new_array3);
}

/* main: run the evidence functions above */
int main(int argc, char *argv[]) {
    evidence_all_positive();
    evidence_exists_positive();
    evidence_first_positive();
    evidence_number_positives();
    evidence_negate();
    evidence_partial_sums();
    evidence_rotate_right();
    evidence_rle_encode();
    evidence_rle_decode();
    evidence_concat_strings();
    return 0;
}
/* ====== evaluation ====== */

/* === correctness === */

/* problem 1 (arrays) */
/* all_positive                        2 / 2 */
/* exists_positive                     2 / 2 */
/* first_positive                      2 / 2 */
/* number_positive                     2 / 2 */
/* negate                              2 / 2 */
/* partial_sums                        3 / 3 */
/* rotate_right                        2 / 4 */ // Fails grading tests

/* problem 2 (run length encoding) */
/* rle_encode                          8  / 10 */ // Need to set outlen
/* rle_decode                          10 / 12 */ // Need to set outlen

/* problem 3 (concat_strings)          9/ 9 */


/* === style === */

/* code layout                         5 / 5 */
/* all lines <= 80 chars               1 / 1 */
/* identifiers are well named          6 / 6 */

/* functions are well designed         6 / 6 */
/* code is well factored               6 / 6 */

/* code is written clearly             6 / 6 */
/* code is efficient                   6 / 6 */

/* header comments for each function   6 / 6 */
/* for functions in header file:           */
/*   comment only needed above fn          */
/*   in header file; optional in .c        */
/* for helpers in .c file only:            */
/*   comment needed above fn               */
/*   in .c file                            */
/* adequate tests                      6 / 6 */
/* svn used correctly                  4 / 4 */

/* _total-score_                       88/100 */

/* graded by Jackson Quinn */

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
