/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * HW 2
 */

/* all_positive : returns 1 if all elements of the array a with length alen 
are positive and 0 if not */
int all_positive(int a[], unsigned int alen);

/* exists_positive : returns 1 if at least one element of a given array a with
length alen is positive and 0 if not */
int exists_positive(int a[], unsigned int alen);

/* first_positive : returns the index number of the first positive number of 
a given array a with length alen. If no positive number, returns -1. */
int first_positive(int a[], unsigned int alen);

/* number_positives : returns the number of positive numbers in an array of 
length alen. */
unsigned int number_positives(int a[], unsigned int alen);

/* negate : changes the sign of every element in an array of length alen, 
except for 0. */
void negate(int a[], unsigned int alen);

/* partial_sums : returns a new array containing partial sums over the provided
array. */
int* partial_sums(int a[], unsigned int alen);

/* rotate_right : modifies a passed-in array so each element appears at one 
greater index value than before */
void rotate_right(int a[], unsigned int alen);

/* concat_strings : concatenates a list of strings into one larger string. */   
char* concat_strings(char** strings, unsigned int num_strings); 

/* rle_encode : uses run-length encoding to compress integer data. */
int* rle_encode(int* in, unsigned int inlen, unsigned int* outlen);

/* rle_decode : uses run-length decoding to expand integer data. */
int* rle_decode(int* in, unsigned int inlen, unsigned int* outlen);
