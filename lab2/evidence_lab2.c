#include <stdlib.h>
#include <stdio.h>
#include "lab2.h"

/* evidence_expt: test expt */
void evidence_binary_char()
{
    printf("*** testing binary_char\n");
    printf("- expecting 00010001:", binary_char(17));
}

int main(int argc, char *argv[]) 
{
	evidence_binary_char();
	return 0;
}
