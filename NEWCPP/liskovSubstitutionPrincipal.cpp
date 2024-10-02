
// In this example, both Rectangle and Square are derived from the common base class Shape. 
// The calculateArea function takes a Shape reference, allowing us to pass objects of derived classes without knowing their specific types.

// This adheres to the Liskov Substitution Principle because objects of the derived classes (Rectangle and Square) can be substituted for objects of the base class (Shape) 
// without affecting the correctness of the program.

#include <iostream>

// Base class representing a geometric shape
class Shape {
public:
    virtual double area() const = 0;
};

// Derived class representing a rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

// Derived class representing a square
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }
};

// Function that calculates the area of a shape without knowing its specific type
double calculateArea(const Shape& shape) {
    return shape.area();
}

int main() {
    Rectangle rectangle(4.0, 5.0);
    Square square(3.0);

    // Using the calculateArea function with different shapes
    std::cout << "Area of rectangle: " << calculateArea(rectangle) << std::endl;
    std::cout << "Area of square: " << calculateArea(square) << std::endl;

    return 0;
}
