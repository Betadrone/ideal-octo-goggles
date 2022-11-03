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

int bossAtk = 2; // Boss stats
float bossHpf = 50;
int heroMp = 10;
bool bossEnrage = false;
int playerChoice = 0;
unsigned int mp = 10; //Initial magic points
bool repeat = false;
float heroHpf = 20;

void Intro();
void bossMoves();
void GiveOptions();
void ManaOptions();
void lowMana();


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
		bossMoves();
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

void StatOverview(float num1, float num2)
{
	cout << "Stat Overview" << endl;
	cout << "---------------------" << endl;
	// cout << "Boss Hp:\t" << num1 << endl;

	if (num1 >= 31) // Green color next to hp
	{
		cout << "\u001b[42m" << "  " << "\u001b[40m" << " Hp: " << num1 << "/50 " << "\u001b[42m" << "  " << "\u001b[40m" << endl;
	}
	else if (num1 >= 30) // This is a repeat of the next else if statement, but does not include an extra space after the /20
	{
		cout << "\u001b[43m" << "  " << "\u001b[40m" << " Hp: " << num1 << "/50 " << "\u001b[43m" << "  " << "\u001b[40m" << endl;
	}
	else if (num1 >= 15) // Yellow colour next to hp
	{
		cout << "\u001b[43m" << "  " << "\u001b[40m" << " Hp: " << num1 << "/50  " << "\u001b[43m" << "  " << "\u001b[40m" << endl;
	}
	else if (num1 > 0) // Red colour next to hp
	{
		cout << "\u001b[41m" << "  " << "\u001b[40m" << " Hp: " << num1 << "/50  " << "\u001b[41m" << "  " << "\u001b[40m" << endl;
	}
	else // White color next to hp
	{
		cout << "\u001b[47m" << "  " << "\u001b[40m" << " Hp: " << num1 << "/50  " << "\u001b[47m" << "  " << "\u001b[40m" << endl;
	}

	cout << endl;
	//cout << "Hero Hp:\t" << num2 << endl;
	
	if (heroHpf >= 11) // Green color next to hp
	{
		cout << "\u001b[42m" << "  " << "\u001b[40m" << " Hp: " << heroHpf << "/20 " << "\u001b[42m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroHpf >= 10) // This is a repeat of the next else if statement, but does not include an extra space after the /20
	{
		cout << "\u001b[43m" << "  " << "\u001b[40m" << " Hp: " << heroHpf << "/20 " << "\u001b[43m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroHpf >= 6) // Yellow colour next to hp
	{
		cout << "\u001b[43m" << "  " << "\u001b[40m" << " Hp: " << heroHpf << "/20  " << "\u001b[43m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroHpf > 0) // Red colour next to hp
	{
		cout << "\u001b[41m" << "  " << "\u001b[40m" << " Hp: " << heroHpf << "/20  " << "\u001b[41m" << "  " << "\u001b[40m" << endl;
	}
	else // White color next to hp
	{
		cout << "\u001b[47m" << "  " << "\u001b[40m" << " Hp: " << heroHpf << "/20  " << "\u001b[47m" << "  " << "\u001b[40m" << endl;
	}

	if (mp == 10) // Blue color next to mp
	{
		cout << "\u001b[44m" << "  " << "\u001b[40m" << " Mp: " << mp << "/10 " << "\u001b[44m" << "  " << "\u001b[40m" << endl;
	}
	else if (mp > 0) // Also a blue color next to mp, but added an extra space so that the colors stay aligned to the hp color.
	{
		cout << "\u001b[44m" << "  " << "\u001b[40m" << " Mp: " << mp << "/10  " << "\u001b[44m" << "  " << "\u001b[40m" << endl;
	}
	else // White color next to mp, to indicate that the player no longer has mp
	{
		cout << "\u001b[47m" << "  " << "\u001b[40m" << " Mp: " << mp << "/10  " << "\u001b[47m" << "  " << "\u001b[40m" << endl;
	}
	system("pause");
	system("cls");
}

void bossMoves()
{

		enum MOVES //This is for the options first presented to the pl
		{
			ATTACK = 1,
			DEFEND,
			MAGIC,
			RUN
		};

		enum CHOICE
		{
			ENCHANT = 1,
			DISABLE,
			HEAL
		};

		enum BOSS_ACTIONS
		{
			NONE,

			BOSS_ATTACK,
			CHARGED_ATTACK,
			BOSS_HEAL,
			FLINCH,

			NUM_BOSS_ACTIONS,
		};

	StatOverview(bossHpf, heroHpf);

	while (bossHpf > 0.0f && heroHpf > 0.0f)
	{

		//Hero attacks
		do
		{
			repeat = false;

			GiveOptions();
			cin >> playerChoice;
			system("cls");
			switch (playerChoice)
			{

			case ATTACK:
			{
				cout << "Player Attacks!" << endl;
				break;
			}

			case DEFEND:
			{
				cout << "Player Defends!" << endl;
				if (mp >= 10)
				{
					cout << "Your Mp is full!" << endl;
				}
				else
				{
					cout << "Recovered 1 Mp!" << endl;
					mp++;
				}
				break;
			}

			case MAGIC:
			{
				ManaOptions();
				cin >> playerChoice;
				system("cls");
				switch (playerChoice)
				{

				case ENCHANT:
				{
					if (mp >= 3)
					{
						cout << "Player enchants his sword and Attacks!" << endl;
						mp -= 3;
					}
					else
					{
						lowMana();
						repeat = true;
					}
					break;
				}

				case DISABLE:
				{
					if (mp >= 6)
					{
						cout << "Player restrains the monster for one turn!" << endl;
						mp -= 6;
					}
					else
					{
						lowMana();
						repeat = true;
					}
					break;
				}

				case HEAL:
				{
					if (mp >= 8 && heroHpf <= 19)
					{
						cout << "Player recovers +10 hp!" << endl;
						mp -= 8;
						heroHpf += 10;
						if (heroHpf >= 20)
						{
							heroHpf = 20;
							cout << "You have fully recovered!" << endl;
						}
					}
					else if (heroHpf == 20)
					{
						cout << "Your Hp is already full!" << endl;
						repeat = true;
						break;
					}
					else
					{
						lowMana();
						repeat = true;
					}
					break;

				}

				default:
				{
					repeat = true;
					break;
				}

				}
				break;
			}

			case RUN:
			{
				cout << "Player runs away!" << endl;
				break;
			}

			default:
			{
				repeat = true;
				break;
			}
			}
		} while (repeat == true);

		//Boss attacks
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
		case BOSS_ATTACK:
		{
			cout << "[The Boss attacked the player normally...]" << endl;
			heroHpf -= bossAtk;
			break;
		}
		case CHARGED_ATTACK:
		{
			cout << "[The Boss attacked the player fiercly...]" << endl;
			heroHpf -= (bossAtk + 1);
			break;
		}
		case BOSS_HEAL:
		{
			cout << "[The boss recovered some of its HP]" << endl;
			if (bossHpf < 50)
			{
				bossHpf += 5;
			}
			else if (bossHpf >= 50)
			{
				bossHpf = 50;
			}
			break;
		}
		case FLINCH:
		{
			cout << "[The Boss flinched and couldn't do anything]" << endl;
			break;
		}
		}

		
		StatOverview(bossHpf, heroHpf);

	}

	if (heroHpf <= 0 )
	{
		cout << "You have died..." << endl;
	}
	else if (bossHpf <= 0)
	{
		cout << "You have killed the boss" << endl;
	}
}
void GiveOptions()
{
	cout << "Please choose a move:" << endl;
	cout << "[1] Attack \t [3] Magic" << endl;
	cout << "[2] Defend \t [4] Run" << endl;
}
void ManaOptions()
{
	cout << "What will you do?" << endl;
	cout << "[1] Enchant \t [3] Heal" << endl;
	cout << "[2] Disable \t [4] Back" << endl;
}
void lowMana()
{
	cout << "You do not have enough Mp!" << endl;
}
