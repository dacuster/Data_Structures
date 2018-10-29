#include "Order.h"
#include "PriorityQueue.h"

#include <fstream>
#include "Gurbled.h"

const std::string FILENAME = "orders.txt";

int main()
{

	std::fstream file(FILENAME);

	if (file.is_open())
	{
		int testCases = 0;
		file >> testCases;

		PriorityQueue orders = NULL;

		for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
		{
			int numberOfOrders = 0;
			file >> numberOfOrders;

			orders = PriorityQueue(numberOfOrders);

			insertOrders(orders, numberOfOrders, file);

			std::cout << "---------------------TEST CASE " << caseNumber << "------------------------" << std::endl;

		}
	}
	else
	{
		std::cout << "Error opening file." << std::endl;
	}

	std::string input;
	std::cin >> input;

	return 0;
}

// TODO: Check that this function is completed.
void insertOrders(PriorityQueue& _orders, int _numberOfOrders, std::fstream& _stream)
{
	int numberOfItems = 0;

	for (int currentOrder = 0; currentOrder < _numberOfOrders; currentOrder++)
	{
		_stream >> numberOfItems;
		_orders.enqueue(readOrder(numberOfItems, _stream));
	}

	return;
}

// TODO: Finish implementing.
Order readOrder(int _numberOfItems, std::fstream& _stream)
{
	Order order;

	for (int currentItem = 0; currentItem < _numberOfItems; currentItem++)
	{

	}

	return order;
}