//The Adapter pattern is a structural design pattern that allows the interface of an existing class to be used as another interface. 
//It is often used when the interface of an existing class does not match the interface required by a client.


#include <iostream>
#include <string>
using namespace std;

// choose weighting machine as an explample that gives mass in pond and a adopter between client  and a meight machine (adaptee) to convert pond to kg. 
// visit concept and coding on youTube.

// Target interface expected by the client
// class Target {
// public:
//     virtual void request() const = 0;
// };

// // Adaptee: the existing class with an incompatible interface
// class Adaptee {
// public:
//     void specificRequest(const std::string& message) {
//         std::cout << "Adaptee: " << message << std::endl;
//     }
// };

// // Adapter: adapts the Adaptee to the Target interface
// class Adapter : public Target {
// private:
//     Adaptee* adaptee;

// public:
//     Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

//     void request() const override {
//         // Call the specificRequest method of the Adaptee
//         adaptee->specificRequest("Adapter Pattern");
//     }
// };

// int main() {
//     // Create an instance of the Adaptee
//     Adaptee adaptee;

//     // Create an Adapter, passing the Adaptee instance to it
//     Adapter adapter(&adaptee);

//     // Use the Adapter as if it were a Target
//     adapter.request();


//     return 0;
// }



class Target{       //socket

    public:
    virtual void request() const = 0;

};

class Adaptee{       // data cable
    public:
    void specificRequest(const std::string str)
    {
          cout<<"Adaptee message: "<<str<<"\n";
    }
};

class Adapter : public Target{       // adapter
    Adaptee * adaptee;

    public:
    Adapter(Adaptee * adp) : adaptee(adp)
    {

    }  

    void request() const override
    {
        adaptee->specificRequest("Adpatee Request\n");
    }
};

int main()
{
    Adaptee * adaptee;

    Target * adapter = new  Adapter(adaptee);
    adapter->request();

    delete adaptee;
    delete adapter;
    return 0;
}


