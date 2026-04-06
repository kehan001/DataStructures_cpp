//Test case


//vector<vector<pair<int, int>>> graph = {
//        {{1,7}, {2,9}, {5,14}},
//        {{0,7}, {2,10}, {3,15}},
//        {{0,9}, {1,10}, {3,11}, {5,2}},
//        {{1,15}, {2,11}, {4,6}},
//        {{3,6}, {5,9}},
//        {{0,14}, {2,2}, {4,9}}
//};
//
//vector<int> dist = Dijkstra_Heap(0, graph);
//for (int i = 0; i < dist.size(); i++) {
//    cout << dist[i] << " ";
//}



#include "Dijkstra_Heap.h"

bool compare::operator() (const std::pair<int, int>& p1, const std::pair<int, int>& p2) const{
    return p1.second > p2.second;
}


std::vector<int> Dijkstra_Heap(int start, std::vector<std::vector<std::pair<int, int>>>& G) {
    const int MAX = 1e9;
    std::vector<bool> visit(G.size(), false);
    std::vector<int> dist(G.size(), MAX);
    std::priority_queue <std::pair<int, int>, std::vector<std::pair<int, int>>, compare > que;
    que.push(std::make_pair(start, 0));
    dist[start] = 0;

    while (!que.empty()) {
        std::pair<int, int> curr = que.top();
        que.pop();

        if (visit[curr.first] || curr.second > dist[curr.first]) {
            continue;
        }

        visit[curr.first] = true;

        for (std::vector<std::pair<int, int>>::const_iterator it = G[curr.first].begin(); it != G[curr.first].end(); it++) {
            if (!visit[(*it).first] && curr.second + (*it).second < dist[(*it).first]) {
                que.push(std::make_pair((*it).first, curr.second + (*it).second));
                dist[(*it).first] = curr.second + (*it).second;
            }
        }
    }

    return dist;
}
