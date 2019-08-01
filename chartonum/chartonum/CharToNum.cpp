//written by Daniel Beckerich
//on 11:37 3/11/2017
//takes a two part co-ordinate and converts the letter portion to a number

#include <iostream>
#include <string>

using namespace std;

int coordsToNum(string Input);

int main() {
	string input;
	cin >> input;
	cout << coordsToNum(input) << endl;
	system("pause");
	return 0;
}

int coordsToNum(string Input) {
	//returns a integer converted from a char. the ascii num for 'a' starts at 97
	//to convert, subtract the char value from 97, this returns 0
	//add 1 because there is no 0 position in battleship
	return ((tolower(Input[0]) - 97) + 1);
}
