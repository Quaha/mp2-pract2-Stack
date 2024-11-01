#include "Stack.h"

#include <gtest.h>
#include <vector>
#include <random>

TEST(Stack, can_create_stack) {
	ASSERT_NO_THROW(Stack<int> stack);
}

TEST(Stack, default_constructor) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, correct_push_back_working) {
	Stack<int> stack;

	for (int i = 0; i < 100; i++) {
		stack.push_back(i);
		EXPECT_EQ(stack.back(), i);
	}
}

TEST(Stack, push_back_and_size) {
    Stack<int> stack;
    stack.push_back(5);
    stack.push_back(10);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 2);
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

TEST(Stack, pop_back_and_size) {
    Stack<int> stack;
    stack.push_back(5);
    stack.push_back(10);
    stack.pop_back();

    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.back(), 5);
}


TEST(Stack, back_on_empty_stack) {
    Stack<int> stack;
    EXPECT_ANY_THROW(stack.back());
}

TEST(Stack, pop_back_on_empty_stack) {
    Stack<int> stack;
    EXPECT_ANY_THROW(stack.pop_back());
}

TEST(Stack, copy_constructor) {
    Stack<int> stack1;
    stack1.push_back(1);
    stack1.push_back(2);

    Stack<int> stack2(stack1);

    EXPECT_EQ(stack2.size(), stack1.size());
    EXPECT_EQ(stack2.back(), stack1.back());

    stack2.pop_back();
    EXPECT_NE(stack2.size(), stack1.size());
}

TEST(Stack, copy_assignment_operator1) {
    Stack<int> stack1;
    stack1.push_back(5);
    stack1.push_back(10);

    Stack<int> stack2;
    stack2 = stack1;

    EXPECT_EQ(stack2.size(), stack1.size());
    EXPECT_EQ(stack2.back(), stack1.back());

    stack2.pop_back();
    EXPECT_NE(stack2.size(), stack1.size());
}

TEST(Stack, copy_assignment_operator2) {
    Stack<int> stack1;
    stack1.push_back(5);
    
    ASSERT_NO_THROW(stack1 = stack1);
}

TEST(Stack, move_constructor) {
    Stack<int> stack1;
    stack1.push_back(8);
    stack1.push_back(16);

    Stack<int> stack2(std::move(stack1));

    EXPECT_EQ(stack2.size(), 2);
    EXPECT_EQ(stack2.back(), 16);
    EXPECT_TRUE(stack1.empty());
}

TEST(Stack, move_assignment_operator1) {
    Stack<int> stack1;
    stack1.push_back(8);
    stack1.push_back(16);

    Stack<int> stack2;
    stack2 = std::move(stack1);

    EXPECT_EQ(stack2.size(), 2);
    EXPECT_EQ(stack2.back(), 16);
    EXPECT_TRUE(stack1.empty());
}

TEST(Stack, move_assignment_operator2) {
    Stack<int> stack1;
    stack1.push_back(5);

    ASSERT_NO_THROW(stack1 = std::move(stack1));
}

TEST(Stack, large_number_of_elements) {
    Stack<int> stack;
    for (int i = 0; i < 1000; ++i) {
        stack.push_back(i);
    }

    EXPECT_EQ(stack.size(), 1000);
    EXPECT_EQ(stack.back(), 999);
}

TEST(Stack, push_and_pop_multiple_times) {
    Stack<int> stack;
    for (int i = 0; i < 5; ++i) {
        stack.push_back(i);
    }
    for (int i = 0; i < 5; ++i) {
        stack.pop_back();
    }

    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

TEST(Stack, empty_after_push_and_pop) {
    Stack<int> stack;
    stack.push_back(1);
    stack.pop_back();

    EXPECT_TRUE(stack.empty());
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

TEST(Stack, stress_test) {
    srand(time(0));
    
    int COUNT_OF_TESTS = 1000;
    int ACTIONS_PER_TEST = 10000;

    for (int CURR_TEST_CASE = 0; CURR_TEST_CASE < COUNT_OF_TESTS; CURR_TEST_CASE++) {
        Stack<int> stack;
        std::vector<int> stack_copy;

        for (int CURR_ACTION = 0; CURR_ACTION < ACTIONS_PER_TEST; CURR_ACTION++) {
            int type = rand() % 2;

            if (type == 0) {
                int value = rand();
                stack.push_back(value);
                stack_copy.push_back(value);
            }
            if (type == 1) {
                if (!stack.empty()) {
                    stack.pop_back();
                    stack_copy.pop_back();
                }
            }

            if (!stack.empty()) {
                EXPECT_EQ(stack.back(), stack_copy.back());
            }
            EXPECT_EQ(stack.size(), stack_copy.size());
        }
    }
}
