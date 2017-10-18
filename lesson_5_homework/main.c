#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "task_1/decimal_to_binary.h"
#include "task_2/stack_with_memory_control.h"
#include "task_4/copy_linked_list.h"

int main() {
    void (*menu[])(void) = {&task_0, &task_1, &task_2, &task_3, &task_4};
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
        printf("\n[%2d] %s", 2, "list-based stack with memory control");
        printf("\n[%2d] %s", 3, "match brackets");
        printf("\n[%2d] %s", 4, "copy linked list");
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
    printf("\nthe stack is deleted from memory.");
}

/*
 * 3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
 * Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
 * неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
 * Например: (2+(2*2)) или [2/{5*(4+7)}]
 */
void task_3() {
    const char *LEFT_BRACKETS = "([{";
    const char *RIGHT_BRACKETS = ")]}";

    Stack *bracketsStack = (Stack *) malloc(sizeof(Stack));
    bracketsStack->head = NULL;

    size_t size = 255;
    char *line = (char *) malloc(size * sizeof(char));
}

/*
 * 4. *Создать функцию, копирующую односвязный список
 * (то есть создает в памяти копию односвязного списка, без удаления первого списка).
 */
void task_4() {
    ListNode *list1 = (ListNode *) malloc(sizeof(ListNode));
    list1->value = rand();
    list1->nextNode = NULL;
    insertAfter(insertAfter(list1, rand()), rand());

    ListNode *list2 = copyList(list1);

    ListNode *cursor;

    printf("the first list:\n");
    cursor = list1;
    while (cursor != NULL) {
        printf("%p: [%c] ", cursor, cursor->value);
        cursor = cursor->nextNode;
    }

    printf("\nthe second list:\n");
    cursor = list2;
    while (cursor != NULL) {
        printf("%p: [%c] ", cursor, cursor->value);
        cursor = cursor->nextNode;
    }
}
