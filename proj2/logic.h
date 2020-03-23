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

/* new_game: creates a new game with run, width, height, and type (bit/matrix)
    values */
game* new_game(unsigned int run, unsigned int width, unsigned int height,
               enum type type);

/* game_free: frees a created game. */
void game_free(game* g);

/* drop_piece: drops piece when player specifies column. */
int drop_piece(game* g, unsigned int col);

/* twist: twists and readjusts board if specified. */
void twist(game* g, direction d);

/* game_outcome: shows the outcome of a game; DRAW, BLACK_WIN, WHITE_WIN, or
    IN_PROGRESS */
outcome game_outcome(game* g);

#endif /* LOGIC_H */
