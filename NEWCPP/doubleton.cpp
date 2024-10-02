#include <iostream>

class Doubleton {
private:
    static Doubleton* instances[2];
    static int callCount;
    
    Doubleton() {}
    
public:
    static Doubleton* getInstance() {
        callCount++;
        return instances[callCount % 2];
    }

    static void initialize() {
        if (!instances[0]) {
            instances[0] = new Doubleton();
        }
        if (!instances[1]) {
            instances[1] = new Doubleton();
        }
    }

    void show() const {
        std::cout << "Instance at: " << this << std::endl;
    }
};

Doubleton* Doubleton::instances[2] = {nullptr, nullptr};
int Doubleton::callCount = -1;

int main() {
    Doubleton::initialize();
    Doubleton* inst1 = Doubleton::getInstance();
    inst1->show();
    Doubleton* inst2 = Doubleton::getInstance();
    inst2->show();
    Doubleton* inst3 = Doubleton::getInstance();
    inst3->show();
    
    return 0;
}
