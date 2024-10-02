#include<iostream>
using namespace std;

// int main()
// {
//     int * p = (int *)malloc(sizeof(int));

//     if(p == NULL)
//     {
//         cout<<"Failed";
//     }
//     else
//     {
//         cout<<*p;
//     }

//     free(p);

//     return 0;
// }

int main()
{
    int * p = (int *)calloc(5, sizeof(int));

    int x = 5;

    // *p = x;

    

    // while(x--)
    // {
    //     if(p == NULL)
    //     {
    //         cout<<"Failed";
    //     }
    //     else
    //     {
    //         cout<<*p<<"\n";

    //         *(p + 1) = x;
    //     }

    //     p++;
    // }



    p = (int*)realloc(p, 10 * sizeof(int));



    x = 10;

    *p = x;

    cout<<"hello";

    while(x--)
    {
        cout<<"hello";
        if(p == NULL)
        {
            cout<<"Failed";
        }
        else
        {
            cout<<*p<<"\n";

            *(p + 1) = x;
        }

        p++;
    }



    free(p);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     size_t alignment = 16; // Example: 16-byte alignment
//     size_t size = 64;     // Example: Allocate 64 bytes

//     void *ptr = aligned_alloc(alignment, size);

//     if (ptr != NULL) {
//         printf("Memory allocated successfully.\n");
//         // Use the allocated memory here
//         // ...
//         free(ptr); // Don't forget to free the memory when done
//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }
