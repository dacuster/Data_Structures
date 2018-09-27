#pragma once

#include <string>
#include <vector>
#include "Song.h"

class HashTable
{
public:
	HashTable();
	HashTable(int _size);
	~HashTable();

	void addSong(Song _song);
	void listArtistSongs(std::string _songArtist);
	void deleteSong(Song _song);
	// TODO: Delete on submission. Used to check all values of the array.
	void printAllContents();



private:
	class Node
	{
	public:
		Node* next = nullptr;
		Song song;

		Node()
		{

		}
		Node(Song _song)
		{
			song = _song;
		}

		~Node()
		{

		}
	};

	Node** hashTable = nullptr;
	int tableSize = 0;


};