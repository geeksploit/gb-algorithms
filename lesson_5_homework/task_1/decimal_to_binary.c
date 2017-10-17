/*
 * 1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
 */

#include <stdio.h>
#include "decimal_to_binary.h"
#include "stack.h"

void task_1() {
    int decimal;
    printf("please enter a decimal to covert: ");
    scanf("%d", &decimal);

    stack.maxSize = 100;
    stack.head = NULL;

    while (decimal > 0) {
        decimal /= 2;
    }
}
