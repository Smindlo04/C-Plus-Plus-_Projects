#include <iostream>

using namespace std;

void displayArr(double arr[], int s)
{
    double arrR[0];
    cout << "Rainfall statistics" << endl;

    for(int k = 0; k < s; k++)
        cout << "Rainfall for month " << (k+1) << " : " << arrR[k] << endl;
}

double calcTotalRainfall(double arrR[], int s)
{
    double total = 0;

    for(int k = 0; k < s; k++)
    {
        total = total + arrR[k];
        //total += arrR[k];
    }


    return total;
}

 int determineLowest(double arrR[], int s)
 {
     double lowest = arrR[0];
     int lowestIndex = 0;

     for(int k = 0; k < s; k++)
     {
         if(arrR[k] < lowest)
         {
             lowest = arrR[k];
             lowestIndex = k;
         }
     }
     return lowestIndex;

 }

 int determineHighest(double arrR[], int s)
 {
     double highest = arrR[0];
     int highestIndex = 0;

     for(int k = 0; k < s; k++)
     {
         if(arrR[k] < highest)
         {
             highest = arrR[k];
             highestIndex = k;
         }
     }
     return highestIndex;

 }

int main()
{
    const int SIZE = 12;

    double arrRainfall[SIZE];

    for(int k = 0; k < SIZE; k++)
    {
        cout << "Enter the rainfall for month " << (k+1) << " : ";
        cin >> arrRainfall[k];

        while(arrRainfall[k] < 0)
        {
            cout << "Invalid input - MUST be a positive value. Try again: ";
            cin >>arrRainfall[k];
        }
    }

    displayArr(arrRainfall, SIZE);
    double totalRainfall = calcTotalRainfall[arrRainfall, SIZE];
    double avgRainfall = totalRainfall / SIZE;

    int lowIndex = determineLowest(arrRainfall, SIZE);
    int highIndex = determineHighest(arrRainfall, SIZE);

    cout << "\n\nTotal rainfall is " << totalRainfall << "mm." << endl;
    cout << "Average rainfall was" << avgRainfall << "mm." << endl;


    cout << "Month " << (lowIndex+1) << "had the lowest rainfall with " << arrRainfall[lowIndex] << "mm recorded" << endl;
    cout << "Month " << (highIndex+1) << "had the highest rainfall with " << arrRainfall[highIndex] << "mm recorded" << endl;




    return 0;
}
