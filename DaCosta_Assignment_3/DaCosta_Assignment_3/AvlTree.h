/*
Author(s):		Nick DaCosta
Class:			CSI-281-03
Assignment:		Assignment 3 AVL Tree Sloth
Date Assigned:	09-28-2018
Due Date:		10-04-2018 11:59pm

Description:	This file includes the AvlTree and Node class function definitions.

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

#pragma once
#include <iostream>

/*
	Declare classes.
*/
class AvlTree;
class Node;

/// <summary>
///		AVL Tree class.
/// </summary>
class AvlTree
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="AvlTree"/> class.
	/// </summary>
	AvlTree()
	{

	}

	/// <summary>
	/// Initializes a new instance of the <see cref="AvlTree"/> class.
	/// </summary>
	/// <param name="_newNode">
	///		The root node.
	///	</param>
	AvlTree(Node* _newNode);

	/// <summary>
	/// Finalizes an instance of the <see cref="AvlTree"/> class.
	/// </summary>
	~AvlTree();

	/// <summary>
	///		Set the root as a new node or check which direction to add the new node.
	/// </summary>
	/// <param name="_value">
	///		The node data value.
	///	</param>
	void addNode(int _value);
	
	/// <summary>
	///		Attemt to add a new node to the left of the current node.
	/// </summary>
	/// <param name="_currentNode">
	///		The current node.
	///	</param>
	/// <param name="_right">
	///		The new node to add.
	///	</param>
	void addRight(Node*& _currentNode, Node*& _right);

	/// <summary>
	///		Attemt to add a new node to the left of the current node.
	/// </summary>
	/// <param name="_currentNode">
	///		The current node.
	///	</param>
	/// <param name="_left">
	///		The new node to add.
	///	</param>
	void addLeft(Node*& _currentNode, Node*& _left);

	/// <summary>
	///		Checks if the difference between the right and left nodes of the root is greater than 1.
	/// </summary>
	/// <returns>
	///		Boolean.
	///	</returns>
	bool shouldDelete() const;


private:
	/// <summary>
	///		The root node of the tree.
	/// </summary>
	Node* pRoot = nullptr;
};

/// <summary>
///		Tree nodes.
/// </summary>
class Node
{
public:
	/// <summary>
	///		Initializes a new instance of the <see cref="Node"/> class.
	/// </summary>
	Node()
	{

	}

	/// <summary>
	///		Initializes a new instance of the <see cref="Node"/> class.
	/// </summary>
	/// <param name="_value">
	///		The data value.
	///	</param>
	Node(int _value)
	{
		value = _value;

	}

	/// <summary>
	///		Finalizes an instance of the <see cref="Node"/> class.
	/// </summary>
	~Node()
	{
		delete pRight;
		delete pLeft;
	}

	/// <summary>
	///		Gets the right tree node.
	/// </summary>
	/// <returns>
	///		Node pointer reference.
	///	</returns>
	Node*& getRight()
	{
		return pRight;
	}

	/// <summary>
	///		Gets the left tree node.
	/// </summary>
	/// <returns>
	///		Node pointer reference.
	///	</returns>
	Node*& getLeft()
	{
		return pLeft;
	}

	/// <summary>
	///		Gets the data value.
	/// </summary>
	/// <returns>
	///		Integer.
	///	</returns>
	int getValue() const
	{
		return value;
	}

	/// <summary>
	///		Gets the node height.
	/// </summary>
	/// <returns>
	///		Integer.
	///	</returns>
	int getHeight() const
	{
		return height;
	}

	/// <summary>
	///		Compares data values.
	/// </summary>
	/// <param name="_right">
	///		The right-hand node.
	///	</param>
	/// <returns>
	///		Boolean.
	///	</returns>
	bool operator> (Node& _right)
	{
		return value > _right.value;
	}

	/// <summary>
	///		Increments the height of this node.
	/// </summary>
	void increment()
	{
		height++;
	}

private:
	/// <summary>
	///		The right node.
	/// </summary>
	Node* pRight = nullptr;

	/// <summary>
	///		The left node.
	/// </summary>
	Node* pLeft = nullptr;

	/// <summary>
	/// The node's height in the tree.
	/// </summary>
	int height;

	/// <summary>
	///		The data value.
	/// </summary>
	int value;
};