#include <iostream>
#include <stdio.h> //c_str()

using namespace std;

struct Date
{
    int month;
    int day;
    int year;
};

struct Place
{
    string address;
    string suburb;
    string city;
    string province;
};

struct EmployeeInfo
{
    string name;
    string empNum;
    Date birthDate;
    Place residence;
};

void display(EmployeeInfo* pInfo, int* pCount)
{
    printf("%-25s %-10s %-15s\n", "Name", "Birth Year", "City");

    for(int k = 0; k < *pCount; k++)
    {
        EmployeeInfo temp = *(pInfo + k);

        printf("%-25s %-10d %-15s\n", temp.name.c_str(),
            temp.birthDate.year, temp.residence.city.c_str());
    }
}

int main()
{
    const int SIZE = 10;
    EmployeeInfo manager[SIZE];

    int counter = 0;

    cout << "Enter the manager's name (# to stop): ";
    getline(cin, manager[counter].name);

    while(manager[counter].name != "#")
    {
        cout << "Enter the manager's employee number: ";
        cin >> manager[counter].empNum;

        cout << "Enter the manager's date of birth" << endl;
        cout << "Month (mm): ";
        cin >> manager[counter].birthDate.month;

        cout << "Day (dd): ";
        cin >> manager[counter].birthDate.day;

        cout << "Year (yyyy): ";
        cin >> manager[counter].birthDate.year;

        cin.ignore();

        cout << "Enter the manager's address" << endl;
        cout << "Street: ";
        getline(cin, manager[counter].residence.address);

        cout << "Suburb: ";
        getline(cin, manager[counter].residence.suburb);

        cout << "City: ";
        getline(cin, manager[counter].residence.city);

        cout << "Province: ";
        getline(cin, manager[counter].residence.province);

        counter++;

        cout << "Enter another manager's name (# to stop): ";
        getline(cin, manager[counter].name);

    }//end of while

    display(manager, &counter);

    return 0;
}
