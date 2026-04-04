//Test case

//int vertex[9];
//int n = sizeof(vertex) / sizeof(vertex[0]);
//for (int i = 0; i < n; i++) {
//    vertex[i] = i;
//}
//
//const int MAX = 1e9;
//vector<vector<int>> G;
//for (int i = 0; i < n; i++) {
//    vector<int> line;
//    for (int j = 0; j < n; j++) {
//        if (i == j) {
//            line.push_back(0);
//        }
//        else {
//            line.push_back(MAX);
//        }
//    }
//    G.push_back(line);
//}
//
//G[0][1] = 1;
//G[0][2] = 5;
//
//G[1][2] = 3;
//G[1][3] = 7;
//G[1][4] = 5;
//
//G[2][4] = 1;
//G[2][5] = 7;
//
//G[3][4] = 2;
//G[3][6] = 3;
//
//G[4][5] = 3;
//G[4][6] = 6;
//G[4][7] = 9;
//
//G[5][7] = 5;
//
//G[6][7] = 2;
//G[6][8] = 7;
//
//G[7][8] = 4;
//
//for (int i = 0; i < n; i++) {
//    for (int j = i; j < n; j++) {
//        G[j][i] = G[i][j];
//    }
//}
//
//int begin = 0;
//
//result res = dijkstra(begin, G);
//for (vector<int>::const_iterator it = res.path.begin(); it != res.path.end(); it++) {
//    cout << *it << " ";
//}
//cout << endl;
//
//printPath(res, begin);


#include "Dijkstra.h"
#include <iostream>


int choose(const std::vector<int>& distance, const std::vector<int>& visit) {
    const int MAX = 1e9;
    int minPos = -1;
    int min = MAX;

    for (int i = 0; i < distance.size(); i++) {
        if (distance[i] < min && visit[i] == 0) {
            min = distance[i];
            minPos = i;
        }
    }

    return minPos;
}

result dijkstra(int begin, const std::vector<std::vector<int>>& G) {
    const int MAX = 1e9;

    int n = G.size();
    std::vector<int> path(n, -1);
    std::vector<int> distance(n, MAX);
    std::vector<int> visit(n, 0);

    for (int i = 0; i < n; i++) {
        path[i] = -1;
        distance[i] = G[begin][i];
        visit[i] = 0;
    }

    distance[begin] = 0;
    visit[begin] = 1;

    for (int i = 0; i < n; i++) {
        int next = choose(distance, visit);
        if (next == -1) {
            break;
        }

        visit[next] = 1;

        for (int i = 0; i < n; i++) {
            if (visit[i] == 0) {
                if (G[next][i] + distance[next] < distance[i]) {
                    distance[i] = G[next][i] + distance[next];
                    path[i] = next;
                }
            }
        }
    }

    result res;
    res.distance = distance;
    res.path = path;
    return res;
}



void printPath(const result& res, int begin) {
    for (int i = 0; i < res.distance.size(); i++) {
        std::cout << "V" << begin << "->V" << i << " = " << res.distance[i] << std::endl;
        int j = i;
        while (res.path[j] != -1) {
            std::cout << "V" << j << " -> ";
            j = res.path[j];
        }
        std::cout << "V" << begin << std::endl;
        std::cout << std::endl;
    }
}
