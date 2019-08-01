//writtten by Daniel Beckerich for DS&AII
//this class will handle all the operations of the menu system

#include "menu.h"

void menu::printCityList() {
	//loop through each populated element of the vector and print the information.
	cout << "Cities from West to east" << endl;
	for (int z = 0; z < cityVector.size(); z = z + 1) {
		cout << z + 1 << ": " << cityVector[z].getname() << endl;
	}
}

//this function will simply return a double value of the distance between two points on the earth.
double menu::calculateAtoB(double latA_d, double lonA_d, double latB_d, double lonB_d) {
	double const R = 6371; //Radius of the earth in km

	//convert all 4 numbers to radians
	double latA_r = latA_d * (M_PI / 180);
	double lonA_r = lonA_d * (M_PI / 180);

	double latB_r = latB_d * (M_PI / 180);
	double lonB_r = lonB_d * (M_PI / 180);

	//find the difference
	double dLat_r = latB_r - latA_r;
	double dLon_r = lonB_r - lonA_r;

	//make the calculation and return it.
	return 2 * R * (asin(sqrt(sin(dLat_r / 2) * sin(dLat_r / 2) + cos(latA_r) * cos(latB_r) * sin(dLon_r / 2) * sin(dLon_r / 2))));
}

//just to save some time, i put this in a method.
bool menu::exitCheck() {
	string selection;
	cout << endl << "Do you want to exit the program? (Y or N)";
	cin >> selection;
	return (selection == "Y" || selection == "y");
}
//this method actually handles the printing and user input
bool menu::calculationScreen() {
	int origin;
	int destenation;
	double total_distance = 0;
	double AtoB_distance = 0;
	bool shouldExit = false;
	
	//data intake and validation
	system("cls");
	while (!shouldExit) {
		cout << "Enter the ID of two cities below. start with the west most city. (e.g. \"1 2\")" << endl;
		printCityList();
		cin >> origin >> destenation;
		if ((origin > 0 & destenation < cityVector.size() + 1) & (origin < destenation)) {
			shouldExit = true;
		}
		else {
			shouldExit = false;
		}
	}
	
	//count through the vector of cities and to the calculation from city to city, and the total distance.
	for (int i = origin - 1; i < destenation - 1; i = i + 1) {

		AtoB_distance = calculateAtoB(cityVector[i].getlat(), cityVector[i].getlong(),
			cityVector[i + 1].getlat(), cityVector[i + 1].getlong());

		total_distance += AtoB_distance;

		cout << "the distance between " << cityVector[i].getname() << " and " << cityVector[i + 1].getname() << " is " << AtoB_distance << "km" << endl;

	}
	cout << "total distance from " << cityVector[origin - 1].getname() << " to " << cityVector[destenation - 1].getname() << " is " << total_distance << "km" << endl;
	return exitCheck();
}

//simple wrapper function to print the list of citys and ask if they wish to exit
bool menu::printCityListMenu() {
	system("cls");
	printCityList();
	return exitCheck();
}

menu::menu() {
	double tLat;
	double tLon;
	string tName;
	
	//define the name of the text file, and open it.
	fileName = "data.txt";
	textFile.open(fileName, ios::in);

	//read each line of the file, and write it into the vector
	while (!textFile.eof()) {
		textFile >> tName >> tLat >> tLon;
		cityVector.push_back(city::city(tName, tLat, tLon));
	}
	textFile.close();

}