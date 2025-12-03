/*
In networking, it is necessary to make sure that bytes are transimitted in the proper order so the receiving device can interpret them correctly. 
This requires that big-endian and little-endian values are converted to something called Network Byte Order before they are transmitted. 
For this problem, write a C program whichEndIsUp.c that will determine whether your computer is big-endian or little-endian as was discussed in class.
*/

#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num = 0x01020304;  // Using a 4-byte number
    uint8_t *ptr = (uint8_t *)&num;  // Pointer to the first byte of num
    
    printf("Number: 0x%08x\n", num);
    printf("Bytes in memory: ");
    
    // Print each byte of the number
    for (int i = 0; i < 4; i++) {
        printf("0x%02x ", ptr[i]);
    }
    printf("\n");
    
    // Check the first byte to determine endianness
    if (ptr[0] == 0x04) {
        printf("This system is little-endian (least significant byte first)\n");
    } else {
        printf("This system is big-endian (most significant byte first)\n");
    }
    
    return 0;
}
