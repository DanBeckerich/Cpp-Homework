//programmed by Daniel Beckerich
//written on 6:38 3/8/2017
//this program generates a random number and allows the user to perform some functions on it
#include <iostream>
#include <string>
using namespace std;

//define our prototypes
void numDouble(int& num);
void numReverse(int& num);
void numSelectPow(int& num);
void numSum(int& num);
void numPow(int& num);
void num3digitPow(int& num);
void printMenuSelections();
bool menu(int& num, int selection);

int main() {
	//our first number
	int num = rand() % 100;
	//the user selection
	int selection;
	//and weather we should repeat or not
	bool repeat;
	//print the menu
	do {
		printMenuSelections();
		cin >> selection;
		//start the menu
		repeat = menu(num, selection);
		
	} while (repeat == true);
	cout << "the final value of num is equil to: " << num << endl;
	system("pause");
	return 0;
}

bool menu(int& num, int selection) {
	//our sentinel variable, used to do some checks befor we set the actual
	char repeat;
	
	//depending on which selection was made, perform the following function
	switch (selection)
	{
	case 1: numDouble(num); break;
	case 2: numReverse(num); break;
	case 3: numSelectPow(num); break;
	case 4: numSum(num); break;
	case 5: numPow(num); break;
	case 6:num3digitPow(num); break;
	default: 
		cout << "that was not a valid selection, please try again." << endl;
		break;
	}
	//print the new value of num
	cout << "the value of num is equil to: " << num << endl;

	//after the desired function has been performed, ask if the user wants to do another.
	cout << "would you like to perform another task? [Y/N]" << endl;
	cin >> repeat;

	//if they entered Y, then return true to go back to the top of the main loop
	if (tolower(repeat) == 'y') return true;
	else return false;

}

// double the number
void numDouble(int& num) {
	num = num * 2;
}

//reverse the digits
void numReverse(int& num) {
	// were going to cheat a little and convert it to a string so we can use std::reverse()
	//define a temp variable
	string temp;	
	//set our string to the correct number
	temp = num;
	//reverse it
	reverse(temp.begin(), temp.end());
	//and now back to a number. no messy math required.
	num = atoi(temp.c_str());
}

void numSum(int& num) {
	//were going to convert it to a string again, to make things easier.
	//our temp variable.
	string temp;
	int total = 0;
	//convert the number to a string.
	temp = num;
	//iterate through the temp string and total it up
	for (unsigned int i = 0; i < temp.length(); i++) {
		total = total + (temp[i] - 48); // the ascii value of the letter "0" is 48, and goes up to 57. all we need to do to convert a char to a number is subtract it from 48
	}
	//now set num to our total. because we passed num by reference, we dont need to return anything.
	num = total;
}

void numPow(int& num) {
	//more string trickery.
	string temp;
	temp = num;
	//this is used to hold the number after the math operator
	double doubleTemp;

	//check to make sure the number has exactly two digits.
	if (temp.length() == 2) {
		doubleTemp = pow(double(temp[0] - 48), double(temp[1] - 48));
		num = int(doubleTemp); //convert back to int and set num to the correct value
	}
	else cout << "The numbe is not two digits exactly!" << endl;
}

void numSelectPow(int& num) {
	//a temp variable
	double doubleTemp;
	//we are going to use this to hold the users selection.
	int selection;
	//get the selection
	cout << "Please enter the power you would like: ";
	cin >> selection;
	cout << endl;
	//aslong as we are either 2,3 or 4. perform the math. could have done it like numPow(), but decided to do it differntly
	if (selection > 1 && selection < 5) {
		doubleTemp = pow(double(num), double(selection));
		num = int(doubleTemp);
	}
	else cout << "that was not a valid selection!";

}
//this raises the first two 
void num3digitPow(int& num) {
	//going to use a string again
	string temp;
	temp = num;
	//we need another temp varaiable.
	double doubleTemp;

	//make sure the number is three digits.
	if (temp.length() == 3) {
		//make sure the last digit is less or equil to 4.
		if ((temp[0] - 48) <= 4) {
			//this one is quit tricky, we are getting the value of the third digits value and putting it in the 10's place
			//and putting the second digit in the 1's place. then raising it all to the power of the first digit.
			doubleTemp = pow(((temp[2] - 48) * 10) + (temp[1] - 48), (temp[0] - 48));
			//now the math is done, convert doubleTemp and set num
			num = int(doubleTemp);
		}
	}
}

void printMenuSelections() {
	//we are only printing the menu here.
	cout << "you can do any of the fallowing functions to the random number that has been generated." << endl;
	cout << "1. double the number" << endl;
	cout << "2. reverse the digits of the number" << endl;
	cout << "3. Raise the number to the power of 2, 3, or 4" << endl;
	cout << "4. Sum the digits:" << endl;
	cout << "5. if the number is two digits, raise the first number to the power of the third." << endl;
	cout << "6. if the number is three digits, riase the last two digits to the power of the first digit" << endl;
}