#pragma once
#include <iostream>

using std::string;
using std::cout;
using std::ostream;
using std::endl;

class Song
{
public:
	Song(string _artist, string _title);

	string getArtist() const
	{
		return artist;
	}

	string getTitle() const
	{
		return title;
	}



	void print(ostream & out = cout) const;

	bool operator< (const Song & second) const;

private:
	string	title,
			artist;


};

ostream & operator << (ostream & out, const Song & second)
{
	second.print(out);
	return out;
}