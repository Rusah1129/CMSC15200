#include <stdlib.h>
#include <stdio.h>
#include "final.h"

void rectangle(unsigned int w, unsigned int h) {
    unsigned int i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int is_prime(unsigned int n) {
    unsigned int i;
    for (i = 0; i < n; i++) {
        if (n % i != 0) {
            return (n % i != 0);
        } else {
            return (n % i != 0);
        }
    }
}

void print_primes(unsigned int n) {
    unsigned int i;
    for (i = 2; i < n; i++) {
        if (is_prime(i)) {
            printf("%d", i);
        }
        printf("\n");
    }
}

void replace(char* s, char from, char to) {
    unsigned int i = 0;
    while (s[i]) {
        if (s[i] == from) {
            s[i] = to;
        } i++;
    }
}

unsigned int length(char* s) {
    unsigned int 0;
    while (s[i]) {
        i++;
    }
    return i;
}

char* reverse (char* s) {
    unsigned int length = length(s);
    char* new_str = (char*) malloc (sizeof(char) * length);
    unsigned int i;
    for (i = 0; i < length; i++) {
        new_str[i] = s[length - i];
    } 
    return new_str;
}

unsigned int tlist_len(int* list) {
    unsigned int i = 0;
    while (list[i] != -1) {
        i++;
    }
    return i;
}

int* tlist_to_array(int* tlist, unsigned int* outlen) {
    outlen = tlist_len(tlist);
    unsigned int i;
    int* new_tlist = (int*) malloc (sizeof(int) * outlen);
    for (i = 0; i < outlen; i++) {
        new_tlist[i] = tlist[i];
    }
    return new_tlist;
}

int* array_to_tlist(int* a, unsigned int alen) {
    int* new = (int*) malloc (sizeof(int) * alen);
    int i;
    for (i = 0; i < alen; i++) {
        if (a[i] == -1) {
            fprintf(stderr, "-1 in list");
            exit(1);
        }
        new[i] = a[i];
    }
    new[alen] = -1;
}

int* dips(int* a, unsigned int alen, unsigned int* outlen) {
    unsigned int i;
    unsigned int j = 0;
    for (i = 0; i < alen; i++) {
        if (a[i] < a[i - 1]) {
            j++;
        }
        
    }
}

int match_index(char* s, char** strings, unsigned int nstrings);

char* diagonalize(char** strings, usigned int nstrings);

int main(int argc, char *argv[])
{
    return 0;
}
