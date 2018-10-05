/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 3 AVL Tree Sloth
Date Assigned:	09-28-2018
Due Date:		10-04-2018 11:59pm

Description:	This file includes the AvlTree class function declarations.

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

#include "AvlTree.h"


AvlTree::AvlTree(Node* _newNode)
{
	pRoot = _newNode;
}

AvlTree::~AvlTree()
{
	delete pRoot;
}

void AvlTree::addNode(int _value)
{

	if (pRoot == nullptr)
	{
		pRoot = new Node(_value);
		return;
	}
	else
	{
		Node *newNode = new Node(_value);
		pRoot->increment();
		newNode > pRoot ? addRight(pRoot->getRight(), newNode) : addLeft(pRoot->getLeft(), newNode);
	}
}

void AvlTree::addRight(Node*& _currentNode, Node*& _right)
{
	if (_currentNode == nullptr)
	{
		_currentNode = _right;
	}
	else
	{
		_currentNode->increment();
		_right > _currentNode ? addRight(_currentNode->getRight(), _right) : addLeft(_currentNode->getLeft(), _right);
	}
}

void AvlTree::addLeft(Node*& _currentNode, Node*& _left)
{
	if (_currentNode == nullptr)
	{
		_currentNode = _left;
	}
	else
	{
		_currentNode->increment();
		_left > _currentNode ? addRight(_currentNode->getRight(), _left) : addLeft(_currentNode->getLeft(), _left);
	}
}

bool AvlTree::shouldDelete() const
{
	int rightHeight = 0,
		leftHeight = 0;

	if (pRoot->getRight() != nullptr)
	{
		rightHeight = pRoot->getRight()->getHeight();
	}
	if (pRoot->getLeft() != nullptr)
	{
		leftHeight = pRoot->getLeft()->getHeight();
	}
	return abs(rightHeight - leftHeight) > 1;
}