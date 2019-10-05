// Tobby Lie



#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

class Dealer
{
    
private:
    string DealerName;
    string DealerAddress;
public:
    void setName(string);
    void setAddress(string);
    string getName() const;
    string getAddress() const;
    Dealer();
    Dealer(string, string);
};

class Vehicle
{
    
private:
    string VIN;
    string make;
    string model;
    int year;
    double price;
public:
    Dealer *DealerPtr;
    Vehicle(string iVIN, string iMake, string iModel, int iYear, double iPrice);
    Vehicle();
    Vehicle(const Vehicle &obj);
    void operator=(const Vehicle &obj);
    //destructor
    ~Vehicle()
    {
        delete DealerPtr;
    }
    string getVIN() const;
    string getMake() const;
    string getModel() const;
    int getYear() const;
    double getPrice() const;
    void setVIN(string);
    void setMake(string);
    void setModel(string);
    void setYear(int);
    void setPrice(double);
    friend ostream &operator << (ostream & out, Vehicle &car);
    // + friend operator << (out:ostream &, Vehicle: car 1):ostream &
    
};
