#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return pow(x, 2); // беремо функцію y = x2 і записуємо її в функцію f.
}

int main()
{
	const int N = 1000; // розбиваємо відрізок а і b на 1000 частин.

	double a, b;
	cout << "a = "; // початкова точка.
	cin >> a;
	cout << "b = "; // кінцева точка.
	cin >> b;
	double sum = 0;
	double dx = (b - a) / N; // dx інтервал по осі OX.
	for (int i = 0; i < N; ++i)
	{
		double y1 = f(a + i * dx); // для кожного x шукаємо свій y по формулам.
		double y2 = f(a + (i + 1) * dx);
		sum += sqrt((dx * dx) + pow(y2 - y1, 2)); // сума шукаємо по формулі
	}
	cout << " L=" << sum;
	return 0;
}
