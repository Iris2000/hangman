#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>

using namespace std;

// function declaration
void welcome();
void menu();
void enterName();
int startGame();
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
char validateInput(char input);
void changePlayer();
void printLife();
<<<<<<< HEAD
void PrintItem();

ofstream os;

int Hash(string key);
void AddItem(string name, int score);//to place the name and score in the hash table
int NumberOfItemIndex(int index);//count the number of item in bucket
void PrintTable();
void PrintItemIndex(int index);
void SearchScore(string name);

struct leaderB{
			string name;
			int score;
			leaderB* next;//pointer
		};


class hash{
	private:
		leaderB* HashTable[tableSize], *head,*tail;//pointer

	public:
		hash(){//a constructure that set default value
			for(int i = 0; i<tableSize; i++){
				HashTable[i] = new leaderB;
				HashTable[i]-> name = "empty";
				HashTable[i]-> score = 0;
				HashTable[i]-> next = NULL;
			}
		}
	void AddItem(string name, int score){

	os.open("linkedList.txt",ofstream::app);
	int index= Hash(name);
	leaderB *temp = new leaderB;

	if(HashTable[index]->name == "empty"){
		HashTable[index]->name = name;
		HashTable[index]->score = score;
		os<<HashTable[index]->name<<"\n"<<HashTable[index]->score<<"\n" ;  // write into text file
	}
	else{
		leaderB* Ptr = HashTable[index];
		leaderB* n=new leaderB;
		n->name = name;
		n->score = score;
		n->next = NULL;
		//os<<n->name<<"\n"<<n->score<<"\n" ;
		while(Ptr->next != NULL){
			Ptr= Ptr->next;//to loop and found last pointer and add in to the index that have element
		}
		Ptr->next = n;
	}
}

};

