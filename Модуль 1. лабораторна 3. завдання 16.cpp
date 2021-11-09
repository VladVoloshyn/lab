#include <iostream>
#include <cmath>
using namespace std;



double func(double x);


int main()
{
	double step = 0.01, eps = 0.005;
	const int a = 0,  b = 10;
	double f1[500], f2[500];

	double x = a, f_x, f_nx, T1, T2;
	double number_steps = (b - a) / step;

	

	for (int i = 1; i <= number_steps; i++) 
	{
		x = i * step;
		f_x = func(a);
		f_nx = func(x);
		//cout << i << endl;
		//cout << "f(x(0)) = " << f_x << endl;
		//cout << "f(x(n)) = " << f_nx << endl;
		f1[i] = f_nx;
		if (abs(f_x - f_nx) < eps)
		{
		T1 = x;
		int n = i;
		//cout << "Function is periodic;  T = " << T1;
		break;
		}
	}
	//cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";

	x = T1;

	f_nx = 0;	
	for (int j = 1; j <= number_steps; j++)
	
	{
		x = T1 + j * step;
		f_x = func(T1);
		f_nx = func(x);
		//cout << j << endl;
		//cout << "f(x(0)) = " << f_x << endl;
		//cout << "f(x(n)) = " << f_nx << endl;
		f2[j] = f_nx;
		if (abs(f_x - f_nx) < eps)
		{
			T2 = x;
			if (f1[1] = f2[1])
			cout << "Function is periodic;  T = " << T2 << endl;
			else cout << "Function is periodic;  T = " << T1 << endl;
			break;
		}
	}

	return 0;

}




double func(double x)
{
	return sin(x);
}
