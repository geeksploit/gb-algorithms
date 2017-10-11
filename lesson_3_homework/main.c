#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"

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

//<editor-fold desc="Utility functions">

void copyArray(int *arrA, int *arrB, size_t size) {
    for (int i = 0; i < size; i++) {
        arrB[i] = arrA[i];
    }
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
}

//</editor-fold>
