//***************************************************************
//description: checks to see if a char is a vowel
//programmer: Daniel Beckerich
//Date: 3:50pm 3/1/2017
//***************************************************************

//get our library and set the namespace
#include <iostream>
using namespace std;

//the prototype for our function
bool isVowel(char input);

int main() {
	//declare our variables
	char userInput;

	//get the data from the user
	cout << "please enter a character: ";
	cin >> userInput;
	cout << endl;

	//check to see if the character is a vowel or not, and print accordingly
	if (isVowel(userInput) == true)
		cout << "The character is a vowel" << endl;
	else
		cout << "The character is not a vowel" << endl;

	//pause the consol and return control
	system("pause");
	return 0;
}

bool isVowel(char input) {
	//make thr comparison
	if (tolower(input) == 'a' || tolower(input) == 'e' || tolower(input) == 'i' || tolower(input) == 'o' || tolower(input) == 'u')
		return true; //if it is a vowel, return true
	else
		return false;// if not, return false
}