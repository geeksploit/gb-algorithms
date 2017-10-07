#include <stdio.h>
#include <stdlib.h>

int main() {
    void (*menu[])(void) = {&task0};
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
        printf("\n> ");
    } while (scanf("%d", &choice));

    return 0;
}

/*
 * Exit the application.
 */
void task0() {
    printf("thanks for staying with us, bye\n");
    exit(0);
}
