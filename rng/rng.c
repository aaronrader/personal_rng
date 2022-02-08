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
* 2. file to output to				(optional)
* 3. (unsigned)numbers to generate	(optional)
* 4. minimum number to generate		(optional)
* 5. maximum number to generate		(optional)
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

	if (argc > 1) { //has command-line arguments (file to write to)
		stream = fopen(argv[1], "w");
		if (stream == NULL) {
			printf("Error: cannot open \"%s\": ", argv[1]);
			print_error_message();
			return EXIT_FAILURE;
		}

		//Numeric argument defined
		if (argc > 2) {
			if ((count = strtoull(argv[2], NULL, 0)) == 0 || count == ULONG_MAX) {
				printf("Error: invalid numeric argument (%s)\n", argv[2]);
				print_error_message();
				return EXIT_FAILURE;
			}

			//4-arg call, "count" numbers generated - [0,max]
			if (argc == 4) {
				if ((max = strtod(argv[3], NULL)) == 0 || max == ULONG_MAX) {
					printf("Error: invalid numeric argument (%s)\n", argv[3]);
					print_error_message();
					return EXIT_FAILURE;
				}
			}

			//5-arg call, "count" numbers generated - [min,max]
			if (argc == 5) {
				if ((min = strtod(argv[3], NULL)) == 0 || min == ULONG_MAX) {
					printf("Error: invalid numeric argument (%s)\n", argv[3]);
					print_error_message();
					return EXIT_FAILURE;
				}
				if ((max = strtod(argv[4], NULL)) == 0 || max == ULONG_MAX) {
					printf("Error: invalid numeric argument (%s)\n", argv[4]);
					print_error_message();
					return EXIT_FAILURE;
				}
			}
		}
		printf("Random Number Generator - Aaron Rader 2022\n\n");
	}

	if (argc == 1) { //no command-line arguments
		printf(
			"Random Number Generator - Aaron Rader 2022\n\n"
			"Enter a positive integer denoting the amount of numbers you would like to generate: "
		);
		if (scanf("%ju", &count) != 1) {
			printf("\nError: number is invalid.\n");
			return EXIT_FAILURE;
		}
		printf("Enter min: ");
		if (scanf("%lf", &min) != 1) {
			printf("\nError: number is invalid.\n");
			return EXIT_FAILURE;
		}
		printf("Enter max: ");
		if (scanf("%lf", &max) != 1) {
			printf("\nError: number is invalid.\n");
			return EXIT_FAILURE;
		}
	}

	printf("Generating random numbers...\n");
	for (uintmax_t i = 0; i < count; ++i) {
		fprintf(stream, "%lf ", (RAND_FLOAT * (max - min)) + min);
	}
	fclose(stream);
}