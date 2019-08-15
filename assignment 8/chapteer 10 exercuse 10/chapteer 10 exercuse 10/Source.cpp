#include <iostream>
#include <iomanip> 
#include <random>
#include <map>

using namespace std;

const int NUMCOUNT = 20;
const int LOW_RANGE = -100;
const int HIGH_RANGE = 100;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//see: https://www.geeksforgeeks.org/bubble-sort/
// A function to implement bubble sort 

//for problem A.
void bubbleSort(int arr[], int n) //bubble sort is O(N^2)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place    
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

//for problem B.
//see: https://www.techiedelight.com/count-sort-cpp-java-implementation/
void countSort(vector<int> &v) //count sort is O(N)
{
	// create an empty map to store frequency of array elements
	map<int, int> freq;

	// store distinct values in the input array as key and 
	// their respective counts as values
	for (int i = 0; i < v.size(); i++) {
		freq[v.at(i)]++;
	}

	// traverse the map and overwrite the input array with sorted elements
	// (map will iterate based on the sorted order of keys)
	int i = 0;
	for (auto it : freq) {
		while (it.second--) {
			v[i++] = it.first;
		}
	}
}
int main() {

	//define the number of random ints we want, and the range we want.


	int nums1[NUMCOUNT];
	vector<int> nums2;

	//found here https://stackoverflow.com/a/7560564
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator
	uniform_int_distribution<> distr(LOW_RANGE, HIGH_RANGE); // define the range

	cout << setw(15) << "original: ";
	//fill the array with ints.
	for (int i = 0; i < NUMCOUNT; i++) {
		nums1[i] = distr(eng); // generate numbers
		nums2.push_back(nums1[i]);
		cout << setw(4) << nums1[i] << " " ;
	}
	cout << endl;

	bubbleSort(nums1, NUMCOUNT);
	countSort(nums2);



	cout << setw(15) << "Bubble Sort: ";
	for (int i = 0; i < NUMCOUNT; i++) {
		cout << setw(4) << nums1[i] << " ";
	}
	cout << endl;

	cout << setw(15) << "Counting Sort: ";
	for (int i = 0; i < NUMCOUNT; i++) {
		cout << setw(4) << nums2[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}