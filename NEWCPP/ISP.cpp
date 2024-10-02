// In this example, Drawable and Resizable are separate interfaces, and classes like Circle and Square implement only the interfaces that are relevant to them. 
// This adheres to the Interface Segregation Principle because each class is not forced to implement methods it doesn't need.

// The Drawable interface provides the draw method, and the Resizable interface provides the resize method. 
// Classes that need both functionalities can implement both interfaces, while those that need only one can implement the relevant interface.


#include <iostream>

// Interface for shapes that can be drawn
class Drawable {
public:
    virtual void draw() const = 0;
};

// Interface for shapes that can be resized
class Resizable {
public:
    virtual void resize(int newSize) = 0;
};

// Concrete class representing a circle
class Circle : public Drawable, public Resizable {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }

    void resize(int newSize) override {
        std::cout << "Resizing the circle to " << newSize << " units." << std::endl;
    }
};

// Concrete class representing a square
class Square : public Drawable, public Resizable {
private:
    double side;

public:
    Square(double s) : side(s) {}

    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }

    void resize(int newSize) override {
        std::cout << "Resizing the square to " << newSize << " units." << std::endl;
    }
};

int main() {
    Circle circle(5.0);
    Square square(4.0);

    // Using the Drawable interface
    circle.draw();
    square.draw();

    // Using the Resizable interface
    circle.resize(8);
    square.resize(6);

    return 0;
}
