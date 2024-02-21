#include "GraphManager.h"

#include "EdgeListGraph.h"

EdgeListGraph GraphManager::GenerateRandomGraph(int numberOfVertices, int numberOfEdges)
{
    EdgeListGraph graph(numberOfVertices);
    for (int i = 0 ; i < numberOfEdges; ++i)
    {
        graph.AddEdge(rand() % numberOfVertices, rand() % numberOfVertices);
    }
    return graph;
}

EdgeListGraph GraphManager::GenerateCompleteGraph(int numberOfVertices)
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
