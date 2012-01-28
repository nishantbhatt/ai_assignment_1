/*
 * ga_eight_queen.h
 *
 *  Created on: Jan 27, 2012
 *      Author: 100413064
 */

#define GA_SUCCESS			1 /* success variable */
#define GA_FAILURE			0 /* failure variable */

#define POPULATION_SIZE		100 /* size of the population */
#define	CHESS_BOARD_SIZE	8 /* size of the chess board */

typedef unsigned char gene; /* 1 byte gene to store position of each queen on the chess board */

/* chromosome containing the N genes */
typedef struct {
	gene _gene[CHESS_BOARD_SIZE];
} chromosome;

char ga_rand_chrom(chromosome *ga_chromosome);
void ga_print_chrom(chromosome *ga_chromosome);
char ga_mut_chrom(chromosome *ga_chromosome);
int ga_rank_chrom(chromosome *ga_chromosome);
