#include <stdio.h>
#include <stdbool.h>
#include "IsCyclic.h"

typedef struct node {
   int data;
   struct node* next;
} Node;

int LengthOfList(Node *head) {
    int len = 0;
    while (head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

Node *advance(Node *p) {
    return (p != NULL) ? p->next : NULL;   
}

bool IsCircular(Node *head) {
     Node *slow = head;   
     Node *fast = head;   
     do {
         slow = advance(slow);
         fast = advance(advance(fast));   
     } while ((fast != NULL && fast != slow));
     return fast != NULL;
}

int runIsCyclic() {
    Node nodes[3];
    nodes[0].next = &nodes[1];
    nodes[1].next = &nodes[2];
    nodes[2].next = NULL;
    printf("IsCircular returns %d\n", IsCircular(&nodes[0]));
    printf("LengthOfList is %d\n",LengthOfList(&nodes[0]));
    nodes[2].next = &nodes[0];
    printf("IsCircular returns %d\n", IsCircular(&nodes[0]));
    printf("LengthOfList is %d\n",LengthOfList(&nodes[0]));
    return 0;
}