#include <iostream>
#include <ctime> // Lib for random seed
using namespace std;



void generateMatrix(int **pMatrix, int matrixSize) {
  //Generates matrix with random numbers from -20 to 20
  cout << "Creating elements of the matrix " << matrixSize << "x" << matrixSize << " ranging from -20 to 20\n" << endl;
  for (int i = 0; i < matrixSize; i++)
  {
    for (int j = 0; j < matrixSize; j++)
    {
      pMatrix[i][j] = rand() % 41 - 20;
    }

  }
}

void formatElementsAboveMainDiagonal(int **pMatrix, int matrixSize)
{
  //Formatting elements above main diagonal according to the task

  for (int i = 0; i < matrixSize - 1; i++)
  {
    for (int j = i + 1; j < matrixSize; j++)
    {
      if (pMatrix[i][j] < 0)
      {
        pMatrix[i][j] = 0;
      }
    }
  }
}

void printMatrix(int **pMatrix, int matrixSize) {
  //Prints out matrix
  for (int i = 0; i < matrixSize; i++) {
    for (int j = 0; j < matrixSize; j++) {
      cout << pMatrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void findMaxElementBelowCounterDiagonal(int **pMatrix, int matrixSize) {

 // Initialize indices of max element
 int rowIndexOfMaxElement = 0;
 int columnIndexOfMaxElement = 0;

 // Iterate through elements below counter-diagonal
 for (int i = 1; i < matrixSize; i++) {
    for (int j = matrixSize - i; j < matrixSize; j++)
    {
        // Update max element indices if current element is greater
        if(pMatrix[i][j] > pMatrix[rowIndexOfMaxElement][columnIndexOfMaxElement])
        {
            rowIndexOfMaxElement = i;
            columnIndexOfMaxElement = j;
        }

    }

 }

 // Print max element and its indices
 cout << "Max element below counter-diagonal is " << pMatrix[rowIndexOfMaxElement][columnIndexOfMaxElement] << " with index (" << rowIndexOfMaxElement << ";" << columnIndexOfMaxElement << ") " << endl;

}



int main()
{
  srand(time(nullptr));// Seed the random number generator

  int matrixSize;
  cout << "Enter the size of matrix: ";
  cin >> matrixSize;

  int **pMainMatrix;

  pMainMatrix = new int *[matrixSize];

  for (int i = 0; i < matrixSize; i++)
  {
    pMainMatrix[i] = new int[matrixSize];
  }

  generateMatrix(pMainMatrix, matrixSize);


  cout << "Created matrix:\n";
  printMatrix(pMainMatrix, matrixSize);


  formatElementsAboveMainDiagonal(pMainMatrix, matrixSize);


  cout << "\nFormatted matrix: " << endl;
  printMatrix(pMainMatrix, matrixSize);

  findMaxElementBelowCounterDiagonal(pMainMatrix, matrixSize);

  for (int i = 0; i < matrixSize; i++)
  {
    delete[]pMainMatrix[i];
  }
  delete[]pMainMatrix;

  return 0;
}


    

