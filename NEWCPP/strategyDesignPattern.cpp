#include <iostream>

// Define the Strategy interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
};

// Concrete Strategy 1: Credit Card Payment
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " dollars using Credit Card." << std::endl;
    }
};

// Concrete Strategy 2: PayPal Payment
class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " dollars using PayPal." << std::endl;
    }
};

// Context class that uses the selected payment strategy
class ShoppingCart {
public:
    void setPaymentStrategy(PaymentStrategy* strategy) {
        paymentStrategy = strategy;
    }

    void checkout(int amount) {
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        } else {
            std::cout << "Please set a payment strategy before checkout." << std::endl;
        }
    }

private:
    PaymentStrategy* paymentStrategy;
};

int main() {
    // Create payment strategy objects
    CreditCardPayment creditCard;
    PayPalPayment paypal;

    // Create a shopping cart
    ShoppingCart cart;

    // Set the payment strategy and checkout
    cart.setPaymentStrategy(&creditCard);
    cart.checkout(100);

    // Change the payment strategy and checkout again
    cart.setPaymentStrategy(&paypal);
    cart.checkout(50);

    return 0;
}
