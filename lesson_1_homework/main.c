#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "main.h"

int main() {

    void (*menu[])(void) = {&task0, &task1, &task2, &task3, &task4, &task5, &task6, &task7, &task8, &task9,
                            &task10, &task11, &task12};
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
        printf("\n[%2d] %s", 1, "body mass index");
        printf("\n[%2d] %s", 2, "max of four");
        printf("\n[%2d] %s", 3, "swap two integers");
        printf("\n[%2d] %s", 4, "quadratic equation");
        printf("\n[%2d] %s", 5, "guess the season by month");
        printf("\n[%2d] %s", 6, "print age");
        printf("\n[%2d] %s", 7, "match chess fields by color");
        printf("\n[%2d] %s", 8, "print squares and cubes");
        printf("\n[%2d] %s", 9, "integer division");
        printf("\n[%2d] %s", 10, "detect odd digits");
        printf("\n[%2d] %s", 11, "count average of +..8");
        printf("\n[%2d] %s", 12, "max of three");
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

    int x, y;

    x = a, y = b;
    int c = x;
    x = y;
    y = c;
    printf("\nswapA: %d, %d", x, y);

    x = a, y = b;
    x ^= y;
    y ^= x;
    x ^= y;
    printf("\nswapB: %d, %d", x, y);

    printf("\ncheck: %d, %d", b, a);
}

/*
 * 4. Написать программу нахождения корней заданного квадратного уравнения.
 */
void task4() {
    int a, b, c;
    printf("please enter coefficients a, b and c: ");
    scanf("%d %d %d", &a, &b, &c);

    float x1, x2;
    if (a == 0 && b == 0) {
        printf("this is not an equation");
        return;
    }
    if (a == 0) {
        x1 = -(float) c / b;
        printf("becomes a linear equation, which has one root: %.2f", x1);
    } else {
        float discriminant = b * b - 4 * a * c;
        if (discriminant == 0) {
            x1 = -(float) b / (2 * a);
            printf("there is only one (double) root: %.2f", x1);
        } else if (discriminant > 0) {
            x1 = (-b - sqrt(discriminant)) / (2 * a);
            x2 = (-b + sqrt(discriminant)) / (2 * a);
            printf("two real roots are: %.2f and %.2f", x1, x2);
        } else {
            float real = -(float) b / (2 * a);
            x1 = sqrt(-discriminant) / (2 * a);
            x2 = sqrt(-discriminant) / (2 * a);
            printf("two imaginary roots are: %.2f + %.2fi and %.2f - %.2fi", real, x1, real, x2);
        }
    }
}

/*
 * 5. С клавиатуры вводится номер месяца.
 * Требуется определить, к какому времени года он относится.
 */
void task5() {
    int month;
    printf("please enter the number of a month: ");
    scanf("%d", &month);

    switch (month) {
        case 12:
        case 1:
        case 2:
            printf("Winter");
            break;
        case 3:
        case 4:
        case 5:
            printf("Spring");
            break;
        case 6:
        case 7:
        case 8:
            printf("Summer");
            break;
        case 9:
        case 10:
        case 11:
            printf("Autumn");
            break;
        default:
            printf("Unknown month");
    }
}

/*
 * 6. Ввести возраст человека (от 1 до 150 лет)
 * и вывести его вместе с последующим словом «год», «года» или «лет».
 */
void task6() {
    int age;
    printf("please enter a person's age: ");
    scanf("%d", &age);

    printf("%d ", age);
    int suffix;
    if (suffix = age % 100, suffix >= 11 && suffix <= 14) {
        printf("let");
    } else if (suffix = age % 10, suffix == 1) {
        printf("god");
    } else if (suffix = age % 10, suffix >= 2 && suffix <= 4) {
        printf("goda");
    } else {
        printf("let");
    }
}

/*
 * 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2).
 * Требуется определить, относятся ли к поля к одному цвету или нет.
 */
void task7() {
    int x1, y1, x2, y2;
    printf("please enter coordinates (x1, y1) and (x2, y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int sum1 = x1 + y1;
    int sum2 = x2 + y2;

    if (sum1 % 2 == sum2 % 2) {
        printf("both fields are of the same color");
    } else {
        printf("fields are of different colors");
    }
}

/*
 * 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
 */
void task8() {
    int a, b;
    printf("please enter two numbers:");
    scanf("%d %d", &a, &b);

    printf("\n%10s %10s %10s", "number", "square", "cube");
    for (int i = a; i <= b; i++) {
        int square = i * i;
        int cube = square * i;
        printf("\n%10d %10d %10d", i, square, cube);
    }
}

/*
 * 9. Даны целые положительные числа N и K.
 * Используя только операции сложения и вычитания, найти
 * частное от деления нацело N на K, а также остаток от этого деления.
 */
void task9() {
    int n, k;
    printf("please enter dividend and divisor: ");
    scanf("%d %d", &n, &k);

    int remainder = n;
    int quotient = 0;
    while (remainder >= k) {
        quotient++;
        remainder -= k;
    }

    printf("%-10s %3d\n", "quotient", quotient);
    printf("%-10s %3d", "remainder", remainder);
}

/*
 * 10. Дано целое число N (> 0).
 * С помощью операций деления нацело и взятия остатка от деления определить,
 * имеются ли в записи числа N нечетные цифры.
 * Если имеются, то вывести True, если нет — вывести False.
 */
void task10() {
    int n;
    printf("please enter an integer: ");
    scanf("%d", &n);

    while (n > 0) {
        if ((n % 10) % 2) {
            printf("True");
            return;
        }
        n /= 10;
    }

    printf("False");
}

/*
 * 11. С клавиатуры вводятся числа, пока не будет введен 0.
 * Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.
 */
void task11() {
    float sum = 0;
    int count = 0;
    int nextNumber;
    printf("please enter a sequence of numbers\n");
    printf("use 0 to terminate the sequence\n");
    while (scanf("%d", &nextNumber), nextNumber != 0) {
        if (nextNumber > 0 && nextNumber % 10 == 8) {
            sum += nextNumber;
            count++;
        }
    }
    float average = sum / count;
    printf("average is: %.3f", average);
}

/*
 * 12. Написать функцию нахождения максимального из трех чисел.
 */
void task12() {
    int a, b, c;
    printf("please enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    int max = a > b ? a : b;
    max = max > c ? max : c;

    printf("the maximum is: %d", max);
}

/*
 * 13. * Написать функцию, генерирующую случайное число от 1 до 100.
 * а) с использованием стандартной функции rand()
 * б) без использования стандартной функции rand()
 */
void task13() {
    int from = 1;
    int to = 100;

    srand(time(NULL));
    int randomA = rand() % (to - from + 1) + from;
    printf("randomA: %d", randomA);

    // This is the xorshift algorithm, which is simple yet efficient.
    unsigned int x = time(NULL);
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    int randomB = x % (to - from + 1) + from;
    printf("\nrandomB: %d", randomB);
}
