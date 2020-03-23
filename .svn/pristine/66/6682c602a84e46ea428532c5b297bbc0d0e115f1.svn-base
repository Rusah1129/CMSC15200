#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"

/* binary_char: test binary_char */
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
