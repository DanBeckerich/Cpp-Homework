#include <iostream>
using namespace std;

int f(int n);

int main()
{
	int val = 8;

	cout << "The value of f(" << val << ") is " << f(val) << endl;

	system("pause");
	return 0;

} // end main


  /** @pre n >= 0. */
int f(int n)
{
	cout << "Function entered with n = " << n << endl;
	switch (n)
	{
	case 0: case 1: case 2:
		return n + 1;
	default:
		return f(n - 2) * f(n - 4);
	} // end switch
} // end f