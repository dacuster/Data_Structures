#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	int n = 1;
	int question = 1;
	int i = 0;
	int j = 0;
	int k = 0;

	cout << "Question " << question << ":" << endl;

	for (i = 0; i < 3; i++)
	{
		n *= 5;

		for (int j = 0; j < n; j++)
		{
			sum++;
		}

		cout << "Sum for " << n << "iterations = " << sum << endl;

		sum = 0;
	}

	n = 1;

	cout << endl << "Question" << question << ":" << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			sum++;
		}

		cout << "Sum for " << (n * n) << "iterations = " << sum << endl;

		sum = 0;
	}

	for (int i = 0; i < n; i++)
	{

	}

	string userInput;
	cin >> userInput;

	return 0;
}