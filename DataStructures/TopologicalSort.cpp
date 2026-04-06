//Test case


//const int vertexNum = 14;
//const int edgeNum = 20;
//
//vector<vector<int>> G(vertexNum, vector<int>(vertexNum, 0));
//
//G[0][4] = 1;
//G[0][5] = 1;
//G[0][11] = 1;
//
//G[1][2] = 1;
//G[1][4] = 1;
//G[1][8] = 1;
//
//G[2][5] = 1;
//G[2][6] = 1;
//G[2][9] = 1;
//
//G[3][2] = 1;
//G[3][13] = 1;
//
//G[4][7] = 1;
//
//G[5][8] = 1;
//G[5][12] = 1;
//
//G[6][5] = 1;
//
//G[8][7] = 1;
//
//G[9][10] = 1;
//G[9][11] = 1;
//
//G[10][13] = 1;
//
//G[12][9] = 1;
//
//
//vector<int> indegree(vertexNum, 0);
//vector<vector<int>> adjList(vertexNum);
//
//for (int i = 0; i < vertexNum; i++) {
//    for (int j = 0; j < vertexNum; j++) {
//        if (G[i][j] == 1) {
//            adjList[i].push_back(j);
//            indegree[j] += 1;
//        }
//
//    }
//}
//
//
//TopologicalSort(indegree, adjList);


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