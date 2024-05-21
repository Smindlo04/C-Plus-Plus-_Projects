#include <iostream>

using namespace std;

struct Restaurant
{
    char name[30];
    int food;     //rate food
    int service;  //rate service
};


void displayData(Restaurant arrRestaurant[], int counter)
{
    cout << "\nList of restaurants" << endl;
    cout << "\t" << "Name" << "\t\tFood" << "\tService" << endl;

    for(int k = 0; k < counter; k++)
    {
        cout << (k + 1) << "\t" << arrRestaurant[k].name << "\t\t" << arrRestaurant[k].food << "\t" << arrRestaurant[k].service << endl;
    }
}


void updateRatings(Restaurant arrRestaurant[], int counter)
{
    int answer, new_foodRate, new_serviceRate;

    for(int k = 0; k < counter; k++)
    {
        cout << "Enter a number from the list (1 to " << (counter) << ") :";
        cin >> answer;

        while(answer > counter)
        {
            cout << "Invalid input, Please enter a number on the list!! :";
            cin >> answer;
        }

        cout << "Name of restaurant: " << arrRestaurant[counter - 2].name;
        cout << "\nCurrent ratings: ";
        cout << "\nFood: "        << arrRestaurant[counter - 2].food;
        cout << "\nService: "     << arrRestaurant[counter - 2].service << endl;

        cout << "\nEnter the new rating for food out of 10: ";
        cin >> new_foodRate;

        cout << "\nEnter the new rating for service out of 10: ";
        cin >> new_serviceRate;

        arrRestaurant[counter - 2].food = new_foodRate;
        arrRestaurant[counter - 2].service = new_serviceRate;

        displayData(arrRestaurant, counter);
        break;
    }
}


void displayBestRestaurant(Restaurant arrRestaurant[], int counter)
{
    double average;
    int highest;

    for(int k = 0; k < counter; k++)
    {

        average = (arrRestaurant[counter].food + arrRestaurant[counter].service) / 2;
        highest = (arrRestaurant[k].food + arrRestaurant[k].service) / 2;


        if(average > highest)
        {
            highest = average;

            cout << "\n\nBest rated restaurant: " << arrRestaurant[k].name;
            cout << "\nFood: " << arrRestaurant[k].food;
            cout << "\nService: " << arrRestaurant[k].service;
            cout << "\nAverage: " << average << endl;
        }
    }
}


int main()
{
    const int SIZE = 12;
    Restaurant arrRestaurant[SIZE];

    int counter = 0;

    cout << "Enter the name of a restaurant (# to quit): ";
    cin >> arrRestaurant[counter].name;

    while(arrRestaurant[counter].name[0] != '#')
    {
        cout << "Enter the rating for food (1 to 10): ";
        cin >> arrRestaurant[counter].food;

        cout << "Enter the rating for service (1 to 10): ";
        cin >> arrRestaurant[counter].service;

        counter++;

        cout << "Enter the name of another restaurant (# to quit): ";
        cin >> arrRestaurant[counter].name;
    }

    displayData(arrRestaurant, counter);
    updateRatings(arrRestaurant, counter);
    displayBestRestaurant(arrRestaurant, counter);

    return 0;
}
