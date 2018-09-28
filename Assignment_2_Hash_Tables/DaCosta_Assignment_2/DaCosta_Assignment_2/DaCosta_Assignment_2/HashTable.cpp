/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 2 Hash Tables
Date Assigned:	09-11-2018
Due Date:		09-27-2018 11:59pm

Description:	This file includes the HashTable class function definitions.

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

#include "HashTable.h"

/// <summary>
/// Initializes a new instance of the <see cref="HashTable"/> class.
/// </summary>
/// <param name="_size">
///		The dynamic size of the table.
///	</param>
HashTable::HashTable(int _size)
{
	tableSize = _size;
	hashTable = new Node*[tableSize] { nullptr };
}

/// <summary>
/// Finalizes an instance of the <see cref="HashTable"/> class.
/// </summary>
HashTable::~HashTable()
{
	/*
		Fail safe to delete every pointer in the table and any linked list pointers.
	*/
	for (int counter = 0; counter < tableSize; counter++)
	{
		Node *tempNode = hashTable[counter];
		
		while (tempNode != nullptr)
		{
			Node *nextTempNode = tempNode;       
			tempNode           = tempNode->next; 

			delete nextTempNode;
		}
		delete tempNode;
	}
	delete[] hashTable;
}

/// <summary>
/// Adds a song to the hash table.
/// </summary>
/// <param name="_song">
///		The song to add.
///	</param>
void HashTable::addSong(Song _song)
{
	/*
		Get the position in the table to add the song.
	*/
	int position = positionFinder(_song.getArtist());

	/*
		Create a new node for the song.
	*/
	Node* newNode = new Node(_song);

	/*
		Check if the current table position is empty and add the song.
	*/
	if (hashTable[position] == nullptr)
	{
		hashTable[position] = newNode;
		std::cout << hashTable[position]->song.getTitle() << " by " << hashTable[position]->song.getArtist() << " has been added to your list." << std::endl;
		return;
	}
	/*
		Traverse the linked list to find an empty location.
	*/
	else
	{
		Node *tempNode = hashTable[position];

		while (tempNode->next != nullptr)
		{
			tempNode = tempNode->next;
		}

		tempNode->next = newNode;              
		Song nextSong  = tempNode->next->song; 

		std::cout << nextSong.getTitle() << " by " << nextSong.getArtist() << " has been added to your list." << std::endl;
		return;
	}
	return;
}

/// <summary>
/// Lists the given artist's songs if they are in the table.
/// </summary>
/// <param name="_songArtist">
///		The name of the artist.
///	</param>
void HashTable::listArtistSongs(std::string _songArtist)
{
	/*
		Get the position in the table to check.
	*/
	int position = positionFinder(_songArtist);

	/*
		The position that the song would be in is empty so it's not in the table.
	*/
	if (hashTable[position] == nullptr)
	{
		std::cout << "There are no songs by " << _songArtist << " in the table." << std::endl;
		return;
	}
	/*
		Traverse the linked list at the table position to print all the songs
		by the given artist if any exist.
	*/
	else
	{
		Node *currentNode = hashTable[position]; 
		int numberOfSongs = 0;                   

		while (currentNode != nullptr)
		{
			if (currentNode->song.getArtist() == _songArtist)
			{
				if (numberOfSongs == 0)
				{
					std::cout << "Songs by " << _songArtist << ": ";
				}
				/*
					If a song has been found before, add a comma to separate the songs.
				*/
				else if (numberOfSongs > 0)
				{
					std::cout << ", ";
				}
				std::cout << currentNode->song.getTitle();
				numberOfSongs++;
			}
			currentNode = currentNode->next;
		}

		if (numberOfSongs == 0)
		{
			std::cout << "Couldn\'t find any songs by " << _songArtist << "." << std::endl;
		}
		else
		{
			std::cout << std::endl;
		}
		return;
	}
}

/// <summary>
/// Deletes the given song from the table if it exists.
/// </summary>
/// <param name="_song">
///		The song to delete.
///	</param>
void HashTable::deleteSong(Song _song)
{
	/*
		Get the position in the table to check.
	*/
	int position = positionFinder(_song.getArtist());

	/*
		The position that the song would be in is empty so it's not in the table.
	*/
	if (hashTable[position] == nullptr)
	{
		return;
	}
	/*
		The position in the table is exactly where the song is.
	*/
	else if (hashTable[position]->song == _song)
	{
		Node* tempNode      = hashTable[position];       
		hashTable[position] = hashTable[position]->next; 

		std::cout << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << " has been deleted from the list." << std::endl;

		delete tempNode;
		return;
	}
	/*
		Traverse the linked list at the table position to see if the song is in it.
	*/
	else
	{
		Node *currentNode = hashTable[position];

		while (currentNode->next != nullptr)
		{
			if (currentNode->next->song == _song)
			{
				Node *tempNode    = currentNode->next;
				currentNode->next = tempNode->next;

				std::cout << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << " has been deleted from the list." << std::endl;

				delete tempNode;
				return;
			}
			else
			{
				currentNode = currentNode->next;
			}
		}

		std::cout << _song.getTitle() << " by " << _song.getArtist() << " is not in the list." << std::endl;

		return;
	}
	return;
}

/// <summary>
///		Prints all the contents of the hash table for the slots that contain data.
/// </summary>
void HashTable::printAllContents()
{
	std::cout << std::endl << "------------------------Hash Table Contents------------------------" << std::endl << "Table size: " << tableSize << std::endl;

	for (int counter = 0; counter < tableSize; counter++)
	{
		if (hashTable[counter] != nullptr)
		{
			std::cout << counter << " is " << hashTable[counter]->song.getTitle() << " by " << hashTable[counter]->song.getArtist() << " ";

			Node *tempNode = hashTable[counter]->next;

			int linkedListCounter = 0;

			while (tempNode != nullptr)
			{
				std::cout << counter << "-" << (linkedListCounter + 1) << " is " << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << " ";
				linkedListCounter++;
				tempNode = tempNode->next;
			}
			std::cout << std::endl;
		}
	}
	return;
}

/// <summary>
/// Determines the position in the table for the song.
/// </summary>
/// <param name="_songArtist">
///		The artist of the song.
///	</param>
/// <returns>
///		Integer.
///	</returns>
int HashTable::positionFinder(std::string _songArtist)
{
	int position = 0;

	for (int counter = 0; counter < _songArtist.length(); counter++)
	{
		position += _songArtist[counter];
	}

	return position % tableSize;
}