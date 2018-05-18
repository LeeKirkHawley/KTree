#pragma once

#include <string>

using namespace std;

class KBTreeNode
{
private:

public:
	int _value;
	KBTreeNode * _leftChild;
	KBTreeNode* _rightChild;

	KBTreeNode(int value)
	{
		_value = value;
		_leftChild = NULL;
		_rightChild = NULL;
	}

	void Add(int Value)
	{
		if (Value == _value)
			return;

		if (Value < _value)
		{
			if (_leftChild == NULL)
			{
				_leftChild = new KBTreeNode(Value);
				return;
			}
			else
			{
				_leftChild->Add(Value);
				return;
			}
		}
		else if (Value > _value)
		{
			if (_rightChild == NULL)
			{
				_rightChild = new KBTreeNode(Value);
				return;
			}
			else
			{
				_rightChild->Add(Value);
				return;
			}
		}
	}

	void Remove()
	{
		if (_leftChild != NULL)
		{
			_leftChild->Remove();
			_leftChild = NULL;
		}

		if (_rightChild != NULL)
		{
			_rightChild->Remove();
			_rightChild = NULL;
		}
	
		delete this;
	}
};

class KBTree
{
private:
	KBTreeNode * _head;

public:
	KBTree();
	virtual ~KBTree();

	void Add(int value);
};

