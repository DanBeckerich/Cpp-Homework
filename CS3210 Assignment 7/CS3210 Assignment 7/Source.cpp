#include <iostream>
#include "list.cpp"

using namespace std;

SLL addTwoLists(SLL numA, SLL numB);

int main() {
	//create the three singly linked lists.
	SLL numA = SLL();
	SLL numB = SLL();
	SLL result = SLL();
	//provide instructions;
	cout << "enter two numbers to be added together." << endl;
	cout << "Enter 0 twice to exit" << endl;
	int raw0 = 1;
	int raw1 = 1;

	//each iteration
	while (true) {

		//wipe the 3 SLL's
		 numA = SLL();
		 numB = SLL();
		 result = SLL();

		 //get the users input
		cout << "Enter number one: ";
		cin >> raw0;


		cout << "Enter number two: ";
		cin >> raw1;

		//check if they want to exit
		if (raw0 == 0 && raw1 == 0) {
			system("pause");
			return 0;
		}

		//parse the users input
		numA.parseInt(raw0);
		numB.parseInt(raw1);

		//get the result
		result = addTwoLists(numA, numB);

		//print everything.
		numA.printReverse(numA.head);
		cout << " + ";
		numB.printReverse(numB.head);
		cout << " = ";
		result.print(result.head);
		cout << endl;
		cout << "-----------------------------------" << endl;
	}
}

//source https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
SLL addTwoLists(SLL numA, SLL numB)
{
	SLL result =  SLL();
	struct node *prev = NULL;
	int carry = 0, sum;

	while (numA.head != NULL || numB.head != NULL) //while both lists exist 
	{
		// Calculate value of next digit in resultant list. 
		// The next digit is sum of following things 
		// (i)  Carry 
		// (ii) Next digit of first list (if there is a next digit) 
		// (ii) Next digit of second list (if there is a next digit) 
		sum = carry + (numA.head ? numA.head->data : 0) + (numB.head ? numB.head->data : 0);

		// update carry for next calculation 
		carry = (sum >= 10) ? 1 : 0;

		// update sum if it is greater than 10 
		sum = sum % 10;

		// Create a new node with sum as data 
		result.insert_start(sum);

		cout << (numA.head ? numA.head->data : 0);
		cout << " + ";
		cout << (numB.head ? numB.head->data : 0);
		cout << " = " << sum << " carry = " << carry << endl;

		// Move first and second pointers to next nodes 
		if (numA.head) numA.head = numA.head->next;
		if (numB.head) numB.head = numB.head->next;
	}
	//after the loop is done, if we have a carry, add it to the results.
	if (carry > 0)
		result.insert_start(carry);
	// return head of the resultant list 
	return result;
}

