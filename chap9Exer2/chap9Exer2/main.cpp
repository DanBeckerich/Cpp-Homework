#include <iostream>
#include <cstdlib>
#include "DLL.cpp"

//source: https://www.tutorialspoint.com/cplusplus-program-to-implement-doubly-linked-list
//and https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/

using namespace std;

int main() { 
	DLL mainList = DLL();
	
	mainList.insert(3);
	mainList.insert(4);

	cout << "Before setEntry" << endl;
	cout << mainList.retrieve(0) << endl;
	cout << mainList.retrieve(1) << endl;

	mainList.setEntry(0, 999);
	mainList.setEntry(1, 222);

	cout << "After setEntry" << endl;
	cout << mainList.retrieve(0) << endl;
	cout << mainList.retrieve(1) << endl;

   //cout<<"The doubly linked list is: ";
   //mainList.display();

   cout << endl;
   system("pause");
   return 0; 
} 