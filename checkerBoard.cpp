//Muhammad Ashhad
//problemSolving5a
//November 1st, 2022
#include <iostream>

using namespace std; //(syntax) there was a space between "name" and "space" when it has to be one word

int main() //(syntax) was missing parentheses
{
	cout << "Welcome to Lab5a, where we will be debugging and fixing broken code..." << endl; //(syntax) was missing a semi-colon

	int userValX = 0;
	int userValY = 0;

	while (userValX != -1 && userValY != -1)
	{
		// print out the top header (column numbers) from 1-8
		cout << "    ";

		for (int i = 1; i <= 8; i++) //(logical) i-- was changed to i++
		{
			cout << i << "  "; //(syntax) had >> instead of <<
		}
		cout << endl;

		//print out the table
		//(logical) switched all x with y and vice versa in the following code
		for (int y = 1; y <= 8; y++) //(syntax) where the second semi-colon is, there was an apostrophe initially. (logical) changed = to <=
		{
			// print out the row number
			cout << y << "  ";

				for (int x = 1; x <= 8; x++)
				{

					// create a checkerboard like pattern with the background colours
					if ((x + y) % 2 == 1) //(logical) changed "== 2" into "== 1"
					{
						cout << "\033[44m"; // changes the background colour to blue output
					}
					else
					{
						cout << "\033[45m"; // changes the background colour to purple output
					}

					if (userValX == x && userValY == y)
					{
						cout << " X "; // mark the spot with an X
						cout << "\033[0m"; // added this line of code to stop the color from bleeding onto the next line.
					} //(syntax) was missing a semi-colon before this curly bracket
					else
					{
						cout << "   "; // just put an empty space for the tile.
						cout << "\033[0m"; // changes the color to green output
					}
				}

			cout << endl; //There was a typo. "end" was writtin when it's supposed to be "endl"
		}

		cout << endl << endl; //(syntax) there was a >> instead of a <<

		// prompt the user for X location
		cout << "Please enter an X location in the table to place your character:" << endl;
		cin >> userValX;

		cout << "Please enter a Y location in the table to place your character:" << endl;
		cin >> userValY;

		system("cls"); // clears the screen
	}

	return 0; //(logical) this "return 0" was missing
  
} //(syntax) This ending parenthese was missing for the "int main" function
