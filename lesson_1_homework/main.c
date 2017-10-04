#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {

    void (*menu[15])(void) = {&task0};

    int choice = -1;
    do {
        if (choice >= 0 && choice <= 14) {
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
