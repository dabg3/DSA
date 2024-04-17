#include "sorting.h"

int* insertion_sort(int* arr, int size) {
	for(int i = 1; i < size; i++) {
		int curr = arr[i];
		int e = i - 1;
		for(; e >= 0 && arr[e] > curr; e--) {
			arr[e+1] = arr[e];
		}
		arr[e + 1] = curr;
	}
	return arr;
}
