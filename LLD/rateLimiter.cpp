#include <iostream>
#include <map>
#include <deque>
#include <string>
using namespace std;

class User{

    string name;
    public:
    User(string s):name(s){};

    string getName()
    {
        return name;
    }

};

class RateLimiter
{
    int rate;
    int capacity;
    map<User *, deque<int> >limiter;
    public: 
    bool isAllow(User * u, int t)
    {
        bool ans = false;
        if(limiter.find(u) == limiter.end())
        {
            limiter[u].push_back(t);  ans = true;
        }
        else 
        {
             deque<int>d = limiter[u];

             while(d.size() > 0 && t - d.front() > rate)
             d.pop_front();

             if(d.size() < capacity)
             {
                d.push_back(t); ans = true;
             }

             limiter[u] = d;
        }

        return ans;
    }

    RateLimiter(int rte, int cap): rate(rte), capacity(cap){}
};

int main()
{
    cout<<"Hello World\n";

    User U1("Ram");
    User U2("Lakshman");
    User U3("Sita");

    RateLimiter RL1(10, 5);

    if(RL1.isAllow(&U1, 2))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }

    //----------------------------------------------
    
    if(RL1.isAllow(&U1, 3))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------


    if(RL1.isAllow(&U1, 5))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------

    if(RL1.isAllow(&U1, 6))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------


    if(RL1.isAllow(&U1, 8))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------


    if(RL1.isAllow(&U1, 9))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------

    if(RL1.isAllow(&U1, 13))
    {
        cout<<U1.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U1.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------

    if(RL1.isAllow(&U2, 8))
    {
        cout<<U2.getName()<<" is allowed."<<"\n";
    }
    else{
        cout<<U2.getName()<<" is not allowed."<<"\n";
    }
    //----------------------------------------------

}