#include <iostream>
#include "DLL.cpp"


using namespace std;

int F(int n)
{
	//vector<int> last5{ 1, 1, 1, 3, 5 };
	DLL last5 = DLL();

	last5.insert(5);
	last5.insert(3);
	last5.insert(1);
	last5.insert(1);
	last5.insert(1);

	int result;

	//if n is less than 6, we can just return one of the results from our list.
	if (n < 6 & n >= 0)
		result = last5.retrieve(n - 1);
	//if n is less than or equal to 0, return 0
	else if (n <= 0) {
		return 0;
	}
	else
	{
		for (int i = 5; i < n; i++)
		{
			result = last5.retrieve((i - 1) % 5) + 3 * last5.retrieve((i - 5) % 5);

			last5.setEntry(i % 5, result);
		}
		result = last5.retrieve((n - 1) % 5);
	}

	return result;
}

int main() {

	int num1;
	int num2;
	int num3;

	cout << "Starting F(100)" << endl;
	num1 = F(100);
	cout << "Starting F(50)" << endl;
	num2 = F(50);
	cout << "Starting F(51)" << endl;
	num3 = F(51);

	cout << num1 << " F(100)" << endl;
	cout << num2 << " F(50)" << endl;
	cout << num3 << " F(51)" << endl;

	cout << num3 - num2 << " F(51) - F(50)" << endl;

	system("pause");
	return 0;
}