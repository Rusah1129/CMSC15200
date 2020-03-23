#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"


enum turn {
    BLACK_NEXT,
    WHITE_NEXT
};

typedef enum turn turn;


enum outcome {
    BLACK_WIN,
    WHITE_WIN,
    DRAW,
    IN_PROGRESS
};

typedef enum outcome outcome;


enum direction {
    CW, CCW
};

typedef enum direction direction;


struct game {
    unsigned int run;
    board* b;
    turn next;
};

typedef struct game game;


game* new_game(unsigned int run, unsigned int width, unsigned int height,
               enum type type);

void game_free(game* g);

int drop_piece(game* g, unsigned int col);

void twist(game* g, direction d);

outcome game_outcome(game* g);

#endif /* LOGIC_H */
