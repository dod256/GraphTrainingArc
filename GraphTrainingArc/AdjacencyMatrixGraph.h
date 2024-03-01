#pragma once
#include <vector>

#include "Graph.h"

class AdjacencyMatrixGraph : Graph
{
public:
    AdjacencyMatrixGraph(int numberOfVertices);
    
    void AddEdge(int v, int u, int w) override;
    Edge* GetEdge(int v, int u) override;

    int CalculateComponents() override;
    void PrintGraph() override;

    EdgeList MinimumSpanningForest() override;

    // ToDo Implement
    int ShortestPath(int start, int finish) override { return -1; }
    
    int ShortestPathWithAtMostKEdges(int v, int u, int k);
private:
    // MAX_WEIGHT in Adjacency matrix means there is no edge.
    static constexpr int MAX_WEIGHT = static_cast<int>(1e9);

    // Move out of this class
    static std::vector<std::vector<int>> MatrixMultiply(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b);

private:
    std::vector<std::vector<int>> m_AdjacencyMatrix;
};
