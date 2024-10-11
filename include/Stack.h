#pragma once

template <typename StackType> class Stack {
private:

	StackType* prev_stack = nullptr; // curr_capacity / 2
	StackType* curr_stack = nullptr; // curr_capacity
	StackType* next_stack = nullptr; // curr_capacity * 2

	int sz = 0;
	int curr_capacity = 2;

	int lup = 0; // last unpushed prev
	int lun = 0; // last unpushed next

	static void destruct(Stack* stack) {
		delete[] stack->prev_stack;
		delete[] stack->curr_stack;
		delete[] stack->next_stack;
	}

	static void construct(Stack* stack) {
		stack->prev_stack = new StackType[1];
		stack->curr_stack = new StackType[2];
		stack->next_stack = new StackType[4];

		stack->sz = 0;
		stack->curr_capacity = 2;
		stack->lup = 0;
		stack->lun = 0;
	}

public:

	Stack() {
		construct(this);
	}

	~Stack() {
		destruct(this);
	}

	Stack(const Stack& other) {

	}

	Stack(Stack&& other) {

	}

	Stack& operator=(const Stack& other) {
		if (this == &other) return;

	}

	Stack& operator=(Stack&& other) {
		if (this == &other) return;

	}

	void push_back(const StackType& value) {

	}

	StackType pop_back() {

	}

	StackType back() const {

	}

	size_t size() const {
		return sz;
	}

	bool empty() const {
		return sz == 0;
	}
};