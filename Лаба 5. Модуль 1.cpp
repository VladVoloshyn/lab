#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int end() { cout << "\nEND\n"; _getch(); return 0; }

queue<char> to_revpol(const string& in)
{
	stack<char> stk;//створюємо стек для зберігання тимчасових операцій 
	queue<char> gen;//створюємо чергу, куди все будемо вкладати
	for (auto i : in)//йдем по рядку
	{
		if (i == '.')//якщо це просто крапка, тобто користувач ввів число типу 0.2,
			gen.push(i);//то поміщаємо його сюди
		else if ((i >= '0' && i <= '9') ||//якщоце число або змінна, то так само поміщаємо
			(i >= 'a' && i <= 'z') ||
			(i >= 'A' && i <= 'Z'))
		{
			if (gen.empty() != true &&
				(gen.back() >= '0' && gen.back() <= '9') &&
				!(i >= '0' && i <= '9'))
			{
				stk.push('*'); gen.push(';');
			}//ця функція потрібна для того, щоб можна було не ставити знак множення перед змінною при вводі 5x, наприклад
			gen.push(i);
		}
		else if
			(i == '+' || i == '-' ||//якщо це операція
				i == '*' || i == '/')
		{
			if (stk.empty() != true && (stk.top() == '*' || stk.top() == '/'))//якщо у нас щось є і послідня операція була * або /, то...
			{
				if (i == '*' || i == '/')//якщо множимо або ділимо...
				{
					gen.push(stk.top());//то можна вигрузити попередню оперцію
					stk.top() = i;//і замінити її
				}
				else if (i == '+' || i == '-')//якщо це була операція меншого пріоритету, тобто + або -
				{
					while (stk.empty() != true && stk.top() != '(')//слід вигрузити все до дужки, що відкривається, або поки стек не спорожніє
					{
						gen.push(stk.top());
						stk.pop();
					}
					stk.push(i);
				}
			}
			else//якщо ж стек порожній чи остання операція була не * чи /, то...
			{
				if (gen.empty() != true && (
					(gen.back() >= '0' && gen.back() <= '9') ||
					(gen.back() >= 'a' && gen.back() <= 'z') ||
					(gen.back() >= 'A' && gen.back() <= 'Z')))//якщо останнє, що було в gen - змінна чи цифра, 
					gen.push(';');//тоді слід поставити обмежуючий знак
				else if (((stk.empty() != true && stk.top() == '(') || gen.empty() == true) && i == '-')//інакше,
					gen.push('_');
				if (gen.back() != '_')
					stk.push(i);
			}
		}
		else if (i == '(')//якщо ж не цифра, не змінна і операція, а відкр. дужка, то...
		{
			if (gen.empty() != true && (
				(gen.back() >= '0' && gen.back() <= '9') ||
				(gen.back() >= 'a' && gen.back() <= 'z') ||
				(gen.back() >= 'A' && gen.back() <= 'Z')))//якщо останнє що було в gen - змінна чи цифра, 
			{
				gen.push(';');//ставимо обмежуючий знак, а стек записуємо *
				stk.push('*');
			}
			stk.push(i);
		}
		else if (i == ')')//якщо ж у нас закрилася дужка, слід вивантажити всі операції з stk в gen
		{
			while (stk.empty() != true && stk.top() != '(')
			{
				gen.push(stk.top());
				stk.pop();
			}
			if (stk.empty() != true)
				stk.pop();
			else
				throw "WRONG INPUT! Missing (";
		}
	}

	while (stk.empty() != true)//після закінчення роботи з рядком у стеку може щось залишитися, тому
	{//виносимо все, що залишилося.
		gen.push(stk.top());
		stk.pop();
	}
	return gen;//і повертаємо результат
}

double calc(queue<char> in)
{
	stack<double> res;//тимчасове сховище значень
	bool minus = false, op = false;
	size_t fl = 0;
	double temp;//тимчасова змінна

	res.push(0.0);
	while (in.empty() != true)
	{
		if (in.front() == '_')
		{
			minus = true;
			in.pop();
		}
		else if (in.front() >= '0' && in.front() <= '9')
		{
			if (op == true) { res.push(0.0); op = false; }
			while (in.empty() != true && in.front() >= '0' && in.front() <= '9')
			{
				if ((in.front() == '0' && res.top() == 0.0) == false)
				{
					if (fl == 0)
					{
						res.top() = res.top() * 10 + in.front() - 48;
					}
					else
					{
						temp = in.front() - 48;
						for (size_t i = 0; i < fl; i++)
							temp /= 10;
						res.top() += temp;
						fl++;
					}
				}
				in.pop();
				if (in.empty() != true && in.front() == '.')
				{
					fl = 1;
					in.pop();
				}
			}
			fl = 0;
		}
		else if ((in.front() >= 'a' && in.front() <= 'z') || (in.front() >= 'A' && in.front() <= 'Z'))
		{
			cout << "Please enter the variable \'";
			do
			{
				cout << in.front();
				in.pop();
			} while (in.empty() != true && (in.front() >= 'a' && in.front() <= 'z') || (in.front() >= 'A' && in.front() <= 'Z'));
			cout << "\': ";
			if (op == true) { res.push(0.0); op = false; }
			cin >> res.top();
		}
		else if (in.front() == ';' ||
			in.front() == '+' || in.front() == '-' ||
			in.front() == '*' || in.front() == '/')
		{
			if (minus == true)
			{
				minus = false;
				res.top() = -res.top();
			}
			if (in.front() == ';')
			{
				res.push(0.0);
				in.pop();
			}
			else if (res.size() > 1)
			{
				temp = res.top();
				res.pop();
				switch (in.front())
				{
				case '+':
					res.top() += temp;
					break;
				case '-':
					res.top() -= temp;
					break;
				case '*':
					res.top() *= temp;
					break;
				case '/':
					res.top() /= temp;
					break;
				}
				op = true;
				in.pop();
			}
		}
	}
	if (res.size() > 1)
	{
		cout << "something went wrong!";
		while (res.empty() != true)
		{
			cout << res.top() << ' ';
			res.pop();
		}
		return 0.0;
	}
	return res.top();
}

template <class T>
ostream& operator<<(ostream & out, queue<T> cs)
{
	while (cs.empty() != true)
	{
		out << cs.front();
		cs.pop();
	}
	return out;
}

int main()
{
	string in;
	queue<char> gen;
	cout << "Enter an expression:\n";
	getline(cin, in);

	gen = to_revpol(in);
	cout << "Result of the function to_revpol: " << gen << endl;
	cout << "Final result: " << calc(gen);
	return end();
}