#pragma once
#include <vector>
#include <queue>

class compare {
public:
    bool operator() (const std::pair<int, int>& p1, const std::pair<int, int>& p2) const;
};

std::vector<int> Dijkstra_Heap(int start, std::vector<std::vector<std::pair<int, int>>>& G);