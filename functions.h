// Tobby Lie

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "vehicle.h"
#include <vector>
#include <cstring>

using namespace std;

void displayInventory(vector<Vehicle>& v)
{
    /*
    This will display the contents of each
     vehicle using the following format:
     
     Vehicle: #
     
     VIN: VVVV
     
     Make: MMMM
     
     Model: MMMM
     
     Year: YYYY
     
     Price: $D.CC
     
     Dealer Name: DDDDDD
     
     Dealer Address:  AAAAAAAAAA
     
     This will be done by using the dot operator
     with subscripts of the vector. This will
     all be inside of a for loop using the 
     size of the vector as a sentinel to end the
     loop.
     
     In order to get the vehicle number, the 
     index + 1 will be used. 
     
     For the dollar sign and decimal for the price
     this will be based off of the user input for the
     double data type and also a dollar sign will
     simply just need to be printed before every price.
     
     
 */
    
    cout << "This option displays the inventory of vehicles." << endl;
    
    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        cout << fixed << showpoint << setprecision(2) << endl;
        
        cout << "Vehicle: # " << i + 1 << endl;
        cout << "VIN: " << v[i].getVIN() << endl;
        cout << "Make: " << v[i].getMake() << endl;
        cout << "Model: " << v[i].getModel() << endl;
        cout << "Year: " << v[i].getYear() << endl;
        cout << "Price: $" << v[i].getPrice() << endl;
        cout << "Dealer Name: " << v[i].DealerPtr->getName() << endl;
        cout << "Dealer Address: " << v[i].DealerPtr->getAddress() << endl;
    }
}

void addVehicle(vector<Vehicle>& v)
{
    /*
     You will ask the user for all of the information 
     to add the vehicle (including the information of its dealer) 
     and then you will add it to the vector.
    */
    
    /*
     I believe this can be done by using the push_back
     function to put the data of one object into the Vehicle object
    */
    string iVIN;
    string imake;
    string imodel;
    int iyear;
    double iprice;
    string iname;
    string iaddress;
    
    cout << "This option will allow you to add a vehicle." << endl;
    cout << endl;
    cout << "Please enter all of the information for the vehicle" << endl;
    cout << endl;
    cout << "Please enter the Vehicle VIN: " << endl;
    cin >> iVIN;
    cin.ignore();
    cout << "Please enter the Vehicle make: " << endl;
    getline(cin,imake);
    cout << "Please enter the Vehicle model: " << endl;
    getline(cin,imodel);
    cout << "Please enter the Vehicle year: " << endl;
    cin >> iyear;
    cout << "Please enter the Vehicle price: " << endl;
    cin >> iprice;
    cin.ignore();
    cout << "Please enter the Dealer name: " << endl;
    getline(cin, iname);
    cout << "Please enter the Dealer address: " << endl;
    getline(cin,iaddress);
    
    
    imodel[0] = toupper(imodel[0]);
    for(int i = 1; i < imodel.size(); i++)
    {
        imodel[i] = tolower(imodel[i]);
    }
    
    Vehicle vehi(iVIN, imake, imodel, iyear, iprice);
    v.push_back(vehi);
    
    int pos = v.size();

    
    v[pos-1].DealerPtr->setName(iname);
    v[pos-1].DealerPtr->setAddress(iaddress);
    
    
}

