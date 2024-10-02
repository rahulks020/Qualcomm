#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
using namespace std;



std::mutex mtx;
std::condition_variable cv;
std::deque<int> buffer;

const unsigned int maxbuffer = 50;



void producer(int val) {
    while(val)
    {
        std::unique_lock<std::mutex> locker(mtx);
        cv.wait(locker, [](){return buffer.size() < maxbuffer;});
        cout<<"Produced "<<val<<"\n";
        buffer.push_back(val);
        val--;
        locker.unlock();
        cv.notify_all();
    }
}

void consumer()
{
       while(true)
       {
        std::unique_lock<std::mutex>locker(mtx);
        cv.wait(locker, [](){return buffer.size() > 0;});
        int val = buffer.front();
        buffer.pop_front();
        cout<<"Consumed :"<<val<<"\n";
        locker.unlock();
        cv.notify_all();
       }
}



int main() {
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
