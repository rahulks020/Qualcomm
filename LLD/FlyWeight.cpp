// Flyweight : use to reduce memeory uses by sharing multiple data accross objects.

// ex  = design game, design word processer

#include <iostream>
#include <map>
using namespace std;

class Sprite
{

};

class Robot
{
    public:
    virtual void display(int, int) = 0;
};

class Homonoid : public Robot{
    string type;
    Sprite * sprite;

    public:

    Homonoid(string s, Sprite * sp)
    {
         this->type  = s;
         this->sprite = sp;
    }

    string getType() const{
        return type;
    }

    Sprite * getBody() const {
        return sprite;
    }

    void display(int x, int y)
    {
        cout<<"use the homonoid sprite object and x n y coordinate to render the object\n";
    }
};

class RoboticDog : public Robot
{
    Sprite * sprite;
    string type;

    public:
    RoboticDog(string s, Sprite * sp)
    {
        this->sprite = sp;
        this->type = s;
    }

    string getType() const{
        return type;
    }

    Sprite * getBody() const {
        return sprite;
    }

    void display (int x, int y ) 
    {
           cout<<"use the Robotc Dog sprite object and x n y coordinate to render the object\n";
    }

};

class RobotFactory
{
     map<string, Robot *>st;

     public:
     RobotFactory()
     {
    
     }

     Robot * createRobot(string type)
     {
        if(st.find(type) != st.end())
        {
            return st[type];
        }

        if(type == "HOMONOID")
        {
            Sprite * sprite  =new Sprite();
            Robot * robot = new Homonoid(type, sprite);
            st[type] = robot;
            return robot;
        }
        else{
            Sprite * sprite  =new Sprite();
            Robot * robot = new RoboticDog(type, sprite);
            st[type] = robot;
            return robot;
        }

        return NULL;
     }

};

int main()
{

    Sprite * sprite  = new Sprite();

    RobotFactory robotfactory;

    Robot * homonoid =  robotfactory.createRobot("HOMONOID");
    homonoid->display(2, 5);

    Robot * homonoid1 =  robotfactory.createRobot("HOMONOID");
    homonoid1->display(20, 15);


    Robot * roboticdog =  robotfactory.createRobot("DOG");
    roboticdog->display(10, 5);

    Robot * roboticDog2 =  robotfactory.createRobot("DOG");
    roboticDog2->display(30, 15);
    
    return 0;
 
}