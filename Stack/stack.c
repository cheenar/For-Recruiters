#include "stack.h"

Stack* init_stack() {
	Stack *stack = malloc(sizeof(Stack));
	stack->data = malloc(sizeof(void*) * DEFAULT_CAPACITY);
	stack->size = 0;
	stack->capacity = DEFAULT_CAPACITY;
	return stack;
}

void resize(Stack *stack) {
	if (stack->size == stack->capacity) {
		stack->capacity *= 2;
		stack->data = realloc(stack->data, sizeof(void*) * stack->capacity);
	}
}

void push(Stack *stack, void *ptr) {
	resize(stack);
	stack->data[stack->size] = ptr;
	stack->size += 1;
}

void *pop(Stack *stack) {
	if (stack->size == 0) {
		return 0;
	}
	stack->size -= 1;
	return stack->data[stack->size];
}

int *gen_int(int i) {
	int *k = malloc(sizeof(int));
	*k = i + 1;
	return k;
}

void int_test(Stack *s) {
	for (int i = 0; i < 100; i++) {
		void *j = gen_int(i);
		push(s, j);
	}

	printf("Capacity: %d\n", s->capacity);
	printf("Size: %d\n", s->size);

	for (int i = 0; i < 100; i++) {
		void *j = pop(s);
		if (i % 10 == 0) printf("%i,", *((int*)j));
		free(j);
	}
	printf("\n");
}

void string_test(Stack *s) {
	char *a = "testa";
	char *b = "testb";
	void *i = a;
	void *j = b;
	push(s, i);
	push(s, j);
	i = pop(s);
	j = pop(s);
	printf("%s\n",i);
	printf("%s\n",j);
}

int main(void) {
	Stack *s = init_stack();
	
	//int_test(s);
	string_test(s);

	free(s->data);
	free(s);
}
