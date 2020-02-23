/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 2
 */

typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

int intlist_nth(intlist* xs, unsigned int n);

void intlist_set(intlist* xs, unsigned int n, int val);

intlist* intlist_append(intlist* xs, int val);

intlist* intlist_prepend(intlist* xs, int val);

void intlist_show(intlist* xs);

void intlist_free(intlist* xs);

intlist* add_digits(unsigned int base, intlist* ds1, intlist* ds2);