=======
int score=0;
>>>>>>> parent of 0661161... with hash table without sorting

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
void menu()
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

    if(choice == 1)
    {
        if (strlen(playerName) != 0)
        {
            changePlayer();
            // startGame();
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
}

// enter player name
void enterName()
{
    cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to start the game!" << endl;
    cout << "\n\t\t\t\t\t\t\t>> ";
    cin.getline(playerName, 50);

    // validate player name
    while(strlen(playerName) == 0)
    {
        cout << "\n\t\t\t\t\t\t\tSeem you haven't enter a name." << endl;
        cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to start the game!" << endl;
        cout << "\n\t\t\t\t\t\t\t>> ";
        cin.getline(playerName, 50);
    }

<<<<<<< HEAD
    cout << "\n\t\t\t\t\t\t\tThank you for playing, " << playerName << "!\n\n\n\n\t\t\t\t\t\t";
<<<<<<< HEAD
    system("pause");
    system("cls");
    menu();
	
=======

    cout<<"Do you want to quit game? [Y/N]: ";
    cin>>choose;

    if(choose=='y'||choose=='Y'){
    	quitGame();
	}
	else{
		//system("pause");
    	system("cls");
		menu();
	}



=======
    cout << "\n\t\t\t\t\t\t\tGood luck, " << playerName << "!\n\n\n\n\t\t\t\t\t\t";
    system("pause");
    system("cls");

    startGame();
>>>>>>> parent of 0661161... with hash table without sorting
>>>>>>> a42ff3c90a179159e8332da60ab6cce21dabeaa9
}

// check if player wants to change player name
void changePlayer()
{
    char changePlayer;
    cout << "\n\t\t\t\t\t\t\tWould you like to start with a new player name?[Y/N]\n" << endl;
    cout << "\t\t\t\t\t\t\t>>";
    cin >> changePlayer;
    cin.ignore();
    changePlayer = validateInput(changePlayer);

    if (changePlayer == 'Y')
    {
        enterName();
    }
    else if (changePlayer == 'N')
    {
        startGame();
    }
}

// validate input [Y/N]
char validateInput(char input)
{
    input = toupper(input);

    while (input != 'Y' && input != 'N')
    {
        cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
        cout << "\t\t\t\t\t\t\t>>";
        cin >> input;
        input = toupper(input);
        cin.clear();
        cin.ignore();
    }

    return input;
}

void printLife(int x){
  while(x>0){
    cout<<"* ";
    x--;
  };
}
// game start here
int startGame()
{
    string guesses;
    string wordToGuess;
    int tries = 0;
    bool win = false;
    char x;
    bool found = false;
    int choice;
    int life=7;
    // get the random word
    wordToGuess = loadRandomWord();

    // repeat process to update interface
     do
    {
        system("cls");
        cout << "Quit Game: 1";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\tTotal score: "<<score<< endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tLife\t: ";
        printLife(life);
        cout<<endl;
        printMessage("HANGMAN", true, true);
        drawHangman(tries);
        printAvailableLetters(guesses);
        printMessage("GUESS A COUNTRY");

        // check status of game
        win = printWordAndResult(wordToGuess, guesses);
        // game completed if won or game over
        if (win)
            break;
        if (tries == 7)
            break;

        // get the guessed letter from player
        cout << "\t\t\t\t\t\t\t>>";
        cin >> x;
        x = toupper(x);

        if (x == '1')
        {
            // check if player really wants to quit the game
            char confirm;
            cout << "\n\t\t\t\t\t\t\tAre you sure to quit game?[Y/N]\n" << endl;
            cout << "\t\t\t\t\t\t\t>>";
            cin >> confirm;
            confirm = validateInput(confirm);

            if (confirm == 'Y')
            {
                system("cls");
                menu();
                return 0;
            }
            else
            {
                // continue the game
                cout << "\n\t\t\t\t\t\t\tGame continue...\n" << endl;
                cout << "\t\t\t\t\t\t\t>>";
                cin >> x;
            }
        }
        // repeat if input is non-alphabet or letter is taken before
        do
        {
            found = false;
            // if player enter non-alphabet
            if (!isalpha(x) && x != '1')
            {
                found = true;
                cout << "\n\t\t\t\t\t\t\tInvalid input. Please enter again.\n" << endl;
                cout << "\t\t\t\t\t\t\t>>";
                cin >> x;
                x = toupper(x);
            }

            // check if letter is taken before
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

        // check attempts available
        tries = triesLeft(wordToGuess, guesses);
        life = 7-tries;
    } while (tries <= 7);

    if (win){
      printMessage("YOU WON!", false, true);
      score=score+life*10;
    }
    else
    {
        printMessage("GAME OVER!", false, false);
        printMessage("WORD: " + wordToGuess);
    }

    // check if player wants to play again
    cout << "\n\t\t\t\t\t\t\tWould you like to play again?[Y/N]\n" << endl;
    cout << "\t\t\t\t\t\t\t>>";
    char playAgain;
    cin >> playAgain;
    playAgain = validateInput(playAgain);

    if (playAgain == 'Y')
    {
        system("cls");
        startGame();
        return 0;
    }
    else if (playAgain == 'N')
    {
        system("cls");
        menu();
        return 0;
    }
<<<<<<< HEAD

=======
>>>>>>> parent of 0661161... with hash table without sorting
}

// print message
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

// load words into .txt file and choose random word
string loadRandomWord()
{
    int count = 0;
    string word;
<<<<<<< HEAD
    string countryName[40] = {"AFGHANISTAN", "BOLIVIA", "DJIBOUTI", "ETHIOPIA","CROATIA",
                              "GEORGIA", "HUNGARY", "JAMAICA", "KAZAKHSTAN","ZAMBIA",
                              "LUXEMBOURG", "MADAGASCAR", "NETHERLANDS", "ROMANIA","SLOVENIA",
                              "TANZANIA", "UKRAINE", "VENEZUELA","ZIMBABWE", "ARGENTINA",
                              "BHUTAN", "KIRIBATI", "BULGARIA","EGYPT", "FIJI",
                              "GHANA", "UZBEKISTAN", "LIBYA","AZERBAIJAN","EGYPT",
                              "LIBERIA", "GHANA", "MAURITANIA", "LIBYA","MONGOLIA",
                              "NIGERIA", "QATAR", "SOMALIA", "TURKMENISTAN","URUGUAY"};
=======
    string countryName[40] = {"AFGHANISTAN", "BOLIVIA", "CZECH", "DJIBOUTI", "ETHIOPIA",
                            "CROATIA", "GEORGIA", "HUNGARY", "JAMAICA", "KAZAKHSTAN",
                            "LUXEMBOURG", "MADAGASCAR", "NETHERLANDS", "PHILIPPINES", "ROMANIA",
                            "SLOVENIA", "TANZANIA", "UKRAINE", "VENEZUELA", "YEMEN",
                            "ZIMBABWE", "ARGENTINA", "BHUTAN", "KIRIBATI", "BULGARIA",
                            "EGYPT", "FIJI", "GHANA", "UZBEKISTAN", "LIBYA",
                            "MONGOLIA", "NIGERIA", "QATAR", "SOMALIA", "TURKMENISTAN",
                            "URUGUAY", "AZERBAIJAN", "ZAMBIA", "MAURITANIA", "LIBERIA"};

>>>>>>> parent of 0661161... with hash table without sorting

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

// draw stroke of hangman
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

// check available attemtps
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

// update the blanks and return status of game
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

// check if guessed letter match the word
// method used: recursion
string checkWord(string wordToGuess, string guesses, int count, string display)
{
    bool found = false;

    if (count == wordToGuess.length())
    {
        return display;
    }

    for (int j = 0; j < guesses.length(); j++)
    {
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

// leaderboard
void leaderboard()
{
    char confirm;
    system("cls");
    cout << "\n\t\t\t\t\t\t\tThis is leaderboard" << endl;
    cout << "\n\t\t\t\t\t\t\tBack to menu?[Y/N]\n" << endl;
    cout << "\t\t\t\t\t\t\t>>";
    cin >> confirm;
    confirm = validateInput(confirm);

    if (confirm == 'Y')
    {
        system("cls");
        menu();
    }
    else
    {
        leaderboard();
    }
}


	while((print>>textname>>textscore)&& count < tableSize){
		if(textname != "empty"){
			cout<<textname<<"\t\t\t\t";
			cout<<textscore<<endl;
			++count;
			//HashTable[i]->score = score[i];
		}
	}

	cout<<"\n\t\t\t\tYour Name: "<<playerName<<endl;
	cout<<"\t\t\t\tYour Score: "<<score<<endl;
}


int Hash(string key){

	int hash=0;
	int index;


	for(int i = 0; i<key.length(); i++){ //.length() find the length of string in terms of byte
		hash = hash + (int)key[i];
		//cout<<key[i] ;
	}

	index = hash % tableSize; //the location of the value store

	return index;

}

=======
>>>>>>> parent of 0661161... with hash table without sorting
//change name to ascii
int name_to_ascii(char name[]){
	int x = 0;
	int ascii;
	int sum=0;
	while (name[x] != '\0')
	{
		ascii = int(name[x]);
		sum=sum+ascii;
		cout<<ascii<<endl;
	    x++;
	}
	return sum;
}

// exit the program
void quitGame()
{
    cout << "\n\t\t\t\t\t\t\tThank you for your support." << endl;
}

int main()
{
<<<<<<< HEAD
	hash hashObj;
	//int score;

   welcome();
   menu();

   hashObj.AddItem(playerName, score);

=======
   welcome();
   menu();

>>>>>>> parent of 0661161... with hash table without sorting
   return 0;
}
