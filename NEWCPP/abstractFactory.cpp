#include<iostream>
using namespace std;


// class ProductA
// {
//     public:
//     virtual void use() = 0;

// };

// class ConcreteProductA1 : public ProductA
// {

//     public:
//     void use()
//     {
//         cout<<"ConcreteProductA1\n";
//     }

// };

// class ConcreteProductA2 : public ProductA
// {

//     public:
//     void use()
//     {
//         cout<<"ConcreteProductA2\n";
//     }

// };

// class ProductB
// {
//     public:
//     virtual void use() = 0;

// };

// class ConcreteProductB1: public ProductB{

//     public:
//     void use()
//     {
//         cout<<"ConcreteProductB1\n";
//     }

// };

// class ConcreteProductB2: public ProductB{

//     public:
//     void use()
//     {
//         cout<<"ConcreteProductB2\n";
//     }

// };

// class Factory
// {
//     public:
//     virtual ProductA* createProductA() = 0;
//     virtual ProductB* createProductB() = 0;
// };

// class ConcreteFactory1 : public Factory
// {
//     public:
//     ProductA* createProductA()
//     {
//         return new ConcreteProductA1();
//     }

//     ProductB* createProductB()
//     {
//         return new ConcreteProductB1();
//     }
// };

// class ConcreteFactory2 : public Factory
// {
//     public:
//     ProductA* createProductA()
//     {
//         return new ConcreteProductA2();
//     }

//     ProductB* createProductB()
//     {
//         return new ConcreteProductB2();
//     }
// };



// int  main()
// {

//     Factory* obj1 = new ConcreteFactory1();
//     ProductA *  pA1 = obj1->createProductA();
//     pA1->use();

//     Factory* obj2 = new ConcreteFactory2();
//     ProductA * pA2 = obj2->createProductA();
//     pA2->use();


//     delete obj1;
//     delete obj2;
//     delete pA1;
//     delete pA2;
//     return 0;
// }

class ProductA
{
    public:
    virtual void use() = 0;

};

class ProductA1 : public ProductA
{
   public:

   void use()
   {
    cout<<"Product A1 create\n";
   }

};

class ProductA2 : public ProductA
{
   public:

   void use()
   {
    cout<<"Product A2 create\n";
   }

};

class ProductB
{
    public:

    virtual void use() = 0;

};

class ProductB1: public ProductB
{
    public:

    void use()
    {
        cout << "Product B1 created\n";
    }
};

class ProductB2: public ProductB
{
    public:

    void use()
    {
        cout << "Product B2 created\n";
    }
};

class Factory
{

     public:
     virtual ProductA * createProductA() = 0;
     virtual ProductB * createProductB() = 0;

};

class concreteFactory1: public Factory
{
     public:

     ProductA * createProductA()
     {
        return new  ProductA1();
     }
     ProductB * createProductB()
     {
        return new ProductB1();
     }

};

class concreteFactory2: public Factory
{
    public:
    ProductA * createProductA()
    {
        return new ProductA2();
    }

    ProductB * createProductB()
    {
        return new ProductB2();
    }
};

int main()
{
    Factory * obj1 = new concreteFactory1();
    ProductA * A1 = obj1->createProductA();
    A1->use();

    ProductB *  B2 = obj1->createProductB();
    B2->use();

    delete obj1;
    delete A1;
    delete B2;
    return 0;
}