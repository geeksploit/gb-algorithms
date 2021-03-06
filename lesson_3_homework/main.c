#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "main.h"

int main() {
    void (*menu[])(void) = {&task0, &task1, &task2, &task3};
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
        printf("\n[%2d] %s", 1, "bubble sort");
        printf("\n[%2d] %s", 2, "shaker sort");
        printf("\n[%2d] %s", 3, "binary search");
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

/* 1. Попробовать оптимизировать пузырьковую сортировку.
 * Сравнить количество операций сравнения оптимизированной и не оптимизированной программы.
 * Написать функции сортировки, которые возвращают количество операций.
 */
void task1() {
    srand(time(NULL));
    const size_t size = 10;

    int *arrA = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arrA[i] = rand() % size;
    }
    printArray(arrA, size);

    printf("\nthe amount of operations to perform bubble sort:");
    int *arrB = (int *) malloc(size * sizeof(int));

    copyArray(arrA, arrB, size);
    printf("\n%-12s: %d\t", "classic", bubbleSortClassic(arrB, size));
    printArray(arrB, size);

    copyArray(arrA, arrB, size);
    printf("\n%-12s: %d\t", "minus i", bubbleSortOptimizedMinusI(arrB, size));
    printArray(arrB, size);

    copyArray(arrA, arrB, size);
    printf("\n%-12s: %d\t", "till last", bubbleSortOptimizedTillLast(arrB, size));
    printArray(arrB, size);

    copyArray(arrA, arrB, size);
    printf("\n%-12s: %d\t", "check sort", bubbleSortOptimizedCheckSort(arrB, size));
    printArray(arrB, size);

    copyArray(arrA, arrB, size);
    printf("\n%-12s: %d\t", "-i & check", bubbleSortOptimizedMinusICheckSort(arrB, size));
    printArray(arrB, size);

    copyArray(arrA, arrB, size);
    printf("\n%-12s: %d\t", "last & check", bubbleSortOptimizedTillLastCheckSort(arrB, size));
    printArray(arrB, size);

    free(arrA);
    free(arrB);
}

/*
 * 2. *Реализовать шейкерную сортировку.
 */
void task2() {
    srand(time(NULL));
    const size_t size = 10;

    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (size * 10);
    }
    printArray(arr, size);

    printf("\nshaker sort:");

    for (int i = 0; i < size; i++) {
        int isSorted = 1;

        for (int j = i; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                isSorted = 0;
            }
        }

        if (isSorted) {
            break;
        }

        printf("\n");
        printArray(arr, size);

        for (int j = size - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
                isSorted = 0;
            }
        }

        if (isSorted) {
            break;
        }

        printf("\n");
        printArray(arr, size);
    }

    free(arr);
}

/* 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
 * Функция возвращает индекс найденного элемента или -1, если элемент не найден.
 */
void task3() {
    srand(time(NULL));
    const size_t size = 20;
    int *array = (int *) malloc(size * sizeof(int));

    array[0] = rand() % size;
    for (int i = 1; i < size; i++) {
        array[i] = array[i - 1] + rand() % size;
    }
    printArray(array, size);

    int numberToFind;
    printf("\nplease enter a number to find: ");
    scanf("%d", &numberToFind);

    int searchResult = binarySearch(array, size, numberToFind);

    printf("the element %d ", numberToFind);
    if (searchResult == -1) {
        printf("is not in the array");
    } else {
        printf("is at index %d", searchResult);
    }
}

int binarySearch(int *sortedArray, size_t size, int numberToFind) {
    size_t tail = 0;
    size_t head = size;
    size_t cursor = size / 2;
    while (sortedArray[cursor] != numberToFind) {
        if (tail + 1 == head) {
            return -1;  // nothing found
        }
        if (sortedArray[cursor] > numberToFind) {
            head = cursor;
        } else {
            tail = cursor;
        }
        cursor = (head + tail) / 2;
    }
    return cursor;
}

int bubbleSortClassic(int *array, size_t size) {
    int counter = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            counter++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }

    return counter;
}

int bubbleSortOptimizedMinusI(int *array, size_t size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            counter++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
    return counter;
}

int bubbleSortOptimizedTillLast(int *array, size_t size) {
    int counter = 0;
    int lastSwap = size - 1;
    for (int i = 0; i < size; i++) {
        int currentSwap = -1;
        for (int j = 0; j < lastSwap; j++) {
            counter++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                currentSwap = j;
            }
        }
        lastSwap = currentSwap;
    }
    return counter;
}

int bubbleSortOptimizedCheckSort(int *array, size_t size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        int isSorted = 1;
        for (int j = 0; j < size - 1; j++) {
            counter++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted) {
            return counter;
        }
    }
    return counter;
}

int bubbleSortOptimizedMinusICheckSort(int *array, size_t size) {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        int isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++) {
            counter++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted) {
            return counter;
        }
    }
    return counter;
}

int bubbleSortOptimizedTillLastCheckSort(int *array, size_t size) {
    int counter = 0;
    int lastSwap = size - 1;
    for (int i = 0; i < size; i++) {
        int currentSwap = -1;
        int isSorted = 1;
        for (int j = 0; j < lastSwap; j++) {
            counter++;
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                currentSwap = j;
                isSorted = 0;
            }
        }
        if (isSorted) {
            return counter;
        }
        lastSwap = currentSwap;
    }
    return counter;
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
    *b = t;
}

//</editor-fold>
