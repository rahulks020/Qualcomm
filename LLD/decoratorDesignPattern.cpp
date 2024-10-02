#include <iostream>
#include <string>
using namespace std;

class Beverage
{
    
    public:
    string name;
    Beverage()
    {
        name  = "";
    }
    virtual string getBeverageName() const = 0;
    

    virtual int getbeveragePrice () const = 0;
};

class Expresso : public Beverage
{
    public:
    Expresso(string beverageName)
    {
        this->name = beverageName;
    }

    string getBeverageName() const override{
        return this->name;
    }

    int getbeveragePrice() const override{
        return 10;
    }

};

class Cappuchino : public Beverage
{
    public:
    Cappuchino(string bevergaeName)
    {
        this->name = bevergaeName;
    }

    string getBeverageName() const override{
        return this->name;
    }

    int getbeveragePrice() const override
    {
        return 15;
    }
};

class Ingedrient : public Beverage
{

    public:
    virtual string getBeverageName() const = 0;
    virtual int getbeveragePrice() const = 0;

};

class Milk : public Ingedrient
{
    Beverage * beverage;
    public:

    Milk(Beverage * beverage)
    {
        this->beverage = beverage;
    }

    string getBeverageName() const override
    {
        return beverage->getBeverageName() + "With Milk\n"; 
    }

    int getbeveragePrice() const override
    {
        return beverage->getbeveragePrice() + 2;
    }


};

class chocolate : public Ingedrient
{
    Beverage * beverage;
    public:

    chocolate(Beverage * beverage)
    {
        this->beverage = beverage;
    }

    string getBeverageName() const override
    {
        return beverage->getBeverageName() + "With chocolate\n"; 
    }

    int getbeveragePrice() const override
    {
        return beverage->getbeveragePrice() + 2;
    }


};

int main()
{
    Beverage * beverage = new Expresso("Expresso");
    cout<<beverage->getBeverageName()<<"\n";
    cout<<beverage->getbeveragePrice()<<"\n";

    beverage = new Milk(beverage);
    cout<<beverage->getBeverageName()<<"\n";
    cout<<beverage->getbeveragePrice()<<"\n";

    beverage = new Milk(beverage);
    cout<<beverage->getBeverageName()<<"\n";
    cout<<beverage->getbeveragePrice()<<"\n";


    return 0;
}