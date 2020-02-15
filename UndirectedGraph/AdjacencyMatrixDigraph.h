#ifndef AdjacencyMatrixDigraph_hpp
#define AdjacencyMatrixDigraph_hpp

#define MAX_VERTEX_NUM 20
#include <vector>
#include <iostream>

using namespace std;

//Note:
//1.无向邻接矩阵表示图时，矩阵具有对称性
//2.顶点的度为顶点在矩阵所在行/列值的和


class AdjacencyMatrixDigraph
{
public:

	enum EageType
	{
		UnEage = 0,
		IsEage = 1
	};
	struct CustomInfo
	{
		int id;
	};

	struct Vertex
	{
		CustomInfo info;
	};

	struct Eage
	{
		int weight;
		EageType type =UnEage;
	};
	
	struct AMDigraph
	{
		Vertex vers[MAX_VERTEX_NUM];
		Eage   eages[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
		int		verNum;
	};

	struct Base
	{};
	enum InitType
	{
		None,
		AdjacencyMatrix,
		CompressedAM,
	};
	struct InitInfo
	{
		InitType type = None;
		std::vector<CustomInfo> versInfo;
		std::vector<std::vector<Eage>> eagesInfo;
	};

	int getVertexDegree(int ID);

	static AdjacencyMatrixDigraph* create();

	bool init(InitInfo& info);

	AMDigraph _amd;
	Base _base;
};

#endif