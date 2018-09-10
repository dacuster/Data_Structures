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


/// <summary>
/// Initializes a new instance of the <see cref="Song" /> class.
/// </summary>
/// <param name="_artist">The artist.</param>
/// <param name="_title">The title.</param>
Song::Song(string _artist, string _title)
{
	artist = _artist; 
	title  = _title;    
}


/// <summary>
/// Operators the specified second song.
/// </summary>
/// <param name="_secondSong">The second song.</param>
/// <returns></returns>
bool Song::operator< (const Song & _secondSong) const
{
	if (getArtist().compare(_secondSong.getArtist()))
	{
		return getArtist() < _secondSong.getArtist();
	}
	
	return getTitle() < _secondSong.getTitle();
}


/// <summary>
/// Operators the specified output stream.
/// </summary>
/// <param name="_outputStream">The output stream.</param>
/// <param name="_secondSong">The second song.</param>
/// <returns></returns>
ostream& operator << (ostream & _outputStream, const Song & _secondSong)
{
	_outputStream << _secondSong.getTitle() << " by " << _secondSong.getArtist();
	return _outputStream;
}