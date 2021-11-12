#include <stdio.h>
#include <conio.h>
# include <iostream>
# include <windows.h>
# include <iomanip>
# include <fstream>
# include <cstdio>

using namespace std;

int main()
{
	int i, j, c;
	const int N = 4;
	int a[N];
	for (i = 0; i < N; i++)
	{
		a[i] = i + 1;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1; j++)
		{
			c = 0;
			int temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;// Цикл який міняє місцями цифри

			for (int z = 0; z < N; ++z)
			{
				if (a[z] == z + 1)
					c = 1;
			}


			for (int z = 0; z < N; ++z)
			{
				if (c == 0)
					cout << a[z] << " ";
				else break;
			}
			cout << '\n';
		}
	}




	return(0);
}

