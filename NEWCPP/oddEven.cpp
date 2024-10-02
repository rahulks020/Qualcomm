#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;
int count1 = 1;

void printEven() {
    mtx.lock();
    while(count1 <= 20) {
        if(count1 % 2 == 0) {
            cout << "Even: " << count1 << endl;
            count1++;
        }
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(100)); // pause for 100ms
        mtx.lock();
    }
    mtx.unlock();
}

void printOdd() {
    mtx.lock();
    while(count1 <= 20) {
        if(count1 % 2 != 0) {
            cout << "Odd: " << count1 << endl;
            count1++;
        }
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(100)); // pause for 100ms
        mtx.lock();
    }
    mtx.unlock();
}

int main() {
    thread t1(printEven);
    thread t2(printOdd);

    t1.join();
    t2.join();

    return 0;
}
