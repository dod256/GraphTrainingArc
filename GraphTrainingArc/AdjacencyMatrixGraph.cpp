#include "AdjacencyMatrixGraph.h"

#include <iostream>
#include <ostream>

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int numberOfVertices) :Graph(numberOfVertices)
{
    m_AdjacencyMatrix = std::vector<std::vector<int>>(numberOfVertices);
    for (std::vector<int>& row : m_AdjacencyMatrix)
    {
        row = std::vector<int>(numberOfVertices, MAX_WEIGHT);
    }
}

void AdjacencyMatrixGraph::AddEdge(int v, int u, int w)
{
    m_AdjacencyMatrix[v][u] = w;
}

int AdjacencyMatrixGraph::CalculateComponents()
{
    return -1;
}

void AdjacencyMatrixGraph::PrintGraph()
{
    const int numberOfVertices = static_cast<int>(m_AdjacencyMatrix.size());
    for(int i = 0; i < numberOfVertices; ++i)
    {
        for(int j = 0; j < numberOfVertices; ++j)
        {
            if (m_AdjacencyMatrix[i][j] == MAX_WEIGHT)
            {
                printf("--");
            }
            else
            {
                printf("%d", m_AdjacencyMatrix[i][j]);
            }
            printf("%c", " \n"[j == numberOfVertices - 1]);
        }
        printf("\n");
    }
        
}

std::vector<std::vector<int>> AdjacencyMatrixGraph::MatrixMultiply(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b)
{
    const int numberOfVertices = static_cast<int>(a.size());
    std::vector<std::vector<int>> res = std::vector<std::vector<int>>(numberOfVertices);
    for (std::vector<int>& row : res)
    {
        row = std::vector<int>(numberOfVertices, MAX_WEIGHT);
    }

    for (int i = 0; i < numberOfVertices; ++i)
    {
        for (int j = 0; j < numberOfVertices; ++j)
        {
            for (int k = 0; k < numberOfVertices; ++k)
            {
                res[i][j] = std::min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    
    return res;
}

int AdjacencyMatrixGraph::ShortestPathWithAtMostKEdges(int v, int u, int k)
{
    int numberOfVertices = m_AdjacencyMatrix.size(); 
    std::vector<std::vector<int>> graph(m_AdjacencyMatrix);
    for(int i = 0; i < graph.size(); ++i)
    {
        graph[i][i] = 0;
    }
    std::vector<std::vector<int>> res(numberOfVertices);
    for (int i = 0; i < numberOfVertices; ++i)
    {
        res[i] = std::vector<int>(numberOfVertices, MAX_WEIGHT);
        res[i][i] = 0;
    }
    
    while (k)
    {
        if (k & 1)
        {
            res = MatrixMultiply(res, graph);
            --k;    
        }
        else
        {
            graph = MatrixMultiply(graph, graph);
            k >>= 1;
        }
    }
    
    return res[v][u] == MAX_WEIGHT ? -1 : res[v][u];
}
