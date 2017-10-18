#include <malloc.h>
#include "stack_with_memory_control.h"

void push(Stack *stack, T value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        return;
    }
}
