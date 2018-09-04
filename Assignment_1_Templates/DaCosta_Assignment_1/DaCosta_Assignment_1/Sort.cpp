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

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"
using namespace std;

template <typename Comparable>
const Comparable & sort(const vector<Comparable> & a)
{
	int maxIndex = 0;

	for (int i = 1; i < a.size(); i++)
	{
		if (a[maxIndex] < a[i])
			maxIndex = i;
	}
	return a[maxIndex];
}

int main()
{
	vector<Song> songs = { Song("artist", "title"), Song("artist2", "title2") }; 
	vector<int> intVec = { 1, 5, 3, 4, 2                                      };  


	 
	cout << sort(intVec) << endl;
	cout << sort(songs) << endl;



	string temp;
	cin >> temp;
}