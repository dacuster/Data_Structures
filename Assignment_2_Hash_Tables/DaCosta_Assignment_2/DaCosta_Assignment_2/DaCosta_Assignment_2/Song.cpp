#include "Song.h"

/// <summary>
///		Initializes a new instance of the <see cref="Song"/> class.
/// </summary>
/// <param name="_artist">
///		The song's artist.
///	</param>
/// <param name="_title">
///		The song's title.
///	</param>
Song::Song(std::string _artist, std::string _title)
{
	artist = _artist;
	title = _title;
}

/// <summary>
///		Checks if both songs' artist and title are the same.
/// </summary>
/// <param name="_rightSong">
///		The comparison song.
///	</param>
/// <returns>
///		True if the songs have the same artists and titles.<br/>
///		False if the songs have different artists and/or titles.
///	</returns>
const bool Song::operator==(Song const & _rightSong)
{
	if (this->getArtist() == _rightSong.getArtist() && this->getTitle() == _rightSong.getTitle())
	{
		return true;
	}
	return false;
}