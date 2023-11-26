#include <iostream>
#include <string.h>

using namespace std;
struct Tree
{
    char name[100];
    int height;
};

int main()
{
  const int elements = 4;
  Tree mas[elements];
 
  for (int i = 0; i < elements; i++)
  {
    cout << "Input name:";
    cin.getline(mas[i].name, 99);
    char tmpStr[100];
    cout << "Input height:";
    cin.getline(tmpStr, 99);
    mas[i].height = atoi(tmpStr);
  }
  for (int i = 0; i < elements; i++)
  {
    cout << mas[i].name << " " << mas[i].height << endl;
  }
  return 0;
}