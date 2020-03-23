#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab2.h"

void aux_one(int byte, int byte_two, char *binary[], int count) {
	count += 1;
	if (count == 8) {
		printf("%s", *binary);
	} else if (byte_two % 2 == 0) {
		char *digit0 = "0";
		binary[count] = digit0;
		aux_one(byte, byte_two / 2, binary, count); 
    } else {
		char *digit1 = "1";
		binary[count] = digit1;
        aux_one(byte, byte_two / 2, binary, count);
    }
}

void aux_two(int byte, int byte_two) {
    if (byte_two == 0) {
        printf("");
    } else if (byte_two % 8 != 0) {
		int remain = (byte_two % 8);
		printf("%d", remain);
        aux_two(byte, byte_two / 8);
    } else {
        printf("0");
        aux_two(byte, byte_two / 8);
    }
}

void aux_three(int byte, int byte_two) {
    if (byte_two == 0) {
        printf("");
    } else if (byte_two % 16 != 0) {
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
		aux_two(byte, byte_two / 16);
    } else {
        printf("0");
        aux_two(byte, byte_two / 16);
    }
}

void binary_char(unsigned char byte) {
	int add = 256;
	int add_byte = byte;
	int byte_two = add_byte + add;
	aux_one(byte_two, byte_two, 00000000, 0);
}

void octal_char(unsigned char byte) {
	int add = 511;
	int add_byte = byte;
	int byte_two = add_byte + add;
	aux_two(byte, byte_two);
}

void hex_char(unsigned char byte) {
    int add = 65535;
    int add_byte = byte;
    int byte_two = add_byte + add;
    aux_three(byte, byte_two);
}

void int_aux1(unsigned int n, int dec, int mult) {
    if (n == 0) {
		printf("%d", dec);
	} else if (n % 2 == 0) {
		mult *= 2;
		int_aux1(n, dec, mult);
	} else {
		n -= 1;
		mult *= 2;
		dec += mult;
		int_aux1(n, dec, mult);
	}
}

void binary_int(unsigned int n) {
	int_aux1(n, 0, 1);
}
