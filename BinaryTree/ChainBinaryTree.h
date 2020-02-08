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
		LevelOrder,
		PreOrder,
		InOrder,
		PostOrder
	};

	struct BaseInfo
	{

	};



	struct CustomInfo
	{
		bool isNull = true;
		int id;
	};

	struct InitInfo
	{
		std::vector<CustomInfo> info;
	};

	struct TNode
	{
		//Note:NULL为0;而nullptr用来表示空指针,不为0。if(nullptr)一定为true;
		TNode* lchild=NULL;
		TNode* rchild=NULL;
		CustomInfo info;
	};

	struct CBTree
	{
		TNode* root =NULL;
	};

	//Test
	void debug();

	//Traverse
	void ChainTraverse(TraverseType type);


	//Get
	ResultType		getRootNode(TNode& node);

	int		getDepth(TNode* node);
	
	//Judge
	bool isEmpty();

	//Base
	static ChainBinaryTree* create();

	bool init(InitInfo& info);
	
	void clear(TNode* &node);

	CBTree		 _cbt;
	BaseInfo	_base;
private:
	void initRecurve(TNode* &tree, std::vector<CustomInfo>& info);

	void ChainRecurve(TNode* &node, TraverseType type);
};	

#endif