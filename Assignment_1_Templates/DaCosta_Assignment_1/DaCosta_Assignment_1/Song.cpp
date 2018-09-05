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

#include <vector>
#include "Song.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;

Song::Song(string _artist, string _title)
{
	artist = _artist; 
	title  = _title;    
}


bool Song::operator< (const Song & second) const
{
	if (!getArtist().compare(second.getArtist()))
	{
		return getArtist() < second.getArtist();
	}
	
	return getTitle() < second.getTitle();
}

ostream& operator << (ostream & out, const Song & second)
{
	out << second.getTitle() << " by " << second.getArtist();
	return out;
}