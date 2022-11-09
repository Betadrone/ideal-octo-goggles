//Muhammad Ashhad
//November 11, 2022
//Walkthrough 7

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;

void PrintName();
int CollectCoins(int numCoins, bool isLarge = false);
void CollectCoins(int &numCoins, int amountToAdd);
void AddLife(int &life);

int main()
{
	srand(time(0));

	cout << "Welcome to walkthrough 7 - Functions and Scope" << endl;
	PrintName();

	int coins = 0;
	int lives = 1;

	coins = CollectCoins(coins);
	cout << "coins = " << coins << endl;

	coins = CollectCoins(coins, true);
	cout << "coins = " << coins << endl;

	CollectCoins(coins, 10);
	cout << "coins = " << coins << endl;

	AddLife(lives);
	cout << "Lives = " << lives << endl;

	for (int i = 1; i <= 150; i++)
	{
		if (rand() % 6 == 0)
		{
			coins = CollectCoins(coins, true);
		}
		else 
		{
			CollectCoins(coins, ((rand() % 3) + 1));
		}

		if (coins >= 100)
		{
			AddLife(lives);
			CollectCoins(coins, (-100));
			cout << "1UP!!!!!!!!!!" << endl;
		}
		cout << coins << endl;
		Sleep(75);
	}

	return 0;
}

void PrintName()
{
	cout << "Muhammad Ashhad" << endl;
}

void AddLife(int &life)
{
	life++;
}


void CollectCoins(int& numCoins, int amountToAdd)
{
	numCoins += amountToAdd;
}

int CollectCoins(int numCoins, bool isLarge)
{
	int retCoins = numCoins;
	if (isLarge == true)
	{
		retCoins += 5;
	}
	else
	{
		++retCoins;
	}
	return retCoins;
}
