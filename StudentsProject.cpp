#include <iostream>

using namespace std;

void displayArray(string arrNames[10])
{
    cout << "\nList of names" << endl;

    for(int  j = 0; j < 10; j++)
    {
        cout << (j + 1) << ". "  << arrNames[j] << endl;

    }
}

void displayMarks(string arrPresent[], int arrMarks[])
{
    cout << "Names and marks" << endl;

    for(int j = 0; j < 10; j++)
    {
        cout << (j + 1) << ". " << arrPresent[j] << "\t" << arrMarks[j] << endl;
    }
}


int findBestProject(int arrMarks[], string arrPresent[])
{
    int highest = 0;
    int high_index = 0;


    for(int j = 0; j < 10; j++)
    {
        if(arrMarks[j] > highest)
        {
            highest = arrMarks[j];
            high_index = j;
        }
    }

    return high_index;

}


int main()

{
    string arrNames[10] = {"Ntsako", "Mondli", "George", "Frank", "Graig", "Zane", "Jacky", "Mary", "Elizabeth", "Sharon"};
    string arrPresent[10] ;
    int arrMarks[10], index = 0, newIndex = 0, temp = 0;
    string answer;

    for(int j = 0; j < 10; j++)
    {
        do
        {
            index = rand() % 10;

        }
        while(arrNames[index] == "");
        {
            arrPresent[j] = arrNames[index];
            arrNames[index] = "";
        }
    }


    displayArray(arrPresent);

    cout << "Do you want to swap names (y or n)? : ";
    cin >> answer;
    while(answer == "y")
    {
        cout << "Enter the number of the name from the list to swap: ";
        cin >> index;

        cout << "Enter the new position for the name from the list: ";
        cin >> newIndex;

        string temp = arrPresent[index - 1];
        arrPresent[index - 1] = arrPresent[newIndex - 1];
        arrPresent[newIndex - 1] = temp;

        cout << "\n\nUpdated list" << endl;
        displayArray(arrPresent);

        cout << "Do you want to swap names again (y or n): ";
        cin >> answer;

    }

    for(int j = 0; j < 10; j++)
    {
        cout << "\n" << "Enter the mark for " << arrPresent[j] << ":";
        cin >> arrMarks[j];
    }


    int k = 0;
    k = findBestProject(arrMarks, arrPresent);
    cout << "The student with the highest mark is " << arrPresent[k] << " with a mark of " << arrMarks[k] << endl;







    return 0;
}
