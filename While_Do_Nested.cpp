// Muhammad Ashhad
// October 11, 2022
// Walkthrough 5

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));

	cout << "Welcome to walkthrough 5" << endl;

	int counter = 1;

	while (true)
	{
		cout << counter << endl;
		
		counter++;

		if (counter == 11)
		{
			break;
		}
	}

	int counter2 = 20;

	do
	{
		cout << counter2;
		
		if (counter2 >= 2)
		{
			cout << ", ";
		}
		else
		{
			cout << endl;
		}
		
		counter2--;
	} while (counter2 > 0);


	int rows = 0;

	while (rows < 10)
	{
		
		int columns = 0;
		
		while (columns < 10)
		{
			columns++;
			
			cout << columns + (rows*10) << "\t";
		}
		
		cout << endl;
		
		rows++;
	}

	cout << endl;

	char anyLetter = '1';

	do
	{
		cout << "please enter any letter [press a to escape]" << endl;
		
		cin >> anyLetter;

	} while ( anyLetter != 'a');


	int rando = rand() % 100 + 1;
	
	int userGuess = 0;
	int numguesses = 0;
	
	while (userGuess != -1 && userGuess != rando && numguesses != 3)
	{
		
		cout << "Guess a number between 1 - 100. You have 3 guesses [press -1 to quit anytime]" << endl;
		cin >> userGuess;
		
		if (userGuess == rando)
		{
			cout << "Congratulations, you have guessed the number!!!" << endl;
		}
		else if (userGuess == -1)
		{
			cout << "Try again later." << endl;
		}
		else
		{
			cout << "Sorry, that was wrong." << endl;
		}

		numguesses++;

	}

	return 0;
}
