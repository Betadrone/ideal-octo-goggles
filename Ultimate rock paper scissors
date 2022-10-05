#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void onePlayerGame()
{

	srand(time(0));

	string p1;
	cout << "Please enter your name, player :\n";
	cin >> p1;
	cout << "Your name is = \t" << p1 << endl;
	cout << "You'll be going against the computer. No stress. Just guess the correct option." << endl;
	cout << "P.S. The computer is randomized every single time. So it's not cheating" << endl;

	cout << "Are you ready?" << endl;
	string answer;
	cin >> answer;

	system("cls");

	cout << "Doesn't matter, we're starting" << endl;



	enum PLAYER_CHOICE
	{
		NONE,

		ROCK,
		PAPER,
		SCISSORS,
		FIRE,
		HUMAN,
		SPONGE,
		AIR,
		WATER,
		GUN,

		NUM_CHOICE
	};

}

void twoPlayerGame()
{

	srand(time(0));

	string p1;
	string p2;

	cout << "Player 1, please enter your name:\n";
	cin >> p1;
	cout << "player 2 please enter your name:\n";
	cin >> p2;
	cout << "Player 1 = \t" << p1 << endl;
	cout << "Player 2 = \t" << p2 << endl;

	cout << "We cannot have both of you going against eachother, so we'll have you both fight against a computer." << endl;
	cout << "Whoever guesses the right outcome will win. If both of you guess correctly, you both tie." << endl;

	cout << "Are you ready?" << endl;
	string answer;
	cin >> answer;

	system("cls");

	cout << "Doesn't matter, we're starting" << endl;


	enum PLAYER_CHOICE
	{
		NONE,

		ROCK,
		PAPER,
		SCISSORS,
		FIRE,
		HUMAN,
		SPONGE,
		AIR,
		WATER,
		GUN,

		NUM_CHOICE
	};

}

int main()
{

	int playerNum = 0;
	cout << "Please select one of the following options: \n";
	cout << "\t1) Solo player" << endl;
	cout << "\t2) two players" << endl;
	cin >> playerNum;

	while (playerNum < 1 || playerNum > 2)
	{
		cout << "We do not have that option available, try again." << endl;
		cout << " Are you\n\t1)One player\n\tor\n\t2)Two players" << endl;
		cin >> playerNum;
	}

	enum NUMBER_OF_PLAYERS
	{
		NONE,

		SOLO,
		MULTI,

		NUM_PLAYERS,
	};

	switch (playerNum)
	{
		case SOLO:
		{
			cout << "You have chosen a one player game." << endl;
			onePlayerGame();
			break;
		}
		case MULTI:
		{
			cout << "you have chosen a two player game" << endl;
			twoPlayerGame();
			break;
		}
	}
	return 0;
}
