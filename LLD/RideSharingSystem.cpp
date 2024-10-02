#include<iostream>
#include<vector>

using namespace std;

enum rideStatus {IDLE, CLOSED, WITHDRAWL, COMPLETED, CREATED};

class Person
{
public:
	string name;
};

class Driver: public Person
{
public:
	Driver(string);
};


class Ride{
  
  int src;
  int dist;
  int seats;
  rideStatus RideStatus;
  int id;

  public:
  static const int AMT_PER_KM = 20;
  Ride();
  void setDist(int);
  int getDist();
  void setsrc(int);
  void setSeats(int);
  int getSeats();
  int getSrc();
  int getId() const;
  void setId(int id);
  int calculateFare(bool);
  void setRideStatus(rideStatus status);
  rideStatus getRideStatus();
};
Ride::Ride()
{
    id = seats = src =  dist = 0;
    RideStatus = IDLE;
}

void Ride::setSeats(int seats)
{
    this->seats = seats;
}
int Ride::getSeats()
{
    return seats;
}
void Ride::setDist(int dist)
{
 this->dist = dist;
}
int Ride::getDist()
{
    return this->dist;
}
void Ride::setsrc(int src)
{
 this->src = src;
}

void Ride::setRideStatus(rideStatus status)
{
    this->RideStatus = status;
}

rideStatus Ride::getRideStatus()
{
    return this->RideStatus;
}

void Ride::setId(int id)
{
    this->id = id;
}
int Ride::getId() const
{
    return id;
}

int Ride::calculateFare(bool isPriorityRider)
{
      int distancd = dist - src;

      if(seats < 2)
        {
            return dist * AMT_PER_KM * (isPriorityRider?0.75:1);
        }

        return dist * seats * AMT_PER_KM * (isPriorityRider?0.5:0.75);
}



class Rider : public Person{
    int id;
    vector<Ride> completedRides;
	Ride currentRide;


    public:
    Rider(string name, int Id);
    void createRide(int id, int origin, int dest, int seats);
    void withdrawRide(int);
    void updateRide(int id, int origin, int dest, int seats);
    int closeRide();

    
};

Rider::Rider(string name, int id)
{
    this->id = id;
	this->name = name;
}

void Rider::createRide(int id, int origin, int dest, int seats)
{
       if(origin >= dest)
       {
        cout<<"Ride canot created\n";
       }

       currentRide.setId(id);
       currentRide.setsrc(origin);
       currentRide.setDist(dest);
       currentRide.setSeats(seats);
       currentRide.setRideStatus(rideStatus::CREATED);

}

void Rider::updateRide(int id, int origin, int dest, int seats)
{
     if(currentRide.getRideStatus() == rideStatus::COMPLETED || currentRide.getRideStatus() == rideStatus::WITHDRAWL)
     {
        cout<<"Ride has already Completed\n";
     }

     createRide(id, origin, dest, seats);
}

void Rider::withdrawRide(int id)
{
    if(currentRide.getRideStatus() != rideStatus::CREATED)
    {
        cout<<"Ride wasn't created\n";
        return;
    }
    if (currentRide.getId() != id)
	{
		cout << "Wrong ride Id as input. Can't withdraw current ride\n";
		return;
	}

    currentRide.setRideStatus(rideStatus::WITHDRAWL);
}

int Rider::closeRide()
{
         
    if(currentRide.getRideStatus() != rideStatus::CREATED)
    {
        cout<<"Ride wasn't create\n";
    }

    currentRide.setRideStatus(rideStatus::COMPLETED);
    completedRides.push_back(currentRide);
    return currentRide.calculateFare(completedRides.size() >= 10);
}

Driver::Driver(string name)
{
    this->name = name;
}

int main()
{
    cout<<"Hello World\n";

    Driver d("Shyam");
    Rider rider("Rahul", 1);
    Rider rider1("Mohan", 2);
    Rider rider2("Sohan", 3);

    rider.createRide(1, 50, 60, 1);
	cout << rider.closeRide() << endl;
	rider.updateRide(1, 50, 60, 2);
	cout << rider.closeRide() << endl;

    return 0;
}