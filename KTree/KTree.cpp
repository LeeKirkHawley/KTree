// KTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "KBTree.h"
#include <string>
#include <list>
#include <iostream>
#include <conio.h>

template <typename T>
void Display(shared_ptr<KBTreeNode<T>>& Node, int Level)
{
	Level++;

	cout << '\n';
	cout << "Level: " << Level << " : " << Node->_value;

	if (Node->_leftChild)
		Display(Node->_leftChild, Level);

	if (Node->_rightChild)
		Display(Node->_rightChild, Level);
}

int main()
{
	//KBTree<int> Tree;
	//Tree.Add(34);
	//Tree.Add(9);
	//Tree.Add(14);
	//Tree.Add(396);
	//Tree.Add(8);

	//KBTreeNode<int>* Node = Tree.FindNode(14);

	KBTree<std::string> Tree;
	Tree.Add("335");
	Tree.Add("les paul");
	Tree.Add("stratocaster");
	Tree.Add("telecaster");
	Tree.Add("sg");

	shared_ptr<KBTreeNode<std::string>> GoodNode = Tree.FindNode("sg");
	cout << "Found node value: " + GoodNode->_value;

	shared_ptr<KBTreeNode<std::string>> BadNode = Tree.FindNode("none");


	//Display(Tree._head, 0);


	cout << "\n\npress any key";
	_getch();

    return 0;
}

