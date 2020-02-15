#include "AdjacencyListDigraph.h"

AdjacencyListDigraph* AdjacencyListDigraph::create()
{
	AdjacencyListDigraph* ald = new AdjacencyListDigraph();
	if (ald)
	{
		return ald;
	};
	return NULL;
}

bool AdjacencyListDigraph::init(AdjacencyListDigraph::InitInfo& info)
{
	switch (info.type)
	{
	case AdjacencyListDigraph::InitType::Adjacency_Array :
	{
		AdjacencyArray& aad = info.AA;
		int size = aad.versInfo.size();
		for (int i = 0; i < size; i++)
		{
			_ald.vers[i].customInfo = aad.versInfo[i];
			_ald.vers[i].eageHead = NULL;
			int e_size = aad.eagesInfo[i].size();
			for (int j = 0; j < e_size; i++)
			{
				AdjacencyListDigraph::Eage* eage = (AdjacencyListDigraph::Eage*)malloc(sizeof(AdjacencyListDigraph::Eage));
				if (eage != NULL)
				{
					eage->theOtherVertexIndex = aad.eagesInfo[i][j].theOtherVertexIndex;
					eage->weight = aad.eagesInfo[i][j].weight;
					//Note:倒序建立链表!,中间指针是eageHead。
					eage->next = _ald.vers[i].eageHead;
					_ald.vers[i].eageHead = eage;
				}
			}
		}
	}
	case AdjacencyListDigraph::InitType::Adjacency_Index:
	{
		AdjacencyListDigraph::AdjacencyIndex& ai = info.AI;
		int size = ai.versInfo.size();
		for (int i = 0; i < size; i++)
		{
			_ald.vers[i].customInfo = ai.versInfo[i];
			_ald.vers[i].eageHead = NULL;
		}
		size = ai.VertexXIndex.size();
		for (int j = 0; j < size; j++)
		{
			AdjacencyListDigraph::Eage* eage = (AdjacencyListDigraph::Eage*)malloc(sizeof(AdjacencyListDigraph::Eage));
			if (eage != NULL)
			{
				int currentVertexIndex = ai.VertexXIndex[j];
				eage->theOtherVertexIndex = ai.VertexYIndex[j];
				eage->weight = ai.weights[j];
				//Note:倒序建立链表!,中间指针是eageHead。
				eage->next = _ald.vers[currentVertexIndex].eageHead;
				_ald.vers[currentVertexIndex].eageHead = eage;

				AdjacencyListDigraph::Eage* theOtherEage = (AdjacencyListDigraph::Eage*)malloc(sizeof(AdjacencyListDigraph::Eage));
				if (theOtherEage != NULL)
				{
					int currentVertexIndex = ai.VertexYIndex[j];
					theOtherEage->theOtherVertexIndex = ai.VertexXIndex[j];
					theOtherEage->weight = ai.weights[j];
					theOtherEage->next= _ald.vers[currentVertexIndex].eageHead;
					_ald.vers[currentVertexIndex].eageHead = eage;
				}
			}
	}
		break;
	default:
		break;
	}
	
	return false;
}

