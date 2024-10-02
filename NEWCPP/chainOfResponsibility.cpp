#include <iostream>

class Handler {
public:
    Handler(Handler* next) : nextHandler(next) {}

    virtual void handleRequest(int request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        }
        else
        {
            std::cout<<"Can not be handled";
        }
    }

private:
    Handler* nextHandler;
};

class ConcreteHandlerA : public Handler {
public:
    ConcreteHandlerA(Handler* next) : Handler(next) {}

    void handleRequest(int request) override {
        std::cout << "A\n" << std::endl;
        if (request <= 10) {
            std::cout << "Handled by ConcreteHandlerA" << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

class ConcreteHandlerB : public Handler {
public:
    ConcreteHandlerB(Handler* next) : Handler(next) {}

    void handleRequest(int request) override {
        std::cout << "B\n" << std::endl;
        if (request > 10 && request <= 20) {
            std::cout << "Handled by ConcreteHandlerB" << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

class ConcreteHandlerC : public Handler {
public:
    ConcreteHandlerC(Handler* next) : Handler(next) {}

    void handleRequest(int request) override {
        std::cout << "C\n" << std::endl;
        if (request > 20 && request < 50) {
            std::cout << "Handled by ConcreteHandlerC" << std::endl;
        } else {
            Handler::handleRequest(request);
        }
    }
};

int main() {
    // Create a chain of handlers
    ConcreteHandlerC handlerC(nullptr);
    ConcreteHandlerB handlerB(&handlerC);
    ConcreteHandlerA handlerA(&handlerB);

    // Process requests
    handlerA.handleRequest(5);  // Handled by ConcreteHandlerA
    handlerA.handleRequest(15); // Handled by ConcreteHandlerB
    handlerA.handleRequest(25); // Handled by ConcreteHandlerC

    handlerA.handleRequest(51); // Handled by ConcreteHandlerC

    return 0;
}
