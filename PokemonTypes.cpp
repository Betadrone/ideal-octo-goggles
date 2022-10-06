#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	cout << "Walkthrough 4" << endl;


	int elementChoice = 0;


	cout << "Choose one of the following six elements:\n";
	
	// Give all of the pokemon types as an option 
	
	cout << "\t1) Fire" << endl;
	cout << "\t2) Water" << endl;
	cout << "\t3) Ground" << endl;
	cout << "\t4) Flying" << endl;
	cout << "\t5) Steel" << endl;
	cout << "\t6) Dark" << endl;
	cout << "\t7) Normal" << endl;
	cout << "\t8) Electric" << endl;
	cout << "\t9) Grass" << endl;
	cout << "\t10) Ice" << endl;
	cout << "\t11) Fighting" << endl;
	cout << "\t12) Poison" << endl;
	cout << "\t13) Psychic" << endl;
	cout << "\t14) Bug" << endl;
	cout << "\t15) Rock" << endl;
	cout << "\t16) Ghost" << endl;
	cout << "\t17) Dragon" << endl;
	cout << "\t18) Fairy" << endl;


	cin >> elementChoice;

	enum ELEMENT_TYPES

	{

		NONE,

		FIRE,

		WATER,

		GROUND,

		FLYING,

		STEEL,

		DARK,

		NORMAL,

		ELECTRIC,

		GRASS,

		ICE,

		FIGHTING,

		POISON,

		PSYCHIC,

		BUG,

		ROCK,

		GHOST,

		DRAGON,

		FAIRY,



		NUM_ELEMENTS

	};

	switch (elementChoice)
	{
	case FIRE: //Fire
	{
		cout << "You chose fire, I chose water" << endl;
		break;
	}
	case WATER: //Water
	{
		cout << "You chose water, I chose ground" << endl;
		break;
	}
	case GROUND: // Earth
	{
		cout << "You chose ground, I chose steel" << endl;
		break;
	}
	case FLYING:
	{
		cout << "You chose flying, I chose ground" << endl;
		break;
	}
	case STEEL:
	{
		cout << "You chose steel, I chose fire" << endl;
		break;
	}
	case DARK:
	{
		cout << "You chose dark, I chose steel" << endl;
		break;
	}
	case NORMAL:
	{
		//statement
		break;
	}
	case ELECTRIC:
	{
		//statement
		break;
	}
	case GRASS:
	{
		//statement
		break;
	}
	case ICE:
	{
		//statement
		break;
	}
	case FIGHTING:
	{
		//statement
		break;
	}
	case POISON:
	{
		//statement
		break;
	}
	case PSYCHIC:
	{
		//statement
		break;
	}
	case BUG:
	{
		//statement
		break;
	}
	case ROCK:
	{
		//statement
		break;
	}
	case GHOST:
	{
		//statement
		break;
	}
	case DRAGON:
	{
		//statement
		break;
	}
	case FAIRY:
	{
		//statement
		break;
	}

	}

	return 0;
  
