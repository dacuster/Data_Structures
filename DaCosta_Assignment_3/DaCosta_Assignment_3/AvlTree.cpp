#include "AvlTree.h"


/// <summary>
/// Initializes a new instance of the <see cref="AvlTree"/> class.
/// </summary>
/// <param name="_newNode">The new node.</param>
/// TODO Edit XML Comment Template for AvlTree
AvlTree::AvlTree(Node* _newNode)
{
	pRoot = _newNode;
}

/// <summary>
/// Finalizes an instance of the <see cref="AvlTree"/> class.
/// </summary>
/// TODO Edit XML Comment Template for ~AvlTree
AvlTree::~AvlTree()
{

}

void AvlTree::addNode(Node* _newNode)
{
	Node* tempNode = pRoot;

	while (tempNode != nullptr)
	{
		if (tempNode < _newNode)
		{

		}
	}
}