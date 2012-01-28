/*
 ============================================================================
 Name        : ga_test.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ga_eight_queen.h"

int main(void) {
	chromosome chrm;

	if(ga_rand_chrom(&chrm) == GA_FAILURE)
		printf("Cannot create a chromosome\n");
	else {
		ga_print_chrom(&chrm);
		printf("%d\n", ga_rank_chrom(&chrm));
		ga_mut_chrom(&chrm);
		ga_print_chrom(&chrm);
		printf("%d\n", ga_rank_chrom(&chrm));

	}


	return 1;
}
