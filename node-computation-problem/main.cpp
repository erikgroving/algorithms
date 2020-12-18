#include <iostream>

#include "Solution.hpp"


int main() {

    // Create graph using adjacency list
    std::unordered_map<char, Node> graph;
    graph['A'].inputs = {};
    graph['A'].weight = 2;
    
    graph['B'].inputs = {'A'};
    graph['B'].weight = 4;
    
    graph['C'].inputs = {'B', 'D'};
    graph['C'].weight = 7;

    graph['D'].inputs = {};
    graph['D'].weight = 3;

    graph['F'].inputs = {'A'};
    graph['F'].weight = 3;

    graph['G'].inputs = {'C', 'F'};
    graph['G'].weight = 2;

    graph['H'].inputs = {'C'};
    graph['H'].weight = 1;
    


    Solution solution;
    std::pair<std::vector<char>, int> result = solution.calculateTotalTime(graph, 'G'); 

    std::cout << "Potential ordering:\n";
    for (auto& c : result.first) {
        std::cout << c <<" "; 
    }
    std::cout << std::endl;

    std::cout << result.second << std::endl;
}