#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"


/* vcard_new : allocate a new vcard, copy all strings, return new object
 * note: this is a "deep copy" as opposed to a "shallow copy"; the string 
 *   arguments are not to be shared by the newly allocated vcard
 */
vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
    vcard *new_vcard = (vcard*) malloc (sizeof(vcard));
    new_vcard -> cnet = strdup(cnet);
    new_vcard -> email = strdup(email);
    new_vcard -> fname = strdup(fname);
    new_vcard -> lname = strdup(lname);
    new_vcard -> tel = strdup(tel);

    return new_vcard; 
}

/* vcard_free : free vcard and the strings it points to
 */
void vcard_free(vcard *c)
{
    if (c != NULL) {
        free(c -> cnet);  
        free(c -> email);
        free(c -> fname);
        free(c -> lname);
        free(c -> tel);
    }
}

/* vcard_show : display contents of vcard
 * note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
void vcard_show(FILE *f, vcard *c)
{
    fprintf(f, "cnet %s \n", c -> cnet);
    fprintf(f, "email %s \n", c -> email);
    fprintf(f, "fname %s \n", c -> fname);
    fprintf(f, "lname %s \n", c -> lname);
    fprintf(f, "tel %s \n", c -> tel);
}
