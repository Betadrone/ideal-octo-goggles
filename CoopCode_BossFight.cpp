// NOTE TO YOU: Delete this later, but please remember to add your comments. Could you also try to make a better message when you die/win?
//  Muhammad Ashhad - Muhammad Asjad
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
int playerChoice = 0; // used to determine what the player will choose to do on their turn
int userInput = 0;
int bossAtk = 2; // Boss stats
unsigned int mp = 10; // The amount of Mp the player has
float bossHpf = 50.0f;
float heroHpf = 20.0f; // The total Hp of the hero you play as
float chargeAtk = 4.5f;
bool bossEnrage = false;
bool repeat = false; // Used for the back button in the menu
bool pendant = false;
bool shield = false; // Used for when the player chooses the Defend option
bool charge = false;
bool skipBoss = false; // Used for when the player uses the Disable spell to stop the monster's next move
bool run = false; // Used for when the player chooses the Run option.

// functions being used aside from the main function
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
	system("Color 0F");	//Changes console text and background color, Got the system color command/codes from: https://www.geeksforgeeks.org/how-to-print-colored-text-in-c/
	cout << "Type -1 anywhere where possible to immediately end the program." << endl;
	system("pause");
	system("cls");

	// From here we are welcoming the user and asking them if they would like to play a game
	cout << "Hello user..." << endl;

	Sleep(1500);

	cout << "Would you like to play a text-based dungeon boss fight?" << endl; // prompting player
	cout << "(1) Yes (2) No" << endl;
	cin >> userInput;

	// -1 is a sentinel value to quit the program
	if (userInput == -1)
	{
		return 0;
	}

	// If user enters a value aside from the given options, they are prompted again
	while (userInput != 1 && userInput != 2)
	{
		cout << "Not an option... Try again..." << endl;
		cin >> userInput;
		if (userInput == -1) // sentinel value
		{
			return 0; // end program
		}
	}

	if (userInput == 1) // if 1 is entered, the main game is initiated
	{

		system("cls");

		Intro(); // intro function is called
		if (userInput == -1) // sentinel value
		{
			return 0; // end program
		}
		gameplay(); // call gameplay function 


		// after gameplay function
		if (heroHpf <= 0 && pendant == false) // if player dies without pendant, the losing text is printed
		{
			system("cls");
			system("Color 0E");
			stats(heroHpf, bossHpf, mp, bossEnrage);
			Sleep(1500);
			cout << "The boss senses that you are nearing your end..." << endl;
			cout << "He wants to end your pitiful life... and end your misery" << endl;
			cout << "In honour of the fierce match... He raises his sword... and pierces you through the heart..." << endl;
			system("pause");
			cout << "You notice your vision getting blurrier..." << endl;
			Sleep(500);
			cout << "You start losing the senses to your body..." << endl;
			Sleep(500);
			cout << "You slowly begin losing consciuousness..." << endl;
			Sleep(500);
			cout << "until...you realize..." << endl;
			Sleep(1000);
			cout << "You..." << endl;
			Sleep(1000);
			cout << "have died..." << endl;
			Sleep(1500);
			cout << "You have lost this adventure..." << endl;
		}
		else if (bossHpf <= 0) // if boss is killed, the winning text is printed
		{
			system("Color 0B");
			stats(heroHpf, bossHpf, mp, bossEnrage);
			Sleep(1500);
			cout << "You have dealt significant damage to the boss..." << endl;
			Sleep(500);
			cout << "He has never faced an enemy such as you..." << endl;
			Sleep(500);
			cout << "Blood profusely flows from the wounds all across his body...His breathing; slow yet heavy..." << endl;
			Sleep(500);
			cout << "Unwilling to yield, he remains standing tall..." << endl;
			Sleep(500);
			cout << "However... You notice him lower his sword to the ground... with eyes filled with satisfaction looking at you..." << endl;
			Sleep(500);
			cout << "He has accepted you to be his final opponent... You acknowledge his strength in return..." << endl;
			Sleep(500);
			cout << "You charge your sword... grab it at the hilt like a javelin... and you throw it towards his chest..." << endl;
			Sleep(500);
			cout << "Thus, piercing his heart..." << endl;
			Sleep(500);
			cout << "The boss slowly closes his eyes... His breathing stops..." << endl;
			Sleep(500);
			cout << "And the realization finally dawns on you..." << endl;
			Sleep(1000);
			cout << "You..." << endl;
			Sleep(1000);
			cout << "have killed the boss" << endl;
			Sleep(1500);
			cout << "You have won this adventure..." << endl;
		}
		else if (heroHpf <= 0 && pendant == true) // if player dies with pendant, the ressurection text is printed
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

			pendant = false; // pendant disappears

			// player is given 10 health and 10 mana
			heroHpf = 10;
			mp = 10;

			gameplay(); // fight is continued from where it left off

			if (heroHpf <= 0 && pendant == false) // text for when player finally dies
			{
				system("cls");
				system("Color 0E");
				stats(heroHpf, bossHpf, mp, bossEnrage);
				Sleep(1500);
				cout << "The boss senses that you are nearing your end..." << endl;
				cout << "He wants to end your pitiful life... and end your misery" << endl;
				cout << "In honour of the fierce match... He raises his sword... and pierces you through the heart..." << endl;
				system("pause");
				cout << "You notice your vision getting blurrier..." << endl;
				Sleep(500);
				cout << "You start losing the senses to your body..." << endl;
				Sleep(500);
				cout << "You slowly begin losing consciuousness..." << endl;
				Sleep(500);
				cout << "unti...you realize..." << endl;
				Sleep(500);
				cout << "You have died..." << endl;
				Sleep(1500);
				cout << "You have lost this adventure..." << endl;
			}
			else if (bossHpf <= 0) // text for when boss is finally killed
			{
				system("Color 0B");
				stats(heroHpf, bossHpf, mp, bossEnrage);
				Sleep(1500);
				cout << "You have dealt significant damage to the boss..." << endl;
				Sleep(500);
				cout << "He has never faced an enemy such as you..." << endl;
				Sleep(500);
				cout << "Blood profusely flows from the wounds all across his body...His breathing; slow yet heavy..." << endl;
				Sleep(500);
				cout << "Unwilling to yield, he remains standing tall..." << endl;
				Sleep(500);
				cout << "However... You notice him lower his sword to the ground... with eyes filled with satisfaction looking at you..." << endl;
				Sleep(500);
				cout << "He has accepted you to be his final opponent... You acknowledge his strength in return..." << endl;
				Sleep(500);
				cout << "You charge your sword... grab it at the hilt like a javelin... and you throw it towards his chest..." << endl;
				Sleep(500);
				cout << "Thus, piercing his heart..." << endl;
				Sleep(500);
				cout << "The boss slowly closes his eyes... His breathing stops..." << endl;
				Sleep(500);
				cout << "And the realization finally dawns on you..." << endl;
				Sleep(1000);
				cout << "You..." << endl;
				Sleep(1000);
				cout << "have killed the boss" << endl;
				Sleep(1500);
				cout << "You have won this adventure..." << endl;
			}
		}
	}
	else if (userInput == 2) // if 2 is entered, the user is given a farewell and program ends
	{
		cout << "Don't know what you are doing here then...\nEnjoy your day\nGoodbye.." << endl;
	}

	return 0; // end program
}

