/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 4 Hamgurbled
Date Assigned:	10-19-2018
Due Date:		10-29-2018 11:59pm

Description:	This file includes the PriorityQueue class definitions.

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

#pragma once

class PriorityQueue
{
public:
	/// <summary>
	///		Initializes a new instance of the <see cref="PriorityQueue"/> class.
	/// </summary>
	PriorityQueue()	{ }

	/// <summary>
	///		Initializes a new instance of the <see cref="PriorityQueue"/> class with an order size.
	/// </summary>
	/// <param name="_orderSize">
	///		The size of the order.
	///	</param>
	PriorityQueue(int _orderSize);
	
	/// <summary>
	///		Finalizes an instance of the <see cref="PriorityQueue"/> class.
	/// </summary>
	~PriorityQueue() { delete[] orders;	}


	/// <summary>
	///		Enqueues the specified order.
	/// </summary>
	/// <param name="_order">
	///		The order to add.
	///	</param>
	void enqueue(Order _order);
	
	/// <summary>
	///		Dequeues the first order in the queue, shrinks, and re-prioritizes it.
	/// </summary>
	/// <returns>
	///		The first order in the queue.
	///	</returns>
	Order dequeue();


	/// <summary>
	///		Swaps the smallest child node with the parent node if either child is smaller than the parent.
	/// </summary>
	/// <param name="_currentNode">
	///		The parent node.
	///	</param>
	void sort(int _currentNode);
	
	/// <summary>
	///		Builds a priority queue starting with the deepest right most non-leaf node and works towards the root.
	/// </summary>
	void build();


	/// <summary>
	///		Prints the queue.
	/// </summary>
	void printQueue();

private:
	/// <summary>
	///		The orders in the queue.
	/// </summary>
	Order* orders;
	
	/// <summary>
	///		The total number of orders.
	/// </summary>
	int orderSize = 0;
	
	/// <summary>
	///		The location of the last order.
	/// </summary>
	int currentOrder = 0;
};