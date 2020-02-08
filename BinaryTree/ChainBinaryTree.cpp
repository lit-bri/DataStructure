#include "ChainBinaryTree.h"

#include <iostream>
using namespace std;

void ChainBinaryTree::debug()
{
	cout << "ChainBinaryTreeTest:" << endl;
	cout << "准备假定数据..." << endl;
	InitInfo initInfo;
	for (int i = 1; i <= 20; i++)
	{
		CustomInfo customInfo;
		switch (i)
		{
		case 4:
		case 5:
		case 7:
		case 8:
		case 10:
		case 13:
		case 14:
		case 15:
		{
			customInfo.isNull = true;
		}
			break;
		default:
			customInfo.id = i;
			customInfo.isNull = false;
			break;
		}
		initInfo.info.push_back(customInfo);
	}
	init(initInfo);

	cout << endl;
	cout << "1.空树？" << endl;
	cout <<" "<< isEmpty() << endl;
	cout << "2.深度/层次？" << endl;
	cout <<" "<< getDepth(_cbt.root) << endl;
	ChainTraverse(TraverseType::PreOrder);
	ChainTraverse(TraverseType::InOrder);
	ChainTraverse(TraverseType::PostOrder);
}

void ChainBinaryTree::ChainTraverse(TraverseType type)
{
	if (isEmpty())
	{
		return;
	}
	cout << endl;
	switch (type)
	{
	case ChainBinaryTree::LevelOrder:
	{

	}
		break;
	case ChainBinaryTree::PreOrder:
	{
		cout << "PreOrderTraverse:" << endl;
	}
		break;
	case ChainBinaryTree::InOrder:
	{
		cout << "InOrderTraverse:" << endl;
	}
		break;
	case ChainBinaryTree::PostOrder:
	{
		cout << "PostOrderTraverse:" << endl;
	}
		break;
	default:
		break;
	}
	ChainRecurve(_cbt.root, type);
}

void ChainBinaryTree::ChainRecurve(TNode* &node, TraverseType type)
{
	if (type == ChainBinaryTree::TraverseType::PreOrder)
		std::cout << node->info.id <<" ";
	if (node->lchild)
	{
		ChainRecurve(node->lchild, type);
	}
	if (type == ChainBinaryTree::TraverseType::InOrder)
	{
		std::cout << node->info.id << " ";
	}
	if (node->rchild)
	{
		ChainRecurve(node->rchild, type);
	}
	if (type == ChainBinaryTree::TraverseType::PostOrder)
	{
		std::cout << node->info.id << " ";
	}
}

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
	if (_cbt.root)
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
	return NULL;
}

bool ChainBinaryTree::init(InitInfo& initInfo)
{
	int i = 0;
	initRecurve(_cbt.root, initInfo.info);
	return true;
}

void ChainBinaryTree::initRecurve(TNode* &tree, std::vector<CustomInfo>& info)
{

	if (info.begin()== info.end())
	{
		return;
	}
	if (info[0].isNull)
	{
		info.erase(info.begin());
		return;
	}

	//Note:malloc申请的内存不会初始化；
	//method1:
	tree = (TNode*)calloc(1,sizeof(TNode));
	//method2:
	//tree = (TNode*)malloc(sizeof(TNode));
	//tree->lchild = NULL;
	//tree->rchild = NULL;
	if (!tree)
	{
		return;
	}
	(*tree).info = info[0];
	info.erase(info.begin());
	initRecurve(tree->lchild, info );
	initRecurve(tree->rchild, info);
}

void ChainBinaryTree::clear(TNode*  &node)
{
	if (!node)
	{
		return;
	}
	if (node->lchild)
	{
		clear(node->lchild);
	}
	if (node->rchild)
	{
		clear(node->rchild);
	}
	free(node);
	node = NULL;
}
