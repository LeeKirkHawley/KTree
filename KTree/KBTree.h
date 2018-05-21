#pragma once

#include "KBTreeNode.h"
#include <string>

using namespace std;


template<class T> class KBTree
{
private:
	KBTreeNode<int> * _head;

public:
	KBTree<T>()
	{
		_head = NULL;
	};
	~KBTree<T>()
	{
		_head->Remove();
	};

	void Add(int value)
	{
		if (_head == NULL)
		{
			KBTreeNode<T>* newNode = new KBTreeNode<T>(value);
			_head = newNode;
		}
		else
		{
			_head->Add(value);
		}
	}
};

