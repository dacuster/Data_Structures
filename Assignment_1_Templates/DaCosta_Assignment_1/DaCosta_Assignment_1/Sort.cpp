/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Assignment 1, Sorting Function Template
*Date Assigned:		08-30-2018
*Due Date:			09-06-2018 11:59pm
*
*Description:		This file includes the functions for the Main file.
*
*Certification of Authenticity:
*I certify that this is entirely my own work, except where I have given
*fully-documented references to the work of others. I understand the definition
*and consequences of plagiarism and acknowledge that the assessor of this
*assignment may, for the purpose of assessing this assignment: Reproduce this
*assignment and provide a copy to another member of academic staff; and/or
*Communicate a copy of this assignment to a plagiarism checking service (which
*may then retain a copy of this assignment on its database for the purpose of
*future plagiarism checking).
*/


//------------------------------------------------------------------------------------
//	Include necessary libraries.
//------------------------------------------------------------------------------------
#include "Song.h"
#include <vector>
#include <algorithm>
#include <iterator>

//------------------------------------------------------------------------------------
//	Include necessary namespace members.
//------------------------------------------------------------------------------------
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::iter_swap;

//------------------------------------------------------------------------------------
//	NAME:			Sort Template Function
//	DESCRIPTION:	Sort vectors using swap method moving larger values to the end.
//------------------------------------------------------------------------------------
/// <summary>
/// Sorts the specified sort vector.
/// </summary>
/// <param name="_sortVector">The sort vector.</param>
template <typename Sortable>
void sort(vector<Sortable> & _sortVector)
{
	for (int counterOne = 0; counterOne < _sortVector.size() - 1; counterOne++)
	{
		for (int counterTwo = 0; counterTwo < _sortVector.size() - counterOne - 1; counterTwo++)
		{
			if (_sortVector[counterTwo + 1] < _sortVector[counterTwo])
			{
				iter_swap(&_sortVector[counterTwo + 1], &_sortVector[counterTwo]);
			}
		}
	}
}

//------------------------------------------------------------------------------------
//	NAME:			Print Template Function
//	DESCRIPTION:	Iterate through vectors and print each element.
//------------------------------------------------------------------------------------
/// <summary>
/// Prints the specified print vector.
/// </summary>
/// <param name="_printVector">The print vector.</param>
template <typename Printable>
void print(vector<Printable> &_printVector)
{
	typename vector<Printable>::const_iterator _printIterator;

	for (_printIterator = _printVector.begin(); _printIterator != _printVector.end(); ++_printIterator)
	{
		cout << *_printIterator << endl;
	}

	cout << endl;
}

//------------------------------------------------------------------------------------
//	NAME:			Main Function
//	DESCRIPTION:	Execute the name program.
//------------------------------------------------------------------------------------
int main()
{
	//------------------------------------------------------------------------------------
	//	Create vectors to sort using a template function.
	//------------------------------------------------------------------------------------
	vector<Song> songs = { Song("Starset", "My Demons"), Song("Avenged Sevenfold", "Unholy Confessions"), Song("Metallica", "Enter Sandman"), Song("Avenged Sevenfold", "The Stage"), Song("Metallica", "King Nothing"), Song("In This Moment", "Roots") }; 
	vector<int> intVec = { 1, 5, 3, 4, 2}; 

	//------------------------------------------------------------------------------------
	//	Print the values of the vectors before sorting.
	//------------------------------------------------------------------------------------
	cout << "Initial vectors:" << endl;
	print(intVec);
	print(songs);

	//------------------------------------------------------------------------------------
	//	Sort the values of the vectors.
	//------------------------------------------------------------------------------------
	sort(intVec);
	sort(songs);

	//------------------------------------------------------------------------------------
	//	Print the values of the vectors after sorting.
	//------------------------------------------------------------------------------------
	cout << "Sorted vectors:" << endl;
	print(intVec);
	print(songs);

	//------------------------------------------------------------------------------------
	//	Wait for user input to hold the console.
	//------------------------------------------------------------------------------------
	string temp;
	cin >> temp;

	return 0;
}