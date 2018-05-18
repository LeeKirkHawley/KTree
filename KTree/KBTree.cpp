#include "stdafx.h"
#include "KBTree.h"


using namespace std;

KBTree::KBTree()
{
	_head = NULL;
}


KBTree::~KBTree()
{
	_head->Remove();
}

void KBTree::Add(int value)
{
	if (_head == NULL)
	{
		KBTreeNode* newNode = new KBTreeNode(value);
		_head = newNode;
	}
	else
	{
		_head->Add(value);
	}
}
