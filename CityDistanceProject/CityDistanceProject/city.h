#include <iostream>
#include <string>
using namespace std;

class city
{
public:

	//set and get methods for our 3 variables
	string getname();
	double getlat();
	double getlong();

	void setname(double newName);
	void setlat(double newlat);
	void setlong(double newlong);

	//two differnet constructors. one empty, and one with data
	city();
	city(string newName, double newLat, double newLong);

//Variables to store information about the city
protected:
	string name;
	double latitude;
	double longitude;
};