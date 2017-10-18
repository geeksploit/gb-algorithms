#include <stdio.h>
#include <malloc.h>
#include "stack.h"

void push(T value) {
    if (stack.size >= stack.maxSize) {
        printf("Error: stack overflow!");
        return;
    }

    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = stack.head;

    stack.head = new_node;
    stack.size++;
}

T pop() {
    if (stack.size == 0) {
        printf("stack is empty");
        return NULL;
    }

    T value = stack.head->value;

    Node *old_head = stack.head;

    stack.head = stack.head->next;
    stack.size--;

    free(old_head);

    return value;
}