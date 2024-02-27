#pragma once
#include <vector>

struct Edge
{
    int m_From;
    int m_To;
    int m_Weight;

    Edge() : m_From(0), m_To(0), m_Weight(0) {}
    Edge(int v, int u, int w) : m_From(v), m_To(u), m_Weight(w) {}
};

class EdgeList
{
public:
    EdgeList() = default;
    void AddEdge(int v, int u, int w = 0);
    void AddEdge(const Edge& edge);
    void Print() const;
    const std::vector<Edge>& GetList() const { return m_Edges; }
    std::vector<Edge> GetList() { return m_Edges; }
    void Sort();
private:
    std::vector<Edge> m_Edges;
};

class Graph
{
public:
    virtual ~Graph() = default;
    explicit Graph(int numberOfVertices) {}

    virtual void AddEdge(int v, int u, int w = 0) = 0;
    virtual Edge* GetEdge(int v, int u) = 0;

    virtual EdgeList MinimumSpanningForest() = 0;
    
    virtual int CalculateComponents() = 0;
    virtual void PrintGraph() = 0;
};
