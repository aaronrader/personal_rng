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

#define RAND_FLOAT ((double)rand()/(double)RAND_MAX)

void print_error_message() {
	printf(
		"Usage: fcount [filename] [(unsigned)numbers to generate] [min] [max]\n"
		"\twhere filename is the name of a file.\n"
		"\twhere numbers to generate is a positive integer.\n"
		"\twhere max and min are real numbers.\n"
		"\tmin is 0 by default, explicitly defining a 0 min will result in an error.\n"
	);
}

/*
* Command line arguments are as follows:
* 1. rng.exe
* 2. (unsigned)numbers to generate	(optional)
* 3. minimum number to generate		(optional)
* 4. maximum number to generate		(optional)
* 5. file to output to				(optionsl)
*/
int main(int argc, char* argv[]) {
	if (argc > 5) {
		printf("Error: too many command-line arguments (%d)\n", argc);
		print_error_message();
		return EXIT_FAILURE;
	}

	uintmax_t count = 1000;
	double max = 1;
	double min = 0;
	FILE* stream = stdout;

	//Numeric argument defined
	if (argc > 1) {
		if ((count = strtoull(argv[1], NULL, 0)) == 0 || count == ULONG_MAX) {
			printf("Error: invalid numeric argument (%s)\n", argv[2]);
			print_error_message();
			return EXIT_FAILURE;
		}

		//3-arg call, "count" numbers generated - [0,max]
		if (argc == 3) {
			if ((max = strtod(argv[2], NULL)) == 0 || max == ULONG_MAX) {
				printf("Error: invalid numeric argument (%s)\n", argv[3]);
				print_error_message();
				return EXIT_FAILURE;
			}
		}

		//4-arg call, "count" numbers generated - [min,max]
		if (argc == 4) {
			if ((min = strtod(argv[2], NULL)) == 0 || min == ULONG_MAX) {
				printf("Error: invalid numeric argument (%s)\n", argv[3]);
				print_error_message();
				return EXIT_FAILURE;
			}
			if ((max = strtod(argv[3], NULL)) == 0 || max == ULONG_MAX) {
				printf("Error: invalid numeric argument (%s)\n", argv[4]);
				print_error_message();
				return EXIT_FAILURE;
			}
		}

		if (argc == 5) {
			stream = fopen(argv[4], "w");
			if (stream == NULL) {
				printf("Error: cannot open \"%s\": ", argv[1]);
				perror("");
				return EXIT_FAILURE;
			}
		}
	}

	srand(time(NULL));
	for (uintmax_t i = 0; i < count; ++i) {
		fprintf(stream, "%lf ", (RAND_FLOAT * (max - min)) + min);
	}
	fclose(stream);
}