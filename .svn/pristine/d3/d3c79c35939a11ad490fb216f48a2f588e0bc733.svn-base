#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

void aux_one(int byte, int byte_two, int count) {
	count += 1;
	if (count == 9) {
		printf("");
	} else if (byte_two % 2 == 0) {
		aux_one(byte, byte_two / 2, count);
		printf("0"); 
    } else {
        aux_one(byte, byte_two / 2, count);
		printf("1");
    }
}

void aux_two(int byte, int byte_two, int count) {
	count += 1;
    if (count == 4) {
        printf("");
    } else if (byte_two % 8 != 0) {
        aux_two(byte, byte_two / 8, count);
		printf("%d", byte_two % 8);
    } else {
        aux_two(byte, byte_two / 8, count);
		printf("0");
    }
}

void aux_three(int byte, int byte_two, int count) {
    count += 1;
	if (count == 3) {
        printf("");
    } else if (byte_two % 16 != 0) {
        aux_three(byte, byte_two / 16, count);
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
        aux_two(byte, byte_two / 16, count);
		printf("0");
    }
}

void binary_char(unsigned char byte) {
	int add = 256;
	int add_byte = byte;
	int byte_two = add_byte + add;
	aux_one(byte_two, byte_two, 0);
}

void octal_char(unsigned char byte) {
	int add = 512;
	int add_byte = byte;
	int byte_two = add_byte + add;
	aux_two(byte, byte_two, 0);
}

void hex_char(unsigned char byte) {
    int add = 256;
    int add_byte = byte;
    int byte_two = add_byte + add;
    aux_three(byte, byte_two, 0);
}

void int_aux1(unsigned int n, int dec, int mult) {
	if (mult != 0) {
		mult = mult * 2;
	} else {
		mult = 1;
	}
	if (n == 0) {
		printf("%d", dec);
	} else if (n % 2 == 0) {
		int_aux1(n / 10, dec, mult);
	} else {
		dec = dec + mult;
		int_aux1(((n - 1) / 10), dec, mult);
	}
}

void int_aux2(unsigned int n, int dec, int mult) {
	if (mult != 0) {
		mult = mult * 8;
	} else {
		mult = 1;
	}
	if (n == 0) {
		printf("%d", dec);
	} else if (n % 8 == 0) {
		int_aux2(n / 10, dec, mult);
	} else {
		dec = dec + mult;
		int_aux2(((n / 10)), dec, mult);
	}
}

void int_aux3(unsigned int n, int dec, int mult) {
	if (mult != 0) {
        mult = mult * 16;
    } else {
        mult = 1;
    }
    if (n == 0) {
        printf("%d", dec);
    } else if (n % 8 == 0) {
        int_aux2(n / 10, dec, mult);
    } else {
        dec = dec + mult;
        int_aux2(((n / 10)), dec, mult);
    }
}

void binary_int(unsigned int n) {
	int add = 256;
    int add_byte = byte;
    int byte_two = add_byte + add;
    aux_one(byte_two, byte_two, 0);
}

void octal_int(unsigned int n) {
	int_aux2(n, 0, 0);
}

void hex_int(unsigned int n) {
	int_aux3(n, 0, 0);
}
