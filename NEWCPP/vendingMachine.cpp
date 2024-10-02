#include <iostream>
#include <vector>

// Define a Product class to represent the items in the vending machine.
class Product {
public:
    Product(int id, std::string name, double price) : id(id), name(name), price(price) {}

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

private:
    int id;
    std::string name;
    double price;
};

// Define a VendingMachine class.
class VendingMachine {
public:
    VendingMachine() : balance(0.0) {
        // Initialize the available products.
        products.push_back(Product(1, "Soda", 1.25));
        products.push_back(Product(2, "Chips", 0.75));
        products.push_back(Product(3, "Candy", 0.50));
    }

    // Display the list of available products.
    void displayProducts() const {
        std::cout << "Available products:" << std::endl;
        for (const Product& product : products) {
            std::cout << product.getId() << ". " << product.getName() << " - $" << product.getPrice() << std::endl;
        }
    }

    // Accept coins (quarters, dimes, nickels).
    void insertCoin(double coin) {
        if (coin == 0.25 || coin == 0.10 || coin == 0.05) {
            balance += coin;
            std::cout << "Inserted $" << coin << ". Current balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid coin. Please insert quarters, dimes, or nickels." << std::endl;
        }
    }

    // Purchase a product.
    void purchaseProduct(int productId) {
        for (const Product& product : products) {
            if (product.getId() == productId) {
                if (balance >= product.getPrice()) {
                    std::cout << "Dispensing " << product.getName() << "." << std::endl;
                    balance -= product.getPrice();
                } else {
                    std::cout << "Insufficient balance. Please insert more coins." << std::endl;
                }
                return;
            }
        }
        std::cout << "Invalid product ID. Please select a valid product." << std::endl;
    }

    // Return any remaining balance to the user.
    void returnChange() {
        if (balance > 0) {
            std::cout << "Returning $" << balance << " in change." << std::endl;
            balance = 0.0;
        }
    }

private:
    std::vector<Product> products;
    double balance;
};

int main() {
    VendingMachine vendingMachine;

    while (true) {
        std::cout << "----------------------------------------" << std::endl;
        vendingMachine.displayProducts();
        std::cout << "----------------------------------------" << std::endl;

        int choice;
        std::cout << "Enter product ID (0 to exit): ";
        std::cin >> choice;

        if (choice == 0) {
            vendingMachine.returnChange();
            std::cout << "Thank you for using the vending machine!" << std::endl;
            break;
        }

        if (choice >= 1 && choice <= 3) {
            vendingMachine.purchaseProduct(choice);
        } else {
            std::cout << "Invalid choice. Please select a valid product or enter 0 to exit." << std::endl;
        }
    }

    return 0;
}
