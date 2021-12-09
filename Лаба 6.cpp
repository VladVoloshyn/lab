#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int main()
{

	string path = "myFile.txt";
	string str;
	stack<char> oper;
	stack<long int> num;
	char ch;
	long int temp = 0, res = 0;
	bool first = 1;
	ifstream fs;
	fs.open(path, fstream::out);
	if (!fs.is_open())
	{
		cout << "Error" << endl;
		return 0;
	}
	else
	{
		cout << "Success" << endl;
		while (!fs.eof())
		{
			ch = fs.peek();
			if (first)
			{
				fs >> res;
				num.push(temp);
				cout << res;
				first = 0;
				continue;
			}
			if (ch >= 48 && ch <= 57)
			{
				fs >> temp;
				num.push(temp);
				cout << temp;
				continue;
			}
			if (ch == '+')
			{
				cout << ch;
				oper.push(ch);
				fs.ignore();
				continue;
			}
		}
		while (oper.size() != 0)
		{
			long int a;
			a = num.top();
			num.pop();
			ch = oper.top();
			oper.pop();
			if (ch == '+')
			{
				res += a;
				continue;
			}
			if (ch == '-')
			{
				res -= a;
				continue;
			}
		}
	}
	cout << "\nresult = " << res;
	fs.close();
	cout << "\nclosing" << endl;
}