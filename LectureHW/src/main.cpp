#include<iostream>

using namespace std;

int main()
{
    const int n = 11;//10
    int matr[n][n]; // Matrix with n rows and n columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = 0;
        }
    }
    // Put elements in matrix
    for (int i = 0; i < n; i++)
    {
        matr[i][i] = 5;
        matr[i][n - 1 - i] = 6;
        
    }
    // Put elements in 1st range
    for (int i = 0; i < (n-1)/2; i++)
    {
        for (int j = i+1; j < n-1-i; j++)
        {
            matr[i][j] = 1;
        }
    }
    
    
    //Put elements in 2nd range
    for (int i = n - 1; i > (n - 1) / 2; i--)
    {
        for (int j = n - i; j < i; j++)
        {
           matr[j][i] = 2;

        }
    }

    //Put elements in 3rd range
    for (int i = n - 1; i > (n - 1) / 2; i--)
    {
        for (int j = n - i; j < i; j++)
        {
           matr[i][j] = 3;

        }
    }

    //Put elements in 4th range
    for (int i = 0; i < (n-1)/2; i++)
    {
        for (int j = i+1; j < n-1-i; j++)
        {
            matr[j][i] = 4;
        }
    }
    
    //Print result
    for (int i = 0; i < n; ++i, cout << endl)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << matr[i][j] << "\t";
        }
    }

    cout << endl;

    return 0;
}
