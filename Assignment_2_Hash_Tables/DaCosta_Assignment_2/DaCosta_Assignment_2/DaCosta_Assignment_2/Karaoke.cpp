#include "HashTable.h"

enum COMMANDS {ADD, LIST, DELETE, QUIT };

/*
	TODO:
	Read file
	First number is test cases (how many times it runs)
	Next number is song addition size
	Next number is number of lines of commands
	Next few lines are commands
	Next number is song addition
	Next number is number of lines of commands
	Next few lines are commands

	Inputs are ARTIST then TITLE

*/
int main()
{
	std::string command;

	HashTable newTable = HashTable(3);

	newTable.printAllContents();
	Song newSong = Song("Avenged_Sevenfold", "Nightmare");
	Song newSong2 = Song("Avenged_Sevenfold", "God_Hates_Us");

	newTable.addSong(newSong);
	newTable.addSong(newSong2);

	newTable.printAllContents();


	system("pause");


	return 0;
}
