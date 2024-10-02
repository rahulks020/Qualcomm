#include<iostream>
using namespace std;

// template <typename T>

// class Vector
// {
//    size_t size;
//    size_t capacity;
//    T * data;

//    void resize(int new_capacity){
//        T * new_data = new T[new_capacity]; 

//        for(size_t i = 0; i < size; i++)
//        {
//          new_data[i] = data[i];
//        }

//        delete [] data;

//        capacity = new_capacity;
//        data = new_data;
//    }

//    public:

//    //defaut constructor
//    Vector() : size(0), capacity(0), data(nullptr){}

//    // parametred constrcutor
//    Vector(size_t initialize_capacity) : size(initialize_capacity), capacity(initialize_capacity), data(new T[initialize_capacity]){

//    }

//    //copy constructor
//    Vector(const Vector & other):data(new T [other.capacity]),size(other.size), capacity(other.capacity)
//    {
//     for(size_t i = 0; i < other.size; i++)
//     {
//         data[i] = other.data[i];
//     }
//    }


//    //Move constructor      = std::move(obj1)
//    Vector(Vector&& other):size(other.size), capacity(other.capacity), data(other.data) 
//    {
//        other.size = 0;
//        other.capacity = 0;
//        other.data = nullptr;
//        cout<<"Inside Move\n";
//    }

//    // copy  assignment operator
//    Vector & operator=(const Vector & other)
//    {
//         if(this == &other)
//         return *this;

//         delete [] data;

//         size = other.size;
//         capacity  = other.capacity;
//         data = new T[other.capacity];

//         for(int i = 0; i < other.size; i++)
//         {
//             data[i] = other.data[i];
//         }

//         return *this;
      
//    }

//    //Move assignment operator
//    Vector & operator=(Vector && other)
//    {
//        if(this == &other)
//        return *this;

//        delete [] data;

//        size = other.size;
//        capacity = other.capacity;
//        data = new T[other.capacity];

//        for(size_t i = 0; i < other.size; i++)
//        {
//         data[i] = other.data[i];
//        }

//        other.size = 0;
//        other.capacity = 0;
//        other.data = nullptr;

//        return *this;
//    }

//    T& operator[](const T index) {
//        if(size <= index)
//        {
//         cout<<"out of Bound\n";
//        }
       
//       cout<<"inside Operator []\n";
//        return data[index];
//    }

//    void push_back(const T& value)
//    {
//        if(size == capacity)
//        {
//             resize(size == 0 ? 1 : 2 * capacity);
//        }

//        data[size++] = value;
//    }

//    void pop_back()
//    {
//        if(size == 0)
//        {
//         cout<<"Vector size is O\n";
//         return;
//        }

//        size--;
//    }

//    size_t getSize()
//    {
//       return size;
//    }

//    void showData()
//    {
//       if(data == nullptr){
//         cout<<"Pointing to nullptr\n";
//       }

//       for(int i = 0; i < size; i++)
//       {
//         cout<<data[i]<<" ";
//       }
//    }

// };

// int main()
// {
//     Vector<int>v1;
//     Vector<int>v2(3);

//     v1.push_back(1);
//     v1.push_back(44);

//     cout<<"V1 : ";
//     v1.showData();
//     cout<<"V1 size "<< v1.getSize();
//     cout<<"\n";

//     v2.push_back(22);
//     v2.push_back(33);

//     cout<<"V2 : ";
//     v2.showData();
//     cout<<"V2 size "<< v2.getSize();
//     cout<<"\n";

//     Vector<int>v3(v1);  // copy constructor   Vector<int>v3 = v2
    
//     cout<<"V3 :";
//     v3.showData();
//     cout<<"\n";


//     Vector<int>v4 = std::move(v3);  // move constructor

//     cout<<"\n";

//     cout<<"v3 after move: "<<v3.getSize()<<"\n";

//     cout<<"V4 :";
//     v4.showData();
//     cout<<"v4 size: "<<v4.getSize();
//     cout<<"\n";

//     Vector<int>v5;

//     v5 = v4; // copy assignment operator

//     cout<<"V5 :";
//     v5.showData();
//     cout<<"\n";

//     Vector<int>v6;

//     v6  = std::move(v5);   // move assignment operator

//     cout<<"v5 after move :"<<v5.getSize()<<"\n";

//     cout<<"V6 :";
//     v6.showData();
//     cout<<"\n";

//     cout<<"v6[1]: "<<v6[1];

//     return 0;
// }



//revision

template <typename T>
class Vector
{
    size_t capacity;
    size_t size;
    T * data;

    void resize(int newSize)
    {
        T * temp = new T[newSize];

        for(size_t i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        
        delete [] data;

        
        capacity = newSize;
        data = temp;


    }

    public:

    Vector(): capacity(0), size(0), data(nullptr)
    {

    }

    // copy constructor
    Vector(const Vector & other)
    {
        size = other.size;
        capacity = other.capacity;
        
        data = new T[size];

        for(int i  = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    // copy assignment operator
    Vector & operator=(const Vector & other)
    {
        if(this == &other ) return *this;

        delete [] data;

        size = other.size;
        capacity = other.capacity;
        data = new T[size];

        for(int i  = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        return *this;

    }

    // move constructor

    Vector(Vector && other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new T[size];

        for(size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;
    }

    // move assignment operator
    Vector & operator=(Vector && other)
    {
        if(this == &other) return *this;

        delete [] data;

        size = other.size;
        capacity = other.capacity;
        data = new T[size];

        for(size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        other.size = 0;
        other.capacity = 0;
        other.data = nullptr;

        return *this;
    }

    void push_back(int x)
    {
        if(size == capacity)
        resize(size == 0 ? 1 : size * 2);

        data[size] = x;
        size++;
    }

    void show()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<data[i]<<" ";
        }
    }
};

int main()
{
    Vector<int>v1;
    Vector<int>v2;

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);

    v2.show();

    Vector<int>v3 = v2;
    v3.show();

    v1 = v3;
    v1.show();

    Vector<int>v4 = std::move(v3);
    v4.show();
    v3.show();

    v1 = std::move(v4);



    return 0;


}