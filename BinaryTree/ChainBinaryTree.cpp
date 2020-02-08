#include "ChainBinaryTree.h"

#include <iostream>

//Get
ChainBinaryTree::ResultType ChainBinaryTree::getRootNode(TNode& node)
{
	if (_cbt.root)
	{
		node = *_cbt.root;
		return ChainBinaryTree::ResultType::FIND;
	}
	else
		return ChainBinaryTree::ResultType::TREE_EMPTY;
}
int ChainBinaryTree::getDepth(TNode* node)
{
	int leftChildTreeDepth, rightChildTreeDepth;
	if (!node)
		return 0;
	if (node->lchild)
		leftChildTreeDepth = getDepth(node->lchild);
	else
		leftChildTreeDepth = 0;

	if (node->rchild)
		rightChildTreeDepth = getDepth(node->rchild);
	else
		rightChildTreeDepth = 0;
	return leftChildTreeDepth > rightChildTreeDepth?++leftChildTreeDepth:++rightChildTreeDepth;
}
//Judge
bool ChainBinaryTree::isEmpty()
{
	if (node)
		return false;
	else
		return true;
}

//Base
ChainBinaryTree* ChainBinaryTree::create()
{
	ChainBinaryTree* cbTree = new ChainBinaryTree();
	if (cbTree)
	{
		return cbTree;
	};
	return nullptr;
}

bool ChainBinaryTree::init(InitInfo& initInfo)
{
	int i = 0;
	initRecurve(_cbt.root, initInfo.info, i);
	return true;
}

void ChainBinaryTree::initRecurve(TNode* tree, std::vector<CustomInfo>& info, int index)
{

	if (info.size == index)
	{
		std::cout << "initRecurveFinish! " << std::endl;
		return;
	}
	if (info[index].isNull)
	{
		return;
	}
	tree = (TNode*)malloc(sizeof(TNode));
	if (!tree)
	{
		static_assert(!tree);
		return;
	}
	(*tree).info = info[index];
	initRecurve(tree->lchild, info, ++ index);
	initRecurve(tree->rchild, info, ++index);
}
