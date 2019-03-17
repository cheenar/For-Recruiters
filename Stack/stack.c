#include "stack.h"

Stack *init_stack(size_t type_size) {
  Stack *stack = malloc(sizeof(Stack));
  stack->data = malloc(type_size);
  stack->capacity = 1;
  stack->size = 0;
  stack->type_size = type_size;
  return stack;
}

void resize(Stack *stack) {
  if (stack->size == stack->capacity) {
    stack->capacity *= 2;
    void *ptr = realloc(stack->data, stack->type_size * stack->capacity);
  }
}

void push(Stack *stack, void *ptr) {
  resize(stack);
  stack->data[stack->size] = ptr;
  stack->size += 1;
}

void *pop(Stack *stack) {
  if (!stack || stack->size <= 0) {
    return 0;
  }
  void *d = stack->data[stack->size - 1];
  stack->size -= 1;
  return d;
}

int main(void) {
 Stack *s = init_stack(sizeof(int));

 void *d1 = malloc(sizeof(int));
 void *d2 = malloc(sizeof(int));

 *((int *)d1) = 4;
 *((int *)d2) = 5;

 push(s, d1);
 push(s, d2);
 printf("%d\n", *((int *)pop(s)));
 printf("%d\n", *((int *)pop(s)));
 
 free(d1);
 free(d2);
 
 int i;
 int ops = 10;

 for (i = 0; i < ops; i++) {
   void *d = malloc(sizeof(int));
   *((int*)d) = i;
   push(s, d);
 }

 printf("size of stack: %d\n", s->size);
 printf("capacity of stack: %d\n", s->capacity);
 
 for (i = 0; i < ops; i++) {
   void *d = pop(s);
   printf("%d,", *((int*)d));
 }

 //free(s);
}







