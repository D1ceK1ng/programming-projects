#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    const int n = 15;
    int mas[n];

    for (int i = 0; i < n; ++i)
    {
        mas[i] = rand() % 201 - 100;
    }
    cout << endl;

    for (int i = 0; i < n; ++i)
    {
        cout << mas[i] << " ";
    }

    int indexOfMinial = 0;
    for (int i = 0; i < n; i++)
    {
        if(mas[i]%2 == 0)
        {
            indexOfMinial = i;
        }


    }

    cout << endl;
    cout << "minimal = " <<mas[indexOfMinial] << " with index: " << indexOfMinial << endl;

    cout << endl;



    return 0;

}