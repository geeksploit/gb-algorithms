#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {

    void (*menu[15])(void) = {&task0, &task1, &task2};

    int choice = -1;
    do {
        if (choice >= 0 && choice <= 14) {
            printf("\nTASK %d\n", choice);
            menu[choice]();
        }
        printf("\n\nMENU");
        printf("\nplease enter your choice to proceed:");
        printf("\n[%2d] %s", 0, "exit");
        printf("\n[%2d] %s", 1, "body mass index");
        printf("\n[%2d] %s", 2, "max of four");
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
 * 1. Ввести вес и рост человека.
 * Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 * где m-масса тела в килограммах, h - рост в метрах.
 */
void task1() {
    float weight, height;
    printf("please enter person's weight (kg) and height (m): ");
    scanf("%f %f", &weight, &height);

    float massIndex = weight / (height * height);
    printf("mass index is: %.2f", massIndex);
}

/*
 * 2. Найти максимальное из четырех чисел. Массивы не использовать.
 */
void task2() {
    int a, b, c, d;
    printf("please enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    int max1 = a > b ? a : b;
    int max2 = c > d ? c : d;
    int max = max1 > max2 ? max1 : max2;

    printf("maximum is: %d", max);
}

/*
 * 3. Написать программу обмена значениями двух целочисленных переменных:
 * a. с использованием третьей переменной;
 * b.*без использования третьей переменной.
 */
void task3() {
    int a, b;
    printf("please enter two numbers: ");
    scanf("%d %d", &a, &b);
}
