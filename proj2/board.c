/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * PROJ 2
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "logic.h"

board* board_new(unsigned int width, unsigned int height, enum type type)
{
    if (width <= 0 || height <= 0) {
                fprintf(stderr, "width and height must be positive");
                exit(1);
            }
    unsigned i, j, size;
    struct board *board1 = (board*) malloc (sizeof(board));
    board1 -> width = width;
    board1 -> height = height;
    board1 -> type = type;
    union board_rep set;
    switch (type) { 
        case BITS:
            size = (height * width * 2);
            if (size % 32 == 0) {
                size = size / 32;
            } else {
                size = (size / 32) + 1;
            }
            unsigned int *new_array = (unsigned int*) malloc (sizeof(unsigned
                int) * size);
            for (j = 0; j < size; j++) {
                new_array[j] = 0;
            }
            board1 -> u.bits = new_array;
            return board1;
        case MATRIX:   
            set.matrix = (cell**) malloc (sizeof(cell*) * height);
            for (i = 0; i < height; i++) {
                set.matrix[i] = (cell*) malloc (sizeof(cell) * width);
                for (j = 0; j < width; j++) {
                    set.matrix[i][j] = EMPTY;
                    }   
            }
            board1 -> u.matrix = set.matrix;
            return board1;
        }
}

void board_free(board* b)
{
    unsigned int i, length, size;
    switch (b -> type) {
        case BITS:
            length = b -> height * b -> width * 2;
            size = length;
            if (size % 32 == 0) {
                size = size / 32;
            } else {
                size = (size / 32) + 1;
            }
            free(b -> u.bits);
            free(b);
            break;
        case MATRIX:
            for (i = 0; i < b -> height; i++) {
                free(b -> u.matrix[i]);
            }
            free(b);
            break;
    }
}

/* helper to print row numbers. */
void print_vertical(unsigned int k) {

    char alphabet[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
        'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        printf("\n");
        if (k < 10) {
            printf("%d ", k);
        } else if (10 <= k && k < 36) {
            printf("%c ", alphabet[k - 10]);
        } else if (36 <= k && k < 62) { 
            printf("%c ", alphabet[k - 10]);
        } else if (k >= 62) {
            printf("? ");
        } 
} 

/* helper to print column numbers. */
void print_horizontal(unsigned int k) {

    char alphabet[52] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
        'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
        'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        if (k < 10) {
            printf("%d", k);
        } else if (10 <= k && k < 36) {
            printf("%c", alphabet[k - 10]);
        } else if (36 <= k && k < 62) {
            printf("%c", alphabet[k - 10]);
        } else if (k >= 62) {
            printf("? ");
        }
}

/* show the board "bit by bit" */
unsigned int bit_reading(unsigned int new_byte) {

    if ((new_byte & 3) == 0) {
        printf(".");
        new_byte >>= 2;
    } else if ((new_byte & 3) == 1) {
        printf("*");
        new_byte >>= 2;
    } else if ((new_byte & 3) == 2) {
        printf("o");
        new_byte >>= 2;
    }
    return new_byte;
}

/* helper to implement board_show for bit representation starting from
    col 0 */
void bit_show(board *b, unsigned int length, unsigned int size) {

    unsigned int new_byte, i = 0;
    unsigned int k = 0;
    int j;
    for (j = 0; j < size; j++) {
        new_byte = b -> u.bits[j];
        while ((j == size - 1) && (i < length)) {
            if (i % (b -> width * 2) == 0) {
                print_vertical(k);
                k++;
            } 
            new_byte = bit_reading(new_byte);
            i = i + 2;
            } while ((j != (size - 1)) && (i < (32 * (j + 1)))) {
                if (i % (b -> width * 2) == 0) {
                    print_vertical(k);
                    k++;
                }
                new_byte = bit_reading(new_byte);
                i = i + 2;
            }   
        }
    printf("\n");
}

void board_show(board* b) {
    unsigned int j, length, size;
    unsigned int i = 0;
    switch (b -> type) 
    {
        case BITS:
            length = b -> height * b -> width * 2;
            size = length;
            if (size % 32 == 0) {
                size = size / 32;
            } else {
                size = (size / 32) + 1;
            }
            for (j = 0; j < b -> width; j++) {
                if (j == 0) {
                    printf("  ");
                }
                print_horizontal(j);
            }
            bit_show(b, length, size);
            break;
        case MATRIX:
            for (i = 0; i <= b -> height; i++) {
                if (i == 0) {
                    for (j = 0; j < b -> width; j++) {
                        if (j == 0) {
                            printf("  ");
                        }
                        print_horizontal(j);
                    }
                } else {
                    int k = i - 1;
                    print_vertical(k);
                    for (j = 0; j < b -> width; j++) {
                        struct pos pos = make_pos(i - 1, j);
                        if (board_get(b, pos) == EMPTY) {
                            printf(".");
                        } else if (board_get(b, pos) == BLACK) {
                            printf("*");
                        } else if (board_get(b, pos) == WHITE) {
                            printf("o");
                        }
                    }
                }
            }
            printf("\n");
            break;
        }
}

/* helper to implement board_get for bit representation. */
cell get_helper(board* b, pos p) {

    unsigned int int_in_array, size, new_byte;
    unsigned int w = b -> width;
    size = b -> height * w * 2;
    unsigned int pos_in_board = ((((w * p.r) + (p.c)) * 2) % 32);
    int_in_array = (((w * p.r) + (p.c)) * 2) / 32;
    new_byte = b -> u.bits[int_in_array];
    new_byte >>= pos_in_board;
    if ((new_byte & 3) == 0) {
        return EMPTY;
    } else if ((new_byte & 3) == 1) {
        return BLACK;
    } else if ((new_byte & 3) == 2) {
        return WHITE;
    }
}

cell board_get(board* b, pos p) {


    switch(b -> type) 
    {
        case BITS:
            return get_helper(b, p);
        case MATRIX:
            return  b -> u.matrix[p.r][p.c];
    }
}

/* helper to implement board_set for bit representation. */
void set_helper(board* b, pos p, cell c) {

    unsigned int int_in_array, size;
    unsigned int w = b -> width;
    size = b -> height * w * 2;
    unsigned int pos_in_board = ((((w * p.r) + (p.c)) * 2) % 32);
    int_in_array = (((w * p.r) + (p.c)) * 2) / 32;
    unsigned int new_int;
    if (c == BLACK) {
        new_int = 1;
        new_int <<=  pos_in_board;
        b -> u.bits[int_in_array] = ((b -> u.bits[int_in_array]) | new_int);
    } else if (c == WHITE) {
        new_int = 2;
        new_int <<= pos_in_board;
        b -> u.bits[int_in_array] = (b -> u.bits[int_in_array]) | new_int;
    }
}

void board_set(board* b, pos p, cell c) {

    switch(b -> type)
    {
        case BITS:
            set_helper(b, p, c);
            break;
        case MATRIX:
            b -> u.matrix[p.r][p.c] = c;
            break;
    }
}

