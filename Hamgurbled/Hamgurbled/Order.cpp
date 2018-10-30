/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 4 Hamgurbled
Date Assigned:	10-19-2018
Due Date:		10-29-2018 11:59pm

Description:	This file includes the Order class declarations.

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

/*
	Order copy constructor.
*/
Order::Order(const Order & _order)
{
	startTime = _order.startTime;
	endTime = _order.endTime;
	items = _order.items;
}

/*
	Set the start time of the order and add it to the end time.
*/
void Order::setStartTime(const int _start)
{
	startTime = _start; 
	endTime += startTime;
	return;
}

/*
	Add a food or drink to the order.
	Increase the end time of the order based on the cooktime of the item.
*/
void Order::addItem(const std::string _item)
{
	items.push_back(_item);
	endTime += getCooktime(_item);
	return;
}

/*
	Compare the end time of the current order to the end time of the specified order.
*/
const bool Order::operator<(const Order& _comparisonOrder)
{
	return this->endTime < _comparisonOrder.endTime;
}

/*
	Get the cooktime of the specified food or drink.
*/
int Order::getCooktime(std::string _item)
{
	if (_item == "Whobber")
	{
		return 5;
	}
	else if (_item == "double_Whobber_with_bees")
	{
		return 7;
	}
	else if (_item == "dingo_nuggets")
	{
		return 4;
	}
	else if (_item == "bonbons")
	{
		return 1;
	}
	else if (_item == "dr_pebber")
	{
		return 1;
	}
	else if (_item == "pebsi")
	{
		return 2;
	}

	return 0;
}

/*
	Add data from a specified order to a specified output stream and return the stream.
*/
std::ostream & operator<<(std::ostream & _output, const Order & _order)
{
	_output << _order.startTime << " " << _order.endTime;

	// Print each item in the order.
	for (size_t currentItem = 0; currentItem < _order.items.size(); currentItem++)
	{
		_output << " " << _order.items[currentItem];
	}
	return _output;
}
