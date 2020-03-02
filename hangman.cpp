#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

// function declaration
void welcome();
int menu();
void startGame();
void leaderboard();
void quitGame();
string loadRandomWord();
void printMessage(string message);
void drawHangman(int wrongCount);

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
    int wrongCount = 0;
    cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to start the game!" << endl;
    cout << "\n\t\t\t\t\t\t\t>> ";
    cin.getline(playerName, 50);
    cout << "\n\t\t\t\t\t\t\tGood luck, " << playerName << "!\t\t\t\t\t" << endl;
    system("pause");
    system("cls");

    // get the random word
    wordToGuess = loadRandomWord();

    drawHangman(wrongCount);
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
        printMessage("\t\t\t\t\t\t\t|");
    else
        printMessage("");
 
    if (guessCount >= 2)
        printMessage("\t\t\t\t\t\t\t|");
    else
        printMessage("");
 
    if (guessCount >= 3)
        printMessage("\t\t\t\t\t\t\tO");
    else
        printMessage("");
 
    if (guessCount == 4)
        printMessage("\t\t\t\t\t\t\t/  ");
   
    if (guessCount == 5)
        printMessage("\t\t\t\t\t\t\t/| ");
 
    if (guessCount >= 6)
        printMessage("\t\t\t\t\t\t\t/|\\");
    else
        printMessage("");
 
    if (guessCount >= 7)
        printMessage("\t\t\t\t\t\t\t|");
    else
        printMessage("");
 
    if (guessCount == 8)
        printMessage("\t\t\t\t\t\t\t/");
 
    if (guessCount >= 9)
        printMessage("\t\t\t\t\t\t\t/ \\");
    else
        printMessage("");
}

void printMessage(string message)
{
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
    cout << message << endl;
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
