#include "pch.h"
#include "CppUnitTest.h"
#include "..\KTree\KBTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(Added_Node_Should_Be_Found)
		{
			KBTree<std::string> Tree;
			Tree.Add("les paul");

			shared_ptr<KBTreeNode<string>> foundNode = Tree.FindNode("les paul");
			string result = foundNode->_value;
			Assert::AreEqual(result, string("les paul"));
		}

		TEST_METHOD(Removed_Node_Should_Not_Be_Found)
		{
			KBTree<std::string> Tree;
			//Tree.Add("none");  // WRONG - first added node is root!!
			Tree.Add("les paul");

			Tree.RemoveNode("les paul");

			shared_ptr<KBTreeNode<string>> foundNode = Tree.FindNode("les paul");
			Assert::IsTrue(foundNode == nullptr);
		}
	};
}
