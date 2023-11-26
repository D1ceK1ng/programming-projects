#include <iostream>
#include <ctime>
#include "NUMBER_OF_ELEMENTS.h"
#include "PRINT_ARRAY.h"
#include "COUT_POSITIVE_AND_SUM.h"
#include "MOVE_NUMBERS.h"

using namespace std;

int main()
{
  srand(time(nullptr));// Seed the random number generator
  int *pArrayOfNumbers = new int[N];

  for (int i = 0; i < N; i++)
  {
    pArrayOfNumbers[i] = rand() % 20 - 7;
  }

  PRINT_ARRAY_H(pArrayOfNumbers, N)
  int positiveCount;
  int sum;

  COUNT_POSITIVE_AND_SUM_H(pArrayOfNumbers, N, positiveCount, sum)

  cout << "Positive count: " << positiveCount << endl;
  cout << "Sum: " << sum << endl;

  MOVE_NUMBERS_H(pArrayOfNumbers, N)

  PRINT_ARRAY_H(pArrayOfNumbers, N)

  delete[] pArrayOfNumbers;
  return 0;
}