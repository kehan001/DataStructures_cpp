#include <iostream>
using namespace std;
#include "Dijkstra_Heap.h"

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1,7}, {2,9}, {5,14}},
        {{0,7}, {2,10}, {3,15}},
        {{0,9}, {1,10}, {3,11}, {5,2}},
        {{1,15}, {2,11}, {4,6}},
        {{3,6}, {5,9}},
        {{0,14}, {2,2}, {4,9}}
    };

    vector<int> dist = Dijkstra_Heap(0, graph);
    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }

}