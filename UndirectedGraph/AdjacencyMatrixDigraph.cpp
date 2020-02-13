#include "AdjacencyMatrixDigraph.h"

int AdjacencyMatrixDigraph::getVertexDegree(int id)
{
	for (int i=0;i<_amd.verNum;i++)
	{
		if(_amd.vers[i].info.id==id)
		{
			int degree = 0;
			for (int j = 0; j < _amd.verNum; j++)
			{
				degree += _amd.eages[i][j].type;
			}
			return degree;
		}
	}
	std::cout << "id为" << id<<"的顶点不存在"<<std::endl;
	return -1;
}

AdjacencyMatrixDigraph* AdjacencyMatrixDigraph::create()
{
	AdjacencyMatrixDigraph* amd = new AdjacencyMatrixDigraph();
	if (amd)
	{
		return amd;
	};
	return NULL;
}

bool AdjacencyMatrixDigraph::init(InitInfo& info)
{
	switch (info.type)
	{
	case InitType::None:
	{
		std::cout << "未指定初始化类型！" << std::endl;
	}
		break;
	case InitType::AdjacencyMatrix:
	{
		int size = info.versInfo.size();
		for (int i = 0; i < size; i++)
		{
			_amd.vers[i].info = info.versInfo[i];
			for (int j = 0; j < size; j++)
			{
				_amd.eages[i][j] = info.eagesInfo[i][j];
			}
		}
		_amd.verNum = size;
	}
	break;
	case InitType::CompressedAM:
	{
		int size = info.versInfo.size();
		for (int i = 0; i < size; i++)
		{
			_amd.vers[i].info = info.versInfo[i];
			for (int j = 0; j < i+1; j++)
			{
				_amd.eages[j][i] = _amd.eages[i][j]= info.eagesInfo[i][j];
			}
		}
		_amd.verNum = size;
	}
	break;
	default:
		break;
	}
	return true;
}
