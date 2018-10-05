/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 3 AVL Tree Sloth
Date Assigned:	09-28-2018
Due Date:		10-04-2018 11:59pm

Description:	This file includes the main function.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment: Reproduce this
assignment and provide a copy to another member of academic staff; and/or
Communicate a copy of this assignment to a plagiarism checking service (which
may then retain a copy of this assignment on its database for the purpose of
future plagiarism checking).
*/

#include "AvlTree.h"
#include <fstream>
#include <string>

#define FILE_NAME "trees.txt"

/// <summary>
/// Reads an input file and performs a certain amount of test cases. <br/>
///	Creates a new AVL Tree for each test and adds nodes to it. <br/>
///	The tree is then tested to see if it is balanced.
/// </summary>
int main()
{
	std::fstream inputFile(FILE_NAME);

	int testCaseNumber = 0;

	inputFile >> testCaseNumber;

	for (int caseCounter = 1; caseCounter <= testCaseNumber; caseCounter++)
	{
		AvlTree newTree = AvlTree();
		int nodeValue = NULL;
		int totalNodes = 0;
		inputFile >> totalNodes;

		std::cout << "Tree #" << caseCounter << ": ";

		for (int nodeCount = 0; nodeCount < totalNodes; nodeCount++)
		{
			inputFile >> nodeValue;
			newTree.addNode(nodeValue);
		}

		if (newTree.shouldDelete())
		{
			std::cout << "REMOVE" << std::endl;
		}
		else
		{
			std::cout << "KEEP" << std::endl;
		}
	}
	
	inputFile.close();

	std::cout << "Enter a character to close the console..." << std::endl;

	std::string input;

	std::cin >> input;

	return 0;
}