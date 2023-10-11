#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


int main(int argc, char *argv[])
{
    char maintString[] = "Hello, I have 3 apples and 2 bananas, but I also like to 3at p1zza without any numbers.";
    char separators[] = " ;,.?!\t\n";

    cout << "Original text: " << maintString << endl;
    size_t stringLength = strlen(maintString); 

    char *pMainCopy1 = new char[stringLength + 1];

    strcpy(pMainCopy1, maintString);

    int wordsWithoutNumbersCount = 0;

    for (char *pToken = strtok(pMainCopy1, separators);pToken != NULL; pToken = strtok(NULL,separators) )
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
    
    delete []pMainCopy1;

    return 0;
}
