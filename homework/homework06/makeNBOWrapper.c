#include <stdint.h>
#include <stdio.h>

// Forward declaration of our makeNBOC function
extern uint32_t makeNBOC(uint32_t hostlong);

// Wrapper function that can be called from assembly
// Using __cdecl calling convention for compatibility
void __cdecl test_nbo() {
    // Test cases
    uint32_t test_values[] = {
        0x01020304,
        0x12345678,
        0xAABBCCDD,
        0xDEADBEEF,
        0xCAFEBABE
    };
    
    for (int i = 0; i < 5; i++) {
        uint32_t original = test_values[i];
        uint32_t swapped = makeNBOC(original);
        
        printf("Original: 0x%08X -> Swapped: 0x%08X\r\n", original, swapped);
    }
}
