// aligned_alloc is a C standard library function introduced in the C11 standard (ISO/IEC 9899:2011) and is also available in C++ as part of the C standard library. 
// This function is used for memory allocation with a specified alignment requirement. It allows you to allocate memory with a specific alignment, which can be useful in 
// situations where you need to work with data that has strict alignment requirements, such as SIMD (Single Instruction, Multiple Data) operations or hardware-specific 
// memory alignment constraints



#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t alignment = 16; // Example: 16-byte alignment
    size_t size = 64;     // Example: Allocate 64 bytes

    void *ptr = aligned_alloc(alignment, size);

    if (ptr != NULL) {
        printf("Memory allocated successfully.\n");
        // Use the allocated memory here
        // ...
        free(ptr); // Don't forget to free the memory when done
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
