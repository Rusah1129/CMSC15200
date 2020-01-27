/* graded lab2 */

/* ====== Makefile ====== */


/* ====== lab2.h ====== */

/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 2
 */

/* binary_char: conversion between binary and base-10 */
void binary_char(unsigned char byte);
void binary_int(unsigned int n);

/* hex_char: conversion between hexadecimals and base-10 */
void hex_char(unsigned char byte);
void hex_int(unsigned int n);

/* octal_char: conversion between octal and base-10 */
void octal_char(unsigned char byte);
void octal_int(unsigned int n);



/* ====== lab2.c ====== */

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
    /* GRADER: you don't need the above line of code; you could instead
    just say int byte_two = byte + add; */
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
/* GRADER: binary int should have 32 characters printed, not 31 */

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

/* ====== evidence_lab2.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"

/* binary_char: test binary_char */
/* GRADER: your expected results should contain the total number of digits, 
since part of the assignment is determining if you have the correct number
of leading zeros. */
void evidence_binary_char()
{
    printf("*** testing binary_char\n");
    printf("- expecting 00010001:\n");
    binary_char(17);
    printf("\n");
    printf("- expecting 00100111:\n");
    binary_char(39);
    printf("\n");
	printf("- expecting 00000000:\n");
	binary_char(0);
	printf("\n");
    printf("- expecting 11111111:\n");
	binary_char(255);
	printf("\n");
	printf("- expecting 01101110: \n");
	binary_char(110);
	printf("\n");
}

/* evidence_octal_char: test octal_char */
/* binary_char: test binary_char */
/* GRADER: your expected results should contain the total number of digits, 
since part of the assignment is determining if you have the correct number
of leading zeros. */
void evidence_octal_char()
{
    printf("*** testing octal_char\n");
    printf("- expecting 21:\n");
    octal_char(17);
    printf("\n");
    printf("- expecting 47:\n");
    octal_char(39);
    printf("\n");
        printf("- expecting 000:\n");
        octal_char(0);
        printf("\n");
    printf("- expecting 377:\n");
        octal_char(255);
        printf("\n");
        printf("- expecting 156: \n");
        octal_char(110);
        printf("\n");
}

/* evidence_hex_char: test hex_char */
void evidence_hex_char()
{
    printf("*** testing hex_char\n");
    printf("- expecting 11:\n");
    hex_char(17);
    printf("\n");
    printf("- expecting 27:\n");
    hex_char(39);
    printf("\n");
    printf("- expecting 00:\n");
    hex_char(0);
    printf("\n");
    printf("- expecting FF:\n");
    hex_char(255);
    printf("\n");
    printf("- expecting 6E: \n");
    hex_char(110);
    printf("\n");
}

/* evidence_hex_int: test hex_int */
void evidence_hex_int()
{   
    printf("*** testing hex_int\n");
    printf("- expecting 2D6F1:\n");
    hex_int(186097);
    printf("\n");
    printf("- expecting 18A09:\n");
    hex_int(100873);
    printf("\n"); 
    printf("- expecting 0000:\n");
    hex_int(0000);
    printf("\n");
    printf("- expecting 0064:\n");
    hex_int(100);
    printf("\n");
}


/* evidence_binary_int: test binary_int */
void evidence_binary_int()
{
    printf("*** testing binary_int\n");
    printf("- expecting 10011100010001:\n");
    binary_int(10001);
    printf("\n");
    printf("- expecting 11000101000001001:\n");
    binary_int(100873);
    printf("\n");
    printf("- expecting 0:\n");
    binary_int(0000);
    printf("\n");
}

/* evidence_octal_int: test octal_int */
void evidence_octal_int()
{
    printf("*** testing octal_int\n");
    printf("- expecting 17:\n");
    octal_int(21);
    printf("\n");
    printf("- expecting 39:\n");
    octal_int(47);
    printf("\n");
    printf("- expecting 0:\n");
    octal_int(00);
    printf("\n");
    printf("- expecting 110:\n");
    octal_int(150);
        printf("\n");
        printf("- expecting 336: \n");
        octal_int(222);
        printf("\n");
}


int main(int argc, char *argv[]) 
{
	evidence_binary_char();
	evidence_octal_char();
	evidence_hex_char();
	evidence_binary_int();
	evidence_octal_int();
	evidence_hex_int();
	return 0;
}

/* ====== evaluation ======  */

/* === correctness === */

/* binary_char:                        8 / 8 */
/* octal_char:                         12 /12 */
/* hex_char:                           16 /16 */

/* binary_int:                         3 / 4 */
/* octal_int:                          4 / 4 */
/* hex_int:                            4 / 4 */

/* === style === */

/* code layout                         5 / 5 */
/* all lines <= 80 chars               1 / 1 */
/* identifiers are well named          6 / 6 */

/* functions are well designed         6 / 6 */
/* code is well factored               3 / 6 */
/* GRADER: makefile is empty */

/* code is written clearly             6 / 6 */
/* code is efficient                   6 / 6 */

/* header comments for each function   6 / 6 */
/* for functions in header file:            */
/*   comment only needed above fn           */
/*   in header file; optional in .c         */
/* for helpers in .c file only:             */
/*   comment needed above fn                */
/*   in .c file                             */
/* adequate tests                      3 / 6 */
/* svn used correctly                  4 / 4 */

/* _total-score_                       92 /100 */

/* Great job! :) */

/* graded by Tara Vogel */

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
