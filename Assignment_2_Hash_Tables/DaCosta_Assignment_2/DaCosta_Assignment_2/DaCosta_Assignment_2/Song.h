/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 2 Hash Tables
Date Assigned:	09-11-2018
Due Date:		09-27-2018 11:59pm

Description:	This file includes the Song class.

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

#pragma once
#include <iostream>
#include <string>
#include <vector>

class Song
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Song"/> class.
	/// </summary>
	Song(){	}

	Song(std::string _artist, std::string _title);

	/// <summary>
	/// Finalizes an instance of the <see cref="Song"/> class.
	/// </summary>
	~Song(){ }

	/// <summary>
	/// Gets the artist of the song.
	/// </summary>
	/// <returns>
	///		String.
	///	</returns>
	std::string getArtist() const
	{
		return artist;
	}

	/// <summary>
	/// Gets the title of the song.
	/// </summary>
	/// <returns>
	///		String.
	///	</returns>
	std::string getTitle() const
	{
		return title;
	}
	
	/// <summary>
	/// Sets the artist of the song.
	/// </summary>
	/// <param name="_artist">
	///		The artist of the song.
	///	</param>
	void setArtist(std::string _artist)
	{
		artist = _artist;
	}
	
	/// <summary>
	/// Sets the title of the song.
	/// </summary>
	/// <param name="_title">
	///		The title of the song.
	///	</param>
	void setTitle(std::string _title)
	{
		title = _title;
	}

	const bool operator== (Song const &_rightSong);

private:
	/// <summary>
	/// The artist of the song.
	/// </summary>
	std::string artist = "";

	/// <summary>
	/// The title of the song.
	/// </summary>
	std::string title = "";
};