#include <iostream>

using namespace std;
struct AtsSubscriber {
    char PIB[1024];
    char livingPlace[1024];
    char phoneNumber[15];
    int atsNumber;
};

int main() {
  int atsSubscriberCount;
  cout << "Enter number of subscriber: ";
  cin >> atsSubscriberCount;

  auto *pAtsSubscriber = new AtsSubscriber[atsSubscriberCount];

  for (int i = 0; i < atsSubscriberCount; i++) {
    cout << "Enter subscriber surname, name and patronymic of " << i + 1 << " subscriber: ";
    cin.ignore();
    cin.getline(pAtsSubscriber[i].PIB, sizeof(pAtsSubscriber[i].PIB));

    cout << "Enter address for  " << i + 1 << " subscriber: ";
    cin.ignore();
    cin.getline(pAtsSubscriber[i].livingPlace, sizeof(pAtsSubscriber[i].livingPlace));

    cout << "Enter full phone number of  " << i + 1 << " subscriber: ";
    cin >> pAtsSubscriber[i].phoneNumber;

    cout << "Enter ATS number of " << i + 1 << " subscriber: ";
    cin >> pAtsSubscriber[i].atsNumber;
    cout << endl;
  }


  bool swapped;
  for (int i = 0; i < atsSubscriberCount - 1; i++) {
    swapped = false;

    for (int j = 0; j < atsSubscriberCount - 1 - i; j++) {
      if (pAtsSubscriber[j].atsNumber > pAtsSubscriber[j + 1].atsNumber) {
        AtsSubscriber c = pAtsSubscriber[j];
        pAtsSubscriber[j] = pAtsSubscriber[j + 1];
        pAtsSubscriber[j + 1] = c;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }


  cout << "All ATS subscriber by their number:\n";
  for (int i = 0; i < atsSubscriberCount; i++) {
    cout << i + 1 << ")\t" << "PIB: " << pAtsSubscriber[i].PIB << ";\t  ATS number: " << pAtsSubscriber[i].atsNumber
         << ";\t Phone number : " << "+" << pAtsSubscriber[i].phoneNumber << "\n";
  }

  delete[] pAtsSubscriber;

  return 0;
}
