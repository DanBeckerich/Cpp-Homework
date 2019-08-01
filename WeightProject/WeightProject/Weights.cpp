//************************
//Name: Daniel Beckerich
//Project Description: Weight converter. From lb to kg
//Time and Date: 6:08 PM 1/29/2017
//************************

//because we are using the consol for input and output, we need to inport iostream
#include <iostream>
#include <iomanip> //we will need this because we are formatting our output

//to make things easier we will use the namespace STD
using namespace std;

int main() {

	//declare the needed variables
	double totalLb = 0;
	double totalKg = 0;

	cout << "Please enter a weight in pounds to be converted to kilograms" << endl; //ask the user to enter the number of pounds that they wish to convert
	cin >> totalLb;

	totalKg = totalLb / 2.2; //make the conversion

	cout << "total pounds: " << setprecision(2) << totalLb << endl; //output the number of pounds again, at 2 decimal places.
	cout << "total kilograms: " << setprecision(2) << totalKg << endl; //and the same for kilograms

	system("pause");
	return 0;
}
