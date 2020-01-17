#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

int aux_one(unsigned char byte, unsigned char length, unsigned char
	binary_byte) {
	 if (byte == 0) { 
		return binary_byte;
	} else if (byte % 2 == 0) {
        return aux_one(byte / 2, length, 0); 
    } else {
        return aux_one(byte / 2, length, 1);
    }
}

void binary_char(unsigned char byte) {
	printf("%d", aux_one(17, 0, 1));

}
