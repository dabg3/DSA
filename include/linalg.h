// a.shape = (m, n) 
// b.shape = (n, p)
int* matmul(int* a, int* b, int m, int n, int p, int* out);

// stride parameters for non-contiguous arrays
int dot_product(int* a, int* b, int size, int stride_a, int stride_b);
