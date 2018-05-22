#pragma once

#include "KBTreeNode.h"
#include <string>
#include <list>
#include <memory>

using namespace std;


template<class T> class KBTree
{
private:
	KBTreeNode<T>* FindNode(unique_ptr<KBTreeNode<T>>& Node, T value)
	{
		if (Node->_value == value)
			return Node.get();

		if (Node->_value > value)
		{
			if (Node->_leftChild != NULL)
				return FindNode(Node->_leftChild, value);
			else
				return NULL;
		}
		else
		{
			if (Node->_rightChild != NULL)
				return FindNode(Node->_rightChild, value);
			else
				return NULL;
		}
	}


public:
	unique_ptr<KBTreeNode<T>> _head;

	KBTree<T>()
	{
		_head = NULL;
	};
	~KBTree<T>()
	{
	};

	void Add(T value)
	{
		if (_head == NULL)
		{
			_head = make_unique<KBTreeNode<T>>(value);
		}
		else
		{
			_head->Add(value);
		}
	}
	
	KBTreeNode<T>* FindNode(T value)
	{
		return FindNode(_head, value);
	}


};

