#include <iostream>
#include <time.h>

using namespace std;

//called only in UserSearchForSecretNum function
void youWon() {
    cout << "You Won!" << endl;
}

//Function for user to guess the secret number within 10 tries.
void UserSearchForSecretNum(int secretNum) {

    int choice;
    int lowest = 1;
    int highest = 100;
    int tries = 0;

    cout << "Enter a Number from 1 - 100" << endl;
    cin >> choice;

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
            cout << "You got it in " << tries << " attempts!" << endl;
            break;
        }
        tries++;
    }

}


//Function using a binary algo to figure out the secret number within 10 tries.
void AlgoSearchForSecretNum(int secretNum) {
    int lowest = 1;
    int highest = 100;
    int mid = lowest + (highest - 1) / 2;
    int tries = 0;
    int algoGuess = mid;

    while (tries < 10) {
        if (algoGuess < secretNum) {
            cout << "Algo guess " << algoGuess << " was too low" << endl;
            lowest = mid;
            mid = ((lowest + 1) + highest) / 2;
            algoGuess = mid;

        }
        else if (algoGuess > secretNum) {
            cout << "Algo guess " << algoGuess << " was too high" << endl;
            highest = mid;
            mid = (lowest + (highest - 1)) / 2;
            algoGuess = mid;
        }
        else {
            algoGuess == secretNum;
            cout << "Algo guess " << algoGuess << " was right!!" << endl;
            cout << "Algo got it in " << tries << " attempts!" << endl;
            cout << "Answer was in fact " << secretNum << endl;
            break;
        }
        tries++;
    }
}

//For start of project and rest is in other functions
int main()
{
 
    int answer;
    time_t t;
    srand((unsigned)time(&t));

    int secretNum = rand() % 100 + 1;

    do {
        cout << "Want algo or user to find answer?" << endl;
        cout << "1. Algo" << endl;
        cout << "2. User" << endl;
        cin >> answer;

        if (answer == 1) {
            AlgoSearchForSecretNum(secretNum);
        }
        else if (answer == 2) {
            UserSearchForSecretNum(secretNum);
        }
        else {
            cout << "Did not get your input" << endl;
        }
    } while (answer != 1 && answer != 2);

}
