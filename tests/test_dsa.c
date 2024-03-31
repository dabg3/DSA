#include "dsa.h"
#include "unity.h"
#include <stdio.h>

void setUp() {
	// called before each test
}

void tearDown() {
	// called after each test
}

void test_example() {
	TEST_ASSERT(algo() == 0);
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_example);
	return UNITY_END();
}
