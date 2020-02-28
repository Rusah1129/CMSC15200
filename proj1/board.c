/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * PROJ 1
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "board.h"

board* board_new(unsigned int width, unsigned int height, enum type type) 
{
    unsigned i, j;
    struct board *board1 = (board*) malloc (sizeof(board*));
    board1 -> width = width;
    board1 -> height = height;
    board1 -> type = type;
    union board_rep set;
    set.matrix = (cell**) malloc (sizeof(cell*) * width);
    for (i = 0; i < height; i++) {
        set.matrix[i] = (cell*) malloc (sizeof(cell) * height);
        for (j = 0; j < width; j++) {
            set.matrix[i][j] = EMPTY;
            }
    }
    board1 -> u = set;
    return board1;

}

void board_free(board* b) 
{
    unsigned i;
    for (i = 0; i < b -> height; i++) {
            free(b -> u.matrix[i]);
    }  
    free(b);
}

void board_show(board* b) {
    unsigned i, j;
    for (i = 0; i <= b -> width; i++) {
        for (j = 0; j <= b -> height; j++) {
            if (i == 0) {
                printf("%d ", j);
            } else if (j == 0) {
                printf("%d  ", i);
            } else {
            }
            printf("\n");
           //set cases; if empty, print one thing, if not, print another            
        }
    }
}

cell board_get(board* b, pos p) {
    return b -> u.matrix[p.r][p.c];
}

void board_set(board* b, pos p, cell c) {
    b -> u.matrix[p.r][p.c] = c;    
}

