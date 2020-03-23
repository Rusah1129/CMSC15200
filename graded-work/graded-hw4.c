evidence_hw4: hw4.h hw4.c evidence_hw4.c
        clang -o evidence_hw4 -Wall -lm hw4.c evidence_hw4.c
/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 2
 */

typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

/* intlist_nth: returns the nth value in an intlist xs, using zero-based
indexing.  */
int intlist_nth(intlist* xs, unsigned int n);

/*  intlist_set: overwrites the value in the list at the nth index with the
new value val */
void intlist_set(intlist* xs, unsigned int n, int val);

/* intlist_append: appends val to the end of the linked list xs, 
returning the head of the resulting list. */
intlist* intlist_append(intlist* xs, int val);

/* intlist_prepend: prepends val to the beginning of the linked list xs, 
returning the head of the resulting list. */
intlist* intlist_prepend(intlist* xs, int val);

/* intlist_show: prints the content of the linked list xs to the screen. */
void intlist_show(intlist* xs);

/* intlist_free: reclaims, or frees, space allocated by linked list xs. */
void intlist_free(intlist* xs);

intlist* add_digits(unsigned int base, intlist* ds1, intlist* ds2);
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











/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 4
 */

#include <stdlib.h>
#include <stdio.h>
#include "hw4.h"

intlist* linked_lists(unsigned int linked_list_num) {

    struct intlist* one = NULL;
    struct intlist* two = NULL;
    struct intlist* three = NULL;
    struct intlist* four = NULL;
    struct intlist* five = NULL;
    struct intlist* six = NULL;
    struct intlist* seven = NULL;
    struct intlist* eight = NULL;
    
    one = (struct intlist*) malloc (sizeof(struct intlist));
    two = (struct intlist*) malloc (sizeof(struct intlist));
    three = (struct intlist*) malloc (sizeof(struct intlist));
    four = (struct intlist*) malloc (sizeof(struct intlist)); 
    five = (struct intlist*) malloc (sizeof(struct intlist));
    six = (struct intlist*) malloc (sizeof(struct intlist));
    seven = (struct intlist*) malloc (sizeof(struct intlist));
    eight = (struct intlist*) malloc (sizeof(struct intlist));

    struct intlist* head = one;

    if (linked_list_num == 1) {
        
        struct intlist* head = one;        

        one -> val = -2;
        one -> next = two;
    
        two -> val = 30;
        two -> next = three;

        three -> val = 16;
        three -> next = four;

        four -> val = 3;
        four -> next = NULL;

        return head;

    }

    if (linked_list_num == 2) {

        struct intlist* head = one;

        one -> val = 2; 
        one -> next = two;

        two -> val = 6;
        two -> next = three;
        
        three -> val = 1;
        three -> next = NULL;
    
        return head;
    }

    if (linked_list_num == 3) {
        
        struct intlist* head = four;

        four -> val = 3;
        four -> next = five;
        
        five -> val = 4;
        five -> next = NULL;
    
        return head;
    }   

    if (linked_list_num == 4) {
    
        struct intlist* head = one;

        one -> val = 3;
        one -> next = two;

        two -> val = 1;
        two -> next = three;

        three -> val = 3;
        three -> next = four;

        four -> val = 7;
        four -> next = five;

        five -> val = 6;
        five -> next = six;

        six -> val = 4;
        six -> next = seven;

        seven -> val = 2;
        seven -> next = eight;

        eight -> val = 1;
        eight -> next = NULL;
   
        return head; 
    } 

    if (linked_list_num == 5) {
        
        struct intlist* head = four;
        
        four -> val = 8;
        four -> next = five;

        five -> val = 0;
        five -> next = six;

        six -> val = 4;
        six -> next = NULL;

        return head;
    }

    return head;

}

void evidence_intlist_nth() {
    printf("*** testing intlist_nth \n");
    struct intlist* one = linked_lists(1);
    printf("- expecting 30: %d \n", intlist_nth(one, 1));
    intlist_free(one);

    struct intlist* two = linked_lists(4);
    printf("- expecting 6: %d \n", intlist_nth(two, 4));
    intlist_free(two); 

    struct intlist* three = linked_lists(2);
    printf("- expecting 2: %d \n", intlist_nth(three, 0));
    intlist_free(three);

    struct intlist* four = linked_lists(3);
    printf("- expecting 4: %d \n", intlist_nth(four, 1));
    intlist_free(four);
}

void evidence_intlist_show() {
    printf("*** testing intlist_show \n");
    printf("- expecting: -2 30 16 3 \n");  
    struct intlist* one = linked_lists(1);
    intlist_show(one);
    free(one);
    printf("\n")
;
    printf("- expecting 2 6 1: \n");
    struct intlist* two = linked_lists(2);
    intlist_show(two);
    free(two);
    printf("\n");
}

void evidence_intlist_set() {
    printf("*** testing intlist_set \n");
    printf("- expecting -2 30 16 45: \n");
    
    struct intlist* one = linked_lists(1);
    intlist_set(one, 3, 45);
    intlist_show(one);
    printf("\n");
    intlist_free(one);

    printf("- expecting 2 13 1: \n");
    struct intlist* two = linked_lists(2);
    intlist_set(two, 1, 13);
    intlist_show(two);
    printf("\n");
    intlist_free(two);

    printf("- expecting 87 4: \n");
    struct intlist* three = linked_lists(3);
    intlist_set(three, 0, 87);
    intlist_show(three);
    printf("\n");
    intlist_free(three);

    printf("- expecting 3 1 3 7 6 98 2 1: \n");
    struct intlist* four = linked_lists(4);
    intlist_set(four, 5, 98);
    intlist_show(four);
    printf("\n");
    intlist_free(four);

}

