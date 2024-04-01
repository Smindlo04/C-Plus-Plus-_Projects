#include <iostream>

using namespace std;

int main()
{
    int list[6] = {1,2,3,4,5,6};

    for(int i = 0; i < 3; i++)
    {
        int temp = list[i];
        list[i] = list[5 - i];
        list[5 - i] = temp;
    }
    for(int i = 0; i < 6; i++)
        cout << list[i] << "\t";

    return 0;
}
