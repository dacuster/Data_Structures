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

//------------------------------------------------------------------------------------
//	Include necessary libraries.
//------------------------------------------------------------------------------------
#include <iostream>
#include <string>

//------------------------------------------------------------------------------------
//	Include necessary namespace members.
//------------------------------------------------------------------------------------
using std::string;
using std::ostream;


/// <summary>
/// The song class.
/// </summary>
class Song
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Song" /> class.
	/// </summary>
	/// <param name="_artist">The artist.</param>
	/// <param name="_title">The title.</param>
	Song(string _artist, string _title);

	/// <summary>
	/// Gets the artist.
	/// </summary>
	/// <returns></returns>
	string getArtist() const
	{
		return artist;
	}

	/// <summary>
	/// Gets the title.
	/// </summary>
	/// <returns></returns>
	string getTitle() const
	{
		return title;
	}


	/// <summary>
	/// Compares the calling song to the second song.
	/// </summary>
	/// <param name="_secondSong">The second song.</param>
	/// <returns></returns>
	bool operator< (const Song & _secondSong) const;
	friend ostream & operator<< (ostream& _outputStream, const Song& _song);

private:
	string	title = "",
			artist = "";
};