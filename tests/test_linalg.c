#include "linalg.h"
#include "unity.h"

void setUp() {
        // called before each test
}

void tearDown() {
        // called after each test
}

void test_matmul() {
        const int m = 2;
        const int n = 3;
        const int p = 3;
        int a[2*3] = {1, 2, 3, 
                      4, 5, 6};
        int b[3*3] = {1, 1, 1,
                      1, 1, 1, 
                      1, 1, 2};
        int expected[2*3] = {6,  6,  9,
                             15, 15, 21};

        int out[2*3] = {0, 0, 0, 
                        0, 0, 0};
        matmul(a, b, m, n, p, out);

        TEST_ASSERT_EQUAL_INT_ARRAY(expected, out, m*p);
}

void test_matmul_vectors() {
        // matmul on vectors == dot product
        int a[3] = {0, 1, 1};
        int b[3] = {1, 2, 3};
        int expected = 5;

        int out = 0;
        matmul(a, b, 1, 3, 1, &out);

        TEST_ASSERT_EQUAL_INT(expected, out);
}

int main() {
        UNITY_BEGIN();
        RUN_TEST(test_matmul);
        RUN_TEST(test_matmul_vectors);
        return UNITY_END();
}
