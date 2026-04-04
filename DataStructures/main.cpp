#include <iostream>
using namespace std;
#include <vector>
#include "HeapSort.h"

int main() {
	vector<int> v = {-1, 47, 35, 60, 95, 77, 15, 28};
	heapSort(v);
	for (vector<int>::const_iterator it = ++v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}

}