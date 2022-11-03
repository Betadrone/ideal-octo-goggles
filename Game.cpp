// Muhammad Ashhad - Muhammad Asjad 
// November 2, 2022 
// ProblemSolving5b

#include <iostream>
using namespace std;

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <windows.h>

void Intro();
void bossMoves();

int main()
{
	Sleep(1500);

	cout << "Hello user..." << endl;
	system("pause");

	cout << "Would you like to play a text-based dungeon boss fight?" << endl;
	cout << "(1) Yes (2) No" << endl;
	int userInput = 0;
	cin >> userInput;

	while (userInput != 1 && userInput != 2)
	{
		cout << "Not an option... Try again..." << endl;
		cin >> userInput;
	}

	if (userInput == 1)
	{
		system("cls");
		Intro();
	}
	else if (userInput == 2)
	{
		cout << "Don't know what you are doing here then...\nEnjoy your day\nGoodbye.." << endl;
	}

	return 0;
}

void Intro()
{
	cout << "You find youself in a dungeon wielding a sword and a shield..." << endl;
	system("pause");
	system("cls");
	cout << "You look around and see a boss gate a small distance ahead of you and a small dark cove to your right..." << endl;
	cout << "What do you do?" << endl;
	cout << "(1)Check the boss gate (2)Inspect the cove" << endl;

	bool pendant = false;
	int userInput = 0;
	cin >> userInput;
	
	while (userInput != 1 && userInput != 2)
	{
		cout << "Not an option... Try again..." << endl;
		cin >> userInput;
	}
	if (userInput == 1)
	{
		system("cls");
		cout << "You decide to ignore the cove and head straight for the boss gate." << endl;
	}
	else if (userInput == 2)
	{
		system("cls");


		cout << "You decide to inspect the dark cove." << endl;
		system("pause");

		cout << "While looking around the cove, you find a rose gold pendant with a sapphire shaded stone lodged within..." << endl;
		cout << "You add it to your inventory..." << endl;
		pendant = true;
		system("pause");

		system("cls");
		cout << "You don't find anything else in the cove..." << endl;
		cout << "You decide to move on towards the boss gate..." << endl;

	}
}

void StatOverview(int num1, int num2)
{
	cout << "Stat Overview" << endl;
	cout << "---------------------" << endl;
	cout << "Boss Hp:\t" << num1 << endl;
	cout << "Hero Hp:\t" << num2 << endl;
	system("pause");
	system("cls");
}

void bossMoves()
{
	int bossAtk = 2; // Boss stats
	int bossHp = 50;
	int heroHp = 20; // Player's health points
	int heroMp = 10;
	bool bossEnrage = false;

	enum BOSS_ACTIONS
	{
		NONE,

		ATTACK,
		CHARGED_ATTACK,
		HEAL,
		FLINCH,

		NUM_BOSS_ACTIONS,
	};

	StatOverview(bossHp, heroHp);

	while (bossHp > 0 && heroHp > 0)
	{
		srand(time(0)); // creates seed
		int bossAct = (rand() % 100) + 1;

		if (bossAct >= 1 && bossAct <= 66)
		{
			bossAct = 1;
		}
		else if (bossAct >= 67 && bossAct <= 89)
		{
			bossAct = 2;

		}
		else if (bossAct >= 90 && bossAct <= 98)
		{
			bossAct = 3;

		}
		else if (bossAct >= 99 && bossAct <= 100)
		{
			bossAct = 4;
		}

		switch (bossAct)
		{
		case ATTACK:
		{
			cout << "[The Boss attacked the player normally...]" << endl;
			heroHp -= bossAtk;
			break;
		}
		case CHARGED_ATTACK:
		{
			cout << "[The Boss attacked the player fiercly...]" << endl;
			heroHp -= (bossAtk + 1);
			break;
		}
		case HEAL:
		{
			cout << "[The boss recovered some of its HP]" << endl;
			if (bossHp < 50)
			{
				bossHp += 5;
			}
			else if (bossHp >= 50)
			{
				bossHp = 50;
			}
			break;
		}
		case FLINCH:
		{
			cout << "[The Boss flinched and couldn't do anything]" << endl;
			break;
		}
		}

		StatOverview(bossHp, heroHp);

	}

	if (heroHp == 0)
	{
		cout << "You have died..." << endl;
	}
	else if (bossHp == 0)
	{
		cout << "You have killed the boss" << endl;
	}
}
