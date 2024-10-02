// #include<iostream>
// using namespace std;

// //helps in loose coupling

// class Shape
// {
//     public:
//     virtual  void draw() = 0;
    
// };

// class Circle: public Shape
// {
//    public:
//    void draw()
//    {
//       cout<<"\nCircle";
//    }
// };

// class Rectangle: public Shape
// {
//     public:
//     void draw()
//     {
//        cout<<"\nRectangle";
//     }
// };

// class Factory
// {
//      public:
//      static Shape * getInstance(string s)
//      {
//           if(s == "Circle")
//           {
//             cout<<"\nCircle Created";
//             return new Circle;
//           }
//           else
//           {
//             cout<<"\nRectangle Created";
//             return new Rectangle;
//           }

//           return NULL;
//      }
// };

// int main()
// {
//      Shape * obj1  = Factory::getInstance("Circle");
//      obj1->draw();

//      Shape * obj2 = Factory::getInstance("Rectangle");
//      obj2->draw();

// }

// #include <iostream>

// class Product {
// public:
//     virtual void use() = 0;
// };

// class ConcreteProductA : public Product {
// public:
//     void use() {
//         std::cout << "Using ConcreteProductA" << std::endl;
//     }
// };

// class ConcreteProductB : public Product {
// public:
//     void use() {
//         std::cout << "Using ConcreteProductB" << std::endl;
//     }
// };

// class Factory {
// public:
//     virtual Product* createProduct() = 0;
// };

// class ConcreteFactoryA : public Factory {
// public:
//     Product* createProduct() {
//         return new ConcreteProductA();
//     }
// };

// class ConcreteFactoryB : public Factory {
// public:
//     Product* createProduct() {
//         return new ConcreteProductB();
//     }
// };

// int main() {
//     Factory* factory = new ConcreteFactoryA();
//     Product* product = factory->createProduct();
//     product->use();

//     factory = new ConcreteFactoryB();
//     product = factory->createProduct();
//     product->use();

//     delete product;
//     delete factory;

//     return 0;
// }
#include <iostream>
class product
{
    public:
    virtual void use() = 0;
};

class productA : public product
{
     public:

     void use()
     {
        std::cout<<"Product A\n";
     }
};

class productB : public product
{
   public:
   void use()
   {
    std::cout<<"Product B\n";
   }
};



class Factory
{
   public:
   virtual product *  createProduct() = 0;
   

};

class concreteFactoryA: public Factory{
      public:
      product * createProduct()
      {
        return new productA();
      }
};

class concreteFactoryB: public Factory
{

     public:

     product * createProduct()
     {
        return new productB();
     }
};

int main()
{
    Factory * obj = new concreteFactoryA();
    product * p = obj->createProduct();
    p->use();

    Factory * objNew = new concreteFactoryB();
    product * pNew = objNew->createProduct();
    pNew->use();
}

