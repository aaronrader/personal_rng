/*
* Program:	rng.exe
* Purpose:	generates a given number of random real numbers
* date:		02/2022
* Author:	Aaron Rader
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define RAND_FLOAT ((double)rand()/(double)RAND_MAX)

void print_error_message() {
	printf(
		"Usage: rng.exe [numbers to generate] [min] [max]\n"
		"\twhere numbers to generate is a positive integer.\n"
		"\twhere min and max are real numbers.\n"
	);
}

/*
* Command line arguments are as follows:
* 1. rng.exe
* 2. (unsigned)numbers to generate	(optional)
* 3. minimum number to generate		(optional)
* 4. maximum number to generate		(optional)
*/
int main(int argc, char* argv[]) {
	if (argc > 4) {
		printf("Error: too many command-line arguments (%d)\n", argc);
		print_error_message();
		return EXIT_FAILURE;
	}

	uintmax_t count = 1000;
	intmax_t temp;
	double max = 1;
	double min = 0;

	if (argc > 1) {
		if ((temp = strtoll(argv[1], NULL, 0)) < 0) {
			printf("Error: invalid numeric argument (%s)\n", argv[1]);
			print_error_message();
			return EXIT_FAILURE;
		}
		count = strtoull(argv[1], NULL, 0);
	}

	//3-arg call, "count" numbers generated - [0,max]
	if (argc == 3) {
		if ((max = strtod(argv[2], NULL)) == 0 && strcmp(argv[2], "0") != 0) {
			printf("Error: invalid numeric argument (%s)\n", argv[2]);
			print_error_message();
			return EXIT_FAILURE;
		}
		if (max < 0) {
			printf("Error: invalid numeric argument (%s): max should be greater than 0 when min is not defined\n", argv[2]);
			print_error_message();
			return EXIT_FAILURE;
		}
	}

	//4-arg call, "count" numbers generated - [min,max]
	if (argc == 4) {
		if ((min = strtod(argv[2], NULL)) == 0 && strcmp(argv[2], "0") != 0) {
			printf("Error: invalid numeric argument (%s)\n", argv[2]);
			print_error_message();
			return EXIT_FAILURE;
		}
		if ((max = strtod(argv[3], NULL)) == 0 && strcmp(argv[3], "0") != 0) {
			printf("Error: invalid numeric argument (%s)\n", argv[3]);
			print_error_message();
			return EXIT_FAILURE;
		}
		if (max < min) {
			printf("Error: invalid numeric argument (%s): max should be greater than min\n", argv[3]);
			print_error_message();
			return EXIT_FAILURE;
		}
	}

	srand(time(NULL));
	//printf("Count:\t%ju\nMin:\t%lf\nMax:\t%lf\n", count, min, max);
	for (uintmax_t i = 0; i < count; ++i) {
		printf("%lf ", (RAND_FLOAT * (max - min)) + min);
	}
}