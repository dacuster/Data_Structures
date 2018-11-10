#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Node.h"
#include "Huffman.h"


Huffman::Huffman(std::string _phrase)
{
	calculateFrequency(_phrase);
}


Huffman::~Huffman()
{
	delete root;
}

void Huffman::print(Node * _root, std::string _phrase)
{
	return;
}

void Huffman::generate(std::map<char, size_t> _characterMap)
{

	return;
}

void Huffman::calculateFrequency(std::string _phrase)
{
	// Map to store all the characters in the phrase and their frequencies.
	std::map<char, size_t> characterMap;
	// Iterator for finding characters.
	std::map<char, size_t>::iterator mapLocation;

	for (size_t currentCharacter = 0; currentCharacter < _phrase.size(); currentCharacter++)
	{
		// Find the character in the string.
		mapLocation = characterMap.find(characterMap[currentCharacter]);

		// The character isn't in the map. Add it.
		if (mapLocation == characterMap.end())
		{
			characterMap.insert(std::pair<char, size_t>(_phrase[currentCharacter], 1));
			continue;
		}

		// Increase the frequency count.
		mapLocation->second++;
	}

	generate(characterMap);

	return;
}
