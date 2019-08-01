//************************************************
//Created By Daniel Beckerich
//9:44 PM 2/5/2017
//This program is the Solution to Exercise 4 in chapter 4
//The user may enter the name of a shape, and some information and the program will return calculations based on what was entered
//************************************************

//inport the things we will need
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

//we use the namespace std so we dont have to type as much
using namespace std;

int main() {
	//declare all the variables, plus our constant
	string shape;
	double height;
	double width;
	double length;
	double radius;
	const double PI = 3.1416;
	
	// prompt the user to make a selection
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter the shape type: (rectangle, circle, cylinder) ";
	cin >> shape;
	cout << endl;
	//make 
	if (shape == "rectangle") {
		//get the width of the recragle 
		cout << "enter the width of the rectangle: ";
		cin >> width;
		cout << endl;
		//get the length of the rectangle
		cout << "enter the length of the rectangle: ";
		cin >> length;
		cout << endl;
		//make the calculation and output the information
		cout << "the perimeter of the rectangle = " << 2 * (length + width) << endl;
		cout << "the are of the rectangle = " << (length * width) << endl;
	}

	else if (shape == "cylinder") {
		//get the radius of the cylinders base
		cout << "enter the radius of the base of the cylinder: ";
		cin >> radius;
		cout << endl;
		//get the hight of the cylinder
		cout << "enter the height of the cylinder: ";
		cin >> height;
		cout << endl;
		//calculate and output the information
		cout << "the volume of the cylinder = " << (PI * pow(radius, 2) * height) << endl;
		cout << "the surface area of the cylinder = " << (2 * PI * radius * height + 2 * PI * pow(radius, 2)) << endl;
	}
	else if (shape == "circle") {
		//get the radius of the circle
		cout << "enter the radius of the circle: ";
		cin >> radius;
		//make the calculation and output the data
		cout << "the area of the circle = " << (PI * pow(radius, 2)) << endl;
		cout << "the circumference of the circle = " << (2 * PI * radius) << endl;
	}

	else {
		cout << "the program does not handle " << shape << endl;
	}
		
	system("pause");
	return 0;
}