#include "AdjacencyMatrixGraph.h"

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
    int numberOfVertices = static_cast<int>(m_AdjacencyMatrix.size());
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
