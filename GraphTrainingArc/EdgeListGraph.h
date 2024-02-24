#pragma once
#include <vector>

#include "Graph.h"

class EdgeListGraph : public Graph
{
public:
    static EdgeListGraph GenerateRandomGraph(int numberOfVertices, int numberOfEdges);
    static EdgeListGraph GenerateCompleteGraph(int numberOfVertices);

    int m_NumberOfVertices;
    int m_NumberOfEdges;

    EdgeListGraph(int numberOfVertices);

    void AddEdge(int v, int u, int w = 0) override;
    int CalculateComponents() override;
    void PrintGraph() override;
private:
    std::vector<int> m_Head;
    std::vector<int> m_To;
    std::vector<int> m_Next;
    std::vector<int> m_Weight;
    
    std::vector<int> m_Component; // move to a vertice class later?

    void Dfs(int v, int component);
    void PrintVerticesLists() const;
};
