#include "Order.h"

void Order::setStartTime(const int _start)
{
	startTime = _start; 
	endTime += startTime;
	return;
}

void Order::addItem(const std::string _item)
{
	order.push_back(_item);
	endTime += getCooktime(_item);
	return;
}

// TODO: Print order details.
void Order::printDetails()
{

	return;
}

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