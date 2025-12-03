#include <stdint.h>
#include <stdio.h>

// Function declarations from makeNBOC.c
extern int is_little_endian();
extern uint32_t makeNBOC(uint32_t hostlong);

extern uint32_t ntohl_manual(uint32_t netlong);

int main() {
    // Test with some values
    uint32_t test_values[] = {0x01020304, 0x12345678, 0xAABBCCDD, 0xDEADBEEF};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("Network Byte Order Test\n");
    printf("System is %s-endian\n\n", is_little_endian() ? "little" : "big");
    
    for (int i = 0; i < num_tests; i++) {
        uint32_t original = test_values[i];
        uint32_t network = makeNBOC(original);
        uint32_t back = ntohl_manual(network);
        
        printf("Original: 0x%08X\n", original);
        printf("Network:  0x%08X\n", network);
        printf("Back to:  0x%08X", back);
        
        if (original == back) {
            printf("  [PASSED]\n\n");
        } else {
            printf("  [FAILED]\n\n");
        }
    }
    
    return 0;
}
