#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdio.h>

void initialize(int level[]);
void printScore(int& score);
void printHeader();
void printBorder();
void displayMap(char guesses[]);
void promptUser(int& guessX, int& guessY);
void updateScore(int &score, int guessX, int guessY, int level[]);
void updateMap(char guesses[], int guessX, int guessY);
void mainGame(int& score, char guesses[], int guessX, int guessY, int level[]);


using namespace std;

int main()
{
	int guessX = -1;
	int guessY = -1;
	int score = 0;
	int level[8 * 8];

	char guesses[64] =
	{
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',
	};

	// Initialize the random values for each entry in the level
	initialize(level);

	// main game loop
	mainGame(score, guesses, guessX, guessY, level);

	cout << "Congrats you won!" << endl;

	return 0;
}

void initialize(int level[])
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			level[y + (x * 8)] = rand() % 10;
		}
	}
}
void printScore(int &score)
{
	cout << "Score: " << score << " /100" << endl << endl;
}
void printHeader()
{
	cout << "     ";
	for (int x = 1; x <= 8; x++)
	{
		cout << x << "  ";
	}
	cout << endl;
}
void printBorder()
{
	cout << "  [X]=======================[X]" << endl;
}
void displayMap(char guesses[])
{
	for (int y = 0; y < 8; y++)
	{
		cout << y + 1 << " || ";
		for (int x = 0; x < 8; x++)
		{
			cout << guesses[y + (x * 8)] << "  ";

			//generate new colour
			char numstr[21];
			sprintf_s(numstr, "color 0%d", y + 1);
			system(numstr);

			Sleep(30);
		}
		cout << "|| " << endl;
	}
}
void promptUser(int& guessX, int& guessY)
{
	cout << endl << "please enter the next coordinate to check: " << endl;
	cout << "X:";
	cin >> guessX;
	cout << "Y:";
	cin >> guessY;
}
void updateScore(int& score, int guessX, int guessY, int level[])
{
	score += level[guessY - 1 + ((guessX - 1) * 8)];
}
void updateMap(char guesses[], int guessX, int guessY)
{
	guesses[guessY - 1 + ((guessX - 1) * 8)] = 'X';
}
void mainGame(int& score, char guesses[], int guessX, int guessY, int level[])
{
	while (score < 100)
	{
		// print score
		printScore(score);

		// print header numbers
		printHeader();

		// print top border
		printBorder();

		// loop through display the map
		displayMap(guesses);

		// print bottom border
		printBorder();

		system("color 0A"); // first letter is the bg colour, second letter is the font colour

		// prompt user for input
		promptUser(guessX, guessY);

		// update score
		updateScore(score, guessX, guessY, level);
		// update map of guesses
		updateMap(guesses, guessX, guessY);
		system("CLS"); // this clears the screen
	}
}
