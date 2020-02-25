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
