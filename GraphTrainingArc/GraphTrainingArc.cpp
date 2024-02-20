
#include <chrono>
#include <cstdlib>

#include "EdgeListGraph.h"

int main(int argc, char* argv[])
{
    const auto tm = std::chrono::system_clock::now();
    const time_t t = std::chrono::system_clock::to_time_t(tm);
    srand(t);

    int n = rand() % 10 + 1;
    int m = rand() % 20 + 1;

    EdgeListGraph graph(n);
    for (int i = 0 ; i < m; ++i)
    {
        graph.AddEdge(rand() % n, rand() % n);
    }

    graph.PrintVerticesLists();
    
    return 0;
}
