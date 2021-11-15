#include<iostream>
#include <string>
#include <stack>
#include<cstring>
#include<fstream>
using namespace std;

string print1() {
	string s;
	cout << "Write" << endl;
	cout << "\t-'console' for consol input" << endl;
	cout << "\t-'file' for file input" << endl;
	cout << "\t-'exit' if you're done" << endl;
	cout << ":: ";
	cin >> s;
	return s;
}

string print2() {
	string s;
	cout << "\nConvert to?" << endl;
	cout << "\t-'prefix'" << endl;
	cout << "\t-'postfix'" << endl;
	cout << "\t:: ";
	cin >> s;
	return s;
}

int precedence(char x) {
	if (x == '+' || x == '-')
		return 1;
	else if (x == '*' || x == '/')
		return 2;
	else if (x == '^')
		return 3;
	else if (x == '(')
		return 4;
	else
		return -1;
}

string mechanism(string st, string task) {
	stack <char> s;
	int l = st.length();
	string rt;
	for (int i = 0; i < l; i++) {
		char ch = st[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(') {
			if (s.empty())
				s.push(ch);

			else if ((!s.empty()) && (precedence(ch) > precedence(s.top())))
				s.push(ch);

			else if ((!s.empty()) && (task == "post") && (ch == '^') && (s.top() == '^'))
				s.push(ch);

			else if ((!s.empty()) && (s.top() == '('))
				s.push(ch);

			else if ((!s.empty()) && (precedence(ch) <= precedence(s.top()))) {
				while ((!s.empty()) && s.top() != '(' && (precedence(ch) <= precedence(s.top()))) {
					rt.push_back(s.top());
					s.pop();
				}
				s.push(ch);
			}
		}
		else if (ch == ')') {
			while ((!s.empty()) && s.top() != '(') {
				rt.push_back(s.top());
				s.pop();
			}
			s.pop();
		}
		else
			rt.push_back(ch);
	}
	while (!s.empty()) {
		rt.push_back(s.top());
		s.pop();
	}
	return rt;
}

string postfix(string st) {
	string post = mechanism(st, "post");
	return post;
}

string prefix(string st) {
	reverse(st.begin(), st.end());
	for (int i = 0; i < st.length(); i++) {
		if (st[i] == '(') {
			st[i] = ')';
		}
		else if (st[i] == ')') {
			st[i] = '(';
		}
	}
	st = mechanism(st, "pre");
	reverse(st.begin(), st.end());
	return st;
}

int main() {
	do {
		string str, inf, path;
		str = print1();
		if ("console" == str) {
			cout << "Write the 'infix' expression :\n\n ";
			cout << "\t:  ";
			cin.ignore();
			getline(cin, inf);
			string ch = print2();
			if ("prefix" == ch) {
				string pref = prefix(inf);
				cout << "\nPrefix :: " << pref << endl;
			}
			else if ("postfix" == ch) {
				string postf = postfix(inf);
				cout << "\nPostfix :: " << postf << endl;
			}
			else {
				cout << "\nPlease Try Again!\n";
			}
			cout << '\n';
		}
		else if ("file" == str) {
			cout << "Write the file path:\n\n ";
			cout << ":: ";
			cin.ignore();
			getline(cin, path);

			string line;
			ifstream myfile(path);
			if (myfile.is_open())
			{
				getline(myfile, line);

				string ch = print2();

				if ("prefix" == ch) {
					string pref = prefix(line);
					ofstream myfile(path, ios::app);
					myfile << "\nPrefix:: " << pref << endl;
					cout << "\n\t[Done]" << endl;
				}
				else if ("postfix" == ch) {
					string postf = postfix(line);
					ofstream myfile(path, ios::app);
					myfile << "\nPostfix :: " << postf << endl;
					cout << "\n\t[Done]" << endl;
				}
				else {
					cout << "\nPlease Try Again!\n";
				}

				cout << '\n';

				myfile.close();
			}

			else cout << "Unable to open file";
		}
		else if ("exit" == str) {
			cout << "Process Closed" << endl;
			break;
		}
		else
			cout << "\nPlease Try Again!\n";
	} while (true);
	return 0;
}
