/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Assignment 1, Sorting Function Template
*Date Assigned:		08-30-2018
*Due Date:			09-06-2018 11:59pm
*
*Description:		This file includes the functions for the Song class.
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

using std::cout;
using std::endl;
using std::cin;
using std::string;

Song::Song(string _artist, string _title)
{
	artist = _artist; 
	title  = _title;  
}

void Song::print(ostream & out = cout) const
{
	out << getTitle() << " by " << getArtist() << endl;
}

bool Song::operator< (const Song & second) const
{
	string artistOne = getArtist();
	string artistTwo = second.getArtist();

	/*
		Check if the artists are the same or not.
	*/
	if (!artistOne.compare(artistTwo))
	{
		/*
			Get the size of the smaller artist string name.
		*/
		int stringSize = artistOne.length() < artistTwo.length() ? artistOne.length() : artistTwo.length();

		/*
			Loop through each character of both strings and check the ASCII value of both
			as lowercase characters.
		*/
		for (int counter = 0; counter < stringSize; counter++)
		{
			if (int(tolower(artistOne[counter])) < int(tolower(artistTwo[counter])))
			{
				return true;
			}
			else if (int(tolower(artistOne[counter])) > int(tolower(artistTwo[counter])))
			{
				return false;
			}
		}

		/*
			The artist names are similar but with added words or character
			after a certain point so the artist with the smaller name is first.
		*/
		return artistOne.length() < artistTwo.length() ? true : false;
	}
	/*
		It's the same artist, compare song names.
	*/
	else
	{
		string titleOne = getTitle();
		string titleTwo = second.getTitle();

		/*
			Get the size of the smaller song title string.
		*/
		int stringSize = titleOne.length() < titleTwo.length() ? titleOne.length() : titleTwo.length();

		/*
			Loop through each character of both strings and check the ASCII value of both
			as lowercase characters.
		*/
		for (int counter = 0; counter < stringSize; counter++)
		{
			if (int(tolower(titleOne[counter])) < int(tolower(titleTwo[counter])))
			{
				return true;
			}
			else if (int(tolower(titleOne[counter])) > int(tolower(titleTwo[counter])))
			{
				return false;
			}
		}

		/*
			The song titles are similar but with added words or character
			after a certain point so the title with the smaller name is first.
		*/
		return titleOne.length() < titleTwo.length() ? true : false;
	}
}