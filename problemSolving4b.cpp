#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "Hello player. Please enter 10 values for accuracy on a target practice firing range:" << endl;

	float userShot = 0.0f;
	float total = 0.0f;
	for (int counter = 1; counter <= 10; counter++)
	{
		cin >> userShot;
		if (userShot < 0.0f || userShot > 100.0f)
		{
			cout << "You didn't enter a value within the range (0-100)... try again..." << endl;
			counter--;
		}
		else if (userShot >= 0.0f && userShot <= 100.0f)
		{
			cout << "you entered " << userShot << endl;
			total += userShot;
		}

		if (counter == 10)
		{
			cout << total / 10 << "% is your average accuracy." << endl;

			if (true) // change condition
			{

			}
			else if (false) // change condition
			{

			}
		}
	}

	return 0;
}
