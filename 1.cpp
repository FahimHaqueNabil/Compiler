#include<iostream>
#include<string>
#include<stack>
#include<cmath>
using namespace std;

int presidence(char a)
{
	if (a == '+')
	{
		return 1;
	}
	else if (a == '-')
	{
		return 2;
	}
	else if (a == '*')
	{
		return 3;
	}
	else if (a == '/')
	{
		return 4;
	}
	else if (a == '^')
	{
		return 5;
	}
}


void func(string exp)
{
	stack <float> s;
	//cout << (float)exp[0] - 48;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
		{
			int pr = presidence(exp[i]);
			if (pr == 1)
			{
				float a = s.top();
				s.pop();
				float b = s.top();
				s.pop();
				float sub_total = a + b;
				s.push(sub_total);
			}
			else if (pr == 2)
			{
				float a = s.top();
				s.pop();
				float b = s.top();
				s.pop();
				float sub_total = a - b;
				s.push(sub_total);
			}
			else if (pr == 3)
			{
				float a = s.top();
				s.pop();
				float b = s.top();
				s.pop();
				float sub_total = a * b;
				s.push(sub_total);
			}
			else if (pr == 4)
			{
				float a = s.top();
				s.pop();
				float b = s.top();
				s.pop();
				float sub_total = a / b;
				s.push(sub_total);
			}
			else if (pr == 5)
			{
				float a = s.top();
				s.pop();
				float b = s.top();
				s.pop();
				float sub_total = pow(a, b);
				s.push(sub_total);
			}

		}
		else
			s.push((int)exp[i] - 48);
		

	}
	cout << s.top() << "\n";
}


int main()
{
	string exp;
	cout << "Enter Expression: ";
	cin >> exp;
	
	reverse(exp.begin(), exp.end());
	
	func(exp);
}