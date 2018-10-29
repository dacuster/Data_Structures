#include "Order.h"

void Order::setStartTime(const int _start)
{
	startTime = _start; 
	endTime += startTime;
	return;
}

void Order::addItem(const std::string _item)
{
	items.push_back(_item);
	endTime += getCooktime(_item);
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

std::ostream & operator<<(std::ostream & _output, const Order & _order)
{
	_output << _order.startTime << " " << _order.endTime;

	for (size_t currentItem = 0; currentItem < _order.items.size(); currentItem++)
	{
		_output << " " << _order.items[currentItem];
	}

	return _output;
}
