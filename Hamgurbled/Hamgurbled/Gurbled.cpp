/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 4 Hamgurbled
Date Assigned:	10-19-2018
Due Date:		10-29-2018 11:59pm

Description:	This file includes the main function and Gurbled declarations.

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

#include "Order.h"
#include "PriorityQueue.h"

#include <fstream>
#include "Gurbled.h"

// The file to read from.
const std::string FILENAME = "orders.txt";

int main()
{
	// Create a file stream and open it.
	std::fstream file(FILENAME);

	// Make sure the file opened.
	if (file.is_open())
	{
		int testCases = 0;
		// Read the number of test cases.
		file >> testCases;

		// Loop through each test case.
		for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
		{
			int numberOfOrders = 0;
			// Read the number of order.
			file >> numberOfOrders;

			// Create a new queue of orders with a specified size.
			PriorityQueue orders(numberOfOrders);

			// Insert order from the file to the queue.
			insertOrders(orders, numberOfOrders, file);

			// Print a test case header.
			std::cout << "---------------------TEST CASE " << caseNumber << "------------------------" << std::endl;

			// Build the priority queue.
			orders.build();

			// Print the queue.
			orders.printQueue();
		}
	}
	// There was an error opening the file.
	else
	{
		std::cout << "Error opening file." << std::endl;
	}

	// Promt the user to close the application.
	std::cout << std::endl << "Input a character and press enter to continue..." << std::endl;
	std::string input;
	std::cin >> input;

	return 0;
}

/*
	Insert orders from the file into a queue.
*/
void insertOrders(PriorityQueue& _orders, int _numberOfOrders, std::fstream& _stream)
{
	int numberOfItems = 0;

	// Read orders line by line from the file.
	for (int currentOrder = 0; currentOrder < _numberOfOrders; currentOrder++)
	{
		_stream >> numberOfItems;
		_orders.enqueue(readOrder(numberOfItems, _stream));
	}
	return;
}

/*
	Read the order information from the file.
*/
Order readOrder(int _numberOfItems, std::fstream& _stream)
{
	Order order;
	std::string item;
	int start;

	// Add the current order's items from the file to an order.
	for (int currentItem = 0; currentItem < _numberOfItems; currentItem++)
	{
		_stream >> item;
		order.addItem(item);
	}

	// Get the start time of the order.
	_stream >> start;

	// Set the start time of the order.
	order.setStartTime(start);

	// Return the newly created order.
	return order;
}