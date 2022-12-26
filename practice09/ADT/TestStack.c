#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"
#include "TestStack.h"

static Element clone_int(Element int_elem) {
    int *p = malloc(sizeof(int));
    *p = *((int*)int_elem);
    return p;
}

void test_stack() {
    Stack st = StackCreate(clone_int, free);
    assert(st);
    assert(StackIsEmpty(st));
    for(int i=100; i<5000; i++) {
        StackPush(st, &i);
        assert(!StackIsEmpty(st));
        int *top = StackTop(st);
        assert(top && *top == i);
    }
    int j = 5000;
    while (!StackIsEmpty(st)) {
        int *popped = StackPop(st);
        --j;
        assert(popped && *popped == j);
    }
    assert(!StackPop(st));
    assert(!StackTop(st));
    StackDestroy(st);
}
