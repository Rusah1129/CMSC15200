/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 2
 */

#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

/* aux_one : first helper function to print result from decimal to binaries */
void aux_one(int byte, int byte_two, int count, int bits) {
	count += 1;
	if (count == bits) {
		printf("");
	} else if (byte_two % 2 == 0) {
		aux_one(byte, byte_two / 2, count, bits);
		printf("0"); 
    } else {
        aux_one(byte, byte_two / 2, count, bits);
		printf("1");
    }
}

/* aux_two : second helper function to print result from decimal to octals */
void aux_two(int byte, int byte_two, int count, int bits) {
	count += 1;
    if (count == bits) {
        printf("");
    } else if (byte_two % 8 != 0) {
        aux_two(byte, byte_two / 8, count, bits);
		printf("%d", byte_two % 8);
    } else {
        aux_two(byte, byte_two / 8, count, bits);
		printf("0");
    }
}

/* aux_three : third helper function to print result from decimal to hexadecimals */
void aux_three(int byte, int byte_two, int count, int bits) {
	count += 1;
	if (count == bits) {
        printf("");
    } else if (byte_two % 16 != 0) {
        aux_three(byte, byte_two / 16, count, bits);
		int remain = (byte_two % 16);
		if (remain == 10) {
			printf("A");
		} else if (remain == 11) {
			printf("B");
		} else if (remain == 12) {
			printf("C");
		} else if (remain == 13) {
			printf("D");
		} else if (remain == 14) {
			printf("E");
		} else if (remain == 15) {
			printf("F");
		} else {
			printf("%d", remain);
        } 
    } else {
        aux_two(byte, byte_two / 16, count, bits);
		printf("0");
    }
}

/* binary_char: main function for translating unsigned char to binary */
void binary_char(unsigned char byte) {
	int add = 256;
	int add_byte = byte;
	int byte_two = add_byte + add;
	aux_one(byte_two, byte_two, 0, 9);
}

/* octal_char: main function for translating unsigned char to octal */
void octal_char(unsigned char byte) {
	int add = 512;
	int add_byte = byte;
	int byte_two = add_byte + add;
	aux_two(byte, byte_two, 0, 4);
}

/* hex_char: main function for translating unsigned char to binary */
void hex_char(unsigned char byte) {
    int add = 256;
    int add_byte = byte;
    int byte_two = add_byte + add;
    aux_three(byte, byte_two, 0, 3);
}

/* binary_int: main function for translating unsigned int to binary */
void binary_int(unsigned int n) {
	long int add = 34359738368;
    int byte_two = n + add;
    aux_one(byte_two, byte_two, 0, 32);
}

/* octal_int: main function for translating unsigned char to octal*/
void octal_int(unsigned int n) {
	long int add = 8589934592;
    long int byte_two = n + add;
    aux_two(n, byte_two, 0, 12);
}

/* hex_int: main function for translating unsigned char to hex */
void hex_int(unsigned int n) {
	long int add = 4294967296;
    int byte_two = n + add;
    aux_three(byte_two, byte_two, 0, 9);
}
