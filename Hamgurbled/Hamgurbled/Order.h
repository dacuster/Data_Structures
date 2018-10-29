#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ostream>

class Order
{
public:
	Order() { }
	~Order() { }

	void setStartTime(const int _start);

	void addItem(const std::string _item);

	const int getEndTime() { return endTime; }
	const int getStartTime() { return startTime; }
	
	const bool operator<(const Order& _comparisonOrder) { return this->endTime < _comparisonOrder.endTime; }


	friend std::ostream &operator<<(std::ostream &_output, const Order &_order);

private:
	std::vector<std::string> items;
	int startTime;
	int endTime;

	int getCooktime(std::string _item);
};

