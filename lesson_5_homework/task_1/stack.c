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
    }
    return NULL;
}