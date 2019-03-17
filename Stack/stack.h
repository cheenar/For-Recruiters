#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  void **data;
  size_t type_size;
  int size;
  int capacity;
} Stack;

Stack* init_stack();
void resize(Stack *stack);
void push(Stack *stack, void *ptr);
void *pop(Stack *stack);
