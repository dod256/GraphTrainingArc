#include "EdgeListGraph.h"

void EdgeListGraph::AddEdge(int v, int u)
{
    to.push_back(u);
    next.push_back(head[v]);
    head[v] = m_NumberOfEdges;
    m_NumberOfEdges++;
}

void EdgeListGraph::PrintVerticesLists()
{
    for (int i = 0; i < m_NumberOfVertices; ++i)
    {
        printf("Vertice #%d:", i);
        for (int j = head[i]; j != -1; j = next[j])
        {
            printf(" %d", to[j]);
        }
        printf("\n");
    }
}
