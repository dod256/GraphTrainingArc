
#include <cassert>
#include <chrono>
#include <cstdlib>

#include "EdgeListGraph.h"
#include "GraphManager.h"

int main(int argc, char* argv[])
{
    const auto tm = std::chrono::system_clock::now();
    const time_t t = std::chrono::system_clock::to_time_t(tm);
    srand(t);

    //EdgeListGraph graph = GraphManager::GenerateRandomGraph(rand() % 10 + 1, rand() % 20 + 1);
    //graph.PrintVerticesLists();

    EdgeListGraph graph = GraphManager::GenerateCompleteGraph(rand() % 10 + 1);
    const int numberOfComponents = graph.CalculateComponents();
    assert(numberOfComponents == 1);
    
    return 0;
}
