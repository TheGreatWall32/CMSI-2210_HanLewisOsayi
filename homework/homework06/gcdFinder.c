#include <stdio.h>
#include <assert.h>

extern long findGCD(long a, long b);

int main() {
    long num1 = 3113041662;
    long num2 = 11570925;
    long expected = 462837;

    printf("Testing findGCD with inputs %ld and %ld...\n", num1, num2);

    long result = findGCD(num1, num2);

    printf("Result received: %ld\n", result);

    assert(result == expected);
    
    assert(findGCD(10, 5) == 5);
    assert(findGCD(17, 13) == 1);

    printf("Logic is correct.\n");

    return 0;
}
