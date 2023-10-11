#include <iostream>

#define N  10

using namespace std;

void countPositiveAndSum(int* array, int size, int& positiveCount, int& sum)
{
    positiveCount = 0;
    sum = 0;
    int lastZeroIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            positiveCount++;
        }
        if (array[i] == 0)
        {
            lastZeroIndex = i;
        }
        if (lastZeroIndex != -1 && i > lastZeroIndex)
        {
            sum += array[i];
        }
    }
}

void moveNumbers(int* array, int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        if (array[i] >= 1 && array[i] <= 2)
        {
            temp = array[i];
            for (int j = i; j > 0; j--)
            {
                array[j] = array[j - 1];
            }
            array[0] = temp;
            break;
        }
    }
}

int main()
{
    int* arrayOfNumbers = new int[N];
    cout << "Enter the elements: ";

    for (int i = 0; i < N; i++)
    {
        cin >> arrayOfNumbers[i];
    }

    int positiveCount;
    int sum;

    countPositiveAndSum(arrayOfNumbers, N, positiveCount, sum);

    cout << "Positive count: " << positiveCount << endl;
    cout << "Sum: " << sum << endl;

    moveNumbers(arrayOfNumbers, N);

    for (int i = 0; i < N; i++)
    {
        cout << arrayOfNumbers[i] << " ";
    }

    return 0;
}