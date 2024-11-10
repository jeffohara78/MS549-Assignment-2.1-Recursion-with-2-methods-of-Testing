// Includes for factorial calculations
#include "factorial.h"

// Using std namespace for cleanliness
using namespace std;

// Recursive func to calculate the factorial of a user provided n
unsigned long long recursiveFactorial(unsigned int n)
{
	// Set the base case for the factorial
	if (n == 0 || n == 1)
		return 1;
	else
		// Recursive case is n * factorial of (n-1)
		return n * recursiveFactorial(n - 1);
}

// Iterative function to calculate the factorial of n
unsigned long long iterativeFactorial(unsigned int n)
{
	// Initialize the result to 1
	unsigned long long result = 1;

	// For loop to multiply numbers from 2 up to n
	for (unsigned int i = 2; i <= n; ++i)
	{
		result *= i; // this will multiply the result by the current value of i
	}

	return result; // Return the final result
}