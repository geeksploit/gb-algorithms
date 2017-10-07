#include <stdio.h>
#include <stdlib.h>
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

/*
 * 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
 */
void task1() {
    int decimal;
    printf("please enter a decimal number to convert: ");
    scanf("%d", &decimal);
    printf("the given number in binary is: %ld", decimalToBinary(decimal));
}

long decimalToBinary(int decimal) {
    if (decimal <= 0) {
        return 0;
    }
    long binary = decimal % 2;
    binary += 10 * decimalToBinary(decimal / 10);
    return binary;
}