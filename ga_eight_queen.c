/*
 * ga_eight_queen.c
 *
 *  Created on: Jan 27, 2012
 *      Author: 100413064
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ga_eight_queen.h"

#define TRUE	1
#define FALSE	0

#define CEILING(X) (X-(int)(X) > 0 ? (int)(X+1) : (int)(X))

char contains(gene g, chromosome *ga_chromosome, int offset);

char ga_mut_chrom(chromosome *ga_chromosome) {

	unsigned int iseed = (unsigned int) time(NULL);
	srand(iseed);

	/* change 2 to 4 genes in chromosome */
	int num = (rand() % 3) + 2;

	/* already changed */
	int changed[4];
	int changed_count = 0;

	/* max position on the chess board */
	int max_position = CHESS_BOARD_SIZE * CHESS_BOARD_SIZE;

	/* changed count becomes equal */
	while(changed_count != num) {
		changed[changed_count++] = rand() % CHESS_BOARD_SIZE;

		int flag;
		for(flag = 0; flag < changed_count - 1; flag++) {
			if(changed[flag] == changed[changed_count - 1]) {
				changed_count--;
				continue;
			}
		}

		gene rand_gene;
		while(TRUE) {
			/* variable to store pseudo-random numbers */
			rand_gene = (rand() % max_position) + 1;
			if(contains(rand_gene, ga_chromosome, CHESS_BOARD_SIZE - 1) == FALSE)
				break;
		}
		ga_chromosome->_gene[changed[changed_count -1]] = rand_gene;
	}

	return GA_SUCCESS;
}

void ga_print_chrom(chromosome *ga_chromosome) {
	printf("{");
	int i = 0;
	for(; i < CHESS_BOARD_SIZE - 1; i++)
		printf("%d, ", ga_chromosome->_gene[i]);

	printf("%d}\n", ga_chromosome->_gene[CHESS_BOARD_SIZE]);
}

int ga_rank_chrom(chromosome *ga_chromosome) {
	int score = 0;
	int i = 0, j, x_col, x_row, y_col, y_row;

	for(; i < CHESS_BOARD_SIZE - 1; i++) {

		x_col = ga_chromosome->_gene[i] % CHESS_BOARD_SIZE;
		if(x_col == 0)
			x_col = CHESS_BOARD_SIZE;

		x_row = CEILING(ga_chromosome->_gene[i] / (double)CHESS_BOARD_SIZE);

		for(j = i + 1; j < CHESS_BOARD_SIZE; j++) {

			y_col = ga_chromosome->_gene[j] % CHESS_BOARD_SIZE;
			if(y_col == 0)
				y_col = CHESS_BOARD_SIZE;

			y_row = CEILING(ga_chromosome->_gene[j] / (double)CHESS_BOARD_SIZE);

			/* could cut*/
			if(x_row == y_row || x_col == y_col || fabs(x_col - y_col) == fabs(x_row - y_row))
				score++;
		}
	}

	return score;
}

char ga_mate_chroms(chromosome *ga_chromosome_f, chromosome *ga_chromosome_m) {

}
char ga_rand_chrom(chromosome *ga_chromosome) {
	unsigned int iseed = (unsigned int) time(NULL);
	srand(iseed);

	/* variable to store pseudo-random numbers */
	gene rand_gene;

	/* flag to track progress */
	int flag = 0;
	/* max position on the chess board */
	int max_position = CHESS_BOARD_SIZE * CHESS_BOARD_SIZE;

	while (flag != CHESS_BOARD_SIZE) {
		/* generate random position */
		rand_gene = (rand() % max_position) + 1;

		if (contains(rand_gene, ga_chromosome, flag) == FALSE)
			ga_chromosome->_gene[flag++] = rand_gene;
	}

	/* return success */
	return GA_SUCCESS;
}

char contains(gene g, chromosome *ga_chromosome, int offset) {
	int i = 0;
	/* search all the genes within a chromosome */
	for (; i < offset; i++) {
		if (ga_chromosome->_gene[i] == g)
			return TRUE;
	}
	/* not contained */
	return FALSE;
}
