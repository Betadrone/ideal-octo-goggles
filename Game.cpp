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
	cout << "You look around and see a boss gate a small distance ahead of you and a small dark cove to your right..." << endl;
	cout << "What do you do?" << endl;
	cout << "(1)Check the boss gate (2)Inspect the cove" << endl;
	int userInput = 0;
	while (userInput != 1 && userInput != 2)
	{
		cout << "Not an option... Try again..." << endl;
		cin >> userInput;
	}
	if (userInput == 1)
	{

	}
	else if (userInput == 2)
	{

	}
}
