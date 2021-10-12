#include <iostream>
using namespace std;

int main()
{
	int number;
	cout << "Number: ";
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		double Mersen = pow(2, i) - 1;
		cout << Mersen << '\n';
	}
	return 0;

}
