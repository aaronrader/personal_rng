# rng
# Aaron Rader, 2022

Generates a series of random real numbers, coded to work with command-line arguments.

Command line arguments are as follows:
1. rng.exe
2. file to output to				      (optional)
3. (unsigned)numbers to generate	(optional)
4. minimum number to generate		  (optional)
5. maximum number to generate		  (optional)

- if 2 arguments are passed, 1000 numbers between 0 and 1 (inclusive) will be writted to the file
- if 3 arguments are passed, the 3rd argument will define the amount of numbers between 0 and 1 (inclusive) to write to the file
- if 4 arguments are passed, the 4th argument will define the maximum number to generate
- if 5 arguments are passed, the 4th argument will define the minimum number and the 5th argument will define the maximum number to generate
- NOTE: if minimum number to generate is 0, user should use the 4-arg call and exclude min dignotation

This program will also work as a console program, prompting for input and generating the same result that would have been generated with the given inputs as command-line arguments.
