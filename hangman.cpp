#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

// function declaration
void welcome();
int menu();
void startGame();
void leaderboard();
void quitGame();
string loadRandomWord();
void printMessage(string message, bool printTop = true, bool printBottom = true);
void drawHangman(int wrongCount);
void printAvailableLetters(char guesses[]);
void printLetters(char taken[], char alphabets[]);

// welcome screen
void welcome()
{
    cout<<"\n\n";
    cout<<"\t\t\t\t\t***************************************************************************************\n";
    cout<<"\t\t\t\t\t**                                           		                             **\n";
    cout<<"\t\t\t\t\t**                                            		                             **\n";
    cout<<"\t\t\t\t\t**                                            		                             **\n";
    cout<<"\t\t\t\t\t**                                            		                             **\n";
    cout<<"\t\t\t\t\t**                                            		                             **\n";
    cout<<"\t\t\t\t\t**                                            		                             **\n";
    cout<<"\t\t\t\t\t**                                  WELCOME TO                                       **\n";
    cout<<"\t\t\t\t\t**                                                                                   **\n";
    cout<<"\t\t\t\t\t**                             HANGMAN GUESSING GAME                                 **\n";
    cout<<"\t\t\t\t\t**                                                                                   **\n";
    cout<<"\t\t\t\t\t**                                                                                   **\n";
    cout<<"\t\t\t\t\t**                                                                                   **\n";
    cout<<"\t\t\t\t\t**                                                                                   **\n";
    cout<<"\t\t\t\t\t**                                                           -Brought To You by GIT  **\n";
    cout<<"\t\t\t\t\t**                                                                                   **\n";
    cout<<"\t\t\t\t\t***************************************************************************************\n\n\n\n\t\t\t\t\t";
    system("pause");
    system("cls");
}

// game menu
int menu()
{
    cout<<"HAHAHA\nYou got me\n";
    int choice;
    cout<<"\n\n\t\t\t\t\t\t\t\t    HANGMAN GUESSING GAME MENU\n";
    cout<<"\n\n\t\t\t\t\t\t\t\tChoose from the following Options:\n\n";
    cout<<"\t\t\t\t\t\t\t _____________________________________________________ \n";
    cout<<"\t\t\t\t\t\t\t|                                        	      |\n";
    cout<<"\t\t\t\t\t\t\t|             1  >> Start game                        |\n";
    cout<<"\t\t\t\t\t\t\t|             2  >> View Leaderboard                  |\n";
    cout<<"\t\t\t\t\t\t\t|             3  >> Exit the Program                  |\n";
    cout<<"\t\t\t\t\t\t\t|_____________________________________________________|\n\n";
    cout<<"\t\t\t\t\t\t\tEnter your choice: ";
    cin>>choice;
    cin.clear();
    cin.ignore();

    // validate input
    while(choice>3||choice<1)
    {
        cout<<"\n\t\t\t\t\t\t\tInvalid Choice\n";
        cout<<"\t\t\t\t\t\t\tTry again...........\n\n";
        cout<<"\t\t\t\t\t\t\tEnter your choice: ";
        cin>>choice;
        cin.clear();
        cin.ignore();
    }

    return choice;
}

void startGame()
{
    char playerName[50];
    string wordToGuess;
    char guesses[26];
    int wrongCount = 7;

    cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to start the game!" << endl;
    cout << "\n\t\t\t\t\t\t\t>> ";
    cin.getline(playerName, 50);

    while(strlen(playerName) == 0)
    {
        cout << "\n\t\t\t\t\t\t\tSeem you haven't enter a name." << endl;
        cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to start the game!" << endl;
        cout << "\n\t\t\t\t\t\t\t>> ";
        cin.getline(playerName, 50);
    }

    cout << "\n\t\t\t\t\t\t\tGood luck, " << playerName << "!\n\n\n\n\t\t\t\t\t\t";
    system("pause");
    system("cls");

    // get the random word
    wordToGuess = loadRandomWord();

    printMessage("HANGMAN", true, true);
    drawHangman(wrongCount);
    printAvailableLetters(guesses);
    printMessage("GUESS A COUNTRY");
}

