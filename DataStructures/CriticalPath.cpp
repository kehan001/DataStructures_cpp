//Test case




#include "CriticalPath.h"

void critical_path(const std::vector<std::vector<std::pair<int, int>>>& adjList) {
    const int n = adjList.size();
    const int MAX = 1e9;

    std::vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            indegree[adjList[i][j].first]++;
        }
    }

    std::vector<int> etv(n, 0);
    std::vector<int> ltv(n, MAX);
    std::stack<int> st1;
    std::stack<int> st2;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            st1.push(i);
        }
    }

    while (!st1.empty()) {
        int curr = st1.top();
        st2.push(curr);
        st1.pop();

        for (int i = 0; i < adjList[curr].size(); i++) {
            int point = adjList[curr][i].first;
            int weight = adjList[curr][i].second;

            indegree[point]--;
            if (indegree[point] == 0) {
                st1.push(point);
            }

            etv[point] = std::max(etv[point], etv[curr] + weight);
        }
    }

    ltv[n - 1] = etv[n - 1];
    while (!st2.empty()) {
        int curr = st2.top();
        st2.pop();

        for (int i = 0; i < adjList[curr].size(); i++) {
            int point = adjList[curr][i].first;
            int weight = adjList[curr][i].second;

            ltv[curr] = std::min(ltv[curr], ltv[point] - weight);
        }
    }

    for (int i = 0; i < n; i++) {
        if (etv[i] == ltv[i]) {
            std::cout << "V" << i << " -> ";
        }
    }
}