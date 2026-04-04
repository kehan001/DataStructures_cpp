#include "HeapSort.h"

void adjust(std::vector<int>& list, int root, int len) {
	int temp = list[root];
	int child = root * 2;

	while (child <= len) {
		if (child < len && list[child] < list[child + 1]) {
			child++;
		}

		if (temp >= list[child]) {
			break;
		}

		list[child / 2] = list[child];
		child *= 2;
	}

	list[child / 2] = temp;
}

void swap(std::vector<int>& list, int idx) {
	int temp = list[idx];
	list[idx] = list[1];
	list[1] = temp;
}

void heapSort(std::vector<int>& list) {
	int n = list.size() - 1;
	for (int i = n / 2; i > 0; i--) {
		adjust(list, i, n);
	}

	for (int i = n; i > 1; i--) {
		swap(list, i);
		adjust(list, 1, i - 1);
	}
}