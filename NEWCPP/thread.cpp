#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isEven = true;
const int MAX_COUNT = 20;

void printEven() {
    for (int i = 2; i <= MAX_COUNT; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        while (!isEven) {
            cv.wait(lock);
        }
        std::cout << "Even: " << i << std::endl;
        isEven = false;
        cv.notify_one();
    }
}

void printOdd() {
    for (int i = 1; i <= MAX_COUNT; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        while (isEven) {
            cv.wait(lock);
        }
        std::cout << "Odd: " << i << std::endl;
        isEven = true;
        cv.notify_one();
    }
}

int main() {
    std::thread evenThread(printEven);
    std::thread oddThread(printOdd);

    evenThread.join();
    oddThread.join();

    return 0;
}
