#include "sorting.h"
#include "linalg.h"

int* insertion_sort(int* arr, int size) {
	for (int i = 1; i < size; i++) {
		int curr = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > curr; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = curr;
	}
	return arr;
}

int dot_product(int* a, int* b, int size, int stride_a, int stride_b) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(a + stride_a * i) * *(b + stride_b * i);
	}
	return sum;
}

int* matmul(int* a, int* b, int m, int n, int p, int* out) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < p; j++) {
			// out[i, j] = a[i] * b[:, j]
			*(out + i * p + j) = 
				dot_product(a + i * n, // a[i, 0]
					    b + j,     // b[0, j]
					    n,
					    1, 	       // row-wise offset
					    p);	       // column-wise offset
		}
	}
	return out;
}


