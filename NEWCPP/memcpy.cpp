#include <iostream>
#include <stdint.h>
using namespace std;

#include <cstddef> // for size_t
#include <cstdint> // for uint64_t

void* optimized_memcpy(void* dest, const void* src, size_t n) {   // taking void * to generalize
    char* d = static_cast<char*>(dest); //  The char type is guaranteed to be 1 byte in size. By converting the pointers to char*, we can easily perform byte-by-byte operations.
    const char* s = static_cast<const char*>(src);

    // Copy 8 bytes at a time if possible
    while (n >= 8) {
        *reinterpret_cast<uint64_t*>(d) = *reinterpret_cast<const uint64_t*>(s);
        d += 8;
        s += 8;
        n -= 8;
    }

    // Copy remaining bytes one by one
    while (n > 0) {
        *d++ = *s++;
        --n;
    }

    return dest;
}


int main() {
    char src[] = "Hello, World!";
    char dest[50];

    // Use my_memcpy to copy the string
    optimized_memcpy(dest, src, sizeof(src));

    // Print the copied string
    printf("Copied string: %s\n", dest);

    return 0;
}
