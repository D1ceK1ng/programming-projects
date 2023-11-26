#include <iostream>
#include <string.h>

using namespace std;


int main()
{
  // Initializing string arrays and separators
  int mainStringLength = 1024;
  char *pMainString = new char[mainStringLength];
  char separators[] = " ;,.?!\t\n";

  // Getting text from the user
  cout << "Enter your text example: ";
  cin.get(pMainString, mainStringLength);

  size_t stringLength = strlen(pMainString);

  // Creating a copy to work with
  char *pMainCopy1 = new char[stringLength + 1];
  strcpy(pMainCopy1, pMainString);

  // Count words without numbers
  int wordsWithoutNumbersCount = 0;

  for (char *pToken = strtok(pMainCopy1, separators); pToken != nullptr; pToken = strtok(nullptr, separators))
  {
    bool containingOnlyLetters = true; // Check for words without digits
    for (int i = 0; pToken[i] != 0; i++)
    {
      if (isdigit(pToken[i]))
      {
        containingOnlyLetters = false;
      }
    }

    if (containingOnlyLetters)
    {
      wordsWithoutNumbersCount++;// Increasing number count
    }
  }

  cout << "Number of words without numbers is: " << wordsWithoutNumbersCount << endl;

  delete[]pMainString;
  delete[]pMainCopy1;

  return 0;
}
