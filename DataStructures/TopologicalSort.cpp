#include "TopologicalSort.h"

void TopologicalSort(std::vector<int> indegree, const std::vector<std::vector<int>>& adjList) {
    int n = adjList.size();
    std::stack<int> st;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            st.push(i);
        }
    }

    int count = 0;

    while (!st.empty()) {
        int idx = st.top();
        std::cout << "V" << idx << " ";
        st.pop();
        count += 1;

        for (int i = 0; i < adjList[idx].size(); i++) {
            int pos = adjList[idx][i];
            indegree[pos] -= 1;
            if (indegree[pos] == 0) {
                st.push(pos);
            }
        }
    }

    if (count != n) {
        std::cout << "Circle exit, invaild sort" << std::endl;
    }
}