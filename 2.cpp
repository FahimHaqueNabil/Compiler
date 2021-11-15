#include<iostream>
#include<fstream>
#include<string>

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


int main()
{
	
	string exp;
	int total=0;
	ifstream myfile("expression.txt");
	if (myfile.is_open())
	{
		
		getline(myfile,exp);
			}
	myfile.close();
	
		
	if (exp[1] == '+' || exp[1] == '-' || exp[1] == '*' || exp[1] == '/')
	{
		
		int pr = presidence(exp[1]);
		if (pr == 1)
		{
			
			int a = (int)exp[0] - 48;
			
			int b = (int)exp[2] - 48;
			
			 total = a + b;
			
			

		}
		else if (pr == 2)
		{
			int a = (int)exp[0] - 48;
			
			int b = (int)exp[2] - 48;

			 total = a - b;

		}
		else if (pr == 3)
		{
			int a = (int)exp[0] - 48;

			int b = (int)exp[2] - 48;

			total = a * b;

		}
		else if (pr == 4)
		{
			int a = (int)exp[0] - 48;
			
			int b = (int)exp[2] - 48;

		    total = a / b;

		}
	}

	
	string exp2;
	ifstream Myfile("random.txt");
	
	if (Myfile.is_open())
	{

		getline(Myfile, exp2);
	}
	Myfile.close();

	int t = (int)exp2[0]-48;
	int r = total - t;
	int result = abs(r);
	int f = result * result * result;
	cout <<"Console: "<<f<<"\n";
	
}