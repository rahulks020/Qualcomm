#include <iostream>
using namespace std;
class Base{
    public:
    virtual void show(){

    }
};

class Derived1 : public Base
{
    public :
    void show() override
    {
        cout<<"Derived 1\n";
    }

};

class Derived2 : public Base
{
    public :
    void show() override
    {
        cout<<"Derived 1\n";
    }

};

int main()
{
    cout<<"HEllo World!\n";

    Base * b ;
    
    b = new Derived1();
    b->show();

    return 0;

    
}