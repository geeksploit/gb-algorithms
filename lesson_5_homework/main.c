#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "task_1/decimal_to_binary.h"

int main() {
    void (*menu[])(void) = {&task_0, &task_1};
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
