/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 4
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hw4.h"

int intlist_nth(intlist* xs, unsigned int n) {

    if (xs == NULL) {
        fprintf(stderr, "list is not sufficiently long.");
        exit(1);        
    }

    while (xs != NULL && n != 0) {
        xs = xs -> next;
        --n;
        return intlist_nth(xs, n);
    }

    return xs -> val; 
}

void intlist_set(intlist* xs, unsigned int n, int val) {
     
    if (xs == NULL) {
        fprintf(stderr, "list is not sufficiently long.");
        exit(1);
    }
    
    if (xs != NULL && n != 0) {
        xs = xs -> next;
        --n;
        intlist_set(xs, n, val);
    }

    if (n == 0) {
        xs -> val = val;
    } 
}

intlist* intlist_append(intlist* xs, int val) {
    
    struct intlist *xs2 = xs;

    if (xs == NULL) {
        fprintf(stderr, "list is not sufficiently long.");
        exit(1);
    }

    while (xs -> next != NULL) {
        xs = xs -> next;
    }
    
    intlist *tail = (struct intlist*) malloc (sizeof(struct intlist));

    tail -> val = val;
    tail -> next = NULL;

    xs -> next = tail;

    return xs2;
}

intlist* intlist_prepend(intlist* xs, int val) {
    
    if (xs == NULL) {
        fprintf(stderr, "list is not sufficiently long.");
        exit(1);
    }

    intlist *head = (struct intlist*) malloc (sizeof(struct intlist));
    
    head -> val = val;
    head -> next = xs;

    return head;

}

void intlist_show(intlist* xs) {
   
    if (xs == NULL) {
        fprintf(stderr, "list is not sufficiently long.");
        exit(1);
    }
 
    while (xs -> next != NULL) {
        printf("%d ", xs -> val);
        xs = xs -> next;        
    }

    if (xs -> next == NULL) {
        printf("%d", xs -> val);
    }
}

void intlist_free(intlist* xs) {
    
    struct intlist *node = xs;

    while (xs) {
        node = xs;
        xs = xs -> next;
        free(node);
    }
}

intlist* add_digits(unsigned int base, intlist* ds1, intlist* ds2) {

    struct intlist *res = NULL;

    unsigned int remainder = 0;
    unsigned int addition = 0;

    if (ds1 == NULL && ds2 == NULL) {
        fprintf(stderr, "both numbers do not exist.");
        exit(1);
    }

    while (ds1 && ds2) {
        
        addition = ds1 -> val + ds2 -> val + remainder;
        remainder = 0;

        if (addition >= base) {
            addition = base - addition;
            remainder = 1;
        }

        ds1 = ds1 -> next;
        ds2 = ds2 -> next;
        if (res  == NULL) {
            res = (struct intlist*) malloc (sizeof(struct intlist));
            res -> val = addition;
            res -> next = NULL;
        } else {
            intlist_append(res, addition);
        }   
    }

    while (ds1 == NULL && ds2 != NULL) {
        addition = ds2 -> val + remainder;
        remainder = 0;

        while (addition >= base) {
            addition = addition % base;
            remainder = addition / base + remainder;
            intlist_append(res, addition);
        }
    
        ds2 = ds2 -> next;
        
        if (res  == NULL) {
            res = (struct intlist*) malloc (sizeof(struct intlist));
            res -> val = addition;
            res -> next = NULL;
        } else {
            intlist_append(res, addition);
        }
    }    

    while (ds2 == NULL && ds1 != NULL) {
        addition = ds1 -> val + remainder;
        remainder = 0;

        while (addition >= base) {
            remainder = addition % base;
            addition = addition / base;
            intlist_append(res, addition);
        }

        ds1 = ds1 -> next;
        
        if (res  == NULL) {
            res = (struct intlist*) malloc (sizeof(struct intlist));
            res -> val = addition;
            res -> next = NULL;
        } else {
            intlist_append(res, addition);
        }
    }
    
    return res;
}











