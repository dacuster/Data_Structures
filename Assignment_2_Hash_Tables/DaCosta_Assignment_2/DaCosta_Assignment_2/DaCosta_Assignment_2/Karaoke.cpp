#include "HashTable.h"

enum COMMANDS {ADD, LIST, DELETE, QUIT };

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
