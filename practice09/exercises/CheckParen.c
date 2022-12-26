#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../ADT/Stack.h"

Element clone_func(Element element) {
    char *i = (char *) element;
    char *p = malloc(sizeof(char));
    *p = *i;
    return p;
}

bool check_paren(const char *s) {
    Stack st = StackCreate(clone_func, free);
    while (*s) {
        char c = *s++;
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
                continue;
            case '(':
            case '[':
                StackPush(st, &c);
                break;
            case ')':
                if (StackIsEmpty(st)) return false;
                if (*(char *)StackPop(st) != '(') return false;
                break;
            case ']':
                if (StackIsEmpty(st)) return false;
                if (*(char*)StackPop(st) != '[') return false;
                break;
            default:
                return false;
        }
    }
    bool ret = StackIsEmpty(st);
    StackDestroy(st);
    return ret;
}

int runCheckParen() {
    const char *strings[] = {"()", "(())", ")(", "(()", "())", "[]()", "([()])", "hello", NULL};
    for (const char **p = strings; *p != NULL; p++) {
        printf("%s is%s ok\n", *p, (check_paren(*p) ? "" : " NOT"));
    }
    return 0;
}
