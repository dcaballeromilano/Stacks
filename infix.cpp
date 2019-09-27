#include "stack.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	int error;
	Stack s;
	string postfix, infix, op1, op2, expr, user_response;
	do
	{
		cout << "Enter postfix expression: ";
		getline(cin, postfix);
		error = 0;
		for (int i = 0; i < postfix.length(); i++)
		{
			string c = postfix.substr(i, 1);
			if (c == "+" || c == "-" || c == "*" || c == "/")
			{
				op2 = s.pop();
				if (op2 == "\0")
				{
					cout << endl << "Too many operators and not enough operands" << endl;
					cout << "============================================" << endl;
					error = 1;
					break;
				}
				op1 = s.pop();
				if (op1 == "\0")
				{
					cout << endl << "Too many operators and not enough operands" << endl;
					cout << "============================================" << endl;
					error = 1;
					break;
				}
				expr = "(" + op1 + c + op2 + ")";
				s.push(expr);
			}
			else if (c == " ")
			{
			continue;
			}
			else
			{
			s.push(c);
			}
		}

		if (!error)
		{
			infix = s.pop();
			if (s.pop() == "\0")
			{
				cout << endl << "The infix expression is: " << infix << endl;
				cout << "============================================" << endl;
			}
			else
			{
				cout << endl << "Too many operands and not enough operators" << endl;
				cout << "============================================" << endl;
				// make sure stack is clear
				while (s.pop() != "\0");
			}
		}
		cout << "Convert another Postfix expression? (Y/N): ";
		cin >> user_response;
		cout << "============================================" << endl << endl;
		getchar(); // swallow new line character 
	} while (user_response == "y" || user_response == "Y");

	return 0;
}

