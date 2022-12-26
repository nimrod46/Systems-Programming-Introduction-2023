#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
typedef void* Element;
typedef struct Stack* Stack;

Stack StackCreate(Element (*clone_func)(Element),
                  void (*free_func)(Element));

void StackDestroy(Stack st);

// Push (a clone of) elem to stack
void StackPush(Stack st, Element elem);

// Pop and return top element or NULL on stack empty
Element StackPop(Stack st);

// Returns top element or NULL on stack empty
Element StackTop(Stack st);

bool StackIsEmpty(Stack st);

#endif