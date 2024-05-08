#include "sorting.h"
#include "unity.h"
#include <stdio.h>
#include <string.h>

void setUp() {
        // called before each test
}

void tearDown() {
        // called after each test
}

/* unused utilities - to be (re)moved */

void print_a(int* arr, int size) {
        for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

void* applycpy(int* (*f)(int*, int), 
                int* dest, void* src, int n) {
        int bytes = 4 * n;
        //printf("%d\n", sizeof(*src));
        memcpy(dest, src, bytes);
        return (*f)(dest, n);
}

void* fill_0s(int* arr, int size) {
        for(int i = 0; i < size; i++) {
                arr[i] = 0;
        }
        return arr;
}

/* tests */

#define SIZE 5
void test_insertion_sort() {
        int input[SIZE] = {0, 1, 5, 2, 1};
        int expected[SIZE] = {0, 1, 1, 2, 5};

        insertion_sort(input, SIZE);

        TEST_ASSERT_EQUAL_INT_ARRAY(expected, input, SIZE);
}

void test_linear_search_success() {
        int input[SIZE] = {0, 1, 5, 2, 1};
        int n = 5;
        int expected = 2;

        int res = linear_search(n, input, SIZE);

        TEST_ASSERT_EQUAL_INT(expected, res);
}

void test_linear_search_fail() {
        int input[SIZE] = {0, 1, 5, 2, 1};
        int n = 3;
        int expected = -1;

        int res = linear_search(n, input, SIZE);

        TEST_ASSERT_EQUAL_INT(expected, res);
}


int main() {
        UNITY_BEGIN();
        RUN_TEST(test_insertion_sort);
        RUN_TEST(test_linear_search_success);
        RUN_TEST(test_linear_search_fail);
        return UNITY_END();
}
