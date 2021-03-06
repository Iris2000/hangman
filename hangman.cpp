#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <cctype>
#define tableSize 100

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
void printLife();
void syncSortLeader();
void decSortArray();
void congratulation();
int Hash(string key);
void AddItem(string name, int score);
void PrintTable();

// global variables
ofstream os;
string playerName="";
int score=0;

ifstream print;

struct unSortArray
{
	string unSortPlyName;
	int unSortScore;
};
unSortArray firstArr[10];

struct leaderB
{
	string name;
	int scores;
	leaderB* next;
};

// hash playerName and score
// method: Linked List
class hash{
	private:
		leaderB* HashTable[tableSize], *head,*tail;//pointer

	public:
		hash(){//a constructure that set default value
			for(int i = 0; i<tableSize; i++){
				HashTable[i] = new leaderB;
				HashTable[i]-> name = "empty";
				HashTable[i]-> scores = 0;
				HashTable[i]-> next = NULL;
			}
		}
	void AddItem(string name, int score){

		os.open("linkedList.txt",ofstream::app);
		int index= Hash(name);
		leaderB *temp = new leaderB;
	
		if(HashTable[index]->name == "empty"){
			HashTable[index]->name = name;
			HashTable[index]->scores = score;
			os<<HashTable[index]->name<<"\n"<<HashTable[index]->scores<<"\n" ;  // write into text file
		}
		else{
			leaderB* Ptr = HashTable[index];
			leaderB* n=new leaderB;
			n->name = name;
			n->scores = score;
			n->next = NULL;
			while(Ptr->next != NULL){
				Ptr= Ptr->next;//to loop and found last pointer and add in to the index that have element
			}
			Ptr->next = n;
		}
		os.close();
	}
};


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
		score = 0;
        startGame();
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

void congratulation(){
	cout<< "\n\t\t\t\t\t\t\tCongratulation you hit the leader board!"<<endl<<endl;
	cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to store in the game!" << endl;
	cout << "\n\t\t\t\t\t\t\t>> ";
	cin>>playerName;

	// validate player name
	while(playerName.length() == 0)
	{
		cout << "\n\t\t\t\t\t\t\tSeem you haven't enter a name." << endl;
		cout << "\n\t\t\t\t\t\t\tPlease enter a cool name to start the game!" << endl;
		cout << "\n\t\t\t\t\t\t\t>> ";
		cin>>playerName;
	}

	cout << "\n\t\t\t\t\t\t\tThank you for playing, " << playerName << "!\n\n\n\n\t\t\t\t\t\t";
}
// enter player name
void enterName()
{
	hash hashObj;
	char choose;
	int rec;
	ifstream readprint;
	ofstream writeprint;
	readprint.open("linkedList.txt");
	
	if(readprint.fail()){
		congratulation();
		writeprint.open("linkedList.txt");
		writeprint<<playerName<<"\n"<<score<<"\n";
		hashObj.AddItem(playerName, score);
		writeprint.close();
		readprint.close();
	}
	else{
		syncSortLeader();

		for(int t=0; t<9; t++ ){
			if(firstArr[t].unSortPlyName==""){
				rec=t;
				break;
			}
			else
			 rec=9;
		}
		if(score>firstArr[rec].unSortScore){
			congratulation();
			writeprint.open("linkedList.txt");
			for(int w=0;w<rec;w++){
				writeprint<<firstArr[w].unSortPlyName<<"\n"<<firstArr[w].unSortScore<<"\n";
			}
			writeprint.close();
			readprint.close();
			hashObj.AddItem(playerName, score);
		}
		else
		{
			cout<<"Score: "<<score<<endl;
			cout<<"Kesiannya tak masuk leader board"<<endl;
		}
	}

	system("pause");
    system("cls");
    menu();

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
// method: recursion
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
				//cout<<wordToGuess<<endl;
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
				enterName();
                //menu();
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
        // recursion
        startGame();
        return 0;
    }
    else if (playAgain == 'N')
    {
        system("cls");
        enterName();
        return 0;
    }

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
		string countryName[40] = {"AFGHANISTAN", "BOLIVIA", "DJIBOUTI", "ETHIOPIA","CROATIA",
		                              "GEORGIA", "HUNGARY", "JAMAICA", "KAZAKHSTAN","ZAMBIA",
		                              "LUXEMBOURG", "MADAGASCAR", "NETHERLANDS", "ROMANIA","SLOVENIA",
		                              "TANZANIA", "UKRAINE", "VENEZUELA","ZIMBABWE", "ARGENTINA",
		                              "BHUTAN", "KIRIBATI", "BULGARIA","EGYPT", "FIJI",
		                              "UZBEKISTAN", "LIBYA","AZERBAIJAN", "CAMEROON", "ANDORRA",
		                              "LIBERIA", "GHANA", "MAURITANIA", "MONGOLIA", "DOMINICA",
		                              "NIGERIA", "QATAR", "SOMALIA", "TURKMENISTAN","URUGUAY"};

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
    cout << "\nTOP 10 LEADERBOARD\n\n" <<endl;
    PrintTable();
    cout << "\nBack to menu?[Y/N]\n" << endl;
    cout << ">>";
    cin >> confirm;
    confirm = validateInput(confirm);

    if (confirm == 'Y')
    {
        system("cls");
        menu();
    }
    else
    {
			system("cls");
    	leaderboard();
    }
}

