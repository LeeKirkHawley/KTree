#pragma once

#include "KBTreeNode.h"
#include <string>
#include <list>
#include <memory>

using namespace std;


template<class T> class KBTree
{
private:

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
};

