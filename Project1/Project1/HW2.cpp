//****************************************************************
//*Name: Daniel Beckerich                                        *
//*Date: 1/21/2017 8:15PM                                        *
//*Description: Print the text "C++" in an ascii art style font. *
//****************************************************************

//import iostream so we can print
#include <iostream>

//use std so we dont have to keep typing it
using namespace std;

int main()
{   //print the message
	cout << "CCCCCCCCCCC       ++               ++" << endl;
	cout << "CC                ++               ++" << endl;
	cout << "CC          ++++++++++++++   ++++++++++++++" << endl;
	cout << "CC          ++++++++++++++   ++++++++++++++" << endl;
	cout << "CC                ++               ++" << endl;
	cout << "CCCCCCCCCCC       ++               ++" << endl;

	//pause the consol so it does not close
	system("pause");
	
	//return control
	return 0;
}