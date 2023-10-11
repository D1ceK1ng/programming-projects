#include <iostream>
#include <math.h>
#include <time.h> // Lib for random seed
using namespace std;



void SortArray(int array[],int size)// Sort array via bubble sort
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j< size; j++)
        {

            if(array[i]<array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void GenerateMatrix(int **pMatrix,int matrixSize)
{
    //Generates matrix with random numbers from -20 to 20
    cout << "Creating elemnts of the matrix " << matrixSize << "x" << matrixSize << " ranging from -20 to 20\n"<< endl;
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
           pMatrix[i][j] = rand()%41 -20;
        }
        
    }
}

void FormatElementsAboveMainDiagonal(int **pMatrix,int matrixSize)
{
    //Formating elements above main diagonal according to the task 
    
    for (int i = 0; i < matrixSize - 1 ; i++)
    {
        for (int j = i + 1; j < matrixSize ; j++)   
        {
            if(pMatrix[i][j] < 0)
            {
                pMatrix[i][j] = 0;
            }
        }
    }    
}

void PrintMatrix(int **pMatrix,int matrixSize)
{
    //Prints out matrix
    for(int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            cout << pMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void  FindMaxElementBelowCounterDiagonal(int **pMatrix,int matrixSize)
{
    int numberOfelementsBelowCounterdiagonal = (pow(matrixSize,2) - matrixSize) / 2;//Calculate all elements below counterdiagonal
    int arrayOfElementsBelowCounterdiagonal[numberOfelementsBelowCounterdiagonal];//Creates an array of elements below counterdiagonal
    
    int counterOfelementsbelowCounterdiagonal = 0;
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = matrixSize - i; j < matrixSize; j++)
        {
                    
            arrayOfElementsBelowCounterdiagonal[counterOfelementsbelowCounterdiagonal] = pMatrix[i][j];//Puts elements from matrix to an array

            if (counterOfelementsbelowCounterdiagonal < numberOfelementsBelowCounterdiagonal)
            {
                counterOfelementsbelowCounterdiagonal++;
            }
        }
        
    }
    
    
    SortArray(arrayOfElementsBelowCounterdiagonal,numberOfelementsBelowCounterdiagonal);//Using Sorting function

    int maxValue = arrayOfElementsBelowCounterdiagonal[0];
    
    cout << "\n\nMax value of the element below counterdiagonal: " << maxValue << endl; 

    
    //Searching for index of max element // Better index iterration
    for (int i = 1; i < matrixSize; i++)
    {
        for (int j = matrixSize - i; j < matrixSize; j++)
        {
            if(pMatrix[i][j] == maxValue)// Cheking if element of matrix equals to max element 
            {
                cout << "Element with max value below counterdiagonal: " << maxValue << ", has index: (" << i + 1 << ";"<< j + 1 <<")" << endl;
            }
        }
        
    }
}


int main()
{
    srand(time(NULL));//Seed the random number generator
    int matrixSize;
    cout << "Enter the size of matrix: "; cin >> matrixSize;
    
    int **pMainMatrix;
    
    pMainMatrix = new int *[matrixSize];

    for (int i = 0; i < matrixSize; i++)
    {
        pMainMatrix[i] = new int [matrixSize];
    }
    
    GenerateMatrix(pMainMatrix,matrixSize);
    
    
    cout <<"Created matrix:\n";
    PrintMatrix(pMainMatrix,matrixSize);
   
    
    FormatElementsAboveMainDiagonal(pMainMatrix,matrixSize);
    

    cout << "\nFormated matrix: " << endl;
    PrintMatrix(pMainMatrix,matrixSize);

    FindMaxElementBelowCounterDiagonal(pMainMatrix,matrixSize);
    
    for (int i = 0; i < matrixSize; i++)
    {
        delete []pMainMatrix[i];
    }
    delete []pMainMatrix;

    return 0; 
}


    

