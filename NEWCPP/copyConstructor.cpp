#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;


    // Default constructor
    Person() : name(""), age(0) {}

    // Parameterized constructor
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Copy constructor
    Person(const Person& other) : name(other.name), age(other.age) {}

    // Display person information
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person person1("Alice", 25);
    Person person2 = person1;  // Copy constructor is called

    person1.display();
    person2.display();

    person2.age = 50;

    person1.display();
    person2.display();

    return 0;
}
