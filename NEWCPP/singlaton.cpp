#include<iostream>
using namespace std;

// class Singlaton
// {
//     int x;
//     static Singlaton * instance;

//     Singlaton()
//     {

//     }
//     public:

//     static Singlaton* getInstances()
//     {
//         if(instance == NULL)
//         {
//             instance  = new Singlaton(); 
//         }

//         return instance;
//     }

//     void setData(int x)
//     {
//         instance->x = x;
//     }

//     int display()
//     {
//         return instance->x;
//     }
// };

// Singlaton* Singlaton::instance = NULL;

// int main()
// {
//     Singlaton* obj = Singlaton::getInstances();

//     obj->setData(80);

//     cout<<obj->display();


// }


// class Singleton {
// public:
//     static Singleton& getInstance() {
//         static Singleton instance; // Guaranteed to be thread-safe in C++11 and later, The static local variable instance is initialized only once, even in a multithreaded environment, ensuring thread safety.
//         return instance;
//     }

//     // Other member functions and data members

// private:
//     Singleton() {} // Private constructor
//     Singleton(const Singleton&) = delete; // Disallow copy construction
//     Singleton& operator=(const Singleton&) = delete; // Disallow assignment
// };

// int main()
// {
//     Singleton& obj = Singleton::getInstance();
// }

// class singlaton
// {
//      static singlaton * instance;
//      singlaton()
//      {
              
//      }

//      public:

//      static singlaton * createInstance()
//      {
//         if(instance == NULL)
//         {
//             instance = new singlaton();
//         }

//         return instance;
//      }


//      void show()
//      {
//         cout<<"Show";
//      }

// };

// singlaton * singlaton::instance = NULL;

// int main()
// {
//     singlaton * obj = singlaton::createInstance();
//     obj->show();
// }

class Singlaton
{
    int x;
    static Singlaton * instance;

    Singlaton(const Singlaton& other )= delete;
    Singlaton & operator=(const Singlaton &other)=delete;
    Singlaton(Singlaton && other)=delete;
    Singlaton & operator=(Singlaton && other)=delete;

    Singlaton()
    {

    }
    public:
    
    static Singlaton * getInstance()
    {
        if(instance == NULL)
        {
            instance = new Singlaton();
        }

        return instance;
    }

    void setValue(int y)
    {
        this->x = y;
    }

    int getValue()
    {
        return this->x;
    }
};

Singlaton * Singlaton::instance = NULL;

int main()
{
    Singlaton * obj = Singlaton::getInstance();
    obj->setValue(100);
    cout<<"Show value: "<<obj->getValue();

    return 0;
}