#include <stdio.h>
#include <stdlib.h>

typedef union stack_data {
  int integer;
  char character;
  char *string;
  double doub;
} StackData;

typedef struct stack {
  StackData **data;
  int size;
  int capacity;
} Stack;

Stack* init_stack();
void resize(Stack *stack);
void push(Stack *stack, StackData *s_data);
StackData *pop(Stack *stack);
