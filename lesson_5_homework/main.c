#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "task_1/decimal_to_binary.h"
#include "task_2/stack_with_memory_control.h"

int main() {
    void (*menu[])(void) = {&task_0, &task_1, &task_2};
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    int choice = -1;
    do {
        if (choice >= 0 && choice < menuSize) {
            printf("\nTASK %d\n", choice);
            menu[choice]();
        }
        printf("\n\nMENU");
        printf("\nplease enter your choice to proceed:");
        printf("\n[%2d] %s", 0, "exit");
        printf("\n[%2d] %s", 1, "decimal to binary using stack");
        printf("\n[%2d] %s", 2, "list-based stack with memory control"
                "");
        printf("\n> ");
    } while (scanf("%d", &choice));

    return 0;
}

/*
 * Exit the application.
 */
void task_0() {
    printf("thanks for staying with us, bye\n");
    exit(0);
}

/*
 * 2. Добавить в программу “реализация стека на основе односвязного списка” проверку на выделение памяти.
 * Если память не выделяется, то выводится соответствующее сообщение.
 * Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).
 */
void task_2() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->head = NULL;
    }

    printf("filling the stack with random values...");
    while (pushStack(stack, rand()) != NULL) {
    }
    printf("\nthere is no memory to push another value on the stack");

    printf("\nreleasing the memory allocated for the stack...");
    while (stack->head != NULL) {
        popStack(stack);
    }
    printf("\nthe stack is now empty");

    free(stack);
}
