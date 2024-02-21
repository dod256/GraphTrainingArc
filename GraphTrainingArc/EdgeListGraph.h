#pragma once
#include <vector>

class EdgeListGraph
{
public:
    int m_NumberOfVertices;
    int m_NumberOfEdges;

    EdgeListGraph(int numberOfVertices) : m_NumberOfVertices(numberOfVertices), m_NumberOfEdges(0)
    {
        m_Head = std::vector<int>(m_NumberOfVertices, -1);
    }

    void AddEdge(int v, int u, int w = 0);
    void PrintVerticesLists() const;
    int CalculateComponents();
private:
    std::vector<int> m_Head;
    std::vector<int> m_To;
    std::vector<int> m_Next;
    std::vector<int> m_Weight;
    
    std::vector<int> m_Component; // move to a vertice class later?

    void Dfs(int v, int component);
};
