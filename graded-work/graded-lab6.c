/* graded lab6 */

/* ====== adrbook ====== */


/* ====== adrbook.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "cmd.h"
#include "adrbook.h"

#define BUFFER_SIZE 256

/* =================================== */
/* === execution of shell commands === */
/* =================================== */

/* === actions for each command === */

/* do_stats: print statistics of given address book */
void do_stats(bst *address_book)
{
  printf("Statistics of current address book:\n");
  printf("* entries in address book:      %d\n", 
	 bst_num_entries(address_book));
  printf("* height of binary search tree: %d\n\n", 
	 bst_height(address_book));
}

/* do_read: build address book from given file if possible;
 * return NULL if file doesn't exist
 * note: this is brittle; has little to no error handling
 */
bst *do_read(char *infile)
{
  vcard *c;
  char buf0[BUFFER_SIZE], buf1[BUFFER_SIZE], 
       buf2[BUFFER_SIZE], buf3[BUFFER_SIZE], 
       buf4[BUFFER_SIZE];
  bst *address_book = NULL;
  FILE *f = fopen(infile,"r");
  if (f==NULL) {
    shell_error_arg("File not found: \"%s\".",infile);
    return NULL;
  }
  while (!feof(f)) {
    /* this particular file format is baked in */
    fscanf(f,"%s\t%s\t%s\t%s\t%s\n",buf0,buf1,buf2,buf3,buf4);    
    c = vcard_new(buf0,buf1,buf2,buf3,buf4);
    if (address_book) {
      int i = bst_insert(address_book,c);
      if (i==0) /* c isn't pointed to by tree; free it */
	vcard_free(c);
    }
    else
      address_book = bst_singleton(c);
  }
  fclose(f);
  if (address_book) {
    printf("Read file %s.\n", infile);
    do_stats(address_book);
  }
  return address_book;
}

/* do_char: execute the CHAR command: display all vcards
 * whose cnet starts with c
 */
void do_char(char c,bst *address_book)
{
  unsigned int z = bst_c(stdout,address_book,c);
  printf("\n(found %u CNETs starting with '%c')\n\n",z,c);
}

/* do_lookup: look for the given CNET, report on findings */
void do_lookup(char *cnet, bst *address_book)
{
  int n_comparisons = 0;
  vcard *c = bst_search(address_book, cnet, &n_comparisons);  
  if (c)
    vcard_show(stdout,c);   
  else
    printf("cnet \"%s\" not found in current address book.\n", cnet); 
  printf("\n(%d comparisons made in search.)\n\n", n_comparisons);
}

/* do_cmd: execute the given command
 * note: address_book is of type bst** so it can be modified in READ
 */
void do_cmd(cmd *c, bst **address_book, int *quit)
{
  bst *tmp; /* for reading in new address book if needed */
  switch (c->name) {
  /* available commands are QUIT, STATS, CHAR, LOOKUP, HELP, READ */
  case QUIT:   *quit=1; break;
  case STATS:  do_stats(*address_book); break;
  case CHAR:   do_char(c->arg[0],*address_book); break;
  case LOOKUP: do_lookup(c->arg,*address_book);  break;    
  case HELP:   help_text(); break;
  case READ:
    tmp = do_read(c->arg);
    if (tmp) {
      bst_free(*address_book);
      *address_book = tmp;
    }
    else {
      shell_error_arg("could not read file %s, address book unchanged",c->arg);
      putchar('\n');
    }
    break;
  default:
    /* this shouldn't happen, ever */
    fprintf(stderr,"BUG (do_cmd): bad tag in cmd (%d)\n",c->name);
    exit(1);
  }    
}

/* ===================================== */
/* === administer the adrbook shell  === */
/* ===================================== */

/* trim_newline: duplicate the string and replace the newline 
 * at the end with '\0' if it exists. 
 */
char *trim_newline(char *s)
{
  int n = strlen(s);
  char *t = strdup(s);
  if (s[n-1]=='\n')
    t[n-1] = '\0';
  return t;
}

