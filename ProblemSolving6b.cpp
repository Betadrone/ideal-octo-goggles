//Muhammad Ashhad
//November 15, 2022
//ProblemSolving6b

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int OpponentPosition();
void AskUserStartingPosition();
float distance(int x1, int y1, int x2, int y2);
void AskUserMove();
void UserMovement(int& userX, int& userY);
void SquareColour(int x, int y);


int main()
{
	srand(time(0));

	int computerX = OpponentPosition();
	int computerY = OpponentPosition();
	int userX = 0;
	int userY = 0;

	cout << "computer x: " << computerX << " and computer y: " << computerY << endl;

	AskUserStartingPosition();
	cin >> userX;
	cin >> userY;

	

	while (userX != computerX || userY != computerY)
	{
		cout << "user x value: " << userX << " and user y value " << userY << endl;
		SquareColour(userX, userY);
		cout << "Your opponent is at a distance of " << distance(userX, userY, computerX, computerY) << " away from you..." << endl;

		AskUserMove();
		UserMovement(userX,userY);

		system("pause");
		system("cls");
	}

	cout << "You have won the game" << endl;

	return 0;
}

int OpponentPosition()
{
	int position = 0;
	position = rand() % 7;
	return position;
}
void AskUserStartingPosition()
{
	cout << "Hello user. Welcome to my little game..." << endl;
	cout << "The game board is 8 by 8 with top left being 0,0 and bottom right being 7,7" << endl;
	cout << "Please enter an x value from 0-7 followed by a y value from 0-7..." << endl;

}
float distance(int x1, int y1, int x2, int y2)
{
	int xdiff = (x2 - x1);
	int ydiff = (y2 - y1);
	int powerOfX = pow(xdiff, 2);
	int powerOfY = pow(ydiff, 2);
	float result = sqrt(powerOfX + powerOfY);
	return result;
}
void AskUserMove()
{
	cout << "Which direction do you want to move in?" << endl;
	cout << "1) Up\n2) Down\n3) Right\n4) Left" << endl;
}
void UserMovement(int& userX, int& userY)
{
		enum USER_DIRECTIONS
		{
			NONE,

			UP,
			DOWN,
			RIGHT,
			LEFT,

			NUM_USER_DIRECTIONS
		};

		int move = 0;
		cin >> move;

		switch (move)
		{
			case UP:
			{
				if (userY == 0)
				{
					cout << "That is out of bounds... Try Again..." << endl;
				}
				else
				{
					userY--;
					cout << "User moved up by one space." << endl;
				}
				break;
			}

			case DOWN:
			{
				if (userY == 7)
				{
					cout << "That is out of bounds... Try Again..." << endl;
				}
				else
				{
					userY++;
					cout << "User moved down by one space." << endl;
				}
				break;
			}

			case RIGHT:
			{
				if (userX == 7)
				{
					cout << "That is out of bounds... Try Again..." << endl;
				}
				else
				{
					userX++;
					cout << "User moved towards the right by one space." << endl;
				}
				break;
			}

			case LEFT:
			{
				if (userX == 0)
				{
					cout << "That is out of bounds... Try Again..." << endl;
				}
				else
				{
					userX--;
					cout << "User moved towards the left by one space." << endl;
				}
				break;
			}

			default:
			{
				cout << "That is not an option" << endl;
			}

		}
}
void SquareColour(int x, int y)
{
	if (((x + y) % 2) == 0)
	{
		cout << "User is on a BLACK square." << endl;
	}
	else
	{
		cout << "User is on a WHITE square." << endl;
	}
}

