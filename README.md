# rng - Random Number Generator
# Aaron Rader, 2022

Generates a series of random real numbers, coded to work with command-line arguments.

Command line arguments are as follows:
1. rng.exe
2. (unsigned)numbers to generate	(optional)
3. minimum number to generate		  (optional)
4. maximum number to generate		  (optional)

- if 1 argument is passed, 1000 numbers between 0 and 1 (inclusive) will be writted to stdout
- if 2 arguments are passed, the 2nd argument will define the amount of numbers between 0 and 1 (inclusive) to write to stdout
- if 3 arguments are passed, the 3rd argument will define the maximum number to generate
- if 4 arguments are passed, the 3rd argument will define the minimum number and the 4th argument will define the maximum number to generate
