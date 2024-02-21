#pragma once
#include "EdgeListGraph.h"

class GraphManager
{
public:
    static EdgeListGraph GenerateRandomGraph(int numberOfVertices, int numberOfEdges);
    static EdgeListGraph GenerateCompleteGraph(int numberOfVertices);
};
