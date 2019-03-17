#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_CAPACITY 2

typedef struct stack {
  void **data;
  int size;
  int capacity;
} Stack;

Stack* init_stack();
void resize(Stack *stack);
void push(Stack *stack, void *ptr);
void *pop(Stack *stack);
