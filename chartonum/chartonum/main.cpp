//written by Daniel Beckerich
//on 11:37 3/11/2017
//takes a two part co-ordinate and converts the letter portion to a number

#include <iostream>
#include <string>

using namespace std;

int coordsToNum(string Input);
bool checkForShips(char board);

int main() {
	
	char populated[10][10] = {
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', 'B', 'B', 'B', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', 'B', 'B', 'B', 'B', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', 'B', 'B', 'B', 'B', 'B', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', 'B', },
		{ '-', 'B', 'B', 'B', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', }
	};

	char blank[10][10] = {
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', }
	};
	
	
	/*string input;
	cin >> input;
	cout << coordsToNum(input) << endl; */
	
	cout << checkForShips(populated) << endl;
	cout << checkForShips(populated) << endl;
	
	system("pause");
	return 0;
}

int coordsToNum(string Input) {
	//returns a integer converted from a char. the ascii num for 'a' starts at 97
	//to convert, subtract the char value from 97, this returns 0
	//add 1 because there is no 0 position in battleship
	return ((tolower(Input[0]) - 97) + 1);
}

bool checkForShip(char board) {
	//this is set by to false, and will be swiched to true if there are and boats.
	bool IsBoats = fsalse;
	
	//itereate through the rows
	for (unsigned int ROWS = 0; ROWS < 10; ROWS++) {

		//and colums
		for (unsigned int COL = 0; COL < 10; COL++) {
			
			//if there are any B's in the array set IsBoats to true and break out of the col loop
			if (board[ROWS][COL] == "B") {
				IsBoats = true;
				break;
			}
		}
		//again, if there is a boat, break out of the rows loop
		if (IsBoats) break;
	}
	//at the end, return IsBoats
	return IsBoats;
}