// In this example, the Switch class represents a high-level module that depends on the abstraction (Device). 

// The Light and Fan classes are low-level modules that implement the details but depend on the same abstraction. 

// This way, the high-level module is not directly dependent on the low-level module implementations. 
// The relationship between the high-level and low-level modules is inverted through the use of abstractions.


#include <iostream>

// Abstract class representing a device
class Device {
public:
    virtual void turnOn() const = 0;
    virtual void turnOff() const = 0;
};

// Concrete implementation of a light
class Light : public Device {
public:
    void turnOn() const override {
        std::cout << "Light is turned on." << std::endl;
    }

    void turnOff() const override {
        std::cout << "Light is turned off." << std::endl;
    }
};

// Concrete implementation of a fan
class Fan : public Device {
public:
    void turnOn() const override {
        std::cout << "Fan is turned on." << std::endl;
    }

    void turnOff() const override {
        std::cout << "Fan is turned off." << std::endl;
    }
};

// High-level module that depends on abstractions
class Switch {
private:
    Device* device;

public:
    Switch(Device* dev) : device(dev) {}

    void performAction() const {
        // The high-level module depends on the abstraction (Device)
        device->turnOn();
        // Additional high-level logic can go here
    }
};

int main() {
    // Low-level modules depend on the abstraction
    Light light;
    Fan fan;

    // High-level module is injected with the abstraction
    Switch lightSwitch(&light);
    Switch fanSwitch(&fan);

    // The high-level module can perform actions without knowing the specific details
    lightSwitch.performAction();
    fanSwitch.performAction();

    return 0;
}
