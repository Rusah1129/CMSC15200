/* graded lab8 */

/* ====== bucket.c ====== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

bucket *bucket_cons(char *s, unsigned long int hash, bucket *b)
{
    bucket *head = (struct bucket*) malloc (sizeof (struct bucket));
    
    head -> string = strdup(s);    
    head -> hash = hash;
    head -> next = b;
    
    return head;
}

unsigned int bucket_size(bucket *b)
{
    int i = 0;
    while (b) {
        i++;
        b = b -> next;
    }
    return i;
}

void bucket_show(bucket *b)
{
    unsigned i = 0;
    while (b) {
        while (b -> string[i]) {
            printf("%c", b -> string[i]);
        }
        b = b -> next;
    }
}

void bucket_free(bucket *b)
{
    struct bucket *node = b;

    while (b) {
        node = b;
        b = b -> next;
        free(node -> string);
        free(node);
    }
}

/* ====== htbl.c ====== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

unsigned long int good_hash(char *s)
{
    unsigned int res = 17;
    unsigned int i = 0;
    while (s[i]) {
        res = res * 37 + s[i];
        i++;
    }
    return res;
}

unsigned long int bad_hash(char *s)
{
    unsigned res = 17;
    unsigned i = 0;
    while (s[i]) {
        while (i < 2) {
            res = res * 37 + s[i];
            i++;
        }
    } 
    return res;
}

htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
    htbl *new_htbl = (htbl*) malloc (sizeof(htbl) * sz);
    new_htbl -> hash = h;
    new_htbl -> buckets = NULL;
    new_htbl -> n_buckets = sz;
    return new_htbl;
}

unsigned int htbl_n_entries(htbl *t)
{
    int i = 0;
    int j = 0;
    struct bucket *bucket;
    while(t) {
        while (t -> buckets[i]) {
            bucket = t -> buckets[i];
            while (bucket) {
                j++;
                bucket = bucket -> next;
            }
            i++; 
        }
    }
    return j;
}

double htbl_load_factor(htbl *t)
{
    int j = 0;
    int i = htbl_n_entries(t);
    while(t) {
        while (t -> buckets[j]) {
            j++;
        }
    }
    return (i / j);
}

unsigned int htbl_max_bucket(htbl *t)
{
    int i = 0;
    int j = 0;
    while (t -> buckets[i]) {
        i++;
        if (i > j) {
            j = i;
        }
    }
    return j;
}

void htbl_insert(char *s, htbl *t)
{
    unsigned long int hash = t -> hash(s);
    unsigned long int new_hash = hash % t -> n_buckets;
    t -> buckets[new_hash] = bucket_cons(s, hash, t -> buckets[new_hash]);
}

int htbl_member(char *s, htbl *t)
{
    unsigned long int hash = good_hash(s);
    unsigned new_hash = hash % t -> n_buckets;
    if (t -> buckets[new_hash]) {
        if (!strcmp(t -> buckets[new_hash] -> string, s)) {
            return 1;
        }
        while (t -> buckets[new_hash] -> next != NULL) {
            if (!strcmp(t -> buckets[new_hash] -> string, s)) {
                return 1;
            }
            t -> buckets[new_hash] = t -> buckets[new_hash] -> next;
        }
        return 0;
    }
    return 0;
}

void htbl_show(htbl *t)
{
    int i = 0;
    while (t -> buckets[i]) {
        printf("h: %lu str: %s ", t -> buckets[i] -> hash, 
            t -> buckets[i] -> string);
        t -> buckets[i] = t -> buckets[i] -> next;
        ++i;
    }
}

void htbl_free(htbl *t)
{
    int i = 0;
    struct bucket *bucket;
    struct bucket *temp;
    while (t -> buckets[i]) {
        bucket = t -> buckets[i];
        while (bucket) {
            temp = bucket -> next;
            free(bucket);
            bucket = temp;
        }
        temp = bucket;
        free(temp);
    }

    /* GRADER: 
    free(t->buckets);
    free(t);
    */
}



/* ====== evaluation ======  */

/* === correctness === */

/* bucket_cons:                        3 / 3 */
/* bucket_size:                        4 / 4 */
/* bucket_show:                        2 / 4 */
/* bucket_free:                        4 / 4 */

/* good_hash:                          4 / 4 */
/* bad_hash:                           3 / 3 */

/* htbl_new:                           1 / 4 */
/* htbl_n_entries:                     4 / 4 */
/* htbl_load_factor:                   2 / 4 */
/* htbl_max_bucket:                    4 / 4 */
/* htbl_insert:                        5 / 5 */
/* htbl_member:                        5 / 5 */
/* htbl_show:                          2 / 4 */
/* htbl_free:                          3 / 4 */

/* === style === */

/* code layout                         7 / 7 */
/* all lines <= 80 chars               1 / 1 */
/* identifiers are well named          6 / 6 */

/* functions are well designed         6 / 6 */
/* code is well factored               6 / 6 */

/* code is written clearly             8 / 8 */
/* code is efficient                   6 / 6 */

/* svn used correctly                  4 / 4 */

/* _total-score_                       82 /100 */


/* graded by Daniar Kurniawan */

/* GRADER: 
I got too many segfault while fixing the code
Here is the list of the wrong code:
    htbl_new
        Should be this way:

          if (sz==0) {
            fprintf(stderr,"error (htbl_new): size 0\n");
            exit(1);
          }
          htbl *t = (htbl*)malloc(sizeof(htbl));
          if (!t) {
            fprintf(stderr,"error (htbl_new): malloc failed\n");
            exit(1);
          }
          t->hash = h;
          t->n_buckets = sz;
          t->buckets = (bucket**)malloc(sizeof(bucket*)*sz);
          for (int i=0; i<sz; i++)
            t->buckets[i] = NULL;
          return t;

	htbl_show
        Should be this way:

          for (int i=0; i<t->n_buckets; i++) {
            printf("[%2d] ", i);
            bucket_show(t->buckets[i]);
          }

    bucket_show
        Should be this way:
        
          for (;b;b=b->next)
            printf("\"%s\"(%lu):",b->string,b->hash);
          printf("[]\n");

    htbl_load_factor
        Should be this way:
            
            return ((double)htbl_n_entries(t))/t->n_buckets;

*/

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
