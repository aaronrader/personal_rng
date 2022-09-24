/*
* Program:		rng
* Author:		Aaron Rader
* Date:			03/2022
*
* Generates random numbers to an output file
*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<fstream>
#include "rando.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	//comman-line args
	vector<string> args(argv + 1, argv + argc);
	srand((unsigned)time(NULL));

	bool integer = false;		//should integers be generated instead of real numbers?
	bool fullReport = false;	//should the generated numbers be printed to console?
	bool report = false;		//should a report be printed to console showing success and simple statistics on the data?
	bool console = false;		//shoud this be a console application? (allows custom min, max, and number of values)
	if (args.size() > 0 && args.front()[0] == '-') {
		for (size_t i = 1; i < args.front().length(); ++i) {
			switch (args.front()[i]) {
			case 'd':
			case 'i':
				integer = true;
				break;
			case 'f':
				fullReport = true;
				report = true;
				break;
			case 'r':
				report = true;
				break;
			case 'c':
				console = true;
				break;
			default:
				cout << "Error: invalid switch." << endl;
				return EXIT_FAILURE;
			}
		}
		args.erase(args.begin());
	}

	string fileName = "rng.txt";
	if (args.size() > 0) {
		fileName = args.front();
		args.erase(args.begin());
	}
	ofstream fout(fileName);

	if (args.size() > 0) {
		cout << "Error: too many command line arguments." << endl;
		return EXIT_FAILURE;
	}

	size_t count = 100;
	double max = 100;
	double min = 0;

	if (console) {
		//Get input from user
		cout << "Enter a minimum value: ";
		cin >> min;
		cout << "Enter a maximum value: ";
		cin >> max;
		cout << "Enter the number of values to generate: ";
		while (!(cin >> count)) {
			cerr << "Error: Invalid entry.\nPlease enter a " << (integer ? "whole" : "real") << " number: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << endl;
	}

	if (report)
		cout << "Random Number Generator - Aaron Rader, 2022\n" << endl;

	//Generate the numbers
	double num;
	double minGen = max;
	double maxGen = min;
	for (size_t i = 0; i < count; ++i) {
		if (integer)
			num = rando((int)ceil(min), (int)floor(max));
		else
			num = rando(min, max);

		if (num > maxGen) maxGen = num;
		if (num < minGen) minGen = num;

		fout << num << " ";
		if (fullReport)
			cout << num << " ";
	}

	if (fullReport) cout << "\n\n";

	if (report) {
		cout <<
			"Numbers generated:\t" << count << endl <<
			"Minimum generated:\t" << minGen << endl <<
			"Maximum generated:\t" << maxGen << endl;
	}

	return EXIT_SUCCESS;
}