#include "OrderBinaryTree.h"
#include "../../VirtualWorld/Utils/VWDebug.h"

using namespace std;

//
void OrderBinaryTree::debug()
{
	//Assume Data
	OrderBinaryTree::CreateInfo info;
	for (int i = 1; i <= 16; i++)
	{
		OrderBinaryTree::TNode node;
		switch (i)
		{
		case 2:
		{
			node.isNULL = false;
			node.info.id = 1001;
			break;
		}
		case 5:
		{
			node.isNULL = false;
			node.info.id = 9;
			break;
		}
		case 15:
		{
			node.isNULL = true;
			node.info.id = 99;
			break;
		}
		default:
		{
			node.isNULL = false;
			node.info.id = i * 2;
		}
		break;
		}
		info.nodes.push_back(node);
	}
	_obt.init(info.nodes);

	//Print
	TNode node;
	cout << "1.空树？" << endl;
	_base.DB->d(_obt.isEmpty());
	cout << "2.深度/层次？"<<endl;
	_base.DB->d(_obt.getDepth());
	cout << "3.图示："<<endl;
	int level = 1;
	for (int i=0;i<_obt.EffectiveLength;i++)
	{
		if (_obt.TreeSpace[i].isNULL)
		{
			cout <<"n ";
		}
		else
		{
			cout << std::to_string(_obt.TreeSpace[i].globalOrder)+" ";
		}	
		if (i + 1 == (int)pow(2, level)-1)
		{
			level++;
			cout << endl;
		}
	}
	_obt.getRootNode(node);
	NodePosition pos;
	pos.level = 3;
	pos.orderInLevel = 3;
	_obt.getNodeWithPosition(node,pos);
	int result = _obt.getLeftChildNode(1001,node);
	result = _obt.getLeftSubling(1001,node);
	result = _obt.getRightChildNode(9, node);
	orderTraverse(TraverseType::Level);
	orderTraverse(TraverseType::PreOrder);
	orderTraverse(TraverseType::InOrder);
	orderTraverse(TraverseType::PostOrder);
}

//Traverse Definition
void OrderBinaryTree:: orderTraverse(OrderBinaryTree::TraverseType type)
{
	if (_obt.isEmpty())
		return;
	switch (type)
	{
	
	case OrderBinaryTree::Level:
	{
		cout << endl;
		cout << "LevelOrderTraverse:" << endl;
		for(int i=0;i<_obt.EffectiveLength;i++)
		{
			if (!_obt.TreeSpace[i].isNULL)
				cout << to_string(_obt.TreeSpace[i].globalOrder)+" ";
		}
		return;
	}
		break;
	case OrderBinaryTree::PreOrder:
		cout << endl;
		cout << "PreOrderTraverse:" << endl;
		break;
	case OrderBinaryTree::InOrder:
		cout << endl;
		cout << "InOrderTraverse:" << endl;
		break;
	case OrderBinaryTree::PostOrder:
		cout << endl;
		cout << "PostOrderTraverse:" << endl;
		break;
	default:
		break;
	}
	orderRecurve(_obt.TreeSpace, 0, type);
}

void OrderBinaryTree::orderRecurve(TNode* tree,int index,OrderBinaryTree::TraverseType type)
{
	if (type == OrderBinaryTree::TraverseType::PreOrder)
		cout << to_string(tree[index].globalOrder) + " ";

	if (_obt.haveNode(index, NodeType::LeftChild))
		orderRecurve(tree, 2 * index + 1,type);

	if (type == OrderBinaryTree::TraverseType::InOrder)
		cout << to_string(tree[index].globalOrder )+ " "; 

	if(_obt.haveNode(index,NodeType::RightChild))
		orderRecurve(tree, 2 * index+2,type);

	if (type == OrderBinaryTree::TraverseType::PostOrder)
		cout << to_string(tree[index].globalOrder) + " ";
}

//
 OrderBinaryTree* OrderBinaryTree::create(CreateInfo& info)
{
	OrderBinaryTree* obTree = new OrderBinaryTree();
	if (obTree)
	{
		return obTree;
	};
	return NULL;
};

bool OrderBinaryTree::init(CreateInfo& info)
{
	_base.DB = VWDebug::getInstance();
	return _obt.init(info.nodes);
};
