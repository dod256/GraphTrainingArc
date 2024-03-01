#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ostream>

#include "AdjacencyMatrixGraph.h"
#include "AdjacencyListGraph.h"

int main(int argc, char* argv[])
{
    const auto tm = std::chrono::system_clock::now();
    const time_t t = std::chrono::system_clock::to_time_t(tm);
    srand(static_cast<int>(t));

    // AdjacencyListGraph graph = GraphManager::GenerateRandomGraph(rand() % 10 + 1, rand() % 20 + 1);
    //graph.PrintVerticesLists();
    
    AdjacencyMatrixGraph graph = AdjacencyMatrixGraph(4);
    graph.AddEdge(0, 1, 100);
    graph.AddEdge(1, 2, 100);
    graph.AddEdge(2, 0, 100);
    graph.AddEdge(1, 3, 600);
    graph.AddEdge(2, 3, 200);
    assert(graph.ShortestPathWithAtMostKEdges(0, 3, 2) == 700);

/*    
    for(int t = 0; t < 10; ++t)
    {
        const int n = rand() % 1000 + 1;
        AdjacencyListGraph graph2 =  AdjacencyListGraph::GenerateCompleteGraph(n);
        const int numberOfComponents = graph2.CalculateComponents();
        assert(numberOfComponents == 1);
        EdgeList spanningForest = graph2.MinimumSpanningForest();
        assert(spanningForest.GetList().size() == graph2.m_NumberOfVertices - 1);
    }
*/
    AdjacencyListGraph graph2(3);
    graph2.AddEdge(0, 1, 1);
    graph2.AddEdge(0, 2, 10);
    graph2.AddEdge(1, 2, 1);
    assert(graph2.ShortestPath(0, 2) == 2);
    
    return 0;
}
