#include <iostream>
#include <stack>
using namespace std;

class AirCondition
{
    bool isOn;
    int setTemperature;

    public:

    void turnOn()
    {
        isOn = true;
        cout<<"AC has turned On\n";
    }

    void turnOff() 
    {
        isOn = false;
        cout<<"AC has turned Off\n";
    }

    void settemperature(int temp) 
    {
        this->setTemperature = temp;
        cout<<"Temperature has changed to "<<setTemperature<<"\n";
    }

};

class Command
{
    public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class TurnOffCommaand : public Command
{
    AirCondition aircondition;
    public:
    TurnOffCommaand(AirCondition ac)
    {
        this->aircondition = ac;
    }

    void execute() override
    {
        aircondition.turnOff();
    }
    void undo() override
    {
        aircondition.turnOn();
    }


};

class TurnOnCommand : public Command
{
    AirCondition ac;
    public:
    TurnOnCommand(AirCondition aircondition)
    {
        this->ac = aircondition;
    }

    void execute() override
    {
        ac.turnOn();
    }

    void undo() override
    {
        ac.turnOff();
    } 

};

class Remote
{

    Command *  c;
    stack<Command *>st;

    public:
    Remote(Command *  command)
    {
        c = command;
    }

    void pressButton()
    {
        c->execute();
        st.push(c);
    }

    void undo()
    {
        if(!st.empty())
        {
            st.top()->undo();
            st.pop();
        }
    }

};

int main()
{
     AirCondition ac;

     Command * cmd = new TurnOnCommand(ac);

     Remote remote(cmd);
     remote.pressButton();

     remote.undo();

     return 0;

}