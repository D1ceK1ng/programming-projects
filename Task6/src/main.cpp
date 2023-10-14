#include <iostream>

#define N 10

using namespace std;

void countPositiveAndSum(int *pArray, int size, int &positiveCount, int &sum) {
 positiveCount = 0; // Initialize positive count
 sum = 0; // Initialize sum
 int lastZeroIndex = -1; // Initialize last zero index

 // Iterate through the array
 for (int i = 0; i < size; i++) {
    if (pArray[i] > 0) { // If positive, increment positive count
      positiveCount++;
    }
    if (pArray[i] == 0) { // If zero, update last zero index
      lastZeroIndex = i;
    }
    if (lastZeroIndex != -1 && i > lastZeroIndex) { // If not first zero and after last zero, add to sum
      sum += pArray[i];
    }
 }
}

void moveNumbers(int *pArray, int size) {
 int temp;

 // Iterate through the array
 for (int i = 0; i < size; i++) {
    // Check if the number is between 1 and 2
    if (pArray[i] >= 1 && pArray[i] <= 2) {
      // Store the number temporarily
      temp = pArray[i];
      // Shift all numbers to the right of the number to the left
      for (int j = i; j > 0; j--) {
        pArray[j] = pArray[j - 1];
      }
      // Place the number at the beginning of the array
      pArray[0] = temp;
      // Exit the loop as we have found and moved the number
      break;
    }
 }
}


int main() {
  int *pArrayOfNumbers = new int[N];
  cout << "Enter the elements: ";

  for (int i = 0; i < N; i++) {
    cin >> pArrayOfNumbers[i];
  }

  int positiveCount;
  int sum;

  countPositiveAndSum(pArrayOfNumbers, N, positiveCount, sum);

  cout << "Positive count: " << positiveCount << endl;
  cout << "Sum: " << sum << endl;

  moveNumbers(pArrayOfNumbers, N);

  for (int i = 0; i < N; i++) {
    cout << pArrayOfNumbers[i] << " ";
  }

  return 0;
}