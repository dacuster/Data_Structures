#include "Song.h"

Song::Song(std::string _artist, std::string _title)
{
	artist = _artist;
	title = _title;
}

const bool Song::operator==(Song const & _rightSong)
{
	if (this->getArtist() == _rightSong.getArtist() && this->getTitle() == _rightSong.getTitle())
	{
		return true;
	}

	return false;
}

const bool Song::operator!=(Song const & _rightSong)
{
	if (this->getArtist() != _rightSong.getArtist() || this->getTitle() != _rightSong.getTitle())
	{
		return false;
	}

	return true;
}
