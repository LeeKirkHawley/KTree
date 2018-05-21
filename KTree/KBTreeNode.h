#pragma once

#include <string>

using namespace std;

template<typename T> class KBTreeNode
{
private:

public:
	T _value;
	KBTreeNode<T> * _leftChild;
	KBTreeNode<T>* _rightChild;

	KBTreeNode<T>(int value)
	{
		_value = value;
		_leftChild = NULL;
		_rightChild = NULL;
	};

	void Add(T Value)
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

