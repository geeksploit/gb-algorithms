#include <malloc.h>
#include "stack_with_memory_control.h"

void pushStack(Stack *stack, T value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }

    new_node->value = value;
    new_node->next = stack->head;

    stack->head = new_node;
}
