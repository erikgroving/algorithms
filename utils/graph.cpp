#include <random>
#include <iostream>

#include "graph.hpp"



std::vector<std::vector<Edge>> GraphBuilder::createGraph(double density, int n) {
    std::vector<std::vector<Edge>> graph;

    for (int i = 0; i < n; i++) {
        graph.push_back(std::vector<Edge>());
    }

    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_real_distribution<> random_gen(0, 1);
    std::uniform_int_distribution<int> random_int_gen(0, 15);
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (random_gen(e1) < density) {
                // i and j have an edge
                graph[i].push_back(Edge(j,  random_int_gen(e1)));
            }
        }
    }

    return graph;
}