#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Address
{
    string city, state;

    public:

    Address(string state, string city) : state(state), city(city)
    {

    }

};

enum ParkingSlotType {COMPACT, LARGE, SMALL, TWHEELER};

enum ParkingSlotStatus {AVAILABLE, OCCUPIED};

enum VehicleCategory {TWOHEELER, SUV, BUS};

class Vehicle{
    string vehicleName;
    VehicleCategory vehicleCategory;

    public:
    Vehicle (string name, VehicleCategory vehicleCaterory) : vehicleName(name), vehicleCategory(vehicleCaterory) {}


    string getVehicleName()
    {
        return vehicleName;
    }

    VehicleCategory getVehicleCaterory()
    {
        return vehicleCategory;
    }
};


class ParkingSlot{

    string name;
    Vehicle * vehicle;
    ParkingSlotStatus parkingSlotStatus;

    public:
    ParkingSlot(string name)
    {
         this->name = name;
         this->parkingSlotStatus = AVAILABLE;
         this->vehicle = NULL;

    }

    void addVehicle(Vehicle * vehicle)
    {
         this->vehicle = vehicle;
         this->parkingSlotStatus = OCCUPIED;
    }

    void removeVehicle()
    {
        this->parkingSlotStatus = AVAILABLE;
        this->vehicle = NULL;
    }
     
    ParkingSlotStatus getParkingSlotStatus()
    {
        return parkingSlotStatus;
    }


};

class ParkingFloor
{
    string floorName;
    map<ParkingSlotType, vector<ParkingSlot*> >parkingSlots;

    public:
    ParkingFloor(string floorName, map<ParkingSlotType , vector<ParkingSlot * > > parkingSlots)
    {
        this->floorName = floorName;
        this->parkingSlots = parkingSlots;
    }

    ParkingSlot * getRelevantSlotForVehicleAndPark(Vehicle * vehicle)
    {
           VehicleCategory vehicleCategory = vehicle->getVehicleCaterory();
           ParkingSlotType parkingSlotType = pickCorrectSlot(vehicleCategory);
           
           vector<ParkingSlot *> slots;
           if(parkingSlots.find(parkingSlotType) != parkingSlots.end())
           {
                slots = parkingSlots[parkingSlotType];
           }

           for(auto slot : slots)
           {
               if(slot->getParkingSlotStatus() == AVAILABLE)
               {
                slot->addVehicle(vehicle);
                return slot;
               }
           }

           
    }

    ParkingSlotType pickCorrectSlot(VehicleCategory vehicleCategory)
    {
        if(vehicleCategory == TWOHEELER) return TWHEELER;
        if(vehicleCategory == SUV) return LARGE;
        if(vehicleCategory == BUS) return LARGE;
    }

    
    

};

class Ticket{
      
    int startTime;
    int endTime;
    ParkingSlot * parkingSlot;
    Vehicle * vehicle;
    public:
    Ticket()
    {
          startTime = endTime = 0; 
    }
    static Ticket createTicket(ParkingSlot * slot, Vehicle * veh)
    {
           Ticket t;
           t.parkingSlot = slot;
           t.vehicle = veh;

           return t;
    }
    int getTicketNumber()
    {
        return 1;
    }

};

class ParkingLot
{
       string parkingLotName;
       vector<ParkingFloor> parkingFloors;

       static ParkingLot * parkingLot;

       ParkingLot()
       {

       }

       public:

       static ParkingLot * getInstance()
       {
        if(parkingLot == NULL)
        {
           parkingLot = new ParkingLot();
        }
         return parkingLot;
       }

       Ticket assignTicket(Vehicle * vehicle)
       {
        ParkingSlot * parkingSlot = getParkingSlotForVehicleAndPark(vehicle);

        Ticket parkingTicket = createTicketForSlot(parkingSlot,vehicle);
        
        return parkingTicket;

       }

       

       ParkingSlot * getParkingSlotForVehicleAndPark(Vehicle * vehicle)
       {
        ParkingSlot * slot = NULL;
          for(auto floor : parkingFloors)
          {
              slot = floor.getRelevantSlotForVehicleAndPark(vehicle);
              if(slot != NULL)
              break;
          }

          return slot;
       }

       Ticket createTicketForSlot(ParkingSlot * parkingSlot, Vehicle * vehicle) {
         Ticket t;
        return t.createTicket(parkingSlot, vehicle);
       }

       int payAmount(Ticket t)
       {
          return 5;
       }

};
ParkingLot * ParkingLot::parkingLot = NULL;

int main()
{
    Address address ("Telangana", "Hyderabad");
    cout<<"Hello world\n";

    Vehicle v1("TATA MOTORS", SUV);
    Vehicle v2("TATA BUS", BUS);

    ParkingSlot s1("S1");
    ParkingSlot s2("S1");
    ParkingSlot s3("S1");

    vector<ParkingSlot *>slots;
    slots.push_back(&s1);
    slots.push_back(&s2);
    slots.push_back(&s3);

    map<ParkingSlotType, vector<ParkingSlot *> >mp;

    mp[LARGE] = slots;

    ParkingFloor f1("F1", mp);


    ParkingLot * parkingLot = ParkingLot::getInstance();


    Ticket ticket = parkingLot->assignTicket(&v1);

    cout<<"Ticket Number"<<ticket.getTicketNumber()<<"\n";

    cout<<parkingLot->payAmount(ticket)<<"\n";

    return 0;

}


