//This class is designed to manage the different menus

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "city.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class menu {
public:
	
	bool printCityListMenu();
	bool calculationScreen();

	menu();

protected:
	vector<city> cityVector;
	fstream textFile;
	string fileName;
	
	void printCityList();
	bool exitCheck();
	double calculateAtoB(double latA, double lonA, double latB, double lonB);
};