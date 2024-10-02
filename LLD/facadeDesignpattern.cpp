// imagine a building, the facade is the outer wall that people see, but behind it is a complex network of wires, pipes, and other 
// systems that make the building function. The facade pattern is like that outer wall. 
// It hides the complexity of the underlying system and provides a simple interface that clients can use to interact with the system.


#include <iostream>
using namespace std;

class Ram
{
      public:
      bool checkingRam()
      {
        cout<<"Checling Ram...\n";
        return  true;
      }
};
class MotherBoard
{
      public:
      bool checkMotherBoard()
      {
        cout<<"Checking MotherBoard...\n";
        return  true;
      }
};

class Hardware
{
      MotherBoard * MB;
      Ram * rm;

      public:

      Hardware ()
      {
        MB = new MotherBoard();
        rm = new Ram();
      }

      bool checkHardware()
      {
        return MB->checkMotherBoard() && rm->checkingRam();
      }

      
};

class OSCheckBoot
{
    public:
    bool checkOSCheckBoot()
    {
        cout<<"Checking OSCHECkBoot ...\n";
        return true;
    }
};
class OSCheckDriver
{
    public:
    bool checkOSCheckDriver()
    {
        cout<<"Checking OSCHEckDriver ...\n";
        return true;
    }
};

class OS{
    OSCheckBoot * oscb;
    OSCheckDriver *oscd;

    public:
    OS()
    {
        oscb = new OSCheckBoot();
        oscd = new OSCheckDriver();
    }

    bool checkOS()
    {
        return oscb->checkOSCheckBoot() && oscd->checkOSCheckDriver();
    }

};

class Laptop
{
    OS * os;
    Hardware * hd;
    public:
    Laptop()
    {
        
    }
    void LaptopOnSwitch()
    {
        os = new OS();
        hd = new Hardware();
    }

    void switchOnLaptop()
    {
        if(os->checkOS() && hd->checkHardware())
        {
            cout<<"Switching laptop\n";
        }
       
    }

   
};

int main()
{
      Laptop LP;
      LP.LaptopOnSwitch();
      LP.switchOnLaptop();

      return 0;
}