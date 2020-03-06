#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>

using namespace std;

// function declaration
void welcome();
int menu();
void enterName();
void startGame();
void leaderboard();
void quitGame();
string loadRandomWord();
void printMessage(string message, bool printTop = true, bool printBottom = true);
void drawHangman(int wrongCount);
void printAvailableLetters(string guesses);
void printLetters(string taken, char alphabets[]);
bool printWordAndResult(string wordToGuess, string guesses);
string checkWord(string wordToGuess, string guesses, int count, string display);
int triesLeft(string wordToGuess, string guesses);

// global variable
char playerName[50];

// welcome screen
void welcome()
{
    cout << "\n\n";
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
    }

    return choice;
}

void enterName()
{
    // cin.clear();
    // cin.ignore();
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

    startGame();
}

void startGame()
{
    string guesses;
    string wordToGuess;
    int tries = 0;
    bool win;
    char x;
    bool found = false;
    int choice;

    // get the random word
    wordToGuess = loadRandomWord();
    // wordToGuess = "MALAYSIA";

     do
    {
        system("cls");
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tQuit Game: 1" << endl;
        printMessage("HANGMAN", true, true);
        drawHangman(tries);
        printAvailableLetters(guesses);
        printMessage("GUESS A COUNTRY");
        win = printWordAndResult(wordToGuess, guesses);
        // cout << "WIN: " << win << endl;
        if (win)
            break;
        if (tries == 7)
            break;

        cout << "\t\t\t\t\t\t\t>>";
        cin >> x;
        x = toupper(x);

        do 
        {
            found = false;
            if (x == '1')
            {
                char confirm;
                cout << "\n\t\t\t\t\t\t\tAre you sure to quit game?[Y/N]\n" << endl;
                cout << "\t\t\t\t\t\t\t>>";
                cin >> confirm;
                confirm = toupper(confirm);

                while (confirm != 'Y' && confirm != 'N')
                {
                    cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
                    cout << "\t\t\t\t\t\t\t>>";
                    cin >> confirm;
                }

                if (confirm == 'Y')
                {
                    system("cls");
                    choice = menu();

                    if(choice == 1)
                    {
                        char changePlayer;
                        cout << "\n\t\t\t\t\t\t\tWould you like to start with a new player name?[Y/N]\n" << endl;
                        cout << "\t\t\t\t\t\t\t>>";
                        cin >> changePlayer;
                        cin.ignore();
                        changePlayer = toupper(changePlayer);

                        while (changePlayer != 'Y' && changePlayer != 'N')
                        { 
                            cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
                            cout << "\t\t\t\t\t\t\t>>";
                            cin >> changePlayer;
                            changePlayer = toupper(changePlayer);
                        }
                        if (changePlayer == 'Y')
                        {
                            enterName();
                        }
                        else if (changePlayer == 'N')
                        {
                            startGame();
                        }
                    }
                    else if (choice == 2)
                    {
                        leaderboard();
                    }
                    else if (choice == 3)
                    {
                        quitGame();
                    }
                }
                else 
                {
                    cout << "\n\t\t\t\t\t\t\tGame continue...\n" << endl;
                    cout << "\t\t\t\t\t\t\t>>";
                    cin >> x;
                }
            }
            else if (!isalpha(x))
            {
                found = true;
                cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
                cout << "\t\t\t\t\t\t\t>>";
                cin >> x;
                x = toupper(x);
            }

            for (int i = 0; i < guesses.length(); i++)
            {
                if (guesses[i] == x)
                {
                    found = true;
                    cout << "\n\t\t\t\t\t\t\tThe letter is not available. Please choose again.\n" << endl;
                    cout << "\t\t\t\t\t\t\t>>";
                    cin >> x;
                    x = toupper(x);
                }
            }
        } while (found == true);
    
        guesses += x;

        tries = triesLeft(wordToGuess, guesses);
        // cout << "TRIES:" << tries << endl;

    } while (tries <= 7);

    if (win)
        printMessage("YOU WON!", false, true);
    else
    {
        printMessage("GAME OVER!", false, false);
        printMessage("WORD: " + wordToGuess);
    }
    
    cout << "\n\t\t\t\t\t\t\tWould you like to play again?[Y/N]\n" << endl;
    cout << "\t\t\t\t\t\t\t>>";
    char playAgain;
    cin >> playAgain;
    playAgain = toupper(playAgain);

    while (playAgain != 'Y' && playAgain != 'N')
    {
        cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
        cout << "\t\t\t\t\t\t\t>>";
        cin >> playAgain;
        playAgain = toupper(playAgain);
    }

    if (playAgain == 'Y')
    {
        system("cls");
        startGame();
    }
    else if (playAgain == 'N')
    {
        system("cls");
        choice = menu();
        if(choice == 1)
        {
            char changePlayer;
            cout << "\n\t\t\t\t\t\t\tWould you like to start with a new player name?[Y/N]\n" << endl;
            cout << "\t\t\t\t\t\t\t>>";
            cin >> changePlayer;
            changePlayer = toupper(changePlayer);

            while (changePlayer != 'Y' && changePlayer != 'N')
            { 
                cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
                cout << "\t\t\t\t\t\t\t>>";
                cin >> changePlayer;
                changePlayer = toupper(changePlayer);
            }
            if (changePlayer == 'Y')
            {
                enterName();
            }
            else if (changePlayer == 'N')
            {
                startGame();
            }
        }
        else if (choice == 2)
        {
            leaderboard();
        }
        else
        {
            quitGame();
        }
    }
}

