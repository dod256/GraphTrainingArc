#pragma once

class Graph
{
public:
    virtual ~Graph() = default;
    explicit Graph(int numberOfVertices) {}

    virtual void AddEdge(int v, int u, int w = 0) = 0;
    virtual int CalculateComponents() = 0;
    virtual void PrintGraph() = 0;
};
