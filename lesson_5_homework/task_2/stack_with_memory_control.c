#include <malloc.h>
#include "stack_with_memory_control.h"

Node *pushStack(Stack *stack, T value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->value = value;
    new_node->next = stack->head;

    stack->head = new_node;
    return stack->head;
}

T popStack(Stack *stack) {
}