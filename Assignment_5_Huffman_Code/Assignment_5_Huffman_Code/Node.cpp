#include <iostream>
#include "Node.h"

Node::Node(char _data, size_t _frequency)
{
	data = _data;
	frequency = _frequency;
	left = nullptr;
	right = nullptr;
}

Node::~Node()
{
	delete left;
	delete right;
}
