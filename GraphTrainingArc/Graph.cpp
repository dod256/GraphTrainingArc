#include "Graph.h"

#include <algorithm>

void EdgeList::AddEdge(int v, int u, int w)
{
    m_Edges.emplace_back(v, u, w);
}

void EdgeList::AddEdge(const Edge& edge)
{
    m_Edges.emplace_back(edge.m_From, edge.m_To, edge.m_Weight);
}

void EdgeList::Print() const
{
    for(const auto& edge : m_Edges)
    {
        printf("%d %d %d\n", edge.m_From, edge.m_To, edge.m_Weight);
    }
}


//ToDo Move to < operator inside edge?
bool CompEdges(const Edge& a, const Edge& b)
{
    if (a.m_Weight == b.m_Weight && a.m_From == b.m_From) return a.m_To < b.m_To;
    if (a.m_Weight == b.m_Weight) return a.m_From < b.m_From;
    return a.m_Weight < b.m_Weight;
}

void EdgeList::Sort()
{
    sort(m_Edges.begin(), m_Edges.end(), CompEdges);
}

