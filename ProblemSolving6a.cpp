//Muhammad Ashhad
//November 15, 2022
//ProblemSolving6a

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void LabIntro();
int RollDie();
int AddTwo(int num1, int num2);


int main()
{
	int answer = 0;
	int dieRoll = 0;

	srand(time(0));


	// [2%] create a void function which just prints this one line. Move the next line into the function and call the function here in it's place.
	LabIntro();

	// [3%] create a function called RollDie which holds the next line. This will return a random number between 1-6 (integer) but not take in any parameters:
	 // call the function and assign the results to dieRoll.
	dieRoll = RollDie();
	

	// [5%] create an AddTwo function which takes in two integers and returns an integer to replace the next line of code.
		// inside this function, add together the two integer parameters and return the results to applly to answer
	answer = AddTwo(7,2);

	cout << answer << endl;

	// [5%] Use the new AddTwo and pass in two RollDie() function calls you created above to rewrite the following code:
	answer = AddTwo(RollDie(),RollDie());

	cout << answer << endl;

	return 0;
}

void LabIntro()
{
	cout << "This is lab 6a" << endl;
}

int RollDie()
{
	int result = (rand() % 6) + 1;
	return result;
}

int AddTwo(int num1, int num2)
{
	int sum = 0;
	sum = num1 + num2;
	return sum;
}
