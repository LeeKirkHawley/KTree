#pragma once

#include <string>
#include <memory>

using namespace std;

template<typename T> class KBTreeNode
{
private:

public:
	T _value;
	unique_ptr<KBTreeNode<T>> _leftChild;
	unique_ptr<KBTreeNode<T>> _rightChild;

	KBTreeNode<T>(T value)
	{
		_value = value;
		_leftChild = NULL;
		_rightChild = NULL;
	};

	~KBTreeNode<T>()
	{
		cout << "\nDeleting " << _value;
	}

	void Add(T Value)
	{
		if (Value == _value)
			return;

		if (Value < _value)
		{
			if (_leftChild == NULL)
			{
				_leftChild = make_unique<KBTreeNode<T>>(Value);
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
				_rightChild = make_unique<KBTreeNode<T>>(Value);
				return;
			}
			else
			{
				_rightChild->Add(Value);
				return;
			}
		}
	}

};

