//written by Daniel Beckerich for DS&AII
//main loop for distance calculator
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "menu.h"

using namespace std;

int main(void) {

	menu currentMenu = menu();
	bool shouldExit = false;
	char selection = '0';

	//start with the menu
	while (!shouldExit) {
		cout << "***********************" << endl;
		cout << "* Distance Calculator *" << endl;
		cout << "***********************" << endl;
		cout << "1. Print the city list" << endl;
		cout << "2. A to B calculation" << endl;
		cout << "9. Exit" << endl;
		cout << "Enter your selection now: ";
		//get the user input and switch with it
		cin >> selection;
		cout << endl;

		switch (selection)
		{
		case '1': shouldExit = currentMenu.printCityListMenu(); break;
		case '2': shouldExit = currentMenu.calculationScreen(); break;
		case '9': shouldExit = true; break;
		default:
			system("cls");
			cout << "That was not a valid selection";
			break;
		}
	}

	//system("pause");
	return 0;
}