
#include <cassert>
#include <chrono>
#include <cstdlib>

#include "AdjacencyMatrixGraph.h"
#include "EdgeListGraph.h"
#include "GraphManager.h"

int main(int argc, char* argv[])
{
    const auto tm = std::chrono::system_clock::now();
    const time_t t = std::chrono::system_clock::to_time_t(tm);
    srand(t);

    //EdgeListGraph graph = GraphManager::GenerateRandomGraph(rand() % 10 + 1, rand() % 20 + 1);
    //graph.PrintVerticesLists();

    //EdgeListGraph graph = EdgeListGraph::GenerateCompleteGraph(rand() % 10 + 1);
    //const int numberOfComponents = graph.CalculateComponents();
    //assert(numberOfComponents == 1);

    AdjacencyMatrixGraph graph = AdjacencyMatrixGraph(4);
    graph.AddEdge(0, 1, 100);
    graph.AddEdge(1, 2, 100);
    graph.AddEdge(2, 0, 100);
    graph.AddEdge(1, 3, 600);
    graph.AddEdge(2, 3, 200);
    graph.PrintGraph();
    
    return 0;
}
