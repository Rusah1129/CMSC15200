/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * PROJ 1
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "board.h"
#include "pos.h"

/*
void evidence_board_new() {
    
    struct board* board1 = board_new(3, 4, MATRIX);
}
*/
void evidence_board_show() {
    struct board* board1 = board_new(3, 4, MATRIX);
    board_show(board1);
}

int main(int argc, char *argv[]) 
{
//    evidence_board_new();
    evidence_board_show();
    return 0;
}
