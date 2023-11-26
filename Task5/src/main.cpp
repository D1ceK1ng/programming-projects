#include <iostream>
#include <ctime>

using namespace std;

int* findUniqueNumbers(int *arrayWithNumbers, int size)
{
  int *arrayOfInedxes = new int[size];
  int indexTemp = 0;
  for (int i = 0; i < size; i++)
  { // Iterate through each element in the array
    int count = 0;
    for (int j = 0; j < size; j++) { // Compare each element with every other element in the array
      if (arrayWithNumbers[i] == arrayWithNumbers[j]) {
        count++; // Increment count if the elements are equal
      }

    }
    if(count == 1){
      arrayOfInedxes[indexTemp] = i+1;
      indexTemp++;
    }

  }
  return arrayOfInedxes;

}

int main()
{
  srand(time(nullptr));// Seed the random number generator

  int size;
  cout << "Enter the size of the array: ";
  cin >> size;

  int *arrayWithNumbers = new int[size];

  cout << "Enter the elements of the array: ";
  for (int i = 0; i < size; i++)
  {
    arrayWithNumbers[i] = rand() % 21 - 7;
    cout << arrayWithNumbers[i] << "\t";
  }
  cout << "\nNumbers that occur only once in the array have this indexes: ";
  for (int i = 0; i < size; ++i)
  {
    if (*(findUniqueNumbers(arrayWithNumbers, size)+ i) !=0)
    {
      cout << *(findUniqueNumbers(arrayWithNumbers, size) + i) << "\t11";
    }
  }


  delete[] arrayWithNumbers;

  return 0;
}