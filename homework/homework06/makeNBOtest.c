#include <stdint.h>
#include <stdio.h>

// Declare the makeNBOC function from makeNBOC.c
extern uint32_t makeNBOC(uint32_t hostlong);

int main() {
    // Test with some values
    uint32_t test_values[] = {0x01020304, 0x12345678, 0xAABBCCDD, 0xDEADBEEF};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("Testing Network Byte Order Conversion:\n");
    
    for (int i = 0; i < num_tests; i++) {
        uint32_t original = test_values[i];
        uint32_t network = makeNBOC(original);
        
        printf("Original: 0x%08X -> Network: 0x%08X\n", original, network);
    }
    
    return 0;
}
