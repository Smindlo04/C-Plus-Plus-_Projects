#include <iostream>
#include <fstream> //Step 1

using namespace std;

int main()
{
    string info;
    char answer;

    //Step 2 - declare file variable and open
    ofstream outFile;
                                    //adding a new file on the existing file
    outFile.open("PhoneNumber.txt", ios::app);
    //ofstream outFile("PhoneNumber.txt");

    do
    {
        cout << "Enter your name and number (XXX to stop): ";
        getline(cin, info);

        outFile << info << endl;

        cout << "Do you want to enter another name & number (Y/N): ";
        cin >> answer;

        cin.ignore();
    }
    while(toupper(answer) == 'Y');

    outFile.close();

    return 0;
}
