//Muhammad Ashhad
//Problem solving 4a - Guessing game
//2022-10-13
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void GuessingGame1()
{

	// Computer initializes a seed and creates random number between 1 and 500
	srand(time(0));
	int computerNum = (rand() % 500) + 1;

	// Welcome the user
	cout << "Welcome user. You will be playing a guessing game." << endl;

	// Introduce them to the guessing game
	cout << "The computer has generated a random number between 1 - 500." << endl;
	cout << "I want you to guess this number" << endl;
	cout << "You have 8 chances to guess and can quit anytime by typing -1" << endl;

	// Prompt the user for an input
	cout << "Let's start! guess a number or type in -1 to quit" << endl;

	// either a while loop, do-while loop, or for loop is needed. let's just test them out.
	// while loop works, but it improved on via a do-while loop as seen ahead.
	int userNum = 0;
	int counter = 0;
	do
	{
		counter++;

		cin >> userNum;
		if (userNum > computerNum && userNum < 501)
		{
			if (counter < 8)
			{
				cout << "Too high, try again" << endl;
			}
			else if (counter == 8)
			{
				cout << "Game Over, You lose" << endl;
			}
		}
		else if (userNum < computerNum && userNum > 0)
		{
			if (counter < 8)
			{
				cout << "Too low, try again" << endl;
			}
			else if (counter == 8)
			{
				cout << "Game over, you lose" << endl;
			}
		}
		else if (userNum == computerNum)
		{
			cout << "Nice, You got it!" << endl;
			break;
		}
		else if (userNum == -1)
		{
			cout << "Thanks for playing... bye..." << endl;
			break;
		}
		else if (userNum < -1 || userNum > 500 || userNum == 0)
		{
			cout << "That was never an option. You get another chance." << endl;
			counter--;
		}

	} while (userNum != -1 && counter < 8);

}

void GuessingGame2()
{

	srand(time(0));

	//int ComNum = rand();
	//int counter = 0;
	//int ans = 0;

	cout << "Welcome to the guessing game!" << endl;
	cout << "Computer has chosen a random number between 1 - 500." << endl;
	cout << "You have 8 chances to guess it." << endl;
	cout << "Enter a number between 1 - 500 [ or press -1 to quit ]:" << endl;

	for (int ComNum = ((rand() % 500) + 1), counter = 0, ans = 0; ans != -1 && counter < 8; counter++)
	{
		cin >> ans;
		// If -1 ; quit
		if (ans == -1)
		{

			cout << "Thanks for playing... try again later..." << endl;

		}
		// if < -1 or > 500, try again and counter goes down by 1
		else if (ans < -1 || ans > 500 || ans == 0)
		{

			cout << "That was never an option... Try again..." << endl;
			counter--;

		}
		// if > -1 and < comnum, too low
		else if (ans > -1 && ans < ComNum)
		{

			if (counter < 7)
			{

				cout << "Too low, try again" << endl;

			}
			else if (counter == 7)
			{

				cout << "Game Over... You Lose..." << endl;

			}
		}
		// if <= 500 and >> comnum, too high
		else if (ans <= 500 && ans > ComNum)
		{
			if (counter < 7)
			{

				cout << "Too high, Try again" << endl;

			}
			else if (counter == 7)
			{

				cout << "Game Over... You Lose..." << endl;

			}
		}
		// if answer is right, congratulate the player
		else if (ans == ComNum)
		{
			cout << "Congrats, You Win!!!" << endl;
			break;
		}

	}

}

int main()
{
	enum GAME_TERMS
	{
		NONE,

		YES,
		NO,
		GAME1,
		GAME2,

		NUM_GAME_TERMS
	};

	cout << "welcome, user. Do you want to play a game?\n1) yes\n2) no" << endl;
	int answer = 0;
	cin >> answer;

	switch (answer)
	{
		case YES:
		{	
			cout << "Would you like to play: \n3) easy \nor \n4) hard" << endl;
			cin >> answer;
			switch (answer)
			{
				case GAME1:
				{
					GuessingGame1();
					break;
				}
				case GAME2:
				{
					GuessingGame2();
					break;
				}
				
			}
			break;
		}
		case NO:
		{
			cout << "Fine then. Have a nice day... :(" << endl;
			break;
		}
	}
	
	

	return 0;
}