void evidence_intlist_append() {
    printf("*** testing intlist_append \n");
   
    printf("- expecting -2 30 16 3 3: \n");
    struct intlist* one = linked_lists(1);
    struct intlist* two = intlist_append(one, 3);
    intlist_show(two);
    printf("\n");
    intlist_free(two);

    printf("- expecting 2 6 1 9: \n");
    struct intlist* three = linked_lists(2);
    struct intlist* four = intlist_append(three, 9);
    intlist_show(four);
    printf("\n");
    intlist_free(four);

    printf("- expecting 3 4 12: \n");
    struct intlist* five = linked_lists(3);
    struct intlist* six = intlist_append(five, 12);
    intlist_show(six);
    printf("\n");
    intlist_free(six);

    printf("- expecting 9 1 3 7 6 4 2 1 5: \n");
    struct intlist* seven = linked_lists(4);
    intlist* eight = intlist_append(seven, 5);
    intlist_show(eight);
    printf("\n");
    intlist_free(eight);

}

void evidence_intlist_prepend() {
    printf("*** testing intlist_prepend \n");
    
    printf("- expecting 3 -2 30 16 3: \n");
    struct intlist* one = linked_lists(1);
    struct intlist* two = intlist_prepend(one, 3);
    intlist_show(two);
    printf("\n");
    intlist_free(two);

    printf("- expecting 37 2 6 1: \n");
    struct intlist* three = linked_lists(2);
    struct intlist* four = intlist_prepend(three, 37);
    intlist_show(four);
    printf("\n");
    intlist_free(four);

    printf("- expecting 9 3 4: \n");
    struct intlist* five = linked_lists(3);
    struct intlist* six = intlist_prepend(five, 9);
    intlist_show(six);
    printf("\n");
    intlist_free(six);

    printf("- expecting 55 3 1 3 7 6 4 2 1: \n");
    struct intlist* seven = linked_lists(4);
    struct intlist* eight = intlist_prepend(seven, 55);
    intlist_show(eight);
    printf("\n");
    intlist_free(eight);

}

/* display digits in reverse order */
void print_add_digits(intlist* xs) {
    
    if (xs != NULL) {
        print_add_digits(xs -> next);
        printf("%d ", xs -> val);
    }
}

void evidence_add_digits() {
    printf("*** testing add_digits \n");
    printf("- expecting 2 0 5: \n");
    struct intlist* one = linked_lists(2);
    struct intlist* two = linked_lists(3);
    struct intlist* three = add_digits(10, one, two);
    print_add_digits(three);
    printf("\n");
    intlist_free(one);
    intlist_free(two);
    intlist_free(three);

    printf("- expecting 5 6 10: \n");
    struct intlist* four = linked_lists(2);
    struct intlist* five = linked_lists(5);
    struct intlist* six = add_digits(16, four, five);
    print_add_digits(six);
    printf("\n");
    intlist_free(four);
    intlist_free(five);
    intlist_free(six);

    printf("- expecting 1 2 4 6 7 3 5 6: \n");
    struct intlist* seven = linked_lists(3);
    struct intlist* eight = linked_lists(4);
    struct intlist* nine = add_digits(8, seven, eight);
    print_add_digits(nine);
    printf("\n");
    intlist_free(seven);
    intlist_free(eight);
    intlist_free(nine);

    printf("- expecting 1 2 4 6 7 3 5 6: \n");
    struct intlist* ten = linked_lists(4);
    struct intlist* eleven = linked_lists(3);
    struct intlist* twelve = add_digits(8, ten, eleven);
    print_add_digits(twelve);
    printf("\n");
    intlist_free(ten);
    intlist_free(eleven);
    intlist_free(twelve);
}

int main(int argc, char *argv[]) {
    evidence_intlist_nth();
    evidence_intlist_show();
    evidence_intlist_set();
    evidence_intlist_append();
    evidence_intlist_prepend();
    evidence_add_digits();
    return 0;
}
/* ====== evaluation ====== */

/* === correctness === */

/* problem 1 (intlists) */
/* nth                                 6 / 6 */
/* set                                 6 / 6 */

// GRADER : append and prepend should not fail when passed the empty list (NULL)
// They should return a list of one item
/* append                              4 / 5 */
/* prepend                             4 / 5 */

/* show                                4 / 4 */
/* free                                6 / 6 */

// GRADER : DAB + E78 should return 1C23 (1 12 2 3), your function returns
// -12 -2 3
/* problem 2 (add_digits)              13/16 */

/* === style === */

/* code layout                         5 / 5 */
/* all lines <= 80 chars               1 / 1 */
/* identifiers are well named          6 / 6 */

/* functions are well designed         6 / 6 */
/* code is well factored               6 / 6 */

/* code is written clearly             6 / 6 */
/* code is efficient                   6 / 6 */

/* header comments for each fn in .h   6 / 6 */
/* for functions in header file:           */
/*   comment only needed above fn          */
/*   in header file; optional in .c        */
/* for helpers in .c file only:            */
/*   comment needed above fn               */
/*   in .c file                            */
/* adequate tests                      6 / 6 */
/* svn used correctly                  4 / 4 */

/* _total-score_                       90/100 */

/* graded by Jackson Quinn */

=== Note: the scoring formula is given here.

The following scoring formula has the effect of scaling style by
correctness. This is so a student cannot, for example, write only one
function out of six and earn full style points.

Let c = correctness points.
Let p = correctness percentage.
Let s = style points.
The total score is (c + p*s), rounded to the nearest integer.

For example, if a student earns 32/64 correctness points and 24/36
style points, the total score is 32 + 0.5 * 24 = 32 + 12 = 44.
