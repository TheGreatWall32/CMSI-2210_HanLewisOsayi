#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    printf("Enter a positive integer N: ");
    if (scanf("%d", &n) != 1) {
        printf("Error: invalid input. Make sure it is a positive integer.\n");
        exit(1);
    }

    if (n <= 0) {
        printf("Error: N must be a positive integer greater than zero.\n");
        exit(1);
    }

    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            printf("fizz-buzz\n");
        } else if (i % 3 == 0) {
            printf("fizz\n");
        } else if (i % 5 == 0) {
            printf("buzz\n");
        } else {
            printf("%d\n", i);
        }
    }

    exit(0);
}


