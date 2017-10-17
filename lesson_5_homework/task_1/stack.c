#include <stdio.h>
#include "stack.h"

void push(T value) {
    if (stack.size >= stack.maxSize) {
        printf("Error: stack overflow!");
        return;
    }
}
