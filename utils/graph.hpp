#pragma once

#include <vector>

struct Edge {
    Edge(int dest, int distance) : dest(dest), distance(distance) {}
    
    int dest;
    int distance;
};

class GraphBuilder {
  public: 
    static std::vector<std::vector<Edge>> createGraph(double density, int n);

};