void printAvailableLetters(char guesses[])
{
    char alphabets1[13] ={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
    char alphabets2[13] ={'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    printMessage("AVAILABLE LETTERS");
    printLetters(guesses, alphabets1);
    printLetters(guesses, alphabets2);

}
// print letters for users to choose
// searching method: linear search
void printLetters(char taken[], char alphabets[])
{
    bool found = false;
    string letters = " ";
    for (char i = 0; i < 13; i++)
    {
        for (char j = 0; j < strlen(taken); j++)
        {
            if (alphabets[i] == taken[j])
            {
                found = true;
            }
        }
        if (!found)
        {
            letters += alphabets[i];
            letters += " ";
        }
        found = false;
    }
    printMessage(letters, false, false);
}

// load words into .txt file and choose random word
string loadRandomWord()
{
    int count = 0;
    string word;
    string countryName[40] = {"AFGHANISTAN", "BOLIVIA", "CZECH", "DJIBOUTI", "ETHIOPIA",
                            "FINLAND", "GEORGIA", "HUNGARY", "JAMAICA", "KAZAKHSTAN",
                            "LUXEMBOURG", "MADAGASCAR", "NETHERLANDS", "PHILIPPINES", "ROMANIA",
                            "SLOVENIA", "TANZANIA", "UKRAINE", "VENEZUELA", "YEMEN",
                            "ZIMBABWE", "ARGENTINA", "BHUTAN", "CHAD", "DENMARK",
                            "EGYPT", "FIJI", "GHANA", "KENYA", "LIBYA",
                            "MONGOLIA", "NIGERIA", "QATAR", "SOMALIA", "TURKMENISTAN",
                            "URUGUAY", "VIETNAM", "ZAMBIA", "MAURITANIA", "LIBERIA"};

    // load words into .txt file
    ofstream countryWrite("countryName.txt");

    for (int i = 0; i < 40; i++)
    {
        countryWrite << countryName[i] << "\n";
    }

    countryWrite.close();

    // generate random word from .txt file
    ifstream countryRead("countryName.txt");

    if (countryRead.is_open())
    {
        srand(time(0));
        int random = rand() % 40;
        while (getline(countryRead, word))
        {
            count++;

            if (count == random)
                return word;
        }
    }
}

void drawHangman(int guessCount)
{
    if (guessCount >= 1)
        printMessage(" |", false, false);

    if (guessCount >= 2)
        printMessage(" |", false, false);

    if (guessCount >= 3)
        printMessage(" O", false, false);

    if (guessCount >= 4)
        printMessage(" /|\\", false, false);

    if (guessCount >= 5)
        printMessage(" |", false, false);

    if (guessCount == 6)
        printMessage(" / ", false, false);

    if (guessCount >= 7)
        printMessage(" / \\", false, false);
}

void printMessage(string message, bool printTop, bool printBottom)
{
    if (printTop)
    {
        cout << "\t\t\t\t\t\t\t\t+*********************************+" << endl;
        cout << "\t\t\t\t\t\t\t\t*";
    }
    else
    {
        cout << "\t\t\t\t\t\t\t\t*";
    }

    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message;

    if (printBottom)
    {
        cout << "*" << endl;
        cout << "\t\t\t\t\t\t\t\t+*********************************+" << endl;
    }
    else
    {
        cout << "*" << endl;
    }
}

void leaderboard()
{
    cout << "This is leaderboard" << endl;
}

void quitGame()
{
    cout << "Thank you for your support." << endl;
}

int main()
{
   int choice;

   welcome();
   choice = menu();

   if(choice == 1)
   {
       startGame();
   }
   else if (choice == 2)
   {
       leaderboard();
   }
   else
   {
       quitGame();
   }

   return 0;
}
