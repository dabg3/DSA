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
