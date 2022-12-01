#include <iostream>

using namespace std;

struct color
{
	float r[3];
	float g[3];
	float b[3];
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

	//Objects
		//Structs
		
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


	phone myPhone1;
	myPhone1.name = "Samsung";
	myPhone1.model = "S10";
	myPhone1.year = 2019;
	myPhone1.screenSize = 5.2;

	cout << myPhone1.name << endl;
	cout << myPhone1.model << endl;
	cout << myPhone1.year << endl;
	cout << myPhone1.screenSize << endl;
	cout << endl;

	phone myPhone2;
	myPhone2.name = "Lenovo";
	myPhone2.model = "5 iii";
	myPhone2.year = 2021;
	myPhone2.screenSize = 5.1;

	cout << myPhone2.name << endl;
	cout << myPhone2.model << endl;
	cout << myPhone2.year << endl;
	cout << myPhone2.screenSize << endl;
	cout << endl;

	vehicle carolla = {2.55f, 8.7f, 5.1f,
						2.55f, 8.7f, 5.1f,
						2.55f, 8.7f, 5.1f, "Honda", 5, 2015, 250};

	return 0;
}
