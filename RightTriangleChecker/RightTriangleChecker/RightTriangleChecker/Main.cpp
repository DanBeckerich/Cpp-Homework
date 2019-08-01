//********************************************************************************************************
//Description: Ask the user for the length of each side of a triangle, and check if it is a right triangle
//Programmer: Daniel Beckerich
//Date: 2:33PM 3/1/2017
//********************************************************************************************************

//get our libraries, and set the namepace
#include <iostream>
#include <math.h>

using namespace std;

//this function will check to see if its a right triangle. more on this later.
bool isRightTriangle(double len1, double len2, double len3);

int main() {
	//get our variables set up
	double num1, num2, num3;

	//prompt the user.
	cout << "Please enter the lengths of a triangle: ";
	//get the input
	cin >> num1 >> num2 >> num3;
	cout << endl;
	
	//check the data
	if (isRightTriangle(num1, num2, num3) == true)
		cout << "The triangle is a right triangle" << endl;
	else
		cout << "the triangle is not a right triangle." << endl;

	//pause the consol and return control
	system("pause");
	return 0;
}
//this function takes 3 numbers and checks to see if they make a right triangle
bool isRightTriangle(double len1, double len2, double len3) {
	
	//this is the main check
	if ((pow(len1, 2.0) == (pow(len2, 2.0) + pow(len3, 2.0))) || (pow(len2, 2.0) == (pow(len1, 2.0) + pow(len3, 2.0))) || (pow(len3, 2.0) == (pow(len2, 2.0) + pow(len1, 2.0))))
		return true; //if its a right triangle, return true
	else
		return false; //if not, return false.
}
