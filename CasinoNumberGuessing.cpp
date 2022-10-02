#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

void rules();

int main()
{
    string playerName;
    int playerBalance;
    int betAmount;
    int playerGuess;
    int diceNumber;
    char playChoice;

    srand(time(0));

    cout << endl << "Insert your name: ";
    getline(cin, playerName);
    cout << endl << "Enter your balance: $ ";
    cin >> playerBalance;

    do
    {
        system("cls");
        rules();
        cout << "Your current balance -> $" << playerBalance<< endl;

        do
        {
            cout << endl << "Enter your betting amount: $ ";
            cin >> betAmount;
            if(betAmount > playerBalance)
                cout <<endl << "Insufficient balance. Try another bet!" << endl;

        }while(betAmount > playerBalance);

        do
        {
            cout <<endl << "Make your guess: ";
            cin >> playerGuess;
            if(playerGuess <= 0 || playerGuess > 10)
                cout << endl << "Wrong number. Try again!" << endl;
        }while(playerGuess <= 0 || playerGuess > 10);

        diceNumber = rand()%10 + 1;
        if(diceNumber == playerGuess)
        {
            cout << endl << "Congratulations! You have won $" << betAmount * 10;
            playerBalance = playerBalance + (betAmount * 10);
        }
        else
        {
            cout << endl << "Sorry! You have lost $" << betAmount << endl;
            playerBalance = playerBalance - betAmount;
        }

        cout << endl << "Correct number was " << diceNumber << endl;
        cout << endl << playerName << ", your current balance is $" << playerBalance << endl;
        if(playerBalance == 0)
        {
            cout << "You have lost all your money!" << endl;
            break;
        }

        cout << "Play again? (Y/N) "<<endl;
        cin >> playChoice;
    }while(playChoice == 'Y' || playChoice == 'y');
    cout << endl;
    cout << "Your balance is: $" << playerBalance << endl;
    return 0;
}

void rules()
{
    system("cls");
    cout << endl << "Guessing number game" << endl;
    cout << endl << "Choose a number between 1 - 10" << endl;
    cout << endl << "If you guess the number you get 10x the bet amount" << endl;
    cout << endl << "If you don't guess the number, you lose the bet amount" << endl;
}