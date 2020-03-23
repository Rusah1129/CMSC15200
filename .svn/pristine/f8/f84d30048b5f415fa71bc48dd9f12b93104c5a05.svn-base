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