int main(int argc, char *argv[])
{
  int quit=0;
  bst *address_book=NULL;
  char *cmd_string;
  char user_input[BUFFER_SIZE];
  memset(user_input,'\0',BUFFER_SIZE);

  /* if too many args given, print usage and exit */
  if (argc>2)
    usage();

  /* say hello and load file, if one is named */
  greet();
  if (argc==2)
    /* if a file name given, read it in */
    address_book=do_read(argv[1]);

  while (!quit) {
    shell_prompt();
    fgets(user_input, BUFFER_SIZE, stdin);
    cmd_string = trim_newline(user_input);
    putchar('\n');
    if (!strcmp(cmd_string,""))
      continue;
    cmd *c = cmd_from_string(cmd_string);
    if (!c) {
      shell_error_arg("unrecognized or malformed command: \"%s\"", cmd_string);
      putchar('\n');
      help_text();
    } else
      do_cmd(c,&address_book,&quit);
    if (cmd_string)
      free(cmd_string);
    cmd_free(c);
  }

  /* clean up and exit */
  bst_free(address_book);
  printf("Bye!\n");
  return 0;
}

/* A note to coders who have read this code with interest:
 * one typically doesn't reinvent the wheel to write a shell
 * from scratch like you see here. For more information, please
 * investigate the Command Line Editor Library (libedit). -ams
 */

/* ====== adrbook.h ====== */

#ifndef _ADRBOOK_H_
#define _ADRBOOK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *cnet;
  char *email;
  char *fname;
  char *lname;
  char *tel;
} vcard;

typedef struct bst bst;
struct bst {
  vcard *c;
  bst *lsub;
  bst *rsub;
};

/* ============================ */
/* ===== vcard operations ===== */
/* ============================ */

/* Construct a new vcard */
/* Copy each string with strdup during construction. */
/* (This is a deep-copy constructor.) */
vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel);

/* Display vcard to f. */
/* The display of a vcard need not match any exact specification, */
/* but it must include all five of the vcard's component strings. */
void vcard_show(FILE *f, vcard *c);

/* Free the vcard and all strings in it. */
void vcard_free(vcard *c);

/* ============================ */
/* =====  bst operations  ===== */
/* ============================ */

/* Create a bst consisting of one leaf node. */
/* Do not copy the vcard, just point to it. */
/* (This is a shallow-copy constructor.) */
bst *bst_singleton(vcard *c);

/* Insert a vcard into a non-empty BST. */
/* Raise an error if given an empty BST. */
/* Use cnet alphabetical order (per strcmp). */
/* If the cnet is already present in the tree, insert nothing. */
/* Do not copy the vcard (this is shallow-copy insert). */
/* Return the number of vcards inserted (either 1 or 0). */
int bst_insert(bst *t, vcard *c);

/* Compute the total number of vcards in the tree. */
unsigned int bst_num_entries(bst *t);

/* The empty bst has height 0. */
/* A singleton tree has height 1, etc. */
/* Return the number of vcards inserted (either 1 or 0). */
unsigned int bst_height(bst *t);

/* Return NULL if nothing is found. */
/* n_comparisons is an out parameter to count the number of */
/* comparisons made during the search. */
/* *n_comparisons is 0 when first called. */
vcard *bst_search(bst *t, char *cnet, int *n_comparisons);

/* Show all cnets that start with given character. */
/* Show cnets one per line in alphabetical order. */
/* Do not traverse parts of the tree you know to be irrelevant. */
/* Return the number of cnets displayed. */
unsigned int bst_c(FILE *f, bst *t, char c);

/* Free the bst and all vcards as well. */
void bst_free(bst *t);

#endif /* _ADRBOOK_H_ */

/* ====== bst.c ====== */

#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst *bst_singleton(vcard *c)
{
    bst *res = (bst*) malloc(sizeof(bst));
    // GRADER: better to check whether malloc is successful here
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
    if (t == NULL) {
        return 0;
    }

    unsigned int counter1 = bst_height(t -> lsub);
    unsigned int counter2 = bst_height(t -> rsub);
    
    if (counter1 > counter2) {
        return counter1 + 1;
    } else {
        return counter2 + 1;
    }
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
    ++*n_comparisons;
    if (t) {
        if (strcmp(t -> c -> cnet, cnet) == 0) {
                return t -> c;
				// GRADER: bad indentation here -1pt
            } else {
                if (strcmp(t -> c -> cnet, cnet) < 0) {
                    return bst_search(t -> rsub, cnet, n_comparisons);
                } else if (strcmp(t -> c -> cnet, cnet) > 0) {
                    return bst_search(t -> lsub, cnet, n_comparisons);
                } 
        }
        return NULL;
    }
		// GRADER: If t is null, what do you return here? -1pt  
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
        if (t -> c -> cnet[0] == c) {
            num_cs++;
            bst_c(f, t -> lsub, c);
            fprintf(f, "%c \n", c);
            bst_c(f, t -> rsub, c);
        } else {
						// GRADER: there exists more efficient implementations
						// GRADER:  need to accumulate the counts  -1pt
            bst_c(f, t -> lsub, c);
            bst_c(f, t -> rsub, c); 
        }
    } else {
        return num_cs;
    }
}

