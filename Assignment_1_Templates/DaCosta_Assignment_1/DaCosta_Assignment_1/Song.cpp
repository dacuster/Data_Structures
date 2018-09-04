#include <iostream>
#include <string>
#include <vector>
#include "Song.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

Song::Song(string _artist, string _title)
{
	artist = _artist;
	title = _title;
}

void Song::print(ostream & out = cout) const
{
	out << getTitle() << " by " << getArtist() << endl;
}

bool Song::operator< (const Song & second) const
{
	return getArtist() < second.getArtist();
}