void Intro() // Text and prompt before the beginning of the boss fight (essentially choosing easy or hard mode)
{
	cout << "You find youself in a dungeon wielding a sword and a shield..." << endl;
	system("pause");
	system("cls");
	cout << "You look around and see a boss gate a small distance ahead of you and a small dark cove to your right..." << endl;
	cout << "What do you do?" << endl;
	cout << "(1) Check the boss gate (Hard Mode) (2) Inspect the cove (Easy Mode)" << endl;

	cin >> userInput;
	if (userInput == -1) // This is so that -1(Sentinel Value) can immediately end the program.
	{
		return;
	}
	while (userInput != 1 && userInput != 2) // to make sure that only the given options are entered and nothing else
	{
		cout << "Not an option... Try again..." << endl;
		cin >> userInput;
		if (userInput == -1)
		{
			return;
		}
	}
	if (userInput == 1) // if hard mode is chosen
	{
		system("cls");
		cout << "You decide to ignore the cove and head straight for the boss gate." << endl;
	}
	else if (userInput == 2) // if easy mode is chosen
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

	cout << "Should you engage in battle? (type Yes or No)" << endl; //prompt user for battle
	string ans;
	cin >> ans;
	if (ans == "Yes" || ans == "yes" || ans == "YES")
	{
		system("cls");
		cout << "You decide to face off with the boss head-on..." << endl;
		Sleep(1500);
	}
	else
	{
		system("cls");
		cout << "You couldn't escape..." << endl;
		Sleep(1500);
	}
}

float stats(float heroH, float bossH, int heroM, bool rage) // This will display and the Hp of both the player and the boss, with in addition to the player's Mp, the colors next to them
{
	// Got the color codes from: https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
	cout << "    Stat Overview" << endl;
	cout << "---------------------" << endl;
	if (bossH <= 0) // Boss' Hp and colors
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

	// Hero's Hp and colors
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

	// Hero's Mp and colors
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

	cout << endl;

	return 0;
}


