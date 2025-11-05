#include <stdio.h>

int digit_count_int(int value) {
    int count = 1;
    if (value < 0) value = -value;
    while (value >= 10) { value /= 10; ++count; }
    return count;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: %s N\n", argv[0]);
        return 1;
    }

    int number;
    char extra;
    if (sscanf(argv[1], "%d%c", &number, &extra) != 1 || number < 2) {
        printf("N must be an integer >= 2\n");
        return 1;
    }

    int maximum_value = number * number;
    int column_width  = digit_count_int(maximum_value);

    printf("%*s", column_width, "");
    for (int column = 2; column <= number; ++column) {
        printf(" %*d", column_width, column);
    }
    putchar('\n');

    for (int row = 2; row <= number; ++row) {
        printf("%*d", column_width, row);
        for (int column = 2; column <= number; ++column) {
            int product = row * column;
            printf(" %*d", column_width, product);
        }
        putchar('\n');
    }

    return 0;
}
