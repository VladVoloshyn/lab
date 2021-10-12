#include <iostream>
#include <conio.h>
using namespace std;

void f(int n);

int main()
{
	int total, max, number;
	cout << " Number:";
	cin >> number;
	total = 0; 
	max = 0;

	while (number != 1)
	{	
		if (number % 2 == 0) number = number / 2;
		else number = number * 3 + 1;
		total++;
		if (number > max) max = number;
		cout << number << " ";
	}

	cout <<  '\n';
	cout << " Max:" << max << '\n';
	cout << " Iter:" << total << '\n';
	return 0;
}
