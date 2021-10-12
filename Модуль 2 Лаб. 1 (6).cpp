#include <iostream>
using namespace std;

int main()
{
	float k, b, X0, Y0, R;
	cout << "y = kx + b. Enter k, b: " << '\n';
	cin >> k >> b;
	cout << "Enter X0, Y0, R: " << '\n';
	cin >> X0 >> Y0 >> R;


	float A, B, C, X1, Y1, X2, Y2;
	A = 1 + k * k;
	B = -2 * X0 + 2 * k * (b - Y0);
	C = X0 * X0 + pow(b - Y0, 2) - R * R;
	
	float D = B * B - 4 * A * C;
	
	if (D == 0)
	{
		cout << "Have one point!" << '\n';
		X1 = -B / (2 * A);
		Y1 = k * X1 + b;
		cout << "(" << X1 << "," << Y1 << ")";
	}
	else
	{
		if (D < 0)
			cout << "Does not intersect!" << '\n';
		else
		{
			cout << "Have two point!" << '\n';
			X1 = (-B + sqrt(D)) / (2 * A);
			Y1 = k * X1 + b;
			
			cout << "(" << X1 << "," << Y1 << ")";

			X2 = (-B - sqrt(D)) / (2 * A);
			Y2 = k * X2 + b;
			cout << "(" << X2 << "," << Y2 << ")";
			
		}
	}
			

	return 0;
}