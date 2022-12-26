#include <stdbool.h>
#include <stdio.h>

//
// Created by nimrod on 26-Dec-22.
//
typedef struct node {
    int data;
    struct node *next;
} Node;


bool isCyclic(Node *head) {
    if(head == NULL) {
        return false;
    }

    if(head->next == NULL) {
        return false;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while(fast != NULL && fast->next != NULL && fast != slow) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return fast == slow;
}


//int main() {
//    Node nodes[3];
//    nodes[0].next = &nodes[1];
//    nodes[1].next = &nodes[2];
//    nodes[2].next = NULL;
//    printf("IsCircular returns %d\n", isCyclic(&nodes[0]));
//    nodes[2].next = &nodes[0];
//    printf("IsCircular returns %d\n", isCyclic(&nodes[0]));
//    return 0;
//}