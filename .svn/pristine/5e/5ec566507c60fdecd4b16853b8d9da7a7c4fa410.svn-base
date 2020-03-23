#include <stdlib.h>
#include <stdio.h>
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

int rle_length_two(int* in, unsigned int inlen, unsigned int outlen) {
    int length = 0;
    int counter = 0;
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
    int counter = 0;
    int counter2 = 0;
    int index = 0;
    for (counter = 0; counter < inlen; counter++) {
        if (counter % 2 == 0) {
            for (counter2 = 0; counter2 < in[counter]; counter2++) {
                ptr[index] = in[counter + 1];
                index++;
            }    
        }
    } 
    return ptr;
}

/*
char* concat_strings(char** strings, unsigned int num_strings) {
    return 0;
}*/
