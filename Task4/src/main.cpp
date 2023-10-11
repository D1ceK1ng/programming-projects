#include <iostream>

using namespace std;
struct ATSabonent
{
    char PIB[1024];
    char livingPlace[1024];
    int phoneNumber;
    int ATSnumber;
};

int main(int argc, char *argv[])
{
    int atsAbonentsCount;
    cout << "Enter number of abonents: ";
    cin >> atsAbonentsCount;

    ATSabonent* atsAbonents = new ATSabonent[atsAbonentsCount];

    for (int i = 0; i < atsAbonentsCount; i++)
    {
        cout << "Enter abonents surname, name and patronymic of " << i + 1 << " abonent: ";
        cin.ignore();
        cin.getline(atsAbonents[i].PIB, sizeof(atsAbonents[i].PIB));

        cout << "Enter adress for  " << i + 1 << " abonent: ";
        cin.ignore();
        cin.getline(atsAbonents[i].livingPlace, sizeof(atsAbonents[i].livingPlace));

        cout << "Enter phone number of  " << i + 1 << " abonent: ";
        cin >> atsAbonents[i].phoneNumber;

        cout << "Enter ATS number of " << i + 1 << " abonent: ";
        cin >> atsAbonents[i].ATSnumber;
        cout << endl;
    }

 
    bool swapped;
    for (int i = 0; i < atsAbonentsCount - 1; i++)
    {
        swapped = false;

        for (int j = 0; j < atsAbonentsCount - 1 - i; j++)
        {
            if (atsAbonents[j].ATSnumber > atsAbonents[j + 1].ATSnumber)
            {
                ATSabonent c = atsAbonents[j];
                atsAbonents[j] = atsAbonents[j + 1];
                atsAbonents[j + 1] = c;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }


    cout << "All ATS abonents by their number:\n";
    for (int i = 0; i < atsAbonentsCount; i++)
    {
        cout << i+ 1 << ")\t" << "PIB: " << atsAbonents[i].PIB << "\t" << "ATS number: " << atsAbonents[i].ATSnumber<< "\t Phone number : " <<"+380" << atsAbonents[i].phoneNumber << "\n";
    }

    delete[] atsAbonents;

    return 0;
}
