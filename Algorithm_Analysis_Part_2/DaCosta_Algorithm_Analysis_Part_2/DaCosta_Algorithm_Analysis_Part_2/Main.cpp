#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;

void printQuestionNumber(int _number, long long& _resetN);
void printSum(long long _iteration, long long _sum);

int main()
{
	ofstream saveFile;


	// Number of times n should be multiplied by the multiplier.
	const int TOTAL_ITERATIONS = 3; 
	// Multiplier for n after each iteration.
	const int N_MULTIPLIER     = 5; 

	long long sum        = 0; 
	long long n          = 1; 
	int question         = 1; 
	int counter          = 0; 

	long long i = 0; 
	long long j = 0; 
	long long k = 0; 

	// Question 1
	printQuestionNumber(question++, n);

	for (counter = 0; counter < TOTAL_ITERATIONS; counter++)
	{
		sum = 0;
		n *= N_MULTIPLIER;

		for (i = 0; i < n; i++)
		{
			sum++;
		}

		printSum(n, sum);
	}

	// Question 2
	printQuestionNumber(question++, n);

	for (counter = 0; counter < TOTAL_ITERATIONS; counter++)
	{
		sum = 0;
		n *= N_MULTIPLIER;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				sum++;
			}
		}

		printSum(n, sum);
	}

	// Question 3
	printQuestionNumber(question++, n);

	for (counter = 0; counter < TOTAL_ITERATIONS; counter++)
	{
		sum = 0;
		n *= N_MULTIPLIER;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < (n * n); j++)
			{
				sum++;
			}
		}

		printSum(n, sum);
	}

	// Question 4
	printQuestionNumber(question++, n);

	for (counter = 0; counter < TOTAL_ITERATIONS; counter++)
	{
		sum = 0;
		n *= N_MULTIPLIER;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				sum++;
			}
		}

		printSum(n, sum);
	}

	// Question 5
	printQuestionNumber(question++, n);

	saveFile.open("question5.csv", ofstream::app);
	long long q5Counter = 0;
	bool printed = false;

	for (counter = 0; counter < TOTAL_ITERATIONS; counter++)
	{

		saveFile << endl << "Iteration " << counter << endl;

		sum = 0;
		n *= N_MULTIPLIER;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < (i * i); j++)
			{
				for (k = 0; k < j; k++)
				{
					sum++;
					if (i < 10)
					{
						saveFile << i << "," << j << "," << k << endl;
					}
				}
			}
			if (i < 25)
			{
				cout << endl << endl << sum << endl << endl;
			}
		}

		printSum(n, sum);
	}

	saveFile.close();

	// Question 6
	printQuestionNumber(question++, n);

	for (counter = 0; counter < TOTAL_ITERATIONS; counter++)
	{
		sum = 0;
		n *= N_MULTIPLIER;

		for (i = 1; i < n; i++)
		{
			for (j = 1; j < (i * i); j++)
			{
				if (j % i == 0)
				{
					for (k = 0; k < j; k++)
					{
						sum++;
					}
				}
			}
		}

		printSum(n, sum);
	}

	string userInput;
	cin >> userInput;

	return 0;
}

/// <summary>
/// Prints the question number and resets n.
/// </summary>
/// <param name="_number">The question number.</param>
/// <param name="_resetN">The value of n.</param>
void printQuestionNumber(int _number, long long& _resetN)
{
	_resetN = 1;

	cout << endl << "Question " << _number << ":" << endl;
}

/// <summary>
/// Prints the sum for the end of the iterations of n.
/// </summary>
/// <param name="_iteration">The value of n.</param>
/// <param name="_sum">The sum of all iterations.</param>
void printSum(long long _iteration, long long _sum)
{
	// Create a file variable.
	ofstream csvFile;

	cout << "Sum for " << _iteration << " iterations = " << _sum << endl;
	
	// Open the file and append.
	csvFile.open("Data.csv", ofstream::app);

	csvFile << _iteration << "," << _sum << endl;

	csvFile.close();

}