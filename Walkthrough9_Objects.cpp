#include <iostream>

using namespace std;

struct color
{
	float r[3];
	float g[3];
	float b[3];
};

struct simpleColor
{
	int red = 0;
	int green = 0;
	int blue = 0;
};

struct vehicle
{
	color purple;
	string make = "Honda";
	short seats;
	int year;

	const float MAX_SPEED = 3;
};

struct phone
{
	string name;
	string model;
	int year;
	float screenSize;
};

class player
{
public:
	player()
	{
		cout << "You are adding a new player" << endl;

	}
	void DetermineInfo()
	{
		cout << "enter name:" << endl;
		cin >> name;
		cout << "enter age:" << endl;
		cin >> age;
		cout << "choose occupation:\n1) Warrior\n2) Mage" << endl;
		cin >> choice;
		if (choice == 1)
		{
			occupation = "Warrior";
		}
		else if (choice == 2)
		{
			occupation = "Mage";
		}
	}
	void PrintStats()
	{
		cout << "Stats" << endl;
		cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
		cout << name << endl;
		cout << age << endl;
		cout << occupation << endl;
	}
	void PrintName()
	{
		cout << name;
	}
	string weapon[3];
private:
	string name;
	int age = 0;
	int choice;
	string occupation;

};

class hero
{
public:
	hero()
	{
		cout << "You just made a hero..." << endl;
		damage = 5;
		defence = 1;
	};
	hero(int dmg, int def)
	{
		cout << "You created a hero..." << endl;
		damage = dmg;
		defence = def;
	};

	~hero()
	{
		cout << "Your hero has died..." << endl;
	};


	float X = 1.0f;
	float Y = 0.0f;

	void TakeDamage(int amount) { health -= amount; }
	void PrintHealth() { cout << "Health: " << health << endl; }
	void PrintStats()
	{ 
		cout << "Health: " << health << endl;
		cout << "Damage: " << damage << endl;
		cout << "Defence: " << defence << endl;
	}
	void SetDamage(int amount) { damage = amount; }
	void SetDefence(int amount) { defence = amount; }

private:
	int damage = 5;
	int defence = 1;
	float health = 100.0f;
};

void SetColor(color& rgbValue);
simpleColor getColor(int red, int green, int blue);


int main()
{
	cout << "Welcome to Walkthrough 9... Objects..." << endl;

	hero jefferey;
	jefferey.SetDamage(10);
	jefferey.SetDefence(7);
	jefferey.TakeDamage(10);
	cout << "Jefferey - ";
	jefferey.PrintStats();

	cout << endl;

	hero serena;
	serena.SetDamage(12);
	serena.SetDefence(5);
	serena.TakeDamage(12);
	cout << "Serena - ";
	serena.PrintStats();

	cout << endl;
		
	vehicle highlander;
	highlander.make = "Mitsubishi";
	highlander.seats = 7;
	highlander.year = 2012;

	cout << "highlander make is: " << highlander.make << endl;
	cout << "highlander year is: " << highlander.year << endl;
	cout << endl;

	vehicle camry;
	camry.make = "Toyota";
	camry.seats = 5;
	camry.year = 2016;

	cout << "camry make is: " << camry.make << endl;
	cout << "camry year is: " << camry.year << endl;
	cout << endl;


	vehicle civic;
	civic.year = 2013;
	civic.seats = 5;

	cout << "civic make is: " << civic.make << endl;
	cout << "civic year is: " << civic.year << endl;
	cout << endl;


	phone myPhone[2]; // array of objects
	myPhone[0].name = "Samsung";
	myPhone[0].model = "S10";
	myPhone[0].year = 2019;
	myPhone[0].screenSize = 5.2;

	cout << myPhone[0].name << endl;
	cout << myPhone[0].model << endl;
	cout << myPhone[0].year << endl;
	cout << myPhone[0].screenSize << endl;
	cout << endl;

	myPhone[1].name = "Lenovo";
	myPhone[1].model = "5 iii";
	myPhone[1].year = 2021;
	myPhone[1].screenSize = 5.1;

	cout << myPhone[1].name << endl;
	cout << myPhone[1].model << endl;
	cout << myPhone[1].year << endl;
	cout << myPhone[1].screenSize << endl;
	cout << endl;

	vehicle carolla = {2.55f, 8.7f, 5.1f,
						2.55f, 8.7f, 5.1f,
						2.55f, 8.7f, 5.1f, "Honda", 5, 2015, 250};

	color darkBlue;
	SetColor(darkBlue);

	simpleColor green = getColor(19,57,38);
	cout << "The rgb value of a shade of green is #" << green.red << green.green << green.blue << endl;

	player one;
	one.DetermineInfo();
	one.PrintStats();
	one.weapon[0] = "Sword";
	one.weapon[1] = "Shield";
	one.weapon[2] = "Bombs";

	one.PrintName();
	cout << " is wielding a " << one.weapon[0] << endl;

	return 0;
}

void SetColor(color& rgbValue)
{
	for (int ii = 0; ii < 3; ii++)
	{
		rgbValue.r[ii] = { 1.2f };
		rgbValue.g[ii] = { 2.4f };
		rgbValue.b[ii] = { 3.6f };
	}
	cout << "The rgb values of this color are set to:" << endl;
	for (int ii = 0; ii < 3; ii++)
	{
		cout << rgbValue.r[ii] << endl;
		cout << rgbValue.g[ii] << endl;
		cout << rgbValue.b[ii] << endl;
	}
}

simpleColor getColor(int red, int green, int blue)
{
	simpleColor newColor;

	newColor.red = red;
	newColor.green = green;
	newColor.blue = blue;

	return newColor;

}
