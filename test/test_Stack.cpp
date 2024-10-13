#include "Stack.h"

#include <gtest.h>

// constructor
TEST(Stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> stack);
}

// push_back, pop_back and back
TEST(Stack, correct_push_back_working) {
	Stack<int> stack;

	for (int i = 0; i < 100; i++) {
		stack.push_back(i);
		EXPECT_EQ(stack.back(), i);
	}
}

TEST(Stack, correct_pop_back_working) {
	Stack<int> stack;

	for (int i = 0; i < 100; i++) {
		stack.push_back(i);
	}

	for (int i = 99; i >= 0; i--) {
		EXPECT_EQ(stack.back(), i);
		stack.pop_back();
	}
}

TEST(Stack, combination_of_push_and_pop_1) {
	Stack<int> stack;

	for (int i = 0; i < 100; i++) {
		stack.push_back(i);
	}

	for (int i = 0; i < 100; i++) {
		stack.pop_back();
	}

	for (int i = 0; i < 100; i++) {
		stack.push_back(i);
		EXPECT_EQ(stack.back(), i);
	}

	for (int i = 99; i >= 0; i--) {
		EXPECT_EQ(stack.back(), i);
		stack.pop_back();
	}
}

TEST(Stack, combination_of_push_and_pop_2) {
	Stack<int> stack;

	for (int i = 0; i < 16; i++) {
		ASSERT_NO_THROW(stack.push_back(i));
	}

	ASSERT_NO_THROW(stack.pop_back());
	for (int i = 0; i < 20; i++) {
		ASSERT_NO_THROW(stack.push_back(i));
	}

	while (!stack.empty()) {
		ASSERT_NO_THROW(stack.pop_back());
	}
}
