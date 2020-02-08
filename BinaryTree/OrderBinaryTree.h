#include <vector>
#define INIT_SPACE_SIZE 100
#define MAX_TREE_SIZE 100

class VWDebug;
class OrderBinaryTree
{
public:
	struct CustomInfo
	{
		int id;
	};

	struct TNode
	{
		bool		isNULL = true;
		int		globalOrder	=0;
		CustomInfo info;
	};

	struct NodePosition
	{
		int level;
		int orderInLevel;
	};

	enum ResultType
	{
		TREE_EMPTY,
		NOTFIND,
		FIND
	};

	enum NodeType
	{
		Parent,
		LeftChild,
		RightChild,
		LeftSubling,
		RightSubling
	};

	enum TraverseType
	{
		PreOrder,
		InOrder,
		PostOrder,
		Level
	};

	struct  OBTree
	{
		
		TNode TreeSpace[MAX_TREE_SIZE];
		int EffectiveLength = 0;
		OBTree()
		{
			for (size_t i = 0; i < MAX_TREE_SIZE; i++)
			{
				TreeSpace[i].globalOrder = i+1;
			}
		}
		bool init(std::vector<TNode>& nodes)
		{
			size_t size = nodes.size();
			if (size == 0)
				return false;
			for (size_t i = 0; i < size; i++)
			{
				TreeSpace[i].isNULL = nodes[i].isNULL;
				if (!nodes[i].isNULL)
				{
					TreeSpace[i].info = nodes[i].info;
				}
			}
			EffectiveLength = size;
			return true;
		}
		bool isEmpty()
		{
			return TreeSpace[0].isNULL;
		}

		bool haveNode(int index,NodeType type)
		{
			int goalIndex;
			switch (type)
			{
			case OrderBinaryTree::Parent:
			{
				goalIndex = (index + 1) / 2 - 1;
			}
				break;
			case OrderBinaryTree::LeftChild:
			{
				goalIndex = 2 * index + 1;
			}
				break;
			case OrderBinaryTree::RightChild:
			{
				goalIndex = 2 * index + 2;
			}
				break;
			case OrderBinaryTree::LeftSubling:
			{
				if (index % 2)
					return false;
				else
					goalIndex = index - 1;
			}
				break;
			case OrderBinaryTree::RightSubling:
			{
				if (index % 2)
				{
					goalIndex = index + 1;
				}
				else
					return false;
			}
				break;
			default:
				break;
			}
			if (TreeSpace[goalIndex].isNULL)
			{
				return false;
			}
			return true;
		}
		void clear()
		{
			TreeSpace[0].isNULL = true;
		}

		void getRootNode(TNode& node)
		{
			if (TreeSpace[0].isNULL)
				return;
			node = TreeSpace[0];
		}
		void getNodeWithPosition(TNode& node, NodePosition& position)
		{
			int aboveLevelsNodeNum = (int)pow(2, position.level - 1) - 1;
			int globalOrder = aboveLevelsNodeNum + position.orderInLevel;
			node = TreeSpace[globalOrder - 1];
		}

		ResultType getParentNode(int customID, TNode node)
		{
			if (TreeSpace[0].isNULL)
				return TREE_EMPTY;
			for (size_t i = 0; i < EffectiveLength; i++)
			{
				if (!TreeSpace[i].isNULL && TreeSpace[i].info.id == customID)
				{
					size_t parentIndex = (i + 1) / 2 - 1;
					node = TreeSpace[parentIndex];
					return FIND;
				}
			}
			return NOTFIND;
		}

		ResultType getLeftChildNode(int customID, TNode& node)
		{
			if (TreeSpace[0].isNULL)
				return TREE_EMPTY;
			for (size_t i = 0; i < EffectiveLength; i++)
			{
				if (!TreeSpace[i].isNULL && TreeSpace[i].info.id == customID)
				{
					//Note:
					//LeftChildGlobalOrder=(i+1)*2
					size_t childIndex = i * 2 + 1;
					node = TreeSpace[childIndex];
					return FIND;
				}
			}
			return NOTFIND;
		}

		ResultType getRightChildNode(int customID, TNode& node)
		{
			if (TreeSpace[0].isNULL)
				return TREE_EMPTY;
			for (size_t i = 0; i < EffectiveLength; i++)
			{
				if (!TreeSpace[i].isNULL && TreeSpace[i].info.id == customID)
				{
					//Note:	RightChildGlobalOrder=(i+1)*2+1
					size_t childIndex = i * 2 + 2;
					node = TreeSpace[childIndex];
					return FIND;
				}
			}
			return NOTFIND;
		}

		ResultType getRightSubling(int customID, TNode& node)
		{
			if (TreeSpace[0].isNULL)
				return TREE_EMPTY;
			for (size_t i = 0; i < EffectiveLength; i++)
			{
				if (!TreeSpace[i].isNULL && TreeSpace[i].info.id == customID)
				{
					if (i % 2)
					{
						if (TreeSpace[i +1].isNULL)
						{
							return NOTFIND;
						}
						else
						{
							node = TreeSpace[i +1];
							return FIND;
						}
					}
					else
						return NOTFIND;
				}
			}
			return NOTFIND;
		}

		ResultType getLeftSubling(int customID, TNode& node)
		{
			if (TreeSpace[0].isNULL)
				return TREE_EMPTY;
			for (size_t i = 0; i < EffectiveLength; i++)
			{
				if (!TreeSpace[i].isNULL && TreeSpace[i].info.id== customID)
				{
					if (i % 2 == 0)
					{
						if (TreeSpace[i-1].isNULL)
						{
							return NOTFIND;
						}else
						{
							node = TreeSpace[i - 1];
							return FIND;
						}
					}
					else
					{
						return NOTFIND;
					}
				}
			}
			return NOTFIND;
		}


		int getDepth()
		{
			if (TreeSpace[0].isNULL)
				return 0;
			size_t depth = -1;
			while (EffectiveLength >= pow(2, ++depth));
			return depth;
		}

		void setNode(TNode& node, NodePosition position)
		{
			if (TreeSpace[0].isNULL && node.isNULL)
				return;
			int index = (int)pow(2, position.level - 1) + position.orderInLevel - 2;
			TreeSpace[index] = node;
		}
	};

	//
	void orderTraverse(TraverseType type);

	void orderRecurve(TNode* tree, int index,TraverseType type);

	//Test
	void debug();

	//Base
	struct Base
	{
		VWDebug* DB;
	};

	struct InitInfo
	{
		std::vector<TNode> nodes;
	};

	static OrderBinaryTree* create(InitInfo& info);

	bool init(InitInfo& info);

	OBTree _obt;
	Base _base;
};

