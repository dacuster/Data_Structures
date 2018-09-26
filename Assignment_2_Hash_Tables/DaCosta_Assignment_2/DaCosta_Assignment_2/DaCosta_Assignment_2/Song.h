#pragma once

#include <iostream>
#include <string>
#include <vector>


class Song
{
public:
	Song(){ }
	Song(std::string _artist, std::string _title);
	~Song(){ }

	std::string getArtist() const { return artist; }
	std::string getTitle() const { return title; }
	void setArtist(std::string _artist) { artist = _artist; }
	void setTitle(std::string _title) { title = _title; }

private:
	std::string artist = ""; 
	std::string title  = ""; 

};