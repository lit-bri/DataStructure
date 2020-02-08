//Create By LitBri on 2020/2/7

#ifndef ChainBinaryTree_hpp
#define ChainBinaryTree_hpp

#include <vector>

class ChainBinaryTree
{
public:
	enum ResultType
	{
		TREE_EMPTY,
		NOTFIND,
		FIND
	};

	enum TraverseType
	{
		PreOrder,
		InOrder,
		PostOrder
	};

	struct BaseInfo
	{

	};

	struct InitInfo
	{
		std::vector<CustomInfo> info;
	};

	struct CustomInfo
	{
		bool isNull;
		int id;
	};

	struct TNode
	{
		bool isNULL;
		TNode* lchild=nullptr;
		TNode* rchild=nullptr;
		CustomInfo info;
	};

	struct CBTree
	{
		TNode* root =nullptr;
	};

	//Test
	void Test();

	//Traverse
	void ChainTraverse(TraverseType type);
	void ChainRecurce(TNode* node,TraverseType type);

	//Get
	ResultType		getRootNode(TNode& node);

	int		getDepth(TNode* node);
	
	//Judge
	bool isEmpty();

	//Base
	static ChainBinaryTree* create();

	bool init(InitInfo& info);

	void initRecurve(TNode* tree,std::vector<CustomInfo>& info,int index);

	void clear();

	CBTree		 _cbt;
	BaseInfo	_base;
};	

#endif