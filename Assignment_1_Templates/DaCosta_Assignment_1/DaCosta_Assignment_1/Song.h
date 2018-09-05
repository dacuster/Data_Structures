/*
*Author(s):			Nick DaCosta
*Class:				CSI-281-03
*Assignment:		Assignment 1, Sorting Function Template
*Date Assigned:		08-30-2018
*Due Date:			09-06-2018 11:59pm
*
*Description:		This file includes the function prototypes for the Song class.
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

#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::ostream;
using std::endl;

class Song
{
public:
	Song(){}

	Song(string _artist, string _title);

	string getArtist() const
	{
		return artist;
	}

	string getTitle() const
	{
		return title;
	}

	bool operator< (const Song & second) const;

	friend ostream & operator << (ostream&, const Song&);


private:
	string	title = "",
			artist = "";


};

/*
ostream & operator << (ostream & out, const Song & second)
{
	out << second.getTitle() << " by " << second.getArtist();
	return out;
}
*/