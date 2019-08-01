//**********************************************************************
//Name: Daniel Beckerich
//Date: 2/15/2017
//Description: The program promps the user to enter a number of Quarters, Dimes, and Nickles; 
//the program then returns the amount of pennies that equates too.
//**********************************************************************

#include <iostream>

using namespace std;

int main() {
	//These variables are used to store the amount of change the user will input
	int quarters, dimes, nickles, pennies = 0;
	
	//these constants are use to hold the amount of pennies per coin.
	const int QUARTERVAL = 25;
	const int DIMEVAL = 10;
	const int NICKLEVAL = 5;
	
	//prompt the user to enter the amount of change
	cout << "Please enter the amount of Quarters, Dimes, and Nickles to be converted to pennies: ";
	
	//store the input
	cin >> quarters >> dimes >> nickles;
	cout << endl;
	
	//calculate the amount of pennies
	pennies = (quarters * QUARTERVAL) + (dimes * DIMEVAL) + (nickles * NICKLEVAL);
	
	//output the information
	cout << quarters << " quarters " << dimes << " dimes " << nickles << " and nickles equates to " << pennies << " pennies" << endl;

	//pause the consol
	system("pause");
	return 0;
}