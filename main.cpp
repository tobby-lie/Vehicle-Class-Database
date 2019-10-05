// Tobby Lie
// last modified 5/5/17 @ 5:12PM

#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    vector<Vehicle> veh;
    int option = 0;
    
    while (option != 8)
    {
    cout << "This program manages cars in a dealership." << endl;
    cout << "Here is the menu of options." << endl;
    cout << "Please input a number from 1-8 to make a choice" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "1. Display Inventory" << endl;
    cout << "2. Add a vehicle" << endl;
    cout << "3. Update a vehicle" << endl;
    cout << "4. Delete a vehicle" << endl;
    cout << "5. Sort inventory by VIN" << endl;
    cout << "6. Search inventory by Model" << endl;
    cout << "7. Read inventory from file" << endl;
    cout << "8. Write inventory to file and exit" << endl;
    
        cin >> option;
        cin.ignore();
        
        switch(option)
        {
            case 1:
            {
                displayInventory(veh);
                break;
            }
            case 2:
            {
                addVehicle(veh);
                break;
            }
            case 3:
            {
                updateVehicle(veh);
                break;
            }
            case 4:
            {
                deleteVehicle(veh);
                break;
            }
            case 5:
            {
                sortVehicle(veh);
                break;

            }
            case 6:
            {
                searchInventory(veh);
                break;

            }
            case 7:
            {
                readInventory(veh);
                break;

            }
            case 8:
            {
                writeInventory(veh);
                break;

            }
        }
        
        
    
    }
    return 0;
}
