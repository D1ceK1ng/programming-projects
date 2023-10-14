#include <iostream>

using namespace std;

void findUniqueNumbers(int *arrayWithNumbers, int size) {
    cout << "Numbers that occur only once in the array: ";
    for (int i = 0; i < size; i++) { // Iterate through each element in the array
        int count = 0;
        for (int j = 0; j < size; j++) { // Compare each element with every other element in the array
            if (arrayWithNumbers[i] == arrayWithNumbers[j]) {
                count++; // Increment count if the elements are equal
            }
        }
        if (count == 1) { // Check if the element occurs only once in the array
            cout << arrayWithNumbers[i] << " "; // Print the unique number
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
    for (int i = 0; i < size; i++) {
        cin >> arrayWithNumbers[i];
    }

    findUniqueNumbers(arrayWithNumbers, size);

    delete[] arrayWithNumbers;

    return 0;
}