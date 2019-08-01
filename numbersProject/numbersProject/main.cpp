//************************************************************************
//description: ask the user to enter a number. and do some things wit hit
//programmer: Daniel Beckerich
//date: 3:06pm 3/1/2017
//************************************************************************

//get our needed librarys and set the namespace
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int main() {
	int userNum; //this holds the number from the user
	int total = 0; //this holds the total of all digits
	string userNumString; // this one holds the string that will be made from the input. to make things easier


	//get the number
	cout << "please enter a number: ";
	cin >> userNum;
	cout << endl;

	//convert the number to a string. we use ABS to make sure the number is positive
	userNumString = to_string(abs(userNum));

	//now that we have the string, time to do some math
	for (int i = 0; i < userNumString.length(); i = i + 1) {

		// each iteration, print the correct char
		cout << userNumString[i] << " ";

		//and add that char to the running total
		//because tpye casting like this returns the ascii value, it needs to be converted to its decimal value.
		total = ((total + (int) userNumString[i]) - 48);
	}

	//after we have printed all the digits and calculated our running total. time to print it
	cout << endl << total << endl;
	system("pause");
	return 0;
}