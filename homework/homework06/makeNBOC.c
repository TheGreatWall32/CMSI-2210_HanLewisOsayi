/*
Building on the previous problem, write a C function makeNBOC.c that takes a number as an argument, checks to see if the order needs to be swapped to make Network Byte Order, 
and swaps its byte order, if necessary. Modify a copy of your previous program from problem 4, whichendisup.c, to make a function that will determine the byte order and if it will need to be swapped. 
You can also research the hton() and ntoh() functions to do the swapping [if you like]. 
Write a test program makeNBOtest.c to call your new function and display the results of the function call on stdout using printf().
*/

#include <stdint.h>
#include <stdio.h>

// Function to check if the system is little-endian
int is_little_endian() {
    uint32_t num = 0x01020304;
    uint8_t *ptr = (uint8_t *)&num;
    return (*ptr == 0x04);
}

// Function to convert 32-bit integer to network byte order (big-endian)
uint32_t makeNBOC(uint32_t hostlong) {
    if (is_little_endian()) {
        return ((hostlong & 0x000000FF) << 24) |
               ((hostlong & 0x0000FF00) << 8) |
               ((hostlong & 0x00FF0000) >> 8) |
               ((hostlong & 0xFF000000) >> 24);
    }
    return hostlong;  // Already in network byte order (big-endian)
}

// Function to convert from network byte order to host byte order
uint32_t ntohl_manual(uint32_t netlong) {
    return makeNBOC(netlong);  // Conversion is symmetric
}

// Test function to demonstrate the functionality
void test_makeNBOC() {
    uint32_t test_values[] = {0x01020304, 0x12345678, 0xAABBCCDD, 0xDEADBEEF};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    printf("Testing makeNBOC function:\n");
    printf("System is %s-endian\n\n", is_little_endian() ? "little" : "big");
    
    for (int i = 0; i < num_tests; i++) {
        uint32_t original = test_values[i];
        uint32_t network = makeNBOC(original);
        uint32_t back = makeNBOC(network);  // Convert back to check
        
        printf("Original: 0x%08X\n", original);
        printf("Network:  0x%08X\n", network);
        printf("Back:     0x%08X\n", back);
        printf("Test %s\n\n", (original == back) ? "PASSED" : "FAILED");
    }
}