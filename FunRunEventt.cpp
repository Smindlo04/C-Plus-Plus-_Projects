#include <iostream>

using namespace std;

struct Participant
{
    string name;
    string gender;
};

struct Date
{
    int day;
    int month;
    int year;
    int minutes;
    Participant Pname;
};

void getInfo(Date* myParticipant, int counter)
{
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, myParticipant[counter].Pname.name);

    cout << "Date of Birth:" << endl;
    cout << "Enter day: ";
    cin >> myParticipant[counter].day;

    cout << "Enter month (1 to 12): ";
    cin >> myParticipant[counter].month;

    cout << "Enter year (yyyy): ";
    cin >> myParticipant[counter].year;

    cout << "Enter gender (M / F): ";
    cin >> myParticipant[counter].Pname.gender;

    cout << "Enter the time in minutes: ";
    cin >> myParticipant[counter].minutes;
}

int calculateAge(Date* myParticipant, int counter)
{
    const int THIS_YEAR = 2022;
    int pAge;

    for(int k = 0; k < counter; k++)
    {
        pAge = THIS_YEAR - myParticipant[k].year;
    }
    return pAge;
}

void displayData(Date* myParticipant, int counter)
{
    int pAge = calculateAge(myParticipant, counter);
    cout << "List of participants" << endl;
    cout << "Name" << "\t\tGender" << "\t\tBirth year" << "\t\tAge" << "\t\tTime in minutes" << endl;

    for(int k = 0; k < counter; k++)
    {
        cout << myParticipant[k].Pname.name << "\t\t" << myParticipant[k].Pname.gender << "\t\t" << myParticipant[k].year << "\t\t" << pAge << "\t\t" << myParticipant[k].minutes << endl;
    }
}

int findWinner(Date* myParticipant, int counter)
{
    int winner = myParticipant[0].minutes;

    for(int k = 0; k < counter; k++)
    {
        if(myParticipant[k].minutes < winner)
        {
            winner = myParticipant[k].minutes;
        }
    }
    return winner;
}

void displayWinner(Date* myParticipant, int counter)
{
    int pAge = calculateAge(myParticipant, counter);
    int winner = findWinner(myParticipant, counter);

    cout << "\nWinner of the FunRun Event" << endl;
    cout << "Name            : " << myParticipant[counter].Pname.name << endl;
    cout << "Date of birth   : " << myParticipant[counter].day << "-" << myParticipant[counter].month << "-" << myParticipant[counter].year << endl;
    cout << "Age             : " << pAge << endl;
    cout << "Time in minutes : " << winner << endl;
}

int main()
{
    const int SIZE = 100;
    Date myParticipant[SIZE];
    int counter = 0;
    string answer;

    cout << "Do you want to add a participant? (Y or N): ";
    cin >> answer;

    while(answer != "n" && answer != "N")
    {
        getInfo(myParticipant, counter);

        cout << "\nDo you want to add another participant? (Y or N): ";
        cin >> answer;

        counter++;
    }
    displayData(myParticipant, counter);
    displayWinner(myParticipant, counter);


    return 0;
}
