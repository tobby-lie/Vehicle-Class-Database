// Tobby Lie


#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include "vehicle.h"

using namespace std;

Dealer::Dealer(string iDealerName, string iDealerAddress)
{
    DealerName = iDealerName;
    DealerAddress = iDealerAddress;
}

Dealer::Dealer()
{
    DealerName = "";
    DealerAddress = "";
}

void Dealer::setName(string name)
{
    DealerName = name;
}

void Dealer::setAddress(string address)
{
    DealerAddress = address;
}

string Dealer::getName() const
{
    return DealerName;
}

string Dealer::getAddress() const
{
    return DealerAddress;
}

Vehicle::Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice)
{
    VIN = iVIN;
    make = iMake;
    model = iModel;
    year = iYear;
    price = iPrice;
    
    DealerPtr = new Dealer;
}

Vehicle::Vehicle()
{
    VIN = "";
    make = "";
    model = "";
    year = 0;
    price = 0.0;
    
    DealerPtr = new Dealer;
}

Vehicle::Vehicle(const Vehicle &obj)
{
    DealerPtr = new Dealer;
    
    VIN = obj.VIN;
    make = obj.make;
    model = obj.model;
    year = obj.year;
    price = obj.price;
    DealerPtr->setAddress(obj.DealerPtr->getAddress());
    DealerPtr->setName(obj.DealerPtr->getName());
    
}

void Vehicle::operator=(const Vehicle &obj)
{
    
    VIN = obj.VIN;
    make = obj.make;
    model = obj.model;
    year = obj.year;
    price = obj.price;
    DealerPtr->setAddress(obj.DealerPtr->getAddress());
    DealerPtr->setName(obj.DealerPtr->getName());
}


string Vehicle::getVIN() const
{return VIN;}

string Vehicle::getMake() const
{return make;}

string Vehicle::getModel() const
{return model;}

int Vehicle::getYear() const
{return year;}

double Vehicle::getPrice() const
{return price;}

void Vehicle::setVIN(string v)
{
    VIN = v;
}

void Vehicle::setMake(string m)
{
    make = m;
}

void Vehicle::setModel(string mo)
{
    model = mo;
}

void Vehicle::setYear(int y)
{
    year = y;
}

void Vehicle::setPrice(double p)
{
    price = p;
}

ostream &operator << (ostream & out, Vehicle &car)
{
    
    out << car.getVIN() << endl;
    out << car.getMake() <<endl;
    out << car.getModel() << endl;
    out << car.getYear()<<endl;
    out << car.getPrice() << endl;
    out << car.DealerPtr->getName() <<endl;
    out << car.DealerPtr->getAddress() <<endl;
    
    return out;
}

/*void printVector (ostream& out, vector<Vehicle> &vehicleVector)
{
    for (int i=0; i < vehicleVector.size(); i++)
    {
        out << vehicleVector[i] <<endl <<endl;
    }
}*/






