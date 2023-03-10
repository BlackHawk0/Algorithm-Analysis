#include <stdio.h>
#include <stdlib.h>
#include "time.h"


long f1(long n) {
    long k = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }
    return k;
}

void f2(long n) {
    long k = 0;
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
            k++;
        }
        for (long t = 0; t < 10000; t++) {
            k++;
        }
    }
}

void f3(long n) {
    if (n > 0) {
        f3(n / 2);
        f3(n / 2);
    }
}

void f4(long n) {
    if (n > 0) {
        f4(n / 2);
        f4(n / 2);
        f2(n);
    }
}

void f5(long n) {
    long k = 0;
    for (long i = 0; i < 10; i++) {
        long j = n;
        while (j > 0) {
            f1(1000);
            k++;
            j = j / 2;
        }
    }
}

void f6(long n) {
    f2(n);
    f3(n);
    f5(n);
}

void f7(long n) {
    long k = 0;
    for (long i = 0; i < f1(n); i++) {
        k++;
    }
    for (long j = 0; j < n; j++) {
        k++;
    }
}

int main() {
    int quit = 0;
    while (!quit) {
        int option;
        printf("Select an option:\n");
        printf("1. f1\n");
        printf("2. f2\n");
        printf("3. f3\n");
        printf("4. f4\n");
        printf("5. f5\n");
        printf("6. f6\n");
        printf("7. f7\n");
        printf("0. Quit\n");
        scanf_s("%d", &option);
        if (option != 0) {
            long n;
            printf("Enter a value for n\n");
            scanf_s("%d", &n);
            clock_t start = clock();
            switch (option) {
            case 1:
                f1(n);
                break;
            case 2:
                f2(n);
                break;
            case 3:
                f3(n);
                break;
            case 4:
                f4(n);
                break;
            case 5:
                f5(n);
                break;
            case 6:
                f6(n);
                break;
            case 7:
                f7(n);
                break;
            default:
                printf("Invalid option\n");
                break;
            }
            clock_t diff = clock() - start;
            long msec = diff * 1000 / CLOCKS_PER_SEC;
            printf("Operation took %d milliseconds\n\n", msec);
        }
        else {
            quit = 1;
        }
    }
    return 0;
}