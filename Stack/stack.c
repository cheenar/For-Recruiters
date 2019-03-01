#include "stack.h"

Stack *init_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->data = malloc(sizeof(StackData));
  stack->capacity = 1;
  stack->size = 0;
  return stack;
}

void resize(Stack *stack) {
  if (stack->size == stack->capacity) {
    stack->capacity *= 2;
    void *ptr = realloc(stack->data, sizeof(Stack) * stack->capacity);
  }
}

void push(Stack *stack, StackData *s_data) {
  resize(stack);
  stack->data[stack->size] = s_data;
  stack->size += 1;
}

StackData *pop(Stack *stack) {
  if (!stack || stack->size <= 0) {
    return 0;
  }
  StackData *d = stack->data[stack->size - 1];
  stack->size -= 1;
  return d;
}

int main(void) {
 Stack *s = init_stack();

 StackData *d1 = malloc(sizeof(StackData));
 d1->string = "Exxon Mobil";

 StackData *d2 = malloc(sizeof(StackData));
 d2->integer = 123;
 
 push(s, d1);
 push(s, d2);
 printf("%d\n", pop(s)->integer);
 printf("%s\n", pop(s)->string);
}

