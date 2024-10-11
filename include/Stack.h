#pragma once

template <typename StackType> class Stack {
private:

	StackType* prev_stack = nullptr; // curr_capacity / 2
	StackType* curr_stack = nullptr; // curr_capacity
	StackType* next_stack = nullptr; // curr_capacity * 2

	int curr_capacity = 2;

	int prev_sz = 0;
	int curr_sz = 1; // there is a fake element in order to simplify the implementation
	int next_sz = 0;

	void destruct(Stack* stack) {
		delete[] stack->prev_stack;
		delete[] stack->curr_stack;
		delete[] stack->next_stack;
	}

	void construct(Stack* stack) {
		stack->prev_stack = new StackType[1]();
		stack->curr_stack = new StackType[2]();
		stack->next_stack = new StackType[4]();

		stack->curr_sz = 1;
		stack->curr_capacity = 2;
		stack->prev_sz = 0;
		stack->next_sz = 0;
	}

public:

	Stack() {
		construct(this);
	}

	~Stack() {
		destruct(this);
	}

	Stack(const Stack& other) {
		this->curr_capacity = other.curr_capacity;

		this->prev_stack = new StackType[curr_capacity / 2];
		this->prev_stack = new StackType[curr_capacity];
		this->prev_stack = new StackType[curr_capacity * 2];

		this->curr_sz = other.curr_sz;
		this->prev_sz = other.prev_sz;
		this->next_sz = other.next_sz;

		for (int i = 0; i < prev_sz; ++i) {
			this->prev_stack = other.prev_stack[i];
		}

		for (int i = 0; i < curr_sz; ++i) {
			this->curr_stack = other.curr_stack[i];
		}

		for (int i = 0; i < next_sz; ++i) {
			this->next_stack = other.next_stack[i];
		}
	}

	Stack(Stack&& other) {
		this->prev_stack = other.prev_stack;
		this->curr_stack = other.curr_stack;
		this->next_stack = other.next_stack;

		this->curr_capacity = other.curr_capacity;

		this->curr_sz = other.curr_sz;
		this->prev_sz = other.prev_sz;
		this->next_sz = other.next_sz;

		construct(other);
	}

	Stack& operator=(const Stack& other) {
		if (this == &other) return;

		this->curr_capacity = other.curr_capacity;

		this->prev_stack = new StackType[curr_capacity / 2];
		this->prev_stack = new StackType[curr_capacity];
		this->prev_stack = new StackType[curr_capacity * 2];

		this->curr_sz = other.curr_sz;
		this->prev_sz = other.prev_sz;
		this->next_sz = other.next_sz;

		for (int i = 0; i < prev_sz; ++i) {
			this->prev_stack = other.prev_stack[i];
		}

		for (int i = 0; i < curr_sz; ++i) {
			this->curr_stack = other.curr_stack[i];
		}

		for (int i = 0; i < next_sz; ++i) {
			this->next_stack = other.next_stack[i];
		}
	}

	Stack& operator=(Stack&& other) {
		if (this == &other) return;

		destruct(this);

		this->prev_stack = other.prev_stack;
		this->curr_stack = other.curr_stack;
		this->next_stack = other.next_stack;

		this->curr_capacity = other.curr_capacity;

		this->curr_sz = other.curr_sz;
		this->prev_sz = other.prev_sz;
		this->next_sz = other.next_sz;

		construct(other);
	}

	void push_back(const StackType& value) {
		curr_stack[curr_sz] = value;
		++curr_sz;
		
		next_stack[next_sz] = curr_stack[next_sz];
		next_stack[next_sz + 1] = curr_stack[next_sz + 1];

		next_sz += 2;

		if (curr_sz == curr_capacity) {
			delete[] prev_stack;

			prev_stack = curr_stack;
			curr_stack = next_stack;

			curr_capacity *= 2;
			next_stack = new StackType[curr_capacity * 2];

			prev_sz = 0;
			next_sz = 0;
		}
	}

	void pop_back() {
		if (empty()) {
			throw std::out_of_range("It is forbidden to use the method .pop_back() on an empty stack!");
		}

		--curr_sz;

		if (next_sz != 0) {
			next_sz -= 2;
		}
		else {
			prev_stack[prev_sz] = curr_stack[prev_sz];
			++prev_sz;
		}

		if (curr_sz == curr_capacity / 4) {
			delete[] next_stack;

			next_stack = curr_stack;
			curr_stack = prev_stack;

			curr_capacity /= 2;

			prev_stack = new StackType[curr_capacity / 2];

			prev_sz = 0;
			next_sz = 0;
		}
	}

	StackType back() const {
		if (empty()) {
			throw std::out_of_range("It is forbidden to use the method .back() on an empty stack!");
		}
		return curr_stack[curr_sz - 1];
	}

	size_t size() const {
		return curr_sz - 1;
	}

	bool empty() const {
		return curr_sz == 1;
	}
};