void updateVehicle(vector<Vehicle>& v)
{
    /*
    You will display the vehicles and then ask the user
    which vehicle to edit. They will give you the index 
    number (starting at 1). Check to ensure they gave
    you a valid entry, then prompt for which item they
    want to edit (year, make, model, price, or VIN).
    Once they make their selection prompt for the new
    information, then return to the main menu.
    */
    
    /*
     This will have to be done in two layers, first
     the verification of the index. Which means the user
     will have to input the index which will then be subtracted
     by one. From there a menu can be presented to the user
     which then they can choose which item they want to edit
     the value of the user will then be stored into a variable
     and then stored into the item.
    */
    cout << "This option allows you to update the  " << endl;
    cout << "year, make, model, price, or VIN of the vehicle of your choosing." << endl;
    cout << endl << endl;
    cout << "Here is the current inventory." << endl;
    
    int size = v.size();
    
    for (int i = 0; i < size; i++)
    {
        cout << fixed << showpoint << setprecision(2) << endl;
        
        cout << "Vehicle: # " << i + 1 << endl;
        cout << "VIN: " << v[i].getVIN() << endl;
        cout << "Make: " << v[i].getMake() << endl;
        cout << "Model: " << v[i].getModel() << endl;
        cout << "Year: " << v[i].getYear() << endl;
        cout << "Price: $" << v[i].getPrice() << endl;
        cout << "Dealer Name: " << v[i].DealerPtr->getName() << endl;
        cout << "Dealer Address: " << v[i].DealerPtr->getAddress() << endl;
    }
    cout << endl << endl;
    
    char confirm;
    do{
    int choice;
    cout << "Which vehicle would you like to update? (enter the vehicle # of your choice)" << endl;
    cin >> choice;
    while (choice > size || choice < 1)
    {
        cout << "Invalid entry! Please input a vehicle number form the inventory list!" << endl;
        cout << endl;
        cout << "Which vehicle would you like to update? (enter the vehicle # of your choice)" << endl;
        cin >> choice;
    }
    
    cout << "You chose vehicle # " << choice << endl;
    cout << endl;
    cout << "Here is a list of items you can change for this vehicle." << endl;
    cout << "1. Year" << endl;
    cout << "2. Make" << endl;
    cout << "3. Model" << endl;
    cout << "4. Price" << endl;
    cout << "5. VIN" << endl;
    cout << endl;
    
    
    
    int item;
    cout << "Enter a number from 1-5 corresponding to the item you would like to change." << endl;
    cin >> item;
    
        
    switch(item)
    {
        case 1:
        {
            int iyear;
            cout << "This option will allow you to change the year of the vehicle." << endl;
            cout << "What year would you like to change this vehicle to?" << endl;
            cin >> iyear;
            v[choice-1].setYear(iyear);
            
            break;
        }
        case 2:
        {
            cin.ignore();
            string imake;
            cout << "This option will allow you to change the make of the vehicle." << endl;
            cout << "What make would you like to change this vehicle to?" << endl;
            getline(cin,imake);
            v[choice-1].setMake(imake);
            
            break;
        }
        case 3:
        {
            cin.ignore();
            string imodel;
            cout << "This option will allow you to change the model of the vehicle." << endl;
            cout << "What model would you like to change this vehicle to?" << endl;
            getline(cin,imodel);
            
            imodel[0] = toupper(imodel[0]);
            for(int i = 1; i < imodel.size(); i++)
            {
                imodel[i] = tolower(imodel[i]);
            }
            
            v[choice-1].setModel(imodel);
            
            break;
        }
        case 4:
        {
            double iprice;
            cout << "This option will allow you to change the price of the vehicle." << endl;
            cout << "What price would you like to change this vehicle to?" << endl;
            cin >> iprice;
            v[choice-1].setPrice(iprice);
            
            break;
        }
        case 5:
        {
            string iVIN;
            cout << "This option will allow you to change the VIN of the vehicle." << endl;
            cout << "What VIN would you like to change this vehicle to?" << endl;
            cin >> iVIN;
            v[choice-1].setVIN(iVIN);
            
            break;
        }
        default:
        {
            cout << "Invalid input!" << endl;
        }
            
        
    }
    
        cout << "Would you like to change the item of another vehicle?" << endl;
        cout << "Input Y or any other character to return to the menu" << endl;
        cin >> confirm;
        
    }while(confirm == 'y' || confirm == 'Y');
    
    
    
    
    
    
}

void deleteVehicle(vector<Vehicle>& v)
{
    /*You will display the vehicles and then ask the
     user which vehicle to delete. They will give you
     the index number (starting at 1). You will then
     check to ensure they gave you a valid entry and
     then remove that vehicle from the vector.
    */
    
    /*
     This can be done by using the user input of index to 
     move back the indexes above the one given by one, thus
     eliminating the chosen vehicle. Since we are working in vectors,
     the size will adjust.
     */
    cout << "This option allows you to delete the " << endl;
    cout << "vehicle of your choosing from inventory." << endl;
    cout << endl << endl;
    cout << "Here is the current inventory." << endl;
    
    int size = v.size();
    
    for (int i = 0; i < size; i++)
    {
        cout << fixed << showpoint << setprecision(2) << endl;
        
        cout << "Vehicle: # " << i + 1 << endl;
        cout << "VIN: " << v[i].getVIN() << endl;
        cout << "Make: " << v[i].getMake() << endl;
        cout << "Model: " << v[i].getModel() << endl;
        cout << "Year: " << v[i].getYear() << endl;
        cout << "Price: $" << v[i].getPrice() << endl;
        cout << "Dealer Name: " << v[i].DealerPtr->getName() << endl;
        cout << "Dealer Address: " << v[i].DealerPtr->getAddress() << endl;
    }
    cout << endl << endl;
    
    cout << "Which vehicle would you like to delete from inventory?" << endl;
    cout << "Enter the vehicle number and hit enter." << endl;
    
    int choice;
    cin >> choice;
    
    v.erase(v.begin()+(choice-1));
    
    cout << endl;
    cout << "Vehicle # " << choice << " has been deleted from the inventory." << endl;
    
}

