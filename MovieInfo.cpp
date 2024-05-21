#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Movie
{
    string title;
    char genre;
    int year;
    double prodCost;
};

void displayData(Movie arrM[], int count)
{
    printf("\n%-20s %-10s %-15s %-10s %-15s\n","Title", "Genre", "Year release", "Age", "Production cost");

    for(int k = 0; k < count; k++)
    {
        int age = 2022 - arrM[k].year;
        string genre = "";

        switch(arrM[k].genre)
        {
        case 'A':
            genre = "Action";
            break;
        case 'C':
            genre = "Comedy";
            break;
        case 'D':
            genre = "Drama";
            break;
        case 'R':
            genre = "Romance";
            break;
        default:
            genre = "Unknown";
            break;
        }

        printf("%-20s %-10s %-15d %-10d %-15.2lf\n", arrM[k].title.c_str(), genre.c_str(), arrM[k].year, age, arrM[k].prodCost);
    }
}

void displayGenreCosts(Movie arrM[], int count)
{
    double drama = 0, comedy = 0, romance = 0, action = 0, unknown = 0;

    for(int k = 0; k < count; k++)
    {
        char temp = arrM[k].genre;

        if(temp == 'A')
            action += arrM[k].prodCost;
        else if(temp == 'C')
            comedy += arrM[k].prodCost;
        else if(temp == 'D')
            drama += arrM[k].prodCost;
        else if(temp == 'R')
            romance += arrM[k].prodCost;
        else
            unknown += arrM[k].prodCost;
    }

    ofstream outFile;
    outFile.open("GenreCosts.txt");//Step 2

    //Step 3
    outFile << "Total costs per genre: " << endl;
    outFile << "Action  : R " << fixed << setprecision(2) << action << endl;
    outFile << "Comedy  : R " << fixed << setprecision(2) << comedy << endl;
    outFile << "Drama   : R " << fixed << setprecision(2) << drama << endl;
    outFile << "Romance : R " << fixed << setprecision(2) << romance << endl;
    outFile << "Unknown : R " << fixed << setprecision(2) << unknown << endl;

    //Step 4
    outFile.close();

}

int main()
{
    const int SIZE = 10;
    Movie arrMovie[SIZE];
    int k = 0;

    //int counter = 0;

    //cout << "Movie title " << (counter + 1) << ": ";
    //getline(cin, arrMovie[counter].title);

    //while(arrMovie[counter].title != "XXX")
    //{
        //cout << "Movie genre (A/C/D/R): ";
        //cin >> arrMovie[counter].genre;
        //arrMovie[counter].genre = toupper(arrMovie[counter].genre);

        //cout << "Year released: ";
        //cin >> arrMovie[counter].year;

        //cout << "Production cost: R ";
        //cin >> arrMovie[counter].prodCost;

        //while(arrMovie[counter].prodCost < 0)
        //{
            //cout << "Invalid input! Only positive values! " << endl;
            //cout << "Try again. Production cost: R ";
            //cin >> arrMovie[counter].prodCost;
        //}
        //counter++;

        //cin.ignore();

        //cout << "Movie title " << (counter + 1) << ": ";
        //getline(cin, arrMovie[counter].title);
    //}

    ifstream infile;
    infile.open("MovieInfo.txt");

    if(infile.fail())
    {
        cout << "Error reading from file !!" << endl;
    }
    else
    {
        while(!infile.eof())
        {
            string temp = "";

            getline(infile, arrMovie[k].title);//reads line 1
            getline(infile, temp);//reads line 2
            //A2015#2500.50

            arrMovie[k].genre = temp[0];

            int posHash = temp.find('#');

            arrMovie[k].year = stoi(temp.substr(1,posHash - 1));
            arrMovie[k].prodCost = stof(temp.substr(posHash + 1));

            k++;
        }
        infile.close();
    }

    displayData(arrMovie, k);
    displayGenreCosts(arrMovie, k);

    return 0;
}
