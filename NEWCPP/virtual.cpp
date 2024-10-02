#include<iostream>
using namespace std;

class base
{
   public:
   virtual void fun1()
   {
       cout<<"base\n";
   }
   virtual void funUtill()
   {
          cout<<"Base Utill\n";   
   }
   void fun()
   {
        funUtill();
   }

   virtual void fun2()
   {
    cout<<"Base\n";
   }
};

class derived: public base
{
    public:


     void fun1()
    {
        cout<<"derived\n"; 
    }

   void funUtill()
   {
          cout<<"Derived Utill\n";   
   }
};

int main()
{
    // derived d;
    // d.fun();
    // d.fun(1);
    // d.fun2();

    base * ptr = new derived();

    ptr->fun1();
    ptr->fun2();

    ptr->funUtill(); // derived Utill
    ptr->fun();    //derived Utill
}