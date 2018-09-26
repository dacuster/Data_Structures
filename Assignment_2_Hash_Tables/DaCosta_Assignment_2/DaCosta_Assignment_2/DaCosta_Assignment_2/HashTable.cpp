#include "HashTable.h"

HashTable::HashTable()
{
	tableSize = 1;
}

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

HashTable::~HashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		delete hashTable[i];
	}

	delete[] hashTable;
}

void HashTable::addSong(Song _song)
{
	int position           = 0;                 
	std::string songArtist = _song.getArtist(); 

	/*
		Add the ASCII values of each character of the artist's name.
	*/
	for (int i = 0; i < _song.getArtist().length(); i++)
	{
		position += songArtist[i];
	}

	/*
		Set the actual position in the table that the
		song will go.
	*/
	std::cout << _song.getArtist() << " position is " << position << std::endl;
	position %= tableSize;

	std::cout << _song.getArtist() << " position is " << position << std::endl;

	/*
		Add the song to a node to add to the table.
	*/
	Node* newNode = new Node(_song);

	/*
		Check if the current table position is empty and add the
		new song node to the table at that position.
		If not, traverse a linked list to find the end and add
		it there.
	*/
	if (hashTable[position] == nullptr)
	{
		std::cout << "Position is null!" << std::endl;
		hashTable[position] = newNode;
	}
	else
	{
		Node *tempNode = hashTable[position];

		while (tempNode->next != nullptr)
		{
			*tempNode = *tempNode->next;
		}

		tempNode->next = newNode;
	}
}

void HashTable::listArtistSongs(std::string _songArtist)
{

}

void HashTable::deleteSong(std::string _songTitle)
{
	/*
		TODO:
		Check if the next pointer is the song being searched.
		Assign the song being searched (next pointer) to a temp pointer.
		Assign next pointer to next pointer next pointer currentNode->next = currentNode->next->next.
		Delete 'temp' node at address.
	*/
}

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
				std::cout << linkedListCounter << "is " << tempNode->song.getTitle() << " by " << tempNode->song.getArtist() << std::endl;
				linkedListCounter++;
				tempNode = tempNode->next;
			}
		}
	}
}
