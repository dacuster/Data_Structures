#include <iostream>
#include "Node.h"

Node::Node(char _data)
{
	data = _data;
	frequency = 1;
	left = nullptr;
	right = nullptr;
}

Node::~Node()
{
	delete left;
	delete right;
}
