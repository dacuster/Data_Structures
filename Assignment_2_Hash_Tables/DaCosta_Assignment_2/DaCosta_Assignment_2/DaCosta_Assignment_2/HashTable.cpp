#include "HashTable.h"

/// <summary>
/// Initializes a new instance of the <see cref="HashTable"/> class with a default table size of 1.
/// </summary>
HashTable::HashTable()
{
	tableSize = 1;
}

/// <summary>
/// Initializes a new instance of the <see cref="HashTable"/> class.
/// </summary>
/// <param name="_size">
///		The dynamic size of the table.
///	</param>
HashTable::HashTable(int _size)
{
	tableSize = _size;
	hashTable = new Node*[tableSize];

	/*
		Populate the table with null nodes.
	*/
	for (int counter = 0; counter < tableSize; counter++)
	{
		hashTable[counter] = nullptr;
	}
}

/// <summary>
/// Finalizes an instance of the <see cref="HashTable"/> class.
/// </summary>
HashTable::~HashTable()
{
	/*
		Fail safe to delete every pointer in the table and any linked list pointers.
	*/
	for (int i = 0; i < tableSize; i++)
	{
		Node *tempNode = hashTable[i];
		
		while (tempNode != nullptr)
		{
			Node *nextTempNode = tempNode;
			tempNode = tempNode->next;

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
	int position           = 0;                 
	std::string songArtist = _song.getArtist(); 

	/*
		Add the ASCII values of each character of the artist's name.
	*/
	for (int i = 0; i < songArtist.length(); i++)
	{
		position += songArtist[i];
	}

	/*
		Set the actual position in the table that the song will go.
	*/
	position %= tableSize;

	/*
		Add the song to the table.
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
			*tempNode = *tempNode->next;
		}

		tempNode->next = newNode;
		Song nextSong = tempNode->next->song;
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
	int position = 0;

	/*
		Add the ASCII values of each character of the artist's name.
	*/
	for (int i = 0; i < _songArtist.length(); i++)
	{
		position += _songArtist[i];
	}

	/*
		Set the actual position in the table that the song will go.
	*/
	position %= tableSize;

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
			std::cout << "Could not find any songs by " << _songArtist << "." << std::endl;
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
	int position           = 0;                 
	std::string songArtist = _song.getArtist();

	/*
		Add the ASCII values of each character of the artist's name.
	*/
	for (int i = 0; i < songArtist.length(); i++)
	{
		position += songArtist[i];
	}

	/*
		Set the actual position in the table that the song will go.
	*/
	position %= tableSize;

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

		std::cout << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << " has been deleted from your list." << std::endl;

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

				std::cout << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << " has been deleted from your list." << std::endl;

				delete tempNode;
				return;
			}
			else
			{
				currentNode = currentNode->next;
			}
		}

		std::cout << "Could not find " << _song.getTitle() << " by " << _song.getArtist() << std::endl;

		return;
	}

	return;
}

//TODO: Delete after testing.
void HashTable::printAllContents()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (hashTable[i] == nullptr)
		{
			std::cout << i << " is null." << std::endl;
		}
		else
		{
			std::cout << i << " is " << hashTable[i]->song.getTitle() << " by " << hashTable[i]->song.getArtist() << std::endl;
			Node *tempNode = hashTable[i]->next;
			int linkedListCounter = 0;
			while (tempNode != nullptr)
			{
				std::cout << linkedListCounter << " is " << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << std::endl;
				linkedListCounter++;
				tempNode = tempNode->next;
			}
		}
	}

	return;
}
