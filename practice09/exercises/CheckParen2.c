#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1024

typedef struct {
    int data[MAX_STACK_SIZE];
    int head;
} Stack;

Stack*			StackCreate();
void			StackDestroy(Stack*);
void			push(Stack*, int);
int   			pop(Stack*);
bool			isEmpty(Stack*);
bool			isFull(Stack*);

Stack* StackCreate() {
    Stack* s = calloc(sizeof(Stack), 1);
    if(!s) {
        fprintf(stderr, "%s, %d: memory allocation failed\n",
                __FILE__, __LINE__);
        exit(-1);
    }
    s->head = -1;
    return s;
}
void StackDestroy(Stack* s) {
    free(s);
}

void push(Stack* s, int item) {
    if(isFull(s))
        return;         // Should we terminate the program?
    s->data[++(s->head)] = item;
}
int pop(Stack* s) {
    if(isEmpty(s))
        return -1;      // Is this a good value?
    return s->data[(s->head)--];
}
bool isFull(Stack* s) {
    return (s->head == MAX_STACK_SIZE-1);
}
bool isEmpty(Stack* s) {
    return (s->head == -1);
}

bool check_paren(const char *s) {
    Stack *st = StackCreate();
    while(*s != '\0') {
        char c = *s++;
        switch (c) {
            case '(':
            case '[':
                push(st, c);
                break;
            case ')':
                if (isEmpty(st) || pop(st) != '(') {
                    return false;
                }
                break;
            case ']':
                if (isEmpty(st) || pop(st) != '[') {
                    return false;
                }
                break;
            default:
                return false;
        }
    }
    bool isParen = isEmpty(st);
    StackDestroy(st);
    return isParen;
}

//int main() {
//    const char *strings[] = { "()", "(())", ")(", "(()", "())", "[]()", "([()])", "hello", NULL};
//    for(const char **p = strings; *p != NULL; p++) {
//        printf("%s is%s ok\n", *p, (check_paren(*p) ? "" : " NOT"));
//    }
//    return 0;
//}
