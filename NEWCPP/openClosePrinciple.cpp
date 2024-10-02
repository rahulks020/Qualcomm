
// In this example, the Shape class is open for extension because you can create new shapes by inheriting from it (e.g., Rectangle and Circle). 
// The calculateTotalArea function is closed for modification because it works with the Shape interface and can handle any new shapes without being changed.

// If you need to add a new shape, you can create a new class derived from Shape without modifying the existing code, thus adhering to the Open/Closed Principle.

#include <iostream>
#include <vector>

// Abstract base class representing a shape
class Shape {
public:
    virtual double area() const = 0;
};

// Concrete implementation of a Rectangle
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

// Concrete implementation of a Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

// Function that calculates the total area of a collection of shapes
double calculateTotalArea(const std::vector<Shape*>& shapes) {
    double totalArea = 0.0;

    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }

    return totalArea;
}

int main() {
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);

    // Using the calculateTotalArea function without modifying its code
    std::vector<Shape*> shapes;
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    double totalArea = calculateTotalArea(shapes);

    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}
