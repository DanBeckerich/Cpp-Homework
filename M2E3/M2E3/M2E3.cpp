//written by Daniel Beckerich 1/19/2019

using namespace std;

#include <iostream>

//the recursive function.
int sumN(int intsArray[], int sumAmount) {
	//base case
	if (sumAmount == 0) {
		return 0;
	}
	//if we havnt returned already
	//return the sum of the lower digits to the next iteration
	return (sumN(intsArray, sumAmount - 1) + intsArray[sumAmount - 1]);

}

int main()
{
	//test it out
	int testArray[] = {5, 2, 7, 10, 2};

	cout << sumN(testArray, 3) << "\n";

	system("pause");
	return 0;
}