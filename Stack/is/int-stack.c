#include "int-stack.h"

int size;
int capacity;
int *stack;

void setup() {
	size = 0;
	capacity = 2;
	stack = malloc(sizeof(int) * capacity);
}

void resize() {
	capacity = capacity * 2;
	realloc(stack, sizeof(int) * capacity);
}

void push(int val) {
	if (size == capacity) resize();
	stack[size] = val;
	size++;
}

int pop() {
	if (size == 0) return -1;
	int val = stack[size - 1];
	stack[size - 1] = 0;
	size -= 1;
	return val;
}


// test
int main(void) {
	setup();
	push(5);
	push(4);
	printf("%d\n", pop());
	printf("%d\n", pop());
}
