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

//------------------------------------------------------------------------------------
//	Include necessary libraries.
//------------------------------------------------------------------------------------
#include "Song.h"

//------------------------------------------------------------------------------------
//	NAME:			Song Constructor
//	DESCRIPTION:	Create a Song object with the artist and song title input
//					parameters to the member variables.
//------------------------------------------------------------------------------------
Song::Song(string _artist, string _title)
{
	artist = _artist; 
	title  = _title;    
}

//------------------------------------------------------------------------------------
//	NAME:			Comparison Overload Operator (<)
//	DESCRIPTION:	Compare song 1 artist with song 2 artist. If they're the same,
//					compare the titles. Return True if the first value is smaller.
//------------------------------------------------------------------------------------
bool Song::operator< (const Song & _secondSong) const
{
	if (getArtist().compare(_secondSong.getArtist()))
	{
		return getArtist() < _secondSong.getArtist();
	}
	
	return getTitle() < _secondSong.getTitle();
}

//------------------------------------------------------------------------------------
//	NAME:			Stream Overload Operator (<<)
//	DESCRIPTION:	Send the song information to the output stream.
//------------------------------------------------------------------------------------
ostream& operator << (ostream & _outputStream, const Song & _secondSong)
{
	_outputStream << _secondSong.getTitle() << " by " << _secondSong.getArtist();
	return _outputStream;
}