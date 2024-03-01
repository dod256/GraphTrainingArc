#include "AdjacencyListGraph.h"

#include <cassert>
#include <iostream>
#include <ostream>
#include <set>

AdjacencyListGraph  AdjacencyListGraph::GenerateRandomGraph(int numberOfVertices, int numberOfEdges)
{
     AdjacencyListGraph graph(numberOfVertices);
    for (int i = 0 ; i < numberOfEdges; ++i)
    {
        graph.AddEdge(rand() % numberOfVertices, rand() % numberOfVertices);
    }
    return graph;
}

 AdjacencyListGraph  AdjacencyListGraph::GenerateCompleteGraph(int numberOfVertices)
{
     AdjacencyListGraph graph(numberOfVertices);
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


 AdjacencyListGraph:: AdjacencyListGraph(int numberOfVertices): Graph(numberOfVertices), m_NumberOfVertices(numberOfVertices), m_NumberOfEdges(0)
{
    m_Head = std::vector<int>(m_NumberOfVertices, -1);
}

void  AdjacencyListGraph::AddEdge(int v, int u, int w)
{
    m_To.push_back(u);
    m_Next.push_back(m_Head[v]);
    m_Weight.push_back(w);
    m_Head[v] = m_NumberOfEdges;
    m_NumberOfEdges++;
}

Edge* AdjacencyListGraph::GetEdge(int v, int u)
{
    // ToDo Implement
    return nullptr;
}

int FindSet(std::vector<int>& u, int a)
{
     if (u[a] == a)
         return a;
     return u[a] = FindSet(u, u[a]);
}


void UnionSets(std::vector<int>& u, int a, int b)
{
    a = FindSet(u, a);
    b = FindSet(u, b);
    if (a != b)
    {
        u[a] = b;
    }
}

EdgeList AdjacencyListGraph::MinimumSpanningForest()
{
    EdgeList edges;
    for (int i = 0 ; i < m_NumberOfVertices; ++i)
    {
        for (int j = m_Head[i]; j != -1; j = m_Next[j])
        {
            edges.AddEdge(i, m_To[j], m_Weight[j]);
        }
    }
    assert(edges.GetList().size() == m_NumberOfEdges);
    edges.Sort();
    std::vector<int> u(m_NumberOfVertices);
    for(int i = 0; i < m_NumberOfVertices; ++i)
    {
        u[i] = i;
    }
    EdgeList result;
    for(const auto& edge : edges.GetList())
    {
        if (FindSet(u, edge.m_From) != FindSet(u, edge.m_To))
        {
            result.AddEdge(edge);
            UnionSets(u, edge.m_From, edge.m_To);
        }
    }
    return result;
}

void  AdjacencyListGraph::PrintVerticesLists() const
{
    for (int i = 0; i < m_NumberOfVertices; ++i)
    {
        printf("Vertex #%d:", i);
        for (int j = m_Head[i]; j != -1; j = m_Next[j])
        {
            printf(" (to %d weight %d)", m_To[j], m_Weight[j]);
        }
        printf("\n");
    }
}

int AdjacencyListGraph::ShortestPath(int start, int finish)
{
    std::set<std::pair<int, int>> s;
    std::vector<int> dist(m_NumberOfVertices, -1);
    dist[start] = 0;
    s.insert(std::make_pair(0, start));
    while (!s.empty())
    {
        const auto q = *s.begin();
        const int v = q.second;
        const int d = q.first;
        s.erase(s.begin());
        std::cerr << v << " " << d << std::endl;
        for (int i = m_Head[v]; i != -1; i = m_Next[i])
        {
            if (dist[m_To[i]] == -1)
            {
                dist[m_To[i]] = d + m_Weight[i];
                s.insert(std::make_pair(d + m_Weight[i], m_To[i]));                
            }
            if (d + m_Weight[i] < dist[m_To[i]])
            {
                const auto it = s.find(std::make_pair(dist[m_To[i]], m_To[i]));
                s.erase(it);
                s.insert(std::make_pair(d + m_Weight[i], m_To[i]));
                dist[m_To[i]] = d + m_Weight[i];
            }
        }
    }
    return dist[finish];
}

int  AdjacencyListGraph::CalculateComponents()
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

void  AdjacencyListGraph::PrintGraph()
{
    PrintVerticesLists();
}

void  AdjacencyListGraph::Dfs(int v, int component)
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
