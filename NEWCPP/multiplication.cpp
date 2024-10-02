//Write a C program for handling 32-bit multiplication on a microprocessor ALU supporting 16-bit multiplication

//To handle 32-bit multiplication on a microprocessor ALU (Arithmetic Logic Unit) that supports 16-bit multiplication, you can break down the multiplication into two 16-bit
// multiplications and then combine the results. Here's a C program to demonstrate this:

#include <stdio.h>

// Function to perform 16-bit multiplication
unsigned int multiply16bit(unsigned int a, unsigned int b) {
    return (unsigned int)(a * b);
}

// Function to handle 32-bit multiplication
unsigned long long multiply32bit(unsigned int a, unsigned int b) {
    // Split the 32-bit inputs into two 16-bit halves
    unsigned int a_low = a & 0xFFFF;
    unsigned int a_high = a >> 16;
    unsigned int b_low = b & 0xFFFF;
    unsigned int b_high = b >> 16;

    // Perform four 16-bit multiplications
    unsigned int p1 = multiply16bit(a_low, b_low);
    unsigned int p2 = multiply16bit(a_low, b_high);
    unsigned int p3 = multiply16bit(a_high, b_low);
    unsigned int p4 = multiply16bit(a_high, b_high);

    // Combine the results to get the 32-bit product
    unsigned long long result = ((unsigned long long)p4 << 32) |
                                ((unsigned long long)(p3 + (p2 << 16)) << 16) |
                                p1;

    return result;
}

int main() {
    unsigned int operand1 = 0x12345678; // First 32-bit operand
    unsigned int operand2 = 0x87654321; // Second 32-bit operand

    unsigned long long product = multiply32bit(operand1, operand2);

    printf("Result: %llu\n", product);

    return 0;
}
