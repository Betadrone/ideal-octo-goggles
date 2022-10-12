// Muhammad Ashhad - October 12, 2022 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	srand(time(0));
	int randomNum = 0;

	cout << "Welcome to walkthough 6" << endl;

	do
	{
		randomNum = rand();
		cout << randomNum << endl;

	} while (randomNum % 100 != 0);

	randomNum = 0;
	while (true)
	{
		randomNum = rand();
		cout << randomNum << endl;
		if (randomNum % 100 == 0)
		{
			break;
		}
	}

	for (int letter = 1; letter <= 26; letter++)
	{
		char asLetter = letter + 64;
		cout << asLetter;
	}

	cout << endl;

	int userNum = 0;
	cout << "Please enter a number to loop with." << endl;
	cin >> userNum;


	for (int counter = userNum; counter > 0; counter--)
	{
		int currentNum = 0;
		for (currentNum = counter; currentNum > 0; currentNum--)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = 0; i < userNum; i++)
	{
		if (i % 5 == 0)
		{
			continue;
		}
		if (i % 2 == 0)
		{
			cout << i << " is even." << endl;
		}
		else
		{
			cout << i << " is odd." << endl;
		}
	}

	for (int verticle = 0; verticle < 5; verticle++)
	{
		for (int horizontal = 0; horizontal < 5; horizontal++)
		{
			cout << "o";
		}
		cout << endl;
	}

	int userX = 0;
	int userY = 0;
	cout << "Please enter an x and y value:" << endl;
	cin >> userX >> userY;

	for (int y = 1; y < 6; y++)
	{
		int x = 1;
		for (x = 1; x < 6; x++)
		{
			if (x == userX && y == userY)
			{
				cout << "X  ";
				break;
			}
			else
			{
				cout << "o  ";
			}
		}
		if (x == userX && y == userY)
		{
			break;
		}
		cout << endl;
	}


	return 0;
}
