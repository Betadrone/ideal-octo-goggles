//Muhammad Ashhad 
// November 16, 2022
//Walkthrough 8
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "Welcome to walkthrough 8" << endl;
	const int NUMPLAYER = 100;
	float playerGold[NUMPLAYER];
	playerGold[0] = 111.25f;
	playerGold[1] = 222.75f;
	playerGold[2] = 333.33f;
	playerGold[3] = 444.35f;
	playerGold[4] = 555.65f;
	playerGold[5] = 666.66f;

	cout << "player 1 gold is " << playerGold[1] << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "player[" << i << "] gold amount is " << playerGold[i] << endl;
	}


	cout << endl;

	int playerScores[NUMPLAYER];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		playerScores[i] = rand();
		cout << "playerScores[" << i << "] is " << playerScores[i] << endl;
	}

	cout << endl;

	int WeaponSlots[4] = {1,2,3,4};

	for (int i = 0; i < 10; i++)
	{
		cout << "weapon[" << i << "] is in slot " << WeaponSlots[i] << endl;
	}

	cout << endl;

	float teamGold = playerGold[1] + playerGold[2];
	cout << "The team's gold is " << teamGold << endl;

	char name[6] = { 'a','s','h','h','a','d' };
	for (int i = 0; i < 6; i++)
	{
		cout << name[i];
	}

	return 0;
}
