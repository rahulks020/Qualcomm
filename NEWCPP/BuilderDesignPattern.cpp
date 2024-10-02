// The Builder Design Pattern is a creational design pattern that separates the construction of a complex object from its representation, 
//allowing the same construction process to create different representations. This pattern is particularly useful when an object has a complex construction 
//process with many optional components or configurations.

// The main components of the Builder pattern are:

// Product: The complex object that is being constructed.

// Builder: An interface or an abstract class that declares the construction steps for building the product.

// ConcreteBuilder: A class that implements the Builder interface and provides specific implementations for constructing the parts of the product.

// Director: Manages the construction process using a Builder object to build the product.

// Let's go through a simple example to illustrate the Builder pattern. Consider building a Computer object with various components like a CPU, RAM, storage, etc.

#include <iostream>
#include <string>
using namespace std;
// using namespace std;

// //Product
// class Computer {
// public:
//     void setCPU(const std::string& CPU) {
//         this->CPU = CPU;
//     }

//     void setRAM(const std::string& RAM) {
//         this->RAM = RAM;
//     }

//     void setStorage(const std::string& storage) {
//         this->storage = storage;
//     }

//     void display() const {
//         std::cout << "Computer Configuration:\n";
//         std::cout << "CPU: " << CPU << "\n";
//         std::cout << "RAM: " << RAM << "\n";
//         std::cout << "Storage: " << storage << "\n";
//         std::cout << "------------------------\n";
//     }

// private:
//     std::string CPU;
//     std::string RAM;
//     std::string storage;
// };

// // Builder interface
// class ComputerBuilder {
// public:
//     virtual void buildCPU(const std::string& CPU) = 0;
//     virtual void buildRAM(const std::string& RAM) = 0;
//     virtual void buildStorage(const std::string& storage) = 0;
//     virtual Computer getResult() = 0;
// };

// // ConcreteBuilder
// class DesktopComputerBuilder : public ComputerBuilder {
// public:
//     void buildCPU(const std::string& CPU) override {
//         computer.setCPU(CPU);
//     }

//     void buildRAM(const std::string& RAM) override {
//         computer.setRAM(RAM);
//     }

//     void buildStorage(const std::string& storage) override {
//         computer.setStorage(storage);
//     }

//     Computer getResult() override {
//         return computer;
//     }

// private:
//     Computer computer;
// };

// // Director
// class ComputerDirector {
// public:
//     Computer constructComputer(ComputerBuilder& builder) {
//         builder.buildCPU("Intel i7");
//         builder. ("16GB");
//         builder.buildStorage("512GB SSD");
//         return builder.getResult();
//     }
// };

// // Client code
// int main() {
//     DesktopComputerBuilder desktopBuilder;
//     ComputerDirector director;

//     Computer desktopComputer = director.constructComputer(desktopBuilder);

//     desktopComputer.display();

//     return 0;
// }


//product
class Computer{
    string CPU;
    string RAM;
    string storage;
    public:

    void setCPU(const string cpu)
    {
        this->CPU = cpu;
    }

    void setRAM(const string ram)
    {
        this->RAM = ram;
    }

    void setStorage(const string storage)
    {
        this->storage = storage;
    }

    void display()
    {
        cout<<"CPU"<<CPU<<"\n";
        cout<<"RAM"<<RAM<<"\n";
        cout<<"STORAGE"<<storage<<"\n";
    }

};

class Builder
{
        public:
        virtual void buildCPU(const string cpu) = 0;
        virtual void buildRAM(const string ram) = 0;
        virtual void buildStorage(const string storage) = 0;
        virtual Computer result() = 0;

};

class Desktopbuilder : public Builder{
    Computer  computer;
    public:
    void buildCPU (const string CPU) override{
        computer.setCPU(CPU);
    }

    void buildRAM(const string RAM) override{
        computer.setRAM(RAM);
    }

    void buildStorage(const string storage) override
    {
        computer.setStorage(storage);
    }

    Computer  result()
    {
        return computer;
    }
};

class Director 
{
    Desktopbuilder  desktop;
    public:
    Director(Desktopbuilder  desktopBuilder) : desktop(desktopBuilder){}

    Computer constructComputer()
    {
        desktop.buildCPU("96 CPU");
        desktop.buildRAM("16GB");
        desktop.buildStorage("1 TB");
        return desktop.result();
    }
    
};


//clinet
int main()
{
    Desktopbuilder db;
    Director d(db);
    Computer c =  d.constructComputer();

    c.display();
    return 0;
}