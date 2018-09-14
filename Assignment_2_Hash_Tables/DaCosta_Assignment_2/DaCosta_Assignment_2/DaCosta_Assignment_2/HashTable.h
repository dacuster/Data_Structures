#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Song.h"

class HashTable
{
public:
	HashTable();
	~HashTable()
	{
	}


private:
	std::vector<Song> songTable;

};