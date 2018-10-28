#pragma once
#include <iostream>
#include <string>
#include <vector>

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

	void printDetails();	

private:
	std::vector<std::string> order;
	int startTime;
	int endTime;

	int getCooktime(std::string _item);
};

