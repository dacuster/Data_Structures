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

private:
	std::string artist = ""; 
	std::string title  = ""; 

};