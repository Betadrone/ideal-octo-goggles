// Muhammad Ashhad - Muhammad Asjad 
// November 2, 2022 
// ProblemSolving5b

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <windows.h>

using namespace std;

// Global variables
int playerChoice = 0;
int userInput = 0;
int bossAtk = 2; // Boss stats
int heroMp = 10;
unsigned int mp = 10; //Initial magic points
float bossHpf = 50.0f;
float heroHpf = 20.0f;
float chargeAtk = 4.5f;
bool bossEnrage = false;
bool repeat = false;
bool pendant = false;
bool shield = false;
bool charge = false;
bool skipBoss = false;
bool run = false;

//
void Intro();
void gameplay();
void GiveOptions();
void ManaOptions();
void lowMana();
void Shieldtxt();
float stats(float heroH, float bossH, int heroM, bool rage);

// Main Function 
int main()
{

	cout << "Hello user..." << endl;
	
	Sleep(1500);

	cout << "Would you like to play a text-based dungeon boss fight?" << endl;
	cout << "(1) Yes (2) No" << endl;
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
		gameplay();

		if (heroHpf <= 0 && pendant == false)
		{
			cout << "You have died..." << endl;
			cout << "You have lost this adventure..." << endl;
		}
		else if (bossHpf <= 0)
		{
			cout << "You have killed the boss" << endl;
			cout << "You have won this adventure" << endl;
		}
		else if (heroHpf <= 0 && pendant == true)
		{
			cout << "You have died..." << endl;
			system("pause");
			system("cls");

			cout << "But wait..." << endl;
			cout << "The pendant begins to react with your lifeless body!" << endl;
			system("pause");
			system("cls");

			cout << "The pendant disappears and in its place you are revived" << endl;
			system("pause");
			system("cls");

			pendant = false;
			heroHpf += 10;
			mp = 10;

			gameplay();

			if (heroHpf <= 0 && pendant == false)
			{
				cout << "You have died..." << endl;
				cout << "You have lost this adventure..." << endl;
			}
			else if (bossHpf <= 0)
			{
				cout << "You have killed the boss" << endl;
				cout << "You have won this adventure" << endl;
			}
		}
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
	system("pause");
	system("cls");

	cout << "As soon as you get close to the gate, it glows brightly and you find yourself teleported in front of an Orc like being" << endl;
	system("pause");
	system("cls");

	cout << "You realize it's the boss..." << endl;
	cout << "The boss let's out a war cry upon laying eyes on you..." << endl;
	Sleep(1500);
	cout << "Should you engage in battle? (yes or no)" << endl;
	string ans;
	if ((ans == "Yes" || ans == "yes"))
	{
		cout << "You face off with the boss head-on" << endl;
	}
	else
	{
		cout << "You couldn't escape..." << endl;
	}
}

