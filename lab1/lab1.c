/* Ruhi Sah, rsah
 * CS 152, Winter 2020
 * Lab 1
 */ 

#include "lab1.h"

long int expt(int a, unsigned int n) {
    if (n == 0) {
	return 1;
    } else {
	return a * expt(a, n - 1);
    }
}

long int ss(int a, unsigned int n) {
    if (n == 0) {
	return 1;
    } else if(n % 2 == 0) {
	return ss(a, n / 2) * ss(a, n / 2); 	
    } else if(n % 2 == 1) {
        return a * ss(a, n - 1);
    } else {
        return 0;
    }
}

int ssm(int a, unsigned int n, unsigned int m) {
    if (n == 0) {
	return 1;
    } else if(n % 2 == 0) {
	return ((ssm(a, n / 2, m) % m) * (ssm(a, n / 2, m) % m)) % m;
    } else {
        return (a * ssm(a, n - 1, m) % m) % m;
    }
}

