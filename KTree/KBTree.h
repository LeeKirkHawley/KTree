#pragma once

#include "KBTreeNode.h"
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <assert.h>
//#include <cstddef>

using namespace std;


template<class T> class KBTree
{
private:
	unique_ptr<KBTreeNode<T>>& FindNode(unique_ptr<KBTreeNode<T>>& Parent, T value)
	{
		if (Parent->_value == value)
			return Parent;

		if (Parent->_value > value)
		{
			if (Parent->_leftChild != NULL)
				return FindNode(Parent->_leftChild, value);
			else
				throw;
		}
		else
		{
			if (Parent->_rightChild != NULL)
				return FindNode(Parent->_rightChild, value);
			else
				throw;
		}
	}


public:
	unique_ptr<KBTreeNode<T>> _root;

	KBTree<T>()
	{
		_root = NULL;
	};
	~KBTree<T>()
	{
	};

	void Add(T value)
	{
		if (_root == NULL)
		{
			_root = make_unique<KBTreeNode<T>>(value);
		}
		else
		{
			_root->Add(value);
		}
	}
	
	unique_ptr<KBTreeNode<T>>& FindNode(T value)
	{
		return FindNode(_root, value);
	}

	void RemoveNode(unique_ptr<KBTreeNode<T>>& Parent, T value)
	{
		if (Parent->_leftChild->_value == value)
		{
			unique_ptr<KBTreeNode<T>>& NodeToDelete = Parent->_leftChild;
			if (NodeToDelete->_leftChild == nullptr && NodeToDelete->_rightChild == nullptr)  // it's a leaf
			{
				Parent->_leftChild = nullptr;
				NodeToDelete->reset(nullptr);
			}
			return;
		}

		if (Parent->_rightChild->_value == value)
		{
			unique_ptr<KBTreeNode<T>>& NodeToDelete = Parent->_rightChild;
			if (NodeToDelete->_leftChild == nullptr && NodeToDelete->_rightChild == nullptr)  // it's a leaf
			{
				Parent->_rightChild = nullptr;
				NodeToDelete->reset();
			}
			return;
		}

		//if (Parent->_value > value)
		//{
		//	if (Parent->_leftChild != NULL)
		//		return FindNode(Parent->_leftChild, value);
		//	else
		//		throw;
		//}
		//else
		//{
		//	if (Parent->_rightChild != NULL)
		//		return FindNode(Parent->_rightChild, value);
		//	else
		//		throw;
		//}

	}

	void RemoveNode(T value)
	{
		if (_root->_value == value)   // don't know parent, might be root
			throw;

		RemoveNode(_root, value);
	}

	vector<string> BuildLevelList()
	{
		vector<string> Levels;

		BuildLevelString(Levels, _root, 0);

		return Levels;
	}

		void BuildLevelString(vector<string>& Levels, unique_ptr<KBTreeNode<T>>& Parent, int Level)
	{
		assert(Level >= 0);

		int ListHeight = Levels.size();
		if (ListHeight <= Level)
			Levels.push_back("");

		int LineLength = 20;
		LineLength /= (Level + 1);  // no zeroes eh!

		for(int i = 0;i < LineLength;i++)
			Levels[Level].append("-");

		Levels[Level].append(Parent->_value);
		for (int i = 0; i < LineLength; i++)
			Levels[Level].append("-");

		if (Parent->_leftChild)
			BuildLevelString(Levels, Parent->_leftChild, Level + 1);

		if (Parent->_rightChild)
			BuildLevelString(Levels, Parent->_rightChild, Level + 1);
	}
};

