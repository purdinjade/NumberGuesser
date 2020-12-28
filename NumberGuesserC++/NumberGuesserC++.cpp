#include <iostream>
#include <time.h>

using namespace std;

void youWon() {
    cout << "You Won" << endl;
}

void UserSearchForSecretNum(int choice) {

    time_t t;
    srand((unsigned)time(&t));

    int secretNum = rand() % 100 + 1;
    int lowest = 1;
    int highest = 100;
    int mid = secretNum;
    int tries = 0;

    while (tries < 10) {
        if (choice < secretNum) {
            cout << "higher" << endl;
            cout << "Try another number: ";
            cin >> choice;
        }
        else if(choice > secretNum){
            cout << "lower" << endl;
            cout << "Try another number: ";
            cin >> choice;
        }
        else {
            choice == secretNum;
            youWon();
            break;
        }
        tries++;
    }

}


int main()
{
    int choice;
    int numbers[100];

    cout << "Enter a Number from 1 - 100" << endl;
    cin >> choice;

    UserSearchForSecretNum(choice);

}
