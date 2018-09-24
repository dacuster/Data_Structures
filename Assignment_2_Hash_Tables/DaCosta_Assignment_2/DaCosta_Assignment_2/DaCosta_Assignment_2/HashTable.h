#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"

class HashTable
{
public:
	HashTable();
	~HashTable();

	void addSong(Song _song);
	void listArtistSongs(std::string _songArtist);
	void deleteSong(std::string _songTitle);



private:
	class Node
	{
	public:
		Node* next = nullptr;
		Song song;

		Node(Song _song, Node* _next = nullptr)
		{
			song = _song;
			next = _next;
		}

		~Node()
		{
			delete next;
		}
	};

	Node* head;
	int totalNodes = 0;
};