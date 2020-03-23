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

/* evidence_partial_sums : test partial_sums */
void evidence_partial_sums() {
    printf("*** testing partial_sums \n");
    int i, j, k = 0;
    
    int array1[7] = {-12, -100, 0, 0, 0, -3, -478};
    int *new_array1 = partial_sums(array1, 7);
    printf("- expecting {0, -12, -112, -112, -112, -112, -115, -593}: \n");
    for (i = 0; i <= 7; i++) {
        printf("%d ", new_array1[i]);
    }
    printf("\n");

    int array2[5] = {-5, -8, 10, 16, 0};
    int *new_array2 = partial_sums(array2, 5);
    printf("- expecting {0, -5, -13, -3, 13, 13}: \n");
    for (j = 0; j <= 5; j++) {
        printf("%d ", new_array2[j]);
    }
    printf("\n");

    int array3[3] = {0, 0, 0};
    int *new_array3 = partial_sums(array3, 3);
    printf("- expecting {0, 0, 0, 0}: \n");
    for (k = 0; k <= 3; k++) {
        printf("%d ", new_array3[k]);
    }
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

/* helper_one : prints results of int array */
void helper_one(int a[], unsigned int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
}

/* helper_two : prints results of char array */
void helper_two(char a[], unsigned int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%c", a[i]);
    }
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
    free(new_array1);
    free(new_array2);
    free(new_array3);
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

    free(new_array1);
    free(new_array2);
    free(new_array3);
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
    printf("- expecting Pompeii is interesting .: \n");
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
