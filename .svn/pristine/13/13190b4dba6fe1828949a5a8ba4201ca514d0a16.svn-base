#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst *bst_singleton(vcard *c)
{
    bst *res = (bst*) malloc(sizeof(bst));
    res -> c = c;
    res -> lsub = res -> rsub = NULL;
    return res;
}

int bst_insert(bst *t, vcard *c)
{
    if (t == NULL) {
        fprintf(stderr, "Empty bst.");
        exit(1);
    } else if (strcmp(t -> c -> cnet, c -> cnet) > 0) {
        if (t -> lsub == NULL) {
            t -> lsub = bst_singleton(c);
            return 1;
        } else {
            return bst_insert(t -> lsub, c);
        }
    } else if (strcmp(t -> c -> cnet, c -> cnet) < 0) {
        if (t -> rsub == NULL) {
            t -> rsub = bst_singleton(c);
            return 1;
        } else {
            return bst_insert(t -> rsub, c);
        }
    } else {
        return 0;
    }
}

unsigned int bst_num_entries(bst *t)
{
    if (t == NULL) {
        return 0;
    } else { 
        return 1 + bst_num_entries(t -> lsub) + bst_num_entries(t -> rsub);
    }
}

unsigned int bst_height(bst *t)
{
    unsigned int counter1 = 0;
    unsigned int counter2 = 0;
    if (t -> lsub) {
        counter1 = bst_height(t -> lsub);
    } else if (t -> rsub) {
        counter2 = bst_height(t -> rsub);
    } 
    if (counter1 > counter2) {
        return counter1 + 1;
    } else {
        return counter2 + 1;
    }
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
    n_comparisons++;
    if (t) {
        if (t -> c -> cnet == cnet) {
                return t -> c;
            } else {
                vcard *found = bst_search(t -> lsub, cnet, n_comparisons);
                if (t -> lsub == NULL) {
                    bst_search(t -> rsub, cnet, n_comparisons);
                    }
                    return found;
                }
    } else {
        return NULL;
    } 
}

/* note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
unsigned int bst_c(FILE *f, bst *t, char c)
{   
    unsigned int num_cs = 0;
    if (t) {
        if (t -> lsub && strcmp(&t -> c -> cnet[0], &c) > 0) {
            bst_c(f, t -> lsub, c);
        } else if (t -> c -> cnet[0] == c) {
            fprintf(f, "%c \n", c);
            num_cs++;
        } else if (t -> rsub && strcmp(&t -> c -> cnet[0], &c) < 0) {
            bst_c(f, t -> rsub, c);
        }
    } return num_cs;
}

void bst_free(bst *t)
{
    if (t) {
        bst_free(t -> lsub);
        bst_free(t -> rsub);
        free(t);
    }
}
