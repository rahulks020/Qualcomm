#include <iostream>
#include <vector>

// Subject interface that defines methods for attaching, detaching, and notifying observers.

// Observer interface that defines the update method.
class Observer {
public:
    virtual void update(int state) = 0;
};

// Concrete Observer class that receives updates from the subject.
class ConcreteObserver : public Observer {
private:
    int observerState;

public:
    ConcreteObserver() : observerState(0) {}

    void update(int state) override {
        observerState = state;
        std::cout << "Observer received an update: " << observerState << std::endl;
    }
};

class Subject {
public:
    virtual void attach(class Observer* observer) = 0;
    virtual void detach(class Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject class that maintains a list of observers and notifies them on state changes.
class ConcreteSubject : public Subject {
private:
    int state;
    std::vector<Observer*> observers;

public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }

    void detach( Observer* observer) override {
        // Find and remove the observer from the list
        // auto it = std::find(observers.begin(), observers.end(), observer);
        // if (it != observers.end()) {
        //     observers.erase(it);
        // }
    }

    void notify() override {
        // Notify all attached observers
        for (auto observer : observers) {
            observer->update(state);
        }
    }

    void setState(int newState) {
        state = newState;
        notify(); // Notify observers when the state changes
    }
};


int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1;
    ConcreteObserver observer2;

    // Attach observers to the subject
    subject.attach(&observer1);
    subject.attach(&observer2);

    // Set the state of the subject (this will notify observers)
    subject.setState(42);

    // Detach an observer
    subject.detach(&observer1);

    // Set the state again (only observer2 will be notified)
    subject.setState(100);

    return 0;
}
