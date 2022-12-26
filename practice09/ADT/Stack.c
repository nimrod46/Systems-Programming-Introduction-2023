#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"

struct Stack {
    Element *elements;
    size_t num_elements;
    size_t alloc_size;
    Element (*clone_func)(Element);
    void (*free_func)(Element);
};

#define QUOTA 512

Stack StackCreate(Element (*clone_func)(Element),
                  void (*free_func)(Element)) {
    Stack st = malloc(sizeof(struct Stack));
    if (st == NULL) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
                __FILE__, __LINE__, sizeof(struct Stack));
        exit(-1);
    }
    st->num_elements = 0;
    st->alloc_size = QUOTA;
    st->elements = malloc(QUOTA*sizeof(Element));
    if (st->elements == NULL) {
        fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
                __FILE__, __LINE__, QUOTA*sizeof(Element));
        exit(-1);
    }
    st->clone_func = clone_func;
    st->free_func = free_func;
}

void StackDestroy(Stack st) {
    for(size_t i = 0; i<st->num_elements; i++)
        st->free_func(st->elements[i]);
    free(st->elements);
    free(st);
}

void StackPush(Stack st, Element elem) {
    if (st->num_elements >= st->alloc_size) {
        st->alloc_size *= 2;
        st->elements = realloc(st->elements, st->alloc_size*sizeof(Element));
        if (st->elements == NULL) {
            fprintf(stderr, "%s/%u: failed to allocate %lu bytes\n\n",
                    __FILE__, __LINE__, st->alloc_size*sizeof(Element));
            exit(-1);
        }
    }
    st->elements[st->num_elements++] = st->clone_func(elem);
}

Element StackPop(Stack st) {
    return (st->num_elements == 0) ? NULL : st->elements[--st->num_elements];
}

Element StackTop(Stack st) {
    return (st->num_elements == 0) ? NULL : st->elements[st->num_elements-1];
}

bool StackIsEmpty(Stack st) {
    return st->num_elements == 0;
}
