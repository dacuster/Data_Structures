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
	///		Initializes a new instance of the <see cref="AvlTree"/> class.
	/// </summary>
	/// TODO Edit XML Comment Template for AvlTree
	AvlTree() {	}

	/// <summary>
	///		Initializes a new instance of the <see cref="AvlTree"/> class.
	/// </summary>
	/// <param name="_newNode">
	///		The new node.
	///	</param>
	/// TODO Edit XML Comment Template for AvlTree
	AvlTree(Node* _newNode);

	/// <summary>
	///		Finalizes an instance of the <see cref="AvlTree"/> class.
	/// </summary>
	/// TODO Edit XML Comment Template for ~AvlTree
	~AvlTree();

	/// <summary>
	///		Adds the node.
	/// </summary>
	/// <param name="_newNode">
	///		The new node.
	///	</param>
	/// TODO Edit XML Comment Template for addNode
	void addNode(Node* _newNode);


private:
	/// <summary>
	///		The root node.
	/// </summary>
	Node* pRoot = nullptr;

	/// <summary>
	///		Was the node added to the right previously?
	/// </summary>
	bool addedRight = false;

	/// <summary>
	///		Was the node added to the left previously?
	/// </summary>
	bool addedLeft = false;

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
	Node() {}

	/// <summary>
	///		Initializes a new instance of the <see cref="Node"/> class.
	/// </summary>
	/// <param name="_value">
	///		The value.
	///	</param>
	Node(int _value)
	{
		value = _value;
	}

	/// <summary>
	///		Memory clean up of an instance of the <see cref="Node"/> class.
	/// </summary>
	~Node()	{}

	/// <summary>
	///		Gets the right node.
	/// </summary>
	/// <returns>
	///		Node.
	///	</returns>
	Node& getRight() const
	{
		return *pRight;
	}
	/// <summary>
	///		Gets the left node.
	/// </summary>
	/// <returns>
	///		Node.
	///	</returns>
	Node& getLeft()  const
	{
		return *pLeft;
	}

	/// <summary>
	///		Check if the value of the left node is greater than the right node.
	/// </summary>
	/// <param name="_right">
	///		The right-hand comparison node.
	///	</param>
	/// <returns>
	///		Boolean.
	///	</returns>
	bool operator> (Node& _right)
	{
		return value > _right.value;
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
	///		The node's value.
	/// </summary>
	int value;
};