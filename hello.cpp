#include<bits/stdc++.h>
using namespace std;

class base
{
private:
    /* data */

     
public:
    int z;
    static int x;
    base()
    {
        cout<<"base\n";
    }
    virtual void foo()
     {
        cout<<"fooB\n";
     }
    
};

class derived : public base
{
    public:
    int y;
    derived()
    {
        cout<<"derived\n";
    }

    public:
      void foo()
      {
        cout<<"fooD\n";
      }

      static int x;
};


bool fun(double arg)
{
    return arg != arg;
}

int main()
{
    // cout<<"Hello\n";

    // derived

    // d.fun();

    // base * b = new derived(); 



    // b->fun();

    // int x = !!5;
    // cout<<"helo\n";
    // cout<<x<<"\n";
    
    // cout<<char(42);

    // derived d;
    // d.foo();

    // if(fun(2.4) == fun(2.4))
    // {
    //     cout<<"hello";
    // }

    // int a = 1, c = 8;

    // int &b = a;

    // a++;

    // b = 90;

    // //b = 97;

    // cout<<a<<" "<<b<<" "<<c;

   // derived d;

   // d.foo();

    // base * b= new derived();

    // b->foo();

    //base b;

    cout<<sizeof(base)<<endl;
    cout<<sizeof(derived);


    return 0;
}