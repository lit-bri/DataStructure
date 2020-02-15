#ifndef AdjacencyListDigraph_hpp
#define AdjacencyListDigraph_hpp

#define MAX_VERTEX_NUM 20

#include <vector>

class AdjacencyListDigraph
{
public:
	struct CustomInfo
	{
		int id;
	};
	struct WeightInfo
	{
		int weight;
	};

	struct Eage
	{
		int theOtherVertexIndex;
		WeightInfo weight;
		Eage* next;
	};

	struct Vertex
	{
		CustomInfo customInfo;
		Eage* eageHead;
	};

	struct ALDigraph
	{
		Vertex vers[MAX_VERTEX_NUM];
		int verNum = -1;
};

	enum class InitType
	{
		None,
		Adjacency_Array,
		Adjacency_Index
	};

	struct AdjacencyArray
	{
		std::vector<	CustomInfo> versInfo;
		std::vector < std::vector<Eage>> eagesInfo;
	};

	struct AdjacencyIndex
	{
		std::vector<CustomInfo> versInfo;
		std::vector<WeightInfo>		weights;
		std::vector<int> VertexXIndex;
		std::vector<int> VertexYIndex;
	};

	struct InitInfo
	{
		AdjacencyListDigraph::InitType type= AdjacencyListDigraph::InitType::None;
		AdjacencyArray AA;
		AdjacencyIndex AI;
	};

	static AdjacencyListDigraph* create();

	bool init(AdjacencyListDigraph::InitInfo& info);

	ALDigraph _ald;
};

#endif // !AdjacencyListDigraph_hpp