// sort scores with descending order
// method: insertion sort
void decSortArray(){
	for(int step = 1; step < 10; step++){
		int sortScore = firstArr[step].unSortScore;
		string sortPlyName = firstArr[step].unSortPlyName;
		int j =step - 1;
		//For descending order, key > array
		while(sortScore > firstArr[j].unSortScore && j >= 0){
			firstArr[j+1].unSortScore = firstArr[j].unSortScore;
			firstArr[j+1].unSortPlyName = firstArr[j].unSortPlyName;
			--j;
		}
		firstArr[j+1].unSortScore=sortScore;
		firstArr[j+1].unSortPlyName=sortPlyName;

	}
}

void syncSortLeader(){
	int number;

	string textname;
	int textscore;
	leaderB temp;
	int count =0;
	ifstream readfile ;
	readfile.open("linkedList.txt");
	while((readfile>>textname>>textscore)&& count < tableSize){
		if (count < 10)
		{
			firstArr[count].unSortPlyName=textname;
			firstArr[count].unSortScore=textscore;
			count++;
		}
	}
	readfile.close();
	decSortArray();
}
void PrintTable(){ //for view the linked list which with element
	int rank = 0;
	print.open("linkedList.txt");
	cout<<"Rank\tName\t\t\t\t\t\t\t\tScore\n";
	syncSortLeader();
	for(int v=0; v<10; v++){
		if(firstArr[v].unSortScore > 0){
			cout<<v+1<<"\t";
			cout<<firstArr[v].unSortPlyName<<"\t\t\t\t\t\t\t\t";
			cout<<firstArr[v].unSortScore<<endl;
			if (firstArr[v].unSortPlyName == playerName)
			{
				rank = v+1;
			}
		}
	}

    if (rank != 0)
		cout<<"\n\nYour Rank: "<<rank<<endl;
	else
		cout<<"\n\nYour Rank: --"<<endl;
		
	cout<<"Your Score: "<<score<<endl;
	print.close();
}

int Hash(string key){

	int hash=0;
	int index;

	for(int i = 0; i<key.length(); i++){ //.length() find the length of string in terms of byte
		hash = hash + (int)key[i];
	}

	index = hash % tableSize; //the location of the value store

	return index;
}

// exit the program
void quitGame()
{
    cout << "\n\t\t\t\t\t\t\tThank you for your support." << endl;
}

int main()
{
   welcome();
   menu();

   return 0;
}