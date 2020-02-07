#include "OrderBinaryTree.h"
#include "../../Utils/VWDebug.h"

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
