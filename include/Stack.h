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

	void destruct() {
		delete[] prev_stack;
		delete[] curr_stack;
		delete[] next_stack;
	}

	void construct(Stack* stack) {
		stack->prev_stack = new StackType[1];
		stack->curr_stack = new StackType[2];
		stack->next_stack = new StackType[4];
	}

public:

	Stack() {
		construct(this);
	}

	~Stack() {
		destruct();
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

	bool empty() {
		return sz == 0;
	}
};