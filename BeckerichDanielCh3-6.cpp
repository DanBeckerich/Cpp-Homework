//***********************************************************************************************************
//Name: Daniel Beckerich
//Date: 2/16/2017
//Description: this program loads in a file and calculates payroll information, then outputs the information
//***********************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	//get our input and output file names
	ifstream inFile;
	ofstream outFile;

	//declare the needed variables
	string firstName, lastName;
	double oldSalery, newSalery , raseAmount;

	//get our input file
	inFile.open("Ch3_Ex6Data.txt");
	outFile.open("midtermOutPut.txt");
	
	//set the formatting for the data output
	outFile << fixed << showpoint;
	outFile << setprecision(2);
	
	//check to see if it input correctly
	if(!inFile)
	{
		cout << "Cannot open the input file, the program will terminate." << endl;
		system("pause");
		return 1;
	}
	//keep looping until we reach the end of the text file
	while (!inFile.eof()) {
		
		//load the information
		inFile >> lastName >> firstName >> oldSalery >> raseAmount;
		
		//calulate the persons new salery
		newSalery = oldSalery * (1 + (raseAmount / 100));
		
		//output the information to the file
		outFile << firstName << " " << lastName << " " << newSalery << " " << endl;
	}
	//tell the user we are finished
	cout << "Calculations complete!" << endl;
	
	//close both our files
	inFile.close();
	outFile.close();
	
	//pause the consol
	system("pause");
	return 0;
}