//Test case

//int n = 9;
//const int MAX = 1e9;
//vector<vector<int>> G;
//for (int i = 0; i < n; i++) {
//	vector<int> temp;
//	for (int j = 0; j < n; j++) {
//		if (i == j) {
//			temp.push_back(0);
//		}
//		else {
//			temp.push_back(MAX);
//		}
//	}
//	G.push_back(temp);
//}
//
//G[0][1] = 10;
//G[0][5] = 11;
//
//// B-C  B-G  B-I
//G[1][2] = 18;
//G[1][6] = 16;
//G[1][8] = 12;
//
//// C-D  C-I
//G[2][3] = 22;
//G[2][8] = 8;
//
//// D-E  D-G  D-H  D-I
//G[3][4] = 20;
//G[3][6] = 24;
//G[3][7] = 16;
//G[3][8] = 21;
//
//// E-F  E-H
//G[4][5] = 26;
//G[4][7] = 7;
//
//// F-G
//G[5][6] = 17;
//
//// G-H
//G[6][7] = 19;
//
//for (int i = 0; i < n; i++) {
//	for (int j = i; j < n; j++) {
//		G[j][i] = G[i][j];
//	}
//}
//
//cout << prim(G) << endl;

#include "Prim.h"

int prim(const std::vector<std::vector<int>>& G) {
	int totalWeight = 0;
	int MAX = 1e9;
	int n = G.size();
	std::vector<int> weight(n, 0);
	std::vector<int> prevNode(n, 0);

	for (int i = 0; i < n; i++) {
		weight[i] = G[0][i];
	}
	weight[0] = 0;
	prevNode[0] = 0;

	for (int i = 0; i < n; i++) {
		int minVal = MAX;
		int k = 0;

		for (int j = 0; j < n; j++) {
			if (weight[j] != 0 && weight[j] < minVal) {
				k = j;
				minVal = weight[j];
			}
		}

		if (k == 0) {
			break;
		}
		totalWeight += weight[k];
		weight[k] = 0;

		for (int j = 0; j < n; j++) {
			if (weight[j] != 0 and G[k][j] < weight[j]) {
				weight[j] = G[k][j];
				prevNode[j] = k;
			}
		}
	}

	return totalWeight;
}