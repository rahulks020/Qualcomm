// In this example, the UserManager class is responsible for both creating and deleting users, violating the Single Responsibility Principle. 
// To adhere to SRP, we can separate the responsibility of user printing into a different class (UserPrinter), making each class have a single responsibility.

// This separation makes the code more modular and easier to maintain. 
// Each class can be modified independently if there is a change in requirements related to its specific responsibility.

#include <iostream>
#include <string>
#include <vector>

// Class representing an employee
class Employee {
private:
    std::string name;
    int id;
    double salary;

public:
    Employee(const std::string& name, int id, double salary) : name(name), id(id), salary(salary) {}

    // Method to calculate the bonus
    double calculateBonus() const {
        // Assume a simple bonus calculation for demonstration
        return salary * 0.1;
    }

    // Method to save employee data to the database
    void saveToDatabase() {
        // Code to save employee data to the database
        std::cout << "Employee " << name << " saved to database." << std::endl;
    }
};

int main() {
    Employee emp("John Doe", 12345, 50000);
    
    // Calculate and display bonus
    double bonus = emp.calculateBonus();
    std::cout << "Bonus for "  << ": $" << bonus << std::endl;

    // Save employee to database
    emp.saveToDatabase();

    return 0;
}


// In this example, the Employee class has two responsibilities:

// Calculating the bonus (calculateBonus method)
// Saving employee data to the database (saveToDatabase method)
// This violates the Single Responsibility Principle because if there is a change in how bonuses are calculated or how employee data is stored 
// (e.g., if you switch to a different database or data storage mechanism), you would need to modify the Employee class, which breaks the principle.

// A better approach would be to separate these responsibilities into different classes. For example, you could have an EmployeeBonusCalculator class 
// responsible for calculating bonuses and an EmployeeDatabase class responsible for database operations. This way, each class would have only one reason to 
// change.

