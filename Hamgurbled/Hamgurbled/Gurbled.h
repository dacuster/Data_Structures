/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 4 Hamgurbled
Date Assigned:	10-19-2018
Due Date:		10-29-2018 11:59pm

Description:	This file includes the Gurbled definitions.

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

/// <summary>
///		Inserts the orders from the file into a queue.
/// </summary>
/// <param name="_orders">
///		The orders queue.
///	</param>
/// <param name="_numberOfOrders">
///		The number of orders.
///	</param>
/// <param name="_stream">
///		The file stream.
///	</param>
void insertOrders(PriorityQueue& _orders, int _numberOfOrders, std::fstream & _stream);

/// <summary>
///		Reads the orders from the file and creates an order object.
/// </summary>
/// <param name="_numberOfItems">
///		The number of items.
///	</param>
/// <param name="_stream">
///		The file stream.
///	</param>
///	<returns>
///		A new order from the read file.
///	</returns>
Order readOrder(int _numberOfItems, std::fstream & _stream);