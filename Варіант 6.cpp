#include <iostream>
using namespace std;
int n;
float sum;
bool find_first;

int main()
{
	find_first = false;
	sum = 0;
	cin >> n;
	if (n > 0)
	{
		float* a = new float[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		float min = a[0];
		for (int i = 0; i < n; i++)
			if (min > a[i]) min = a[i];

		cout << "Min element: " << min << endl;

		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				sum += a[i];
				find_first = true;
			}
			else if (find_first) {
				break;
			}
		}

		cout << "Sum: " << sum << endl;
	}
	else
		cout << "Error: something wrong with your array" << endl;

	return 0;
}