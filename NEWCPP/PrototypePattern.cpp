#include<iostream>
#include<map>
using namespace std;

// class Prototype
// {
//     public:
//     virtual Prototype* clone() = 0;
//     virtual void print() = 0;
// };

// class concretePrototype1: public Prototype
// {
//     int n;
//     public:

//     concretePrototype1(int y): n(y){}
//     concretePrototype1(const concretePrototype1& other){n = other.n;}
//     Prototype* clone()
//     {
//         new concretePrototype1(*this);
//     }

//     void print()
//     {
//         cout<<"Concrete Prototype1\n";
//     }
// };

// class concretePrototype2: public Prototype
// {
//     string s;
//     public:
//     concretePrototype2(string c):s(c){}
//     concretePrototype2(const concretePrototype2& other){s = other.s;}
//     Prototype * clone ()
//     {
//         return new concretePrototype2(*this);
//     }

//     void print()
//     {
//         cout<<"cconcretePrototype2\n";
//     }
// };

// class PrototypeFactory
// {
//     map<int, Prototype*>m;
//     public:
//     PrototypeFactory()
//     {
//         m[1] = new concretePrototype1(1);
//         m[2] = new concretePrototype2("ram");
//     }

//     ~PrototypeFactory()
//     {
//         for(auto i : m)
//         {
//             delete i.second;
//         }

//         m.clear();
//     }

//     Prototype * create(int id)
//     {
//            return m[id]->clone();
//     }

// };

// int main()
// {
//     PrototypeFactory factory;
//     Prototype * p1 = factory.create(1);
//     p1->print();

//     Prototype* p2 = factory.create(2);
//     p2->print();

//     delete p1;
//     delete p2;

//     return 0;
// }

class Prototype
{
    public:
    virtual Prototype * clone() = 0;
    virtual void show() = 0;
};

class concretePrototype1 : public Prototype
{
    int n; 
    public:
    concretePrototype1(int n) : n (n){}
    concretePrototype1(const concretePrototype1 & other) : n (other.n){}
    Prototype * clone()
    {
        return new concretePrototype1(*this);
    }

    void show()
    {
        cout<<"Show : ConcreteFactory1 \n";
    }

};

class concreteFactory2 : public Prototype
{
    string s;
    public:
    concreteFactory2(string str) : s(str){}
    concreteFactory2(const concreteFactory2 & other) : s(other.s){}
    Prototype * clone()
    {
        return new concreteFactory2(*this);
    }

    void show()
    {
        cout<<"Show : ConcreteFactory2 \n";
    }
};

class PrototypeFactory{
    map<int, Prototype* >m;
    public:
    PrototypeFactory( )
    {
        m[1] = new concretePrototype1(1);
        m[2] = new concreteFactory2("Ram");
    }

    Prototype* create(int n)
    {
        if(n == 1)
        {
            return m[1]->clone();
        }
        else if(n == 2)
        {
            return m[2]->clone();
        }
    }
};

int main()
{
    PrototypeFactory prototypeFactory;
    Prototype * obj = prototypeFactory.create(1);
    obj->show();

    delete obj;
    return 0;
}