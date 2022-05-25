//Реалізувати перевід рядка у expression tree(змінні, дійсні числа, операції + , -
	//       , *, / , унарний мінус, степінь. Обчислити вираз, роблячи запит по змінним
#include<iostream>
#include<stack>
#include<string>
#pragma warning(disable : 4996) 
using namespace std;

int prec(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}


string infixToPostfix(string s) 
{
	stack<char> st;
	string result;

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;
		
		else 
			if (c == '(')
			st.push('(');
		    else if (c == ')')
					{
					while (st.top() != '(')
					{
					result += st.top();
					st.pop();
					}
					st.pop();
					}
			     else 
					 {
					 while (!st.empty() && prec(s[i]) <= prec(st.top())) 
						{
						result += st.top();
						st.pop();
						}
						st.push(c);
					 }
	}


	while (!st.empty()) 
	{
		result += st.top();
		st.pop();
	}

	return result;
}


struct Node
{
	string val;
	Node* left, * right;

	Node(string val)
	{
		this->val = val;
		this->left = this->right = nullptr;
	}
};


bool isLeaf(Node * node) {
	return node->left == nullptr && node->right == nullptr;
}


double process(string op, double x, double y)
{
	if (op == "+") { return x + y; }
	if (op == "-") { return x - y; }
	if (op == "*") { return x * y; }
	if (op == "/") { return x / y; }
	if (op == "^") { return pow(x, y); }
	return 0;
}


double evaluate(Node * root)
{

	if (root == nullptr) 
	{
		return 0;
	}


	if (isLeaf(root)) 
	{
		return stod(root->val);
	}


	double x = evaluate(root->left);
	double y = evaluate(root->right);


	return process(root->val, x, y);
}


void evaluate_tree(string postfix)  
{
	Node* root = new Node(&postfix[postfix.size() - 1]);    
	Node * root2 = root;
	char x; char x_arr[2];
	x_arr[1] = '\0';
	int check = 0;
	for (int i = 0; i < postfix.size() - 1; i++)
	{
		if (!isdigit(postfix[i]))
		{
			while (check != 1)
			{
				if (root2->left == NULL)  
				{
					x_arr[0] = postfix[i];
					root2->left = new Node(&x_arr[0]);
					check = 1;
				}
				else if (root2->right == NULL)
				{
					x_arr[0] = postfix[i];
					root2->right = new Node(&x_arr[0]);
					check = 1;
				}
				else
				{
					root2 = root2->right;
				}
			}
			check = 0;
		}

	}
	root2 = root;
	for (int i = 0; i < postfix.size() - 1; i++)
	{
		if (isdigit(postfix[i]))
		{
			while (check != 1)
			{
				if (root2->left != NULL) {  //
					strcpy(&x_arr[0], root2->left->val.c_str()); // ВКАЗІВНИК НА СИМВОЛ left копіює дані в &x_arr
				}
				if (root2->left == NULL)
				{

					x_arr[0] = postfix[i];
					root2->left = new Node(&x_arr[0]);
					check = 1;
				}

				else if (root2->left != NULL && !isdigit(x_arr[0]))
				{

					root2 = root2->left;
				}
				else if (root2->right == NULL)
				{

					x_arr[0] = postfix[i];
					root2->right = new Node(&x_arr[0]);
					check = 1;
				}
				else
				{
					strcpy(&x_arr[0], root2->left->val.c_str());
					if (!isdigit(x_arr[0]))
					{
						root2 = root2->left;
					}
					else
					{
						strcpy(&x_arr[0], root2->right->val.c_str());
						if (isdigit(x_arr[0]))
						{
							if (root->right == NULL)
							{
								x_arr[0] = postfix[i];
								root->right = new Node(&x_arr[0]);
								check = 1;
							}
							else { 
								root2 = root->right; 
							}


						}

					}
				}
			}
			check = 0;
		}

	}

	cout << endl << endl << "Result: " << evaluate(root) << endl;
}




int main() {
	string exp = "3^2*(1+2)";

	cout << exp;
	string res = infixToPostfix(exp);


	evaluate_tree(res);
	cout << res << endl;
	return 0;
}