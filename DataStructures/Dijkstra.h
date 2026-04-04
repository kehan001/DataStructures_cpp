#pragma once

#include <vector>

struct result {
    std::vector<int> path;
    std::vector<int> distance;
};

int choose(const std::vector<int>& distance, const std::vector<int>& visit);
result dijkstra(int begin, const std::vector<std::vector<int>>& G);
void printPath(const result& res, int begin);


