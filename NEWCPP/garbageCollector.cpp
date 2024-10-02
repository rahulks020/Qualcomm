#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

// class GarbageCollector {
//     std::unordered_map<void*, bool> allocated_memory;

// public:
//     void* allocate(size_t size) {
//         void* ptr = malloc(size);
//         allocated_memory[ptr] = false;
//         return ptr;
//     }

//     void mark(void* ptr) {
//         if (allocated_memory.find(ptr) != allocated_memory.end()) {
//             allocated_memory[ptr] = true;
//         }
//     }

//     void sweep() {
//         for (auto it = allocated_memory.begin(); it != allocated_memory.end();) {
//             if (!it->second) {
//                 free(it->first);
//                 it = allocated_memory.erase(it);
//                 cout<<"Erased\n";
//             } else {
//                 it->second = false; // Reset mark for next cycle
//                 ++it;
//             }
//         }
//     }

//     void collect_garbage() {
//         // Example mark logic (normally you'd traverse stack, etc.)
//         // mark(...);
//         sweep();
//     }

//     ~GarbageCollector() {
//         for (auto& entry : allocated_memory) {
//             free(entry.first);
//         }
//     }
// };

// int main() {
//     GarbageCollector gc;

//     void* p1 = gc.allocate(10);
//     void* p2 = gc.allocate(20);
    
//     gc.mark(p1); // Manually marking for example
//     gc.collect_garbage();

//     return 0;
// }



class GarbageCollector
{
    unordered_map<void*, bool>allocated_memory;
    public:

    void* allocat_memory(int size)
    {
        void * ptr  = malloc(size);
        allocated_memory[ptr] = false;
        return ptr;
    }

    void mark(void * ptr)
    {
        if(allocated_memory.find(ptr) != allocated_memory.end())
        {
            allocated_memory[ptr] = true;
        }
    }

    void sweep()
    {
        for(auto it = allocated_memory.begin(); it != allocated_memory.end() ;)
        {
            if(!it->second)
            {
                free(it->first);
                it = allocated_memory.erase(it);
            }
            else{
                it++;
            }
        }
            
    }

    void collect_memory()
    {
        sweep();
    }

    int getSize() const
    {
        return allocated_memory.size();
    }

};
int main()
{
    GarbageCollector gc;
    void * ptr1 = gc.allocat_memory(10);
    void * ptr2 = gc.allocat_memory(20);

    gc.mark(ptr1);


    cout<<gc.getSize()<<"\n";
    gc.collect_memory();
    
    cout<<gc.getSize()<<"\n";

    return true;
}