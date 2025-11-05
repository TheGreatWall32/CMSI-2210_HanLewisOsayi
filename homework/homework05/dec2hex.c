#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num;
    if (argc == 2) {
        num = atoi(argv[1]);
    } else {
        printf("Enter a number: ");
        scanf("%d", &num);
    }
    printf("%d in binary is: ", num);
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
    return 0;
}
