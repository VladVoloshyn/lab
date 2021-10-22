#include <iostream>

void turnOX(double X, double Y, double Z)
{
		int a;  		
		for (a = 20; a <= 360; a += 20)
		{
			// X = X;
			Y = Y * cos(a) - Z * sin(a);
			Z = Y * sin(a) + Z * cos(a);
		}
}

void turnOY(double X, double Y, double Z)
{
	int a;

	for (a = 20; a <= 360; a += 20)
	{
		// Y = Y;
		X = X * cos(a) + Z * sin(a);
		Z = -X * sin(a) + Z * cos(a);
	}
}

void turnOZ(double X, double Y, double Z)
{
	int a;
	for (a = 20; a <= 360; a += 20)
	{
		// Z = Z;
		X = X * cos(a) - Y * sin(a);
		Y = X * sin(a) + Y * cos(a);
	}
}


int main()
{

	double XA, YA, ZA;
	double XB, YB, ZB;
	double XC, YC, ZC;
	double XS, YS, ZS;
		std::cout << "A:" << '\n';
		std::cout << "X = ";
		std::cin >> XA;
		std::cout << "Y = ";
		std::cin >> YA;
		std::cout << "Z = ";
		std::cin >> ZA;

		std::cout << "B:" << '\n';
		std::cout << "X = ";
		std::cin >> XB;
		std::cout << "Y = ";
		std::cin >> YB;
		std::cout << "Z = ";
		std::cin >> ZB;

		std::cout << "C:" << '\n';
		std::cout << "X = ";
		std::cin >> XC;
		std::cout << "Y = ";
		std::cin >> YC;
		std::cout << "Z = ";
		std::cin >> ZC;

		std::cout << "S:" << '\n';
		std::cout << "X = ";
		std::cin >> XS;
		std::cout << "Y = ";
		std::cin >> YS;
		std::cout << "Z = ";
		std::cin >> ZS;

		turnOX(XA, YA, ZA);
		turnOX(XB, YB, ZB);
		turnOX(XC, YC, ZC);
		turnOX(XS, YS, ZS);

	return 0;
}
