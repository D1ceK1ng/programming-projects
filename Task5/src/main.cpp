#include <iostream>

using namespace std;

void findUniqueNumbers(int *arrayWithNumbers, int size)
{
    cout << "Numbers that occur only once in the array: ";
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arrayWithNumbers[i] == arrayWithNumbers[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << arrayWithNumbers[i] << " ";
        }
    }
}

int main(int argc, char *argv[])
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arrayWithNumbers = new int[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arrayWithNumbers[i];
    }

    findUniqueNumbers(arrayWithNumbers, size);

    delete[] arrayWithNumbers;

    return 0;
}