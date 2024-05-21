#include <iostream>
#include <fstream>

using namespace std;

struct Book
{
    string title;
    char type;
    int ratings[3];
};

void displayData(Book arrBooks[], int count)
{
    cout << "\nList of books" << endl;
    printf("%-28s %-15s %-12s\n", "Title", "Type", "Ratings");

    for(int k = 0; k < count; k++)
    {
        string type = "";

        switch(arrBooks[k].type)
        {
        case 'F':
            type = "Fiction";
            break;
        case 'N':
            type = "Non-Fiction";
            break;
        default:
            type = "Unknown";
            break;
        }

        printf("%-2d %-25s %-15s %-5d %-5d %-5d\n", (k + 1), arrBooks[k].title.c_str(), type.c_str(), arrBooks[k].ratings[0], arrBooks[k].ratings[1], arrBooks[k].ratings[2]);
    }
}

int determineHighestRating(Book arrB[], int count, double &average)
{
    int total;
    int index;
    double temp = 0;

    for(int k = 0; k < count; k++)
    {
        total = 0;

        for(int j = 0; j < 3; j++)
        {
            total += arrB[k].ratings[j];
        }
        average = total / 3;

        if(average > temp)
        {
            index = k;
            temp = average;
        }
    }
    average = temp;

    return index;
}

int main()
{
    const int SIZE = 10;
    Book arrBooks[SIZE];

    int count = 0;
    string temp1;

    ifstream infile;
    infile.open("BookInfo.txt");

    if(infile.fail())
    {
        cout << "Error reading file !!" << endl;
    }
    else
    {
        while(!infile.eof())
        {
            getline(infile, arrBooks[count].title);
            infile >> arrBooks[count].type;

            getline(infile, temp1);

            arrBooks[count].ratings[0] = temp1[0];
            arrBooks[count].ratings[1] = temp1[1];
            arrBooks[count].ratings[2] = temp1[2];

            count++;
        }
        infile.close();

        cout << "Data read from text file successfully !!" << endl;
    }
    displayData(arrBooks, count);

    int index;
    char answer;

    do
    {
        cout << "\nEnter a number from the list: ";
        cin >> index;

        cout << "Book title: " << arrBooks[index - 1].title << endl;
        cout << "------------------" << endl;

        for(int k = 0; k < 3; k++)
        {
            cout << "Rating " << (k + 1) << ": ";
            cin >> arrBooks[index - 1].ratings[k];

            while(arrBooks[index - 1].ratings[k] < 1 || arrBooks[index -1].ratings[k] > 9)
            {
                cout << "***INVALID input. Rating must be in range 1-9! TRY AGAIN***" << endl;
                cout << "Rating " << (k + 1) << ": ";
                cin >> arrBooks[index - 1].ratings[k];
            }//end of while
        }//end of for

        displayData(arrBooks, count);

        cout << "\nDo you want to change the rating of another book (Y/N): ";
        cin >> answer;

    }//end of do-block
    while(toupper(answer) == 'Y');

    double avg = 0;

    int highPos = determineHighestRating(arrBooks, count, avg);

    cout << "\nBest Rated Book: " << arrBooks[highPos].title << endl;
    printf("Average rating : %-5.1lf ".avg);
    cout << endl << endl;

    return 0;
}
