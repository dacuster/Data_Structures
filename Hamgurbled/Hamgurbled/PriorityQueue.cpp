#include "Order.h"
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int _orderSize)
{
	orderSize = _orderSize;
	orders = new Order[orderSize];
}

void PriorityQueue::enqueue(Order _order)
{
	orders[currentOrder] = _order;
	currentOrder++;
}

/* TODO:
	Check if this works with deletion and reassigning the pointer.
*/
Order PriorityQueue::dequeue()
{
	int size = (orderSize < 1 ? 0 : --orderSize);

	Order* tempOrders = new Order[--orderSize];
	Order returnOrder = orders[0];

	for (int _currentOrder = 0; _currentOrder < orderSize; _currentOrder++)
	{
		tempOrders[_currentOrder] = orders[_currentOrder + 1];
	}

	currentOrder--;
	delete[] orders;
	orders = tempOrders;

	return returnOrder;
}

// TODO: Add sort function from board.
void PriorityQueue::sort()
{

}

// TODO: Add build function from board.
void PriorityQueue::build()
{

}

// TODO: dequeue deallocates memory. Is this still needed?
void PriorityQueue::clearQueue()
{
	delete[] orders;
}