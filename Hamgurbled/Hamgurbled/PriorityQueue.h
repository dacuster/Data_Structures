#pragma once

class PriorityQueue
{
public:
	PriorityQueue(){ }
	PriorityQueue(int _orderSize);
	~PriorityQueue() { delete[] orders; }

	void enqueue(Order _order);
	Order dequeue();

	void sort();
	void build();

	void clearQueue();

private:
	Order* orders = nullptr;
	int orderSize = 0;
	int currentOrder = 0;
};