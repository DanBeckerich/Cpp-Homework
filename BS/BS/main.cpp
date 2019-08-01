#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

//all ship grids must be 10x10
const int SHIP_ROWS = 10;
const int SHIP_COLS = 10;

const int NUM_GRIDS = 5;

//struct must be declared before any functions that use it
struct shipGrid
{
	string name;
	char grid[SHIP_ROWS][SHIP_COLS];
};

//structs for player - AI will have  pre-filled fire sequence
struct player {
	string name;
	shipGrid playerGrid;
	int fireSeq[100];
};


int welcome();
char showGrid(shipGrid& structVar);
void makeStructs(char theGrid[SHIP_ROWS][SHIP_COLS], string gridName, shipGrid& structVar);
int getRandNum(int min, int max);
void makeFireSeq(player& inPlayer);

int main() {
	//generate new random seed
	srand(time(NULL));

	//ship grids
	char A1[10][10] = {
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

	char A2[10][10] = {
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', 'B', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', 'B', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', 'B', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', 'B', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', 'B', 'B', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', 'B', },
		{ '-', '-', '-', '-', 'B', 'B', 'B', '-', '-', '-', },
	};

	char A3[10][10] = {
		{ 'B', '-', 'B', 'B', 'B', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ 'B', '-', '-', '-', '-', '-', 'B', '-', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', 'B', '-', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', 'B', '-', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', 'B', '-', '-', 'B', },
		{ '-', '-', '-', '-', '-', '-', 'B', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
	};

	char A4[10][10] = {
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', 'B', 'B', 'B', 'B', 'B', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', 'B', 'B', 'B', 'B', '-', '-', '-', '-', },
		{ '-', 'B', '-', '-', '-', '-', 'B', '-', '-', '-', },
		{ '-', 'B', 'B', '-', '-', '-', 'B', '-', '-', '-', },
		{ '-', '-', 'B', '-', '-', '-', 'B', '-', '-', '-', },
		{ '-', '-', 'B', '-', '-', '-', '-', '-', '-', '-', },
	};

	char A5[10][10] = {
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', 'B', 'B', 'B', 'B', 'B', '-', },
		{ '-', '-', '-', '-', '-', '-', 'B', 'B', 'B', '-', },
		{ '-', '-', '-', 'B', 'B', 'B', 'B', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', '-', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', 'B', '-', '-', '-', '-', '-', '-', '-', },
		{ '-', '-', 'B', '-', '-', '-', 'B', '-', '-', '-', },
		{ '-', '-', 'B', '-', '-', '-', 'B', '-', '-', '-', },
	};


	bool quit = false;
	bool pickedGrid = false;



	shipGrid gridA1;
	shipGrid gridA2;
	shipGrid gridA3;
	shipGrid gridA4;
	shipGrid gridA5;

	//copy conents of arrays into structs
	makeStructs(A1, "A1", gridA1);
	makeStructs(A2, "A2", gridA2);
	makeStructs(A3, "A3", gridA3);
	makeStructs(A4, "A4", gridA4);
	makeStructs(A5, "A5", gridA5);

	shipGrid allShipGrids[NUM_GRIDS] = { gridA1, gridA2, gridA3, gridA4, gridA5 };

	int gridIndex = 0;


	player humanPlayer;
	player aiPlayer;

	humanPlayer.name = "human";
	aiPlayer.name = "computer";


	while (!quit) {


		switch (welcome()) {
		case 1:
			//randomly assign AI ship grid
			aiPlayer.playerGrid = allShipGrids[getRandNum(0, NUM_GRIDS)];
			//make firing sequence for AI
			makeFireSeq(aiPlayer);
			cout << "Play game:" << endl << endl;
			cout << "Player " << aiPlayer.name << " picked ship grid: " << aiPlayer.playerGrid.name << endl << endl;
			while (!pickedGrid) {

				if (showGrid(allShipGrids[gridIndex]) == 'y') {
					cout << "You choose " << allShipGrids[gridIndex].name << endl;
					humanPlayer.playerGrid = allShipGrids[gridIndex];
					pickedGrid = true;
				}
				gridIndex++;
				if (gridIndex > NUM_GRIDS - 1 && pickedGrid == false) {
					gridIndex = 0;
				}

			}

			break;
		case 9:
			cout << endl << "Thanks for playing" << endl;
			quit = 1;
			break;
		default:
			cout << "Invalid Selection" << endl;
		}
	}

	system("pause");

	return 0;
}

void makeStructs(char theGrid[SHIP_ROWS][SHIP_COLS], string gridName, shipGrid& structVar) {
	structVar.name = gridName;
	for (unsigned int i = 0; i < SHIP_ROWS; i++) {
		for (unsigned int j = 0; j < SHIP_ROWS; j++) {
			structVar.grid[i][j] = theGrid[i][j];
		}
	}


}

int welcome() {

	int choice;

	cout << "Welcome to Battleship - the ultimate duel at sea!" << endl;
	cout << "Choose an option:" << endl;
	cout << endl;
	cout << "1. Play" << endl;
	cout << "9. Quit" << endl;
	while (!(cin >> choice)) {
		choice = 0;
		cin.clear();
		cin.ignore(100, '\n');
	}

	return choice;

}


char showGrid(shipGrid& structVar) {
	char choice = 'n';
	cout << "------------Choose a grid------------" << endl << endl;
	cout << "This is grid " << structVar.name << endl << endl;
	for (unsigned int i = 0; i < SHIP_ROWS; i++) {
		for (unsigned int j = 0; j < SHIP_COLS; j++) {
			cout << structVar.grid[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << "Do you want to use this grid? (y for yes, n for no): ";
	cin >> choice;
	cout << endl;


	return tolower(choice);
}

int getRandNum(int min, int max) {
	return rand() % (min + max);
}

void makeFireSeq(player& inPlayer) {
	//generate vector of random numbers, 0-99
	//transalte vector of numbers to coordinates of 2-d array
	vector<int> sourceArray;
	vector<int> targetArray;
	int currRand;

	//make source vector
	for (int i = 0; i < 100; i++) {
		sourceArray.push_back(i);
	}





	//move to destination vector

	while (!sourceArray.empty()) {
		currRand = getRandNum(0, sourceArray.size());
		targetArray.push_back(sourceArray[currRand]);
		sourceArray.erase(sourceArray.begin() + currRand);

	}


	cout << "----------Making Firing Sequence-----------" << endl << endl;
	for (unsigned int x = 0; x < targetArray.size(); x++) {
		cout << targetArray[x] << " ";
		//translate destination vector into 2-d array

		int rowNum = targetArray[x] / 10;

		//select case on division for row num
		switch (targetArray[x] / 10)
		{
		case 0:
			break;
		default:
			break;
		}
	}

}