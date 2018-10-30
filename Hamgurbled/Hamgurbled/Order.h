/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 4 Hamgurbled
Date Assigned:	10-19-2018
Due Date:		10-29-2018 11:59pm

Description:	This file includes the Order class definitions.

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
#include <iostream>
#include <string>
#include <vector>
#include <ostream>

class Order
{
public:
	/// <summary>
	///		Initializes a new instance of the <see cref="Order"/> class.
	/// </summary>
	Order() { }

	/// <summary>
	///		Initializes a new instance of the <see cref="Order"/> class and copies the specified <see cref="Order"/> class's properties.
	/// </summary>
	/// <param name="_order">
	///		The input order to copy.
	///	</param>
	Order(const Order& _order);

	/// <summary>
	///		Finalizes an instance of the <see cref="Order"/> class.
	/// </summary>
	~Order() { }


	/// <summary>
	///		Sets the start time of the order.
	/// </summary>
	/// <param name="_start">
	///		The time to set.
	///	</param>
	void setStartTime(const int _start);


	/// <summary>
	///		Adds the given item to the order.
	/// </summary>
	/// <param name="_item">
	///		The item to add to the order.
	///	</param>
	void addItem(const std::string _item);
	

	/// <summary>
	///		Comparison of order end times.
	/// </summary>
	/// <param name="_comparisonOrder">
	///		The comparison order.
	///	</param>
	/// <returns>
	///		True or False based on the current order end time and the specified order end time.
	///	</returns>
	const bool operator<(const Order& _comparisonOrder);
	
	///	<summary>
	///		Sends data to the output stream.
	///	</summary>
	///	<param name="_output">
	///		The output stream.
	///	</param>
	///	<param name="_order">
	///		The order used for the output.
	///	</param>
	///	<returns>
	///		The output stream.
	///	</returns>
	friend std::ostream &operator<<(std::ostream &_output, const Order &_order);

private:
	/// <summary>
	///		All the food and/or drinks in the order.
	/// </summary>
	std::vector<std::string> items;

	/// <summary>
	///		The start time of the order.
	/// </summary>
	int startTime = 0;

	/// <summary>
	///		The end time of the order.
	/// </summary>
	int endTime = 0;

	/// <summary>
	///		Gets the cooktime of a specified item.
	/// </summary>
	/// <param name="_item">
	///		The item to check a cooktime for.
	///	</param>
	/// <returns>
	///		The integer cooktime for the specified item.
	///	</returns>
	int getCooktime(std::string _item);
};