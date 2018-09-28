/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 2 Hash Tables
Date Assigned:	09-11-2018
Due Date:		09-27-2018 11:59pm

Description:	This file includes the Song class function definitions.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment: Reproduce this
assignment and provide a copy to another member of academic staff; and/or
Communicate a copy of this assignment to a plagiarism checking service (which
may then retain a copy of this assignment on its database for the purpose of
future plagiarism checking).
*/

#include "Song.h"

/// <summary>
///		Initializes a new instance of the <see cref="Song"/> class.
/// </summary>
/// <param name="_artist">
///		The artist of the song.
///	</param>
/// <param name="_title">
///		The title of the song.
///	</param>
Song::Song(std::string _artist, std::string _title)
{
	artist = _artist; 
	title  = _title;  
}

/// <summary>
///		Checks if both songs' artist and title are the same.
/// </summary>
/// <param name="_rightSong">
///		The comparison song.
///	</param>
/// <returns>
///		Boolean.
///	</returns>
const bool Song::operator==(Song const & _rightSong)
{
	if (this->getArtist() == _rightSong.getArtist() && this->getTitle() == _rightSong.getTitle())
	{
		return true;
	}
	return false;
}