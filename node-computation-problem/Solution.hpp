#pragma once 

#include <utility>
#include <vector>
#include <unordered_map>

class Node {
public:
    std::vector<char> inputs;
    int weight;
};

class Solution {
public:
    std::pair<std::vector<char>, int> calculateTotalTime(std::unordered_map<char, Node> graph, char target);
    int calculateTotalTimeHelper(std::unordered_map<char, Node> graph, 
                                    char target,
                                    std::vector<char>& order,
                                    std::unordered_map<char, int>& times);
};