void gameplay()
{

	enum MOVES // This is for the options first presented to the player
	{
		ATTACK = 1,
		DEFEND,
		MAGIC,
		RUN,   // This can act as a Setinel Value

		NUM_MOVES,
	};

	enum CHOICE // This is for the options that appear when the Magic option iis selected
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


	for (int turn = 0; run == false && heroHpf > 0.0f && bossHpf > 0.0f; turn++) // i is the temporary integer we will be using as a turn counter 
	{
		//Hero attacks
		do
		{
			cout << endl << "------ Turn: " << turn << " ------" << endl; // This is the turn counter
			stats(heroHpf, bossHpf, mp, bossEnrage);

			repeat = false;
			shield = false;

			GiveOptions(); // i.e the attack options
			cin >> playerChoice;
			if (playerChoice == -1) // this is specifically for the Sentinel Value
			{
				return;
			}
			system("cls");
			switch (playerChoice)
			{

			case ATTACK:
			{
				cout << "Player Attacks! +2 Atk" << endl;
				bossHpf -= 2;
				Sleep(250);
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
					cout << "+1 Mp!" << endl;
					mp++;
				}
				Sleep(250);
				break;
			}

			case MAGIC:
			{
				ManaOptions();
				cin >> playerChoice;
				system("cls");
				switch (playerChoice) // This is a sub-menu for the Magic option
				{

				case ENCHANT:
				{
					if (mp >= 2)
					{
						cout << "Player enchants his sword and Attacks! +5 Atk" << endl;
						mp -= 2;
						bossHpf -= 5;
						Sleep(250);
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
					if (mp >= 3)
					{
						cout << "Player restrains the monster for one turn!" << endl;
						mp -= 3;
						skipBoss = true;
						Sleep(250);

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
						Sleep(250);
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
				system("Color 0F");
				cout << "You miraculously find a chance to run away!" << endl;
				run = true;
				Sleep(250);
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
			cout << "You Got Away Safely" << endl;
		}
		else if (bossHpf <= 0.0f) // This code is here so that the boss can't attack once the player defeats it
		{
			system("cls");
		}
		else
		{
			//Boss attacks
			srand(time(0)); // creates seed
			int bossAct = (rand() % 100) + 1; // gives a random number to randomize boss moves

			if (bossAct >= 1 && bossAct <= 66) // 66% chance for boss to attack normally
			{
				bossAct = 1;
			}
			else if (bossAct >= 67 && bossAct <= 89) // 23% for boss to do a charged attack
			{
				bossAct = 2;

			}
			else if (bossAct >= 90 && bossAct <= 91) // 2% chance for boss to heal
			{
				bossAct = 3;

			}
			else if (bossAct >= 92 && bossAct <= 100) // 9% chance for boss to flinch
			{
				bossAct = 4;
			}

			if (skipBoss == true) // This is for when the player chooses the Disable option from the Magic menu. Meant to cancel the boss' next move.
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
						Shieldtxt();
						cout << "[Boss dealt 2.25 dmg]" << endl;
					}
					else if (bossEnrage == true)
					{
						cout << "[The Boss attacked fiercly...]" << endl;
						Shieldtxt();
						cout << "[Boss dealt 4.5 dmg]" << endl;
					}
					Sleep(500);
					heroHpf -= chargeAtk / 2;
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
					Sleep(500);
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
						if (shield == true)
						{
							Shieldtxt();
							cout << "[Boss dealt 1 dmg]" << endl;
						}
						else
						{
							cout << "[Boss dealt 2 dmg]" << endl;
						}
						Sleep(500);
					}
					else if (bossEnrage == true)
					{
						cout << "[The Boss attacked the player normally...]" << endl;
						if (shield == true)
						{
							Shieldtxt();
							cout << "[Boss dealt 2 dmg]" << endl;
						}
						else
						{
							cout << "[Boss dealt 4 dmg]" << endl;
						}
						Sleep(500);
					}

					if (shield == true)
					{
						heroHpf -= (bossAtk / 2);
					}
					else
					{
						heroHpf -= bossAtk;
					}
					break;
				}
				case CHARGED_ATTACK:
				{
					cout << "[The Boss readies himself for a powerful attack...]" << endl;
					charge = true;
					Sleep(500);
					break;
				}
				case BOSS_HEAL:
				{
					cout << "[The boss recovered some of its HP]" << endl;
					Sleep(500);
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
					Sleep(500);
					break;
				}
				}
			}

			if (bossHpf <= 20 && bossEnrage == false) // special text for informing player about boss becoming enraged
			{
				system("cls");
				Sleep(1500);
				bossEnrage = true;
				system("Color 04");
				cout << "Boss";
				Sleep(300);
				cout << " has";
				Sleep(300);
				cout << " become";
				Sleep(300);
				cout << " enraged" << endl;
				chargeAtk *= 2;
				bossAtk *= 2;

				Sleep(1500);
				system("pause");
				system("cls");
				system("Color 0C");
			}
		}
	}
}

void GiveOptions() // function for player actions
{
	cout << "Please choose a move:" << endl;
	cout << "[1] Attack [+2 Atk] \t [3] Magic" << endl;
	cout << "[2] Defend [+1 Mp]  \t [4] Run" << endl;
}
void ManaOptions() // function for player magic actions
{
	cout << "What will you do?" << endl << endl;
	cout << "[1] Enchant [+5 Atk, -2 Mp] \t [3] Heal [-4 Mp]" << endl;
	cout << "[2] Disable [-3 Mp]         \t [4] Back" << endl;
}
void lowMana() // function to print not enough mp
{
	cout << "You do not have enough Mp!" << endl;
}
void Shieldtxt() // function to print that player shield was up
{
	cout << "Your shield was up!" << endl;
}