void sortVehicle(vector<Vehicle>& v)
{
    /*You will sort the vector by VIN number
     (when sort is done, the vector in main will be sorted by VIN number).
     */
    
    int startScan, minIndex;
    string minVIN;
    Vehicle minValue;
    
    
     int size = v.size();
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minVIN = v[startScan].getVIN();
        minValue = v[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (v[index].getVIN() < minVIN)
            {
                minValue = v[index];
                minIndex = index;
            }
        }
        
        v[minIndex].operator = (v[startScan]);
        v[startScan].operator = (minValue);
        
        
    }
    
    cout << endl;
    //cout << "************************************" << endl;
    cout << "*Inventory has been sorted by VIN.*" << endl;
    //cout << "************************************" << endl;
    cout << endl;

    
    /*
     Will use either bubble sort or selection sort algorithm to sort VIN numbers
     making sure to also carry through other items of the object with the same
     index.
     */
}

void searchInventory(vector<Vehicle>& v)
{
    /*
     6. You will ask the user for a model, then
     search the vector for that vehicle. You will
     return the first matching entry’s index number
     or an appropriate message if not found.
     */
    
    cout << "This option allows you to search for a vehicle " << endl;
    cout << "by model, it will then give you the vehicle number" << endl;
    cout << endl << endl;
    cout << "Here is the current inventory." << endl;
    
    int size = v.size();
    
    for (int i = 0; i < size; i++)
    {
        cout << fixed << showpoint << setprecision(2) << endl;
        
        cout << "Vehicle: # " << i + 1 << endl;
        cout << "VIN: " << v[i].getVIN() << endl;
        cout << "Make: " << v[i].getMake() << endl;
        cout << "Model: " << v[i].getModel() << endl;
        cout << "Year: " << v[i].getYear() << endl;
        cout << "Price: $" << v[i].getPrice() << endl;
        cout << "Dealer Name: " << v[i].DealerPtr->getName() << endl;
        cout << "Dealer Address: " << v[i].DealerPtr->getAddress() << endl;
    }
    cout << endl << endl;
    
    cout << "Which vehicle model are you looking for?" << endl;
    
    string choice;
    
    getline(cin,choice);
    
    choice[0] = toupper(choice[0]);
    for(int i = 1; i < choice.size(); i++)
    {
        choice[i] = tolower(choice[i]);
    }
    
    //binary search
    /*int first = 0;
    int last = size - 1, middle, position = -1;
    bool found = false;
    
    while (!found && first <= last)
    {
        middle = (first+last)/2;
        if(v[middle].getModel() == choice)
        {
            found = true;
            position = middle;
        }
        else if (v[middle].getModel() > choice)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    
    if(position != -1)
    {
        cout << "Vehicle # " << position + 1 << " is  model " << choice << endl;
    }
    else if (position = -1)
    {
        cout << "Vehicle model could not be found in the inventory." << endl;
    }*/
    
    //switched to a linear search because the vehicles will be sorted by VIN
    
    int index = 0;
    int position  = -1;
    bool found = false;
    
    while(index < v.size() && !found)
    {
        if(v[index].getModel() == choice)
        {
            found = true;
            position = index;
        }
        index++;
    }
    if(position != -1)
    {
        cout << "Vehicle # " << position + 1 << " is  model " << choice << endl;
    }
    else if (position = -1)
    {
        cout << "Vehicle model could not be found in the inventory." << endl;
    }
    
    
    
    
    /*
     Will use either binary or linear search for
     model of vehicle. Once found, the vehicle number
     will be displayed. If nothing is found, then a message is displayed
     This will mean that -1 will be returned for position causing
     there to be no match found.
     */
}

void readInventory(vector<Vehicle>& v)
{
    
    int size = v.size();
    
    ifstream inFile;
    
    inFile.open("inventory.txt");
    
    if(inFile.fail())
       {
           cout << "Unable to open file!" << endl;
       }
   
    
    
    string iVIN;
    string imake;
    string imodel;
    int iyear;
    double iprice;
    string iname;
    string iaddress;
    
    //This part is confusing for me
   // Dealer v.DealerPtr = new Dealer;
    
    string temp;
    while(inFile)
    {
        inFile >> iVIN;
        inFile >> imake;
        inFile >> imodel;
        inFile >> iyear;
        inFile >> iprice;
        getline(inFile, temp);
        getline(inFile, iname);
        getline(inFile, iaddress);
        getline(inFile, temp);
        
        imodel[0] = toupper(imodel[0]);
        for(int i = 1; i < imodel.size(); i++)
        {
            imodel[i] = tolower(imodel[i]);
        }
        
        
        Vehicle vehi(iVIN, imake, imodel, iyear, iprice);
        
        v.push_back(vehi);
        int pos = v.size();
        

        v[pos-1].DealerPtr->setName(iname);
        v[pos-1].DealerPtr->setAddress(iaddress);
        
       
    }
    inFile.close();
    
    cout << "Your file has been read." << endl;
}

void writeInventory(vector<Vehicle>& v)
{
    /*
     You will write the entire inventory out to a
     file called inventory.out (using the << operator)
     and then exit the program.
     */
    ofstream outfile("inventory.out");
    //ofstream outfile("test.txt");
    
    for(int i = 0; i < v.size(); i ++)
    {
        outfile << v[i] << endl;;
    }
    
    outfile.close();
    
}


