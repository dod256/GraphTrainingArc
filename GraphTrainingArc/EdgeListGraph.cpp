#include "EdgeListGraph.h"

#include <cassert>

EdgeListGraph EdgeListGraph::GenerateRandomGraph(int numberOfVertices, int numberOfEdges)
{
    EdgeListGraph graph(numberOfVertices);
    for (int i = 0 ; i < numberOfEdges; ++i)
    {
        graph.AddEdge(rand() % numberOfVertices, rand() % numberOfVertices);
    }
    return graph;
}

EdgeListGraph EdgeListGraph::GenerateCompleteGraph(int numberOfVertices)
{
    EdgeListGraph graph(numberOfVertices);
    for (int i = 0 ; i < numberOfVertices; ++i)
    {
        for (int j = 0 ; j < numberOfVertices; ++j)
        {
            if (i == j)
            {
                continue;
            }
            graph.AddEdge(i, j);
        }        
    }
    return graph;
    
}


EdgeListGraph::EdgeListGraph(int numberOfVertices): Graph(numberOfVertices), m_NumberOfVertices(numberOfVertices), m_NumberOfEdges(0)
{
    m_Head = std::vector<int>(m_NumberOfVertices, -1);
}

void EdgeListGraph::AddEdge(int v, int u, int w)
{
    m_To.push_back(u);
    m_Next.push_back(m_Head[v]);
    m_Weight.push_back(w);
    m_Head[v] = m_NumberOfEdges;
    m_NumberOfEdges++;
}

void EdgeListGraph::PrintVerticesLists() const
{
    for (int i = 0; i < m_NumberOfVertices; ++i)
    {
        printf("Vertice #%d:", i);
        for (int j = m_Head[i]; j != -1; j = m_Next[j])
        {
            printf(" (to %d weight %d)", m_To[j], m_Weight[j]);
        }
        printf("\n");
    }
}

int EdgeListGraph::CalculateComponents()
{
    m_Component = std::vector<int>(m_NumberOfVertices, -1);
    int cnt = 0;
    for (int i = 0; i < m_NumberOfVertices; ++i)
    {
        if (m_Component[i] == -1)
        {
            Dfs(i, cnt);
            cnt++;
        }
    }
    return cnt;
}

void EdgeListGraph::PrintGraph()
{
    PrintVerticesLists();
}

void EdgeListGraph::Dfs(int v, int component)
{
    m_Component[v] = component;
    for (int i = m_Head[v]; i != -1; i = m_Next[i])
    {
        const int u = m_To[i];
        assert(m_Component[u] == component || m_Component[u] == -1);
        if (m_Component[u] == -1)
        {
            Dfs(u, component);
        }
    }
}
