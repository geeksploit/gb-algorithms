#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

int main() {
    void (*menu[])(void) = {&task0, &task1, &task2, &task3, &task4};
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
        printf("\n[%2d] %s", 3, "calculator");
        printf("\n[%2d] %s", 4, "fill the array");
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
    printf("%d^%d =", base, exponent);
    printf("\n%-20s: %ld", "non-recursively", productA);
    printf("\n%-20s: %ld", "recursively", power(base, exponent));
    printf("\n%-20s: %ld", "with parity control", powerWithParity(base, exponent));
    printf("\n%-20s: %.2f", "control value", pow(base, exponent));
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
    if (exponent % 2 == 0) {
        return powerWithParity(base, exponent / 2) * powerWithParity(base, exponent / 2);
    }
    return base * powerWithParity(base, exponent - 1);
}

/*
 * 3. Исполнитель Калькулятор преобразует целое число, записанное на экране.
 * У исполнителя две команды, каждой команде присвоен номер:
 * Прибавь 1
 * Умножь на 2
 * Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
 * Сколько существует программ, которые число 3 преобразуют в число 20.
 * а) с использованием массива;
 * б) с использованием рекурсии.
 */
void task3() {
    int from = 3;
    int to = 20;
    int increaseBy = 1;
    int multiplyBy = 2;
    printf("there are %d ways to get from %d to %d", calculatorA(from, to, increaseBy, multiplyBy), from, to);
    printf("\nthere are %d ways to get from %d to %d", calculatorB(from, to, increaseBy, multiplyBy), from, to);
}

int calculatorA(int startFrom, int endWith, int increment, int multiplier) {
    int *pathsTo = (int *) calloc(endWith + 1, sizeof(int *));
    pathsTo[startFrom] = 1;

    for (int i = startFrom; i <= endWith; i++) {
        if (i % multiplier == 0) {
            pathsTo[i] += pathsTo[i / multiplier];
        }
        if (i - increment > 0) {
            pathsTo[i] += pathsTo[i - increment];
        }
    }

    int result = pathsTo[endWith];
    free(pathsTo);

    return result;
}

int calculatorB(int startWith, int endWith, int increment, int multiplier) {
    if (startWith == endWith) {
        return 1;
    }
    if (startWith > endWith) {
        return 0;
    }
    return calculatorB(startWith + increment, endWith, increment, multiplier)
           + calculatorB(startWith * multiplier, endWith, increment, multiplier);
}

/*
 * 4. Реализовать меню с выбором способа заполнения массива: из файла, случайными числами, с клавиатуры.
 */
void task4() {
    int choice;
    printf("how would you like to fill the array?");
    printf("\n1) from a file");
    printf("\n2) with random values");
    printf("\n3) from the keyboard");
    printf("\n>");
    scanf("%d", &choice);

    if (choice == 1) {
    } else if (choice == 2) {
        size_t size;
        printf("please enter the size of the array: ");
        scanf("%d", &size);
    } else if (choice == 3) {
        int size;
        printf("please enter the size of the array: ");
        scanf("%d", &size);

        int *array = (int *) malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            scanf("%d", &array[i]);
        }

        for (int i = 0; i < size; i++) {
            printf("%d:[%d] ", i, array[i]);
        }

        free(array);
    }
}