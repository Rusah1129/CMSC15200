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


    if (linked_list_num == 1) {
        
        struct intlist* head = one;        

        one -> val = 2;
        one -> next = two;
    
        two -> val = 30;
        two -> next = three;

        three -> val = 16;
        three -> next = four;

        four -> val = 45;
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
}

void evidence_intlist_nth() {
    printf("*** testing intlist_nth \n");
    struct intlist* one = linked_lists(1);
    printf("- expecting 30: %d \n", intlist_nth(one, 1));
    printf("\n"); 
}

// testing intlist_show with this function and below ones as well.
void evidence_intlist_set() {
    printf("*** testing intlist_set \n");
    printf("- expecting 2 30 16 45: \n");
    struct intlist* one = linked_lists(1);
    intlist_set(one, 3, 45);
    intlist_show(one);
    printf("\n");
}

void evidence_intlist_append() {
    printf("*** testing intlist_append \n");
    printf("- expecting 2 30 16 45 3: \n");
    struct intlist* one = linked_lists(1);
    intlist_show(intlist_append(one, 3));
    printf("\n");
}

void evidence_intlist_prepend() {
    printf("*** testing intlist_prepend \n");
    printf("- expecting 3 2 30 16 45: \n");
    struct intlist* one = linked_lists(1);
    intlist_show(intlist_prepend(one, 3));
    printf("\n");

}

void evidence_add_digits() {
    printf("*** testing add_digits \n");
    printf("- expecting 5 0 2: \n");
    struct intlist* one = linked_lists(2);
    struct intlist* two = linked_lists(3);
    intlist_show(add_digits(10, one, two));
    printf("\n");
}

int main(int argc, char *argv[]) {
    evidence_intlist_nth();
    evidence_intlist_set();
    evidence_intlist_append();
    evidence_intlist_prepend();
    evidence_add_digits();
    return 0;
}
