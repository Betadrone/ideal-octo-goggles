//Muhammad Ashhad
//Problem solving 4a - Guessing game
//2022-10-13
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
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
	int userNum = 0;
	int counter = 0;
	while (userNum != -1 && counter < 8)
	{
		counter++;

		cin >> userNum;
		if (userNum > computerNum)
		{
			cout << "Too high, try again" << endl;
		}
		else if (userNum < computerNum && userNum > -1)
		{
			cout << "Too low, try again" << endl;
		}
		else if (userNum == computerNum)
		{
			cout << "Nice, You got it!" << endl;
		}
		else if (userNum == -1)
		{
			cout << "Thanks for playing... bye..." << endl;
			break;
		}
		
	}



	// The user is asked to guess the number or press -1 to quit 
	




	return 0;
}
