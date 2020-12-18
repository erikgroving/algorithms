#include "Solution.hpp"

std::pair<std::vector<char>, int> Solution::calculateTotalTime(std::unordered_map<char, Node> graph, char target) {

    // times will be used for dynamic programming to save results of intermediate nodes 
    // so we only ever calculate time for intermediate nodes once.
    std::unordered_map<char, int> times;
    for (auto& node : graph) {
        times[node.first] = -1;
    }
    std::vector<char> order;
    int result = calculateTotalTimeHelper(graph, target, order, times); 

    return std::make_pair(order, result);
}

int Solution::calculateTotalTimeHelper(std::unordered_map<char, Node> graph, 
                                       char target,
                                       std::vector<char>& order,
                                       std::unordered_map<char, int>& times) {
    
    if (times[target] != -1) {
        return times[target];
    }

    Node currNode = graph[target];
    
    if (currNode.inputs.size() == 0) {
        // For leaf node, just return current weight
        times[target] = currNode.weight;
    }
    else {
        // Otherwise, the value is the maximum input time
        for (auto& input : currNode.inputs) {
            times[target] = std::max(times[target], currNode.weight + calculateTotalTimeHelper(graph, input, order, times));
        }
    }
    
    // topological sort for ordering
    order.push_back(target);
    return times[target];
}