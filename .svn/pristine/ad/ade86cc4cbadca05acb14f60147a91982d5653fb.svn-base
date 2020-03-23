#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"

/* evidence_expt: test expt */
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

void evidence_binary_int()
{   
    printf("*** testing binary_int\n");
    printf("- expecting 17:\n");
    binary_int(10001);
    printf("\n");
    printf("- expecting 39:\n");
    binary_int(100111);
    printf("\n"); 
        printf("- expecting 0:\n");
        binary_int(0000);
        printf("\n");
    printf("- expecting 255:\n");
        binary_int(11111111);
        printf("\n");
        printf("- expecting 110: \n");
        binary_int(11011110);
        printf("\n");
}

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
    printf("- expecting D2: \n");
    hex_char(110);
    printf("\n");
}


int main(int argc, char *argv[]) 
{
	evidence_binary_char();
	evidence_binary_int();
	evidence_octal_char();
	evidence_hex_char();
	return 0;
}
