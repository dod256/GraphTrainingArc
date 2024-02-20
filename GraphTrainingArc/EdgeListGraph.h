#pragma once
#include <vector>

class EdgeListGraph
{
public:
    int m_NumberOfVertices;
    int m_NumberOfEdges;

    EdgeListGraph(int numberOfVertices) : m_NumberOfVertices(numberOfVertices), m_NumberOfEdges(0)
    {
        head = std::vector<int>(m_NumberOfVertices, -1);
    }

    void AddEdge(int v, int u);
    void PrintVerticesLists();
private:
    std::vector<int> head;
    std::vector<int> to;
    std::vector<int> next;
};