float stats(float heroH, float bossH, int heroM, bool rage)
{
	// Got the color codes from: https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
	cout << "Stat Overview" << endl;
	cout << "---------------------" << endl;
	if (bossH <= 0)
	{
		cout << "\u001b[47m" << "  " << "\u001b[40m" << " Boss Hp: " << bossH << "/50 " << "\u001b[47m" << "  " << "\u001b[40m" << endl;
	}
	else if (rage == true)
	{
		cout << "\u001b[46m" << "  " << "\u001b[40m" << " Boss Hp: " << bossH << "/50 " << "\u001b[46m" << "  " << "\u001b[40m" << endl;
	}
	else // Magenta color next to hp
	{
		cout << "\u001b[45m" << "  " << "\u001b[40m" << " Boss Hp: " << bossH << "/50 " << "\u001b[45m" << "  " << "\u001b[40m" << endl;
	}

	cout << endl;
	//cout << "Hero Hp:\t" << num2 << endl;

	if (heroH >= 11) // Green color next to hp
	{
		cout << "\u001b[42m" << "  " << "\u001b[40m" << " Hp: " << heroH << "/20 " << "\u001b[42m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroH >= 10) // This is a repeat of the next else if statement, but does not include an extra space after the /20
	{
		cout << "\u001b[43m" << "  " << "\u001b[40m" << " Hp: " << heroH << "/20 " << "\u001b[43m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroH >= 6) // Yellow colour next to hp
	{
		cout << "\u001b[43m" << "  " << "\u001b[40m" << " Hp: " << heroH << "/20  " << "\u001b[43m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroH > 0) // Red colour next to hp
	{
		cout << "\u001b[41m" << "  " << "\u001b[40m" << " Hp: " << heroH << "/20  " << "\u001b[41m" << "  " << "\u001b[40m" << endl;
	}
	else // White color next to hp
	{
		cout << "\u001b[47m" << "  " << "\u001b[40m" << " Hp: " << heroH << "/20  " << "\u001b[47m" << "  " << "\u001b[40m" << endl;
	}

	if (heroM == 10) // Blue color next to mp
	{
		cout << "\u001b[44m" << "  " << "\u001b[40m" << " Mp: " << heroM << "/10 " << "\u001b[44m" << "  " << "\u001b[40m" << endl;
	}
	else if (heroM > 0) // Also a blue color next to mp, but added an extra space so that the colors stay aligned to the hp color.
	{
		cout << "\u001b[44m" << "  " << "\u001b[40m" << " Mp: " << heroM << "/10  " << "\u001b[44m" << "  " << "\u001b[40m" << endl;
	}
	else // White color next to mp, to indicate that the player no longer has mp
	{
		cout << "\u001b[47m" << "  " << "\u001b[40m" << " Mp: " << heroM << "/10  " << "\u001b[47m" << "  " << "\u001b[40m" << endl;
	}
	return 0;
}


void gameplay()
{

	enum MOVES //This is for the options first presented to the pl
	{
		ATTACK = 1,
		DEFEND,
		MAGIC,
		RUN,   // This will act as a Setinel Value

		NUM_MOVES,
	};

	enum CHOICE
	{
		ENCHANT = 1,
		DISABLE,
		HEAL,

		NUM_MAGIC,
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


	for (int i = 0; run == false && heroHpf > 0.0f && bossHpf > 0.0f; i++) // i is the temporary integer we will be using as a turn counter 
	{
		//Hero attacks
		do
		{
			cout << "Turn: " << i << endl;
			stats(heroHpf, bossHpf, mp, bossEnrage);

			repeat = false;
			shield = false;

			GiveOptions();
			cin >> playerChoice;
			system("cls");
			switch (playerChoice)
			{

			case ATTACK:
			{
				cout << "Player Attacks! +2 Atk" << endl;
				bossHpf -= 2;
				break;
			}

			case DEFEND:
			{
				cout << "You raise your shield!" << endl;
				shield = true;
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
					if (mp >= 2)
					{
						cout << "Player enchants his sword and Attacks! +5 Atk" << endl;
						mp -= 2;
						bossHpf -= 5;
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
					if (mp >= 4)
					{
						cout << "Player restrains the monster for one turn!" << endl;
						mp -= 4;
						skipBoss = true;

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
					if (mp >= 4 && heroHpf <= 19)
					{
						cout << "Player recovers +10 hp!" << endl;
						mp -= 4;
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
				run = true;
				break;
			}

			default:
			{
				repeat = true;
				break;
			}
			}
		} while (repeat == true);

		if (run == true)
		{
			cout << "You got away Safely" << endl;
		}
		else if (bossHpf <= 0.0f)
		{

		}
		else
		{
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
			else if (bossAct >= 90 && bossAct <= 91)
			{
				bossAct = 3;

			}
			else if (bossAct >= 92 && bossAct <= 100)
			{
				bossAct = 4;
			}

			if (skipBoss == true)
			{
				charge = false;
				skipBoss = false;
			}
			else if (charge == true)    // This is for the boss' charge Attack. It's normal attacks will not be available. 
			{
				if (shield == true)
				{
					if (bossEnrage == false)
					{
						cout << "[The Boss attacked fiercly...]" << endl;
						cout << "[Boss dealt 2.25 dmg]" << endl;
					}
					else if (bossEnrage == true)
					{
						cout << "[The Boss attacked fiercly...]" << endl;
						cout << "[Boss dealt 4.5 dmg]" << endl;
					}
					heroHpf -= chargeAtk / 2;
					Shieldtxt();
					cout << "-" << chargeAtk / 2 << " Hp" << endl;
				}
				else
				{
					if (bossEnrage == false)
					{
						cout << "[The Boss attacked fiercly...]" << endl;
						cout << "[Boss dealt 4.5 dmg]" << endl;
					}
					else if (bossEnrage == true)
					{
						cout << "[The Boss attacked fiercly...]" << endl;
						cout << "[Boss dealt 9 dmg]" << endl;
					}
					heroHpf -= chargeAtk;
				}
				charge = false;
			}
			else
			{
				switch (bossAct)
				{
				case BOSS_ATTACK:
				{
					if (bossEnrage == false)
					{
						cout << "[The Boss attacked the player normally...]" << endl;
						cout << "[Boss dealt 2 dmg]" << endl;
					}
					else if (bossEnrage == true)
					{
						cout << "[The Boss attacked the player normally...]" << endl;
						cout << "[Boss dealt 4 dmg]" << endl;
					}

					if (shield == true)
					{
						heroHpf -= (bossAtk / 2);
						Shieldtxt();
						cout << "-" << bossAtk / 2 << " Hp" << endl;
					}
					else
					{
						heroHpf -= bossAtk;
					}
					break;
				}
				case CHARGED_ATTACK:
				{
					cout << "[The Boss readies himself for smiting...]" << endl;
					charge = true;
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
			}

			if (bossHpf <= 20 && bossEnrage == false)
			{
				system("cls");
				bossEnrage = true;
				cout << "Boss has become enraged" << endl;
				chargeAtk *= 2;
				bossAtk *= 2;

				system("pause");
			}
		}
	}
}

void GiveOptions()
{
	cout << "Please choose a move:" << endl;
	cout << "[1] Attack         \t [3] Magic" << endl;
	cout << "[2] Defend [+1 Mp] \t [4] Run" << endl;
}
void ManaOptions()
{
	cout << "What will you do?" << endl;
	cout << "[1] Enchant [3 Mp] \t [3] Heal [4 Mp]" << endl;
	cout << "[2] Disable [4 Mp] \t [4] Back" << endl;
}
void lowMana()
{
	cout << "You do not have enough Mp!" << endl;
}
void Shieldtxt()
{
	cout << "Your shield was up!";
}
