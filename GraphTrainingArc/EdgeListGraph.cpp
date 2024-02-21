#include "EdgeListGraph.h"

#include <cassert>

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
