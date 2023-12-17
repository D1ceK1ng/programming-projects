#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void deleteMatrix(int **matrix, int size){
  for (int i = 0; i < size; i++) {
    delete matrix[i];
  }
  delete[] matrix;
}

void sortDiagonal(int **matrix, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k) {
        if (matrix[i][j] > matrix[k][k]) {
          int temp = matrix[i][j];
          matrix[i][j] = matrix[k][k];
          matrix[k][k] = temp;
        }
      }
    }
  }
}

int main() {
  FILE *fptr;
  int size;

  fptr = fopen("input.txt", "r");
  if (fptr == nullptr) {
    cout << ("Cannot open file.\n");
    exit(0);
  }
  if(fscanf(fptr, "%d", &size) != 1){
    cout << "Error reading size from the file!\n";
    return 1;
  }
  cout << size << endl;
  int **pMatrix = new int *[size];
  for (int i = 0; i < size; i++) {
    pMatrix[i] = new int[size];
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (fscanf(fptr, "%d", &pMatrix[i][j]) != 1) {
        cout << "Error reading matrix from the file!\n";
        deleteMatrix(pMatrix, size);
        return 1;
      }
    }
  }

  fclose(fptr);

  cout << ("Unsorted array:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << *((*pMatrix + i) + j) << " ";
    }
    cout << ("\n");
  }

  sortDiagonal(pMatrix, size);

  cout << ("\nSorted array:\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << *((*pMatrix + i) + j) << " ";
    }
    cout << endl;
  }

  fptr = fopen("output.txt", "w");
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      fprintf(fptr, "%d%s", pMatrix[i][j], "\t");
    }
    fprintf(fptr, "%s", "\n");
  }
  fclose(fptr);
  
  fptr = fopen("output.bin", "wb");
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      fwrite(&pMatrix[i][j], sizeof(int), 1, fptr);
    }
  }
  fclose(fptr);

  deleteMatrix(pMatrix, size);

  return 0;
}
