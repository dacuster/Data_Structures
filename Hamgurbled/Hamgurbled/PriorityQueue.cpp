/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 4 Hamgurbled
Date Assigned:	10-19-2018
Due Date:		10-29-2018 11:59pm

Description:	This file includes the PriorityQueue class declarations.

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

/*
	Create a new instance of a PriorityQueue.
*/
PriorityQueue::PriorityQueue(int _orderSize)
{
	orderSize = _orderSize;
	orders = new Order [orderSize];
}

/*
	Enqueue a new order.
*/
void PriorityQueue::enqueue(Order _order)
{
	orders[currentOrder] = _order;
	currentOrder++;
}

/* 
	Dequeue an order from the queue.
*/
Order PriorityQueue::dequeue()
{
	int size = (orderSize < 1 ? 0 : --orderSize);

	// Create a temporary orders queue for resizing.
	Order* tempOrders = new Order[size];
	// Store the first order in the queue before it's removed.
	Order returnOrder = orders[0];

	// Copy all the orders in the old queue to the temporary queue starting with the second order.
	for (int _currentOrder = 0; _currentOrder < orderSize; _currentOrder++)
	{
		tempOrders[_currentOrder] = orders[_currentOrder + 1];
	}

	// Decrease last order location.
	currentOrder--;
	// Deallocate memory from the old orders.
	delete[] orders;
	// Assign the temporary queue to the actual queue.
	orders = tempOrders;

	// Return the first order from the original queue.
	return returnOrder;
}

/*
	Swap the parent node with its smallest child if either child is smaller than the parent.
*/
void PriorityQueue::sort(int _currentNode)
{
	// Get the left and right child locations.
	int left = 2 * _currentNode + 1;
	int right = 2 * _currentNode + 2;
	// Assign the smallest node as the parent.
	int smallest = _currentNode;

	// The left child is smaller than the parent.
	if (left < orderSize && orders[left] < orders[_currentNode])
	{
		smallest = left;
	}

	// The right child is smaller than the parent.
	if (right < orderSize && orders[right] < orders[smallest])
	{
		smallest = right;
	}

	// Swap the elements if its not the parent and re-sort at the child location.
	if (smallest != _currentNode)
	{
		std::swap(orders[smallest], orders[_currentNode]);
		sort(smallest);
	}

	return;
}

/*
	Build a priority queue starting with the deepest right most non-leaf node.
*/
void PriorityQueue::build()
{
	for (int currentNode = orderSize / 2 - 1; currentNode >= 0; currentNode--)
	{
		sort(currentNode);
	}
}

/*
	Print the queue.
*/
void PriorityQueue::printQueue()
{
	// Assign the queue size to a variable since it will decrease as orders are dequeued.
	int totalSize = orderSize;

	// Dequeue orders and rebuild the priority queue.
	for (int queueCounter = 0; queueCounter < totalSize; queueCounter++)
	{
		std::cout << dequeue() << std::endl;
		build();
	}
}