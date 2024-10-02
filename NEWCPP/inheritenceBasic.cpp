#include<iostream>
using namespace std;

class Base
{
    int k;

    public: 
    Base(int x) : k (x)
    {
        cout<<k <<" ------\n";
    }

    virtual void show()
    {
        cout << k <<"Base\n";
    }
};

class Derived1 : public Base
{

    int x;
    public :
    Derived1(int z) : Base(z)
    {
        x = z;
    }

    void show()
    {
        cout <<x<<"Derived1\n";
    }

};

class Derived2 : public Base
{

    int x;
    public :
    Derived2(int z) : Base(z + 1)
    {
        x = z;
    }

    void show()
    {
        cout <<x<<"Derived2\n";
    }
};

int main()
{
    cout<<"Hello world\n";

    Derived1 d1(4);
    Derived2 d2(7);

    d1.show();
    d2.show();

    Base * ptr = new Derived1(10);
    ptr->show();

    return 0;
}