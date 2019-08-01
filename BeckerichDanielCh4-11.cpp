//***********************************************************
//Name: Daniel Beckerich
//Date: 2/15/2017
//Description: 

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	//delcare the needed variables
	double baseSalery, totalSales, commissionBonus, bonus, payCheck;
	int noOfServiceYears;

	//set the formatting
	cout << fixed << showpoint;
	cout << setprecision(2);

	//get the information
	cout << "Please enter the number of years that you have been employed at this company: ";
	cin >> noOfServiceYears;
	cout << endl;
	cout << "Please enter your base salery: ";
	cin >> baseSalery;
	cout << endl;
	cout << "Please enter the amount of sales made: ";
	cin >> totalSales;
	cout << endl;

	//determin the flat rate bonus amount
	if (noOfServiceYears <= 5)
		bonus = 10;
	else
		bonus = 20;
	
	//calculate the commission
	if (totalSales < 5000)
		commissionBonus = 0;
	
	else if (totalSales >= 5000 && totalSales < 10000)
		commissionBonus = totalSales * 0.03;
	
	else
		commissionBonus = totalSales * 0.06;
	
	//calculate the total paycheck
	payCheck = baseSalery + bonus + commissionBonus;

	//output the information
	cout << "Your Total paycheck is " << payCheck << " your bonus is " << bonus << " and you sailes commission is " << commissionBonus << endl;

	system("pause");
	return 0;

}