void bst_free(bst *t)
{
    if (t != NULL) {
        bst_free(t -> lsub);
        bst_free(t -> rsub);
				// GRADER: NEED TO FREE VCARD -1pt
        free(t);
    }
}

/* ====== cmd.c ====== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "cmd.h"

/* === command constructors  === */

/* cmd_new: make a new heap-allocated command with arg set to NULL */
cmd *cmd_new(enum cmd_name name) 
{
  cmd *c = (cmd*)malloc(sizeof(cmd));
  if (c==NULL) {
    fprintf(stderr,"error (cmd_tag): malloc failed\n");
    exit(1);
  }
  c->name=name;
  c->arg=NULL;
  return c;
}

/* cmd_read: make a new heap-allocated READ command */
/* note: copy filename (deep copy) */
cmd *cmd_read(char *filename)
{
  if (!strlen(filename)) {
    shell_error("no filename given with read command");
    return NULL;
  }
  cmd *c = cmd_new(READ);
  c->arg = strdup(filename);
  return c;
}

/* cmd_char: make a new heap-allocated CHAR command */
/* note: copy "character" (actually length 1 string) (deep copy) */
cmd *cmd_char(char *ch)
{
  unsigned int len = strlen(ch);
  if (len==0) {
    shell_error("no character given with char command");
    return NULL;
  } else if (len>1) {
    shell_error("more than one character given with char command");
    return NULL;
  }
  cmd *c = cmd_new(CHAR);
  c->arg = strdup(ch);
  return c;
}

/* cmd_lookup: make a new heap-allocated LOOKUP command */
/* note: copy cnet (deep copy) */
cmd *cmd_lookup(char *cnet)
{
  if (!strlen(cnet)) {
    shell_error("no cnet provided for lookup command");
    return NULL;
  }
  cmd *c = cmd_new(LOOKUP);
  c->arg = strdup(cnet);
  return c;
}

/* === command free === */

/* cmd_free: free command struct and its string, if there is one */
void cmd_free(cmd *c)
{
  if (c) {
    if (c->arg)
      free(c->arg);
    free(c);
  }
}

/* === command display (for debugging, logging) === */

/* cmd_name_tos: return string constant for command name */
/* note: for debugging only; not currently used in shell */
char *cmd_name_tos(cmd *c)
{
  switch (c->name) {
  case QUIT:   return "QUIT";
  case STATS:  return "STATS";
  case READ:   return "READ";
  case CHAR:   return "CHAR";
  case LOOKUP: return "LOOKUP";
  case HELP:   return "HELP";
  }
  /* this should never happen, ever */
  fprintf(stderr,"BUG (cmd_name_tos): unrecognized command name %d\n",c->name);
  exit(1);
}

/* cmd_show: print command to FILE* (typically stderr) */
/* note: for debugging only; not currently used in shell */
void cmd_show(FILE *f, cmd *c)
{
  /* note: cmd_name_tos result does not need to be freed
   * since that function returns pointers to string constants
   */
  if (c->arg)
    fprintf(f,"%s %s\n",cmd_name_tos(c),c->arg);
  else
    fprintf(f,"%s\n",cmd_name_tos(c));
}

/* === command parsing === */

/* cmd_from_string: build a cmd (as defined above) from a string;
 * return NULL if the parse fails
 */
cmd *cmd_from_string(char *s)
{
  char cmdbuf[2];
  char argbuf[99];
  memset(cmdbuf,0,2);
  memset(argbuf,0,99);
  sscanf(s,"%s %s",cmdbuf,argbuf);
  if (strlen(cmdbuf)==1) {
    switch (cmdbuf[0]) {
    case 'q' : return cmd_new(QUIT);
    case 's' : return cmd_new(STATS);
    case 'r' : return cmd_read(argbuf);
    case 'c' : return cmd_char(argbuf);
    case 'l' : return cmd_lookup(argbuf);
    case 'h' : return cmd_new(HELP);
    }
  } 
  /* if we get this far, we couldn't parse the command string */
  return NULL;
}

/* ====== cmd.h ====== */

#ifndef _CMD_H
#define _CMD_H

/* ======================================= */
/* === command datatype and operations === */
/* ======================================= */

enum cmd_name {
  QUIT, STATS, READ, CHAR, LOOKUP, HELP
};

typedef struct {
  enum cmd_name name;
  char *arg; /* optional argument */
} cmd;

/* === command constructors === */

