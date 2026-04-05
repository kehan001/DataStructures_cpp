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
