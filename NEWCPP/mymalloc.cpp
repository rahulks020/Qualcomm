#include <iostream>
using namespace std;

const int MAX_MEMORY_SIZE = 10000;

int allocationSize;

bool myMalloc(int size, void **ptr)
{
    if(allocationSize + size > MAX_MEMORY_SIZE)
    {
        return false;
    }

    *ptr = malloc(size);

    allocationSize += size;

    return true;

}

void free(void *ptr, int size)
{
    if(ptr) return ;

    free(ptr);

    cout<<"Memory freed successfully\n";

    allocationSize -= size;    
}

int main()
{
    void *ptr1;
    void *ptr2;

    allocationSize = 0;

    if(myMalloc(20, &ptr1))
    {
        cout<<"Memmory allocated successful\n";
    }
    else{
        cout<<"Memmory allocated Failed\n";
    }

    free(ptr1, 20);

    return 0;

}