//written by Daniel Beckerich
//on 11:37 3/11/2017
//takes a two part co-ordinate and converts the letter portion to a number

#include <iostream>
#include <string>

using namespace std;

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
	
	
	
	cout << checkForShips(populated) << endl;
	cout << checkForShips(populated) << endl;
	
	system("pause");
	return 0;
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