/* cmd_new: make a new heap-allocated command with arg set to NULL */
cmd *cmd_new(enum cmd_name name);

/* cmd_read: make a new heap-allocated READ command */
/* note: copy filename (deep copy) */
cmd *cmd_read(char *filename);

/* cmd_char: make a new heap-allocated CHAR command */
/* note: copy "character" (actually length 1 string) (deep copy) */
cmd *cmd_char(char *ch);

/* cmd_lookup: make a new heap-allocated LOOKUP command */
/* note: copy cnet (deep copy) */
cmd *cmd_lookup(char *cnet);

/* === command free === */

/* cmd_free: free command struct and its string, if there is one */
void cmd_free(cmd *c);

/* === command display (for debugging, logging) === */

/* cmd_name_tos: return string constant for command name */
/* note: for debugging only; not currently used in shell */
char *cmd_name_tos(cmd *c);

/* cmd_show: print command to FILE* (typically stderr) */
/* note: for debugging only; not currently used in shell */
void cmd_show(FILE *f, cmd *c);

/* === command parsing === */

/* cmd_from_string: build a cmd (as defined above) from a string;
 * return NULL if the parse fails
 */
cmd *cmd_from_string(char *s);

#endif /* _CMD_H */

/* ====== contact-info.csv ====== */


/* ====== Makefile ====== */

# Makefile for CS152 Winter 2020 Lab 6

.PHONY: clean

adrbook: cmd.h cmd.c shell.h shell.c adrbook.h bst.c vcard.c adrbook.c
	clang -g -o adrbook -Wall vcard.c bst.c shell.c cmd.c adrbook.c -lm

# type 'make clean' to remove the executable and debug information
clean:
	rm -rf a.out adrbook *.dSYM

/* ====== README ====== */


/* ====== shell.c ====== */

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/* ========================= */
/* === interface actions === */
/* ========================= */

void help_text()
{
  char p[] = 
    "c [char] // show all cnets beginning with character\n"
    "h        // help\n"
    "l [cnet] // look up a vcard by cnet\n"
    "r [file] // read a file into address book\n"
    "s        // show statistics about address book\n"
    "q        // quit\n\n";
  printf("%s",p);
}

void usage()
{
  char u[] = "usage: adrbook [file]";
  fprintf(stderr,"%s\n",u);
  exit(1);
}

void shell_prompt()
{
  printf("adrbook (h for help) > ");
}

void greet()
{
  printf("***** Welcome to adrbook! *****\n\n");
  help_text();
}

/* shell_error: this is for user errors (as opposed to bugs in code) */
/* (gives all such errors a uniform appearance) */
void shell_error(char *s)
{
  fprintf(stderr,"===> ERROR: %s <===\n",s);
}

/* shell_error_arg: this is for user errors (as opposed to bugs)
 * - this version takes a string arg for added flexibility
 */
void shell_error_arg(char *fmt, char *s)
{
  fprintf(stderr,"===> ERROR: ");
  fprintf(stderr,fmt,s);
  fprintf(stderr," <===\n");
}

/* ====== shell.h ====== */

#ifndef _SHELL_H
#define _SHELL_H

/* ========================= */
/* === interface actions === */
/* ========================= */

void help_text();

void usage();

void shell_prompt();

void greet();

/* shell_error: this is for user errors (as opposed to bugs in code) */
/* (gives all such errors a uniform appearance) */
void shell_error(char *s);

/* shell_error_arg: this is for user errors (as opposed to bugs)
 * - this version takes a string arg for added flexibility
 */
void shell_error_arg(char *fmt, char *s);

#endif /* _SHELL_H */

/* ====== vcard.c ====== */

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
		// GRADER: NEED TO free(c)
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

/* ====== evaluation ======  */

/* === correctness === */

/* vcard_new:                           / 4 */
/* vcard_free:                          1/ 2 */
/* vcard_show:                          / 3 */

/* bst_singleton:                       / 2 */
/* bst_insert:                          / 8 */
/* bst_num_entries:                     / 5 */
/* bst_height:                          / 5 */
/* bst_search:                          7/ 8 */
/* bst_c:                               7/ 8 */
/* bst_free:                            2/ 3 */

/* === style === */

/* code layout                          / 7 */
/* all lines <= 80 chars                / 1 */
/* identifiers are well named           / 8 */

/* functions are well designed          / 8 */
/* code is well factored                / 8 */

/* code is written clearly              / 8 */
/* code is efficient                    / 8 */

/* svn used correctly                   / 4 */

/* _total-score_                        92/100 */

/* graded by zeweichu */

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
