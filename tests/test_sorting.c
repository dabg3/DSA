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

int main() {
        UNITY_BEGIN();
        RUN_TEST(test_insertion_sort);
        return UNITY_END();
}
