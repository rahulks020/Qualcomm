#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
    int userId;
    string userName;

    public:
    void setUserId(int id)
    {
        this->userId = id;
    }

    int getUserId() const
    {
        return userId;
    }

    string getUserName() const
    {
        return userName;
    }

    User(string s):userName(s){}
    
};

class Message
{
    string msg;
    User * user;

    public:

    void setUserId(User * u)
    {
          this->user = u;
    }

    void showMessage()
    {
        cout<<msg<<" "<<user->getUserName()<<"\n";
    }

    Message(string s)
    {
        this->msg = s;
    }
    
};

class ChatRoom
{
    vector<User *>users;
    vector<Message *>messages;

    public:
    void addUser(User * u)
    {
        users.push_back(u);
    }

    void removeUser(User * u)
    {
        //auto it = find(users.begin(), users.end(), u);
        users.erase(users.begin());
    }

    void broadCastMessage()
    {
        for(auto message : messages)
        {
            message->showMessage();
        }
    }

    void addMessage(User * u, Message * m)
    {
        m->setUserId(u);
        messages.push_back(m);
    }

};

int main()
{
    Message M1("Hi Buddy");
    Message M2("Hi there");
    Message M3("How are you");

    User U1("Rahul");
    User U2("Mohan");
    U1.setUserId(1);
    U2.setUserId(2);

    ChatRoom c1;

    c1.addUser(&U1);
    c1.addUser(&U2);

    c1.addMessage(&U1, &M1);
    c1.addMessage(&U2, &M2);
    c1.addMessage(&U1, &M3);

    c1.broadCastMessage();

    return 0;
}