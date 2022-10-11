// Muhammad Ashhad
// 2022 - October - 05
// Walkthrough 4
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
 
cout << "Walktghrough 4" << endl;
 
 
int elementChoice = 0;
 
 
cout << "Choose one of the following six elements:\n";
 
cout << "\t1) Fire" << endl;
 
cout << "\t2) Water" << endl;
 
cout << "\t3) Ground" << endl;
 
cout << "\t4) Air" << endl;
 
cout << "\t5) Steel" << endl;
 
cout << "\t6) Dark" << endl;
 
 
cin >> elementChoice;
 
enum ELEMENT_CHOICES
 
{
 
NONE,
 
FIRE,
 
WATER,
 
GROUND,
 
AIR,
 
STEEL,
 
DARK,
 
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
 
case AIR:
 
{
 
cout << "You chose air, I chose ground" << endl;
 
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
 
}
 
return 0;
}
