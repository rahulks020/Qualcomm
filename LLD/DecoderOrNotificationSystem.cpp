#include <iostream>
using namespace std;

// Bridge Design pattern : decouple abstractions from its implementation to go indendently.

// ex - LivingThings  (Dog , Tree, Fish)         Breathe(LandBreath, waterBreath TreeBreath)   both Living things and Breathe can grow independently.
// LivingThings will have Breath object (has a relationship)  // check concepts and coding on You tube.
 
class NotificationSender
{
    public:
    virtual void sendNotification() = 0;
};

class SMS : public NotificationSender
{
    public:
    void sendNotification()
    {
        cout<<"You are sending Through SMS\n";
    }
};

class EMAIL : public NotificationSender
{
    public:
    void sendNotification()
    {
        cout<<"You are sending Through Email:\n";
    }
};



class Notification
{
    
    public:
    NotificationSender * notificationSender;
    Notification(NotificationSender * notification = NULL)
    {
        this->notificationSender = notification;
    }

    virtual void sendMessage() = 0;

};

class TextMessage : public Notification
{
      public:
      TextMessage (NotificationSender * notificationSender)
      {
        this->notificationSender = notificationSender;
      }
      void sendMessage()
      {
        cout<<"THIS IS TEXT MESSAGE : ";
        notificationSender->sendNotification();
      }
};

class QRMessage : public Notification
{
      public:
      QRMessage (NotificationSender * notificationSender)
      {
        this->notificationSender = notificationSender;
      }
      void sendMessage()
      {
        cout<<"THIS IS QR MESSAGE : ";
        notificationSender->sendNotification();
      }
};

int main()
{
    Notification * notification = new  TextMessage (new SMS());
    notification->sendMessage();

    notification = new  TextMessage (new EMAIL());
    notification->sendMessage();

    notification = new  QRMessage (new EMAIL());
    notification->sendMessage();


    return 0;
}


