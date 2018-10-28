#pragma once

void insertOrders(PriorityQueue & _orders, int _numberOfOrders, std::fstream & _stream);

Order readOrder(int _numberOfItems, std::fstream & _stream);