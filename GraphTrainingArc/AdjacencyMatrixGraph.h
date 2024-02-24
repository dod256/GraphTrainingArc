#pragma once
#include <vector>

#include "Graph.h"

class AdjacencyMatrixGraph : Graph
{
public:
    AdjacencyMatrixGraph(int numberOfVertices);
    
    void AddEdge(int v, int u, int w) override;
    int CalculateComponents() override;
    void PrintGraph() override;

private:
    // MAX_WEIGHT in Adjacency matrix means there is no edge.
    static constexpr int MAX_WEIGHT = static_cast<int>(1e9);
    std::vector<std::vector<int>> m_AdjacencyMatrix;
};
