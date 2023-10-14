#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    int mainStringLength = 1024;
    char *pMaintString = new char[mainStringLength];
    char separators[] = " ;,.?!\t\n";
    cout << "Enter your text example: "; cin.get(pMaintString,mainStringLength);

    cout << "\nOriginal text: " << pMaintString << endl;
    size_t stringLength = strlen(pMaintString);

    char *pMainCopy1 = new char[stringLength + 1];

    strcpy(pMainCopy1, pMaintString);

    int wordsWithoutNumbersCount = 0;

    for (char *pToken = strtok(pMainCopy1, separators);pToken != nullptr; pToken = strtok(nullptr,separators) )
    {
        bool containingOnlyLetters = true;
        for (int i = 0; pToken[i] != 0; i++)
        {
            if(isdigit(pToken[i]))
            {
                containingOnlyLetters = false;
            }
        }

        if(containingOnlyLetters)
        {
            wordsWithoutNumbersCount++;
        }
        
    }
    
    cout << "Number of words without numbers is: " << wordsWithoutNumbersCount<< endl;

    delete []pMaintString;
    delete []pMainCopy1;

    return 0;
}