int triesLeft(string wordToGuess, string guesses)
{
    int error = 0;
    for (int i = 0; i < guesses.length(); i++)
    {
        if (wordToGuess.find(guesses[i]) == string::npos)
            error++;
    }

    return error;
}

void printAvailableLetters(string guesses)
{
    char alphabets1[13] ={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M'};
    char alphabets2[13] ={'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    printMessage("AVAILABLE LETTERS");
    printLetters(guesses, alphabets1);
    printLetters(guesses, alphabets2);
}

// print letters for users to choose
// searching method: linear search
void printLetters(string taken, char alphabets[])
{
    bool found = false;
    string letters = " ";
    for (char i = 0; i < 13; i++)
    {
        for (char j = 0; j < taken.length(); j++)
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

bool printWordAndResult(string wordToGuess, string guesses)
{
    bool won = true;
    string displayWord;

    displayWord = checkWord(wordToGuess, guesses, 0, "");

    for (int i = 0; i < displayWord.length(); i ++)
    {
        if (displayWord[i] == '_')
            won = false;
    }
    printMessage(displayWord, false);
    return won;
}

string checkWord(string wordToGuess, string guesses, int count, string display)
{
    // cout << "wordToGuess: " << wordToGuess << endl;
    // cout << "length: " << wordToGuess.length() << endl;
    // cout << "Guesses: " << guesses << endl;
    // cout << "length: " << strlen(guesses) << endl;
    // cout << "Count: " << count << endl;
    // cout << "Display: " << display << endl;

    bool found = false;

    if (count == wordToGuess.length())
    {
        return display;
    }

    for (int j = 0; j < guesses.length(); j++)
    {
        // cout << "Guesses[j]: " << guesses[j] << endl;
        // cout << "wordToGuess[count]: " << wordToGuess[count] << endl;
        if (guesses[j] == wordToGuess[count])
        {
            found = true;
            display += wordToGuess[count];
            display += " ";
            break;
        }
    }

    if (found == false)
    {
        display += "_ ";
    }

    count++;
    return checkWord(wordToGuess, guesses, count, display);
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
    cout << "\n\t\t\t\t\t\t\tThis is leaderboard" << endl;
}

void quitGame()
{
    cout << "\n\t\t\t\t\t\t\tThank you for your support." << endl;
}

int main()
{
   int choice;

   welcome();
   choice = menu();

   if(choice == 1)
   {
       if (strlen(playerName) != 0)
       {
           startGame();
       }
       else
       {
           enterName();
       }
   }
   else if (choice == 2)
   {
       leaderboard();
   }
   else if (choice == 3)
   {
       quitGame();
   }

   return 0;
}
