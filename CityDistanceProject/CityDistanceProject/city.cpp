//basic method for holding data. could have used a struct, but oh well.
#include "city.h"

//empty constructor
city::city() {
	name = "";
    latitude = 0;
    longitude = 0;
}

//populated constructor
city::city(string newName, double newLat, double newLong) {
	name = newName;
	latitude = newLat;
	longitude = newLong;
}

//set and get method
string city::getname() {
	return name;
}
double city::getlat() {
	return latitude;
}
double city::getlong() {
	return longitude;
}

void city::setname(double newName) {
	name = newName;
}
void city::setlat(double newlat) {
	latitude = newlat;
}
void city::setlong(double newlong) {
	longitude = newlong;
}