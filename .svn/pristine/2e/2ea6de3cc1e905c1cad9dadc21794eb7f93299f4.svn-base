/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * PROJ 1
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "logic.h"

game* new_game(unsigned int run, unsigned int width, unsigned int height,
    enum type type) 
{
    board* new_board = board_new(width, height, type);
    struct game *new_game = (game*) malloc (sizeof(game*));
    game -> run = run;
    game -> b = new_board;
    game -> turn = BLACK_NEXT;
}

void game_free(game* g) {
    board_free(game -> b);
    free(g);
}
/*
int drop_piece(game* g, unsigned int col) {
    
}*/
