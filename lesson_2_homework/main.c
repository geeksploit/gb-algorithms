#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    void (*menu[])(void) = {&task0, &task1, &task2};
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
        printf("\n[%2d] %s", 1, "decimal to binary");
        printf("\n[%2d] %s", 2, "a pow b");
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
    binary += 10 * decimalToBinary(decimal / 2);
    return binary;
}

/*
 * 2. Реализовать функцию возведения числа a в степень b:
 * a. без рекурсии;
 * b. рекурсивно;
 * c. *рекурсивно, используя свойство чётности степени.
 */
void task2() {
    int base, exponent;
    printf("please enter the base and the exponent: ");
    scanf("%d %d", &base, &exponent);

    long productA = 1;
    for (int i = 0; i < exponent; i++) {
        productA *= base;
    }
    printf("%-20s: %ld", "non-recursively", productA);

    printf("\n%-20s: %ld", "recursively", power(base, exponent));
}

long power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

long powerWithParity(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
}
