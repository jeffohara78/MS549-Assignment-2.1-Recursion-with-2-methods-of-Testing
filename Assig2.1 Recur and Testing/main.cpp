/*
MS549 Data Structures and Testing
Assignment 2.1 Part 1: Recursion with two forms of testing
11-9-24
Jeff O'Hara
This program is a basic C++ program that illustrates in the console how to calculate basic factorial numbers for n and have two
forms of testing done at the same time, Unit Testing and Performance Testing.
*/


// Libraries
#include <iostream>
#include <chrono>
#include "factorial.h"

// use standard namespace for cleaner code
using namespace std;

// Functions for testing
void unitTest();
void performanceTest();

int main()
{
	// initialize varaibles
	unsigned int number;

	cout << "Enter a non-negative integer: ";
	cin >> number;

	// Input validation
	if (cin.fail())
	{
		cerr << "Invalid input! Please input a non-negative integer." << endl;
		return 1;
	}

	// Calculate factorial using the recursive function
	unsigned long long recResult = recursiveFactorial(number);

	// Calculate factorial using iterative function
	unsigned long long iterResult = iterativeFactorial(number);

	// Display the results to the user
	cout << "Recursive Factorial of " << number << " is " << recResult << endl;
	cout << "Iterative Factorial of " << number << " is " << iterResult << endl;

	// Run unit tests to verify if correct
	unitTest();

	// Run Performance Tests to compare execution times
	performanceTest();

	return 0;
}

// Functions
void unitTest()
{
	cout << "\nRunning Unit Tests..." << endl;

	// Define a Struct for test cases
	struct TestCase
	{
		unsigned int input; // Input number
		unsigned long long expectedOutput; // Expected factorial result
	};

	// Set an array of test cases with known outputs
	TestCase testCases[] =
	{
		{0, 1}, // 0! with value
		{1, 1}, // 1! with value
		{5, 120}, //5! with value
		{10, 3628800}, //10! with value
		{15, 1307674368000}, //15! with value
	};

	// Loop through each test case
	for (const auto& testCase : testCases)
	{
		// Calculate factorial using both functions
		unsigned long long recResult = recursiveFactorial(testCase.input);
		unsigned long long iterResult = iterativeFactorial(testCase.input);

		// Check if the results match the expected output
		bool recPass = recResult == testCase.expectedOutput;
		bool iterPass = iterResult == testCase.expectedOutput;

		// Output the test results to the user
		if (recPass && iterPass)
		{
			cout << "Test Passed for input " << testCase.input << endl;
		}
		else
		{
			cout << "Test Failed for input " << testCase.input << endl;
			if (!recPass)
				cout << " Recursive Result: " << recResult << " (Expected: " << testCase.expectedOutput << ")" << endl;
			if (!iterPass)
				cout << " Iterative Result: " << iterResult << " (Expected: " << testCase.expectedOutput << ")" << endl;
		}
	}
}

// Function for Performance Testing
void performanceTest()
{
	cout << "\nRunning Performance Tests..." << endl;

	// Array of values to test performance on
	unsigned int testValues[] = { 10, 15, 20, 25, 30, 35 };

	// Loop through each value of n
	for (unsigned int n : testValues)
	{
		// Measure execution time of the recursive function
		auto startRec = chrono::high_resolution_clock::now();
		recursiveFactorial(n);
		auto endRec = chrono::high_resolution_clock::now();
		chrono::duration<double, nano> durationRec = endRec - startRec;

		// Measure execution time of the iterative funtion
		auto startIter = chrono::high_resolution_clock::now();
		iterativeFactorial(n);
		auto endIter = chrono::high_resolution_clock::now();
		chrono::duration<double, nano> durationIter = endIter - startIter;

		// Output the execution times to the user
		cout << "n = " << n << ":" << endl;
		cout << " Recursive Time: " << durationRec.count() << " ns" << endl;
		cout << " Iterative Time: " << durationIter.count() << " ns" << endl;
	}
}