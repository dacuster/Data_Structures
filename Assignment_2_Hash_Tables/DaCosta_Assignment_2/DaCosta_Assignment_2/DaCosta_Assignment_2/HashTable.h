/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 2 Hash Tables
Date Assigned:	09-11-2018
Due Date:		09-27-2018 11:59pm

Description:	This file includes the HashTable and Node classes.

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
#include "Song.h"

class HashTable
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="HashTable"/> class.
	/// </summary>
	HashTable(){ }
	HashTable(int _size);
	~HashTable();

	void addSong(Song _song);                      
	void listArtistSongs(std::string _songArtist); 
	void deleteSong(Song _song);
	void printAllContents();

	int positionFinder(std::string _songArtist);

private:
	class Node
	{
	public:
		/// <summary>
		/// The next pointer.
		/// </summary>
		Node* next = nullptr;

		/// <summary>
		/// The node's song data.
		/// </summary>
		Song song;

		/// <summary>
		/// Initializes a new instance of the <see cref="Node"/> class.
		/// </summary>
		/// <param name="_song">
		///		The song data to add.
		///	</param>
		Node(Song _song)
		{
			song = _song;
		}
	};

	/// <summary>
	/// Creates a pointer to a hash table of pointers.
	/// </summary>
	Node** hashTable = nullptr;

	/// <summary>
	/// The table size.
	/// </summary>
	int tableSize = 1;
};