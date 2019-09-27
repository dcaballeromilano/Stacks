#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

Stack::Stack()
{
	myTop = 0;
}

Stack::~Stack()
{
	StackNode *p;

	while (myTop != 0)
	{
		p = myTop;
		myTop = myTop->next;
		delete p;
	}
}

Stack::Stack(const Stack & org)
{
	StackNode *p = org.myTop;
	Stack T;

	while (p != 0)
	{
		T.push(p->data);
		p = p->next;
	}
	while (!T.empty())
	{
		push(T.top());
		T.pop();
	}

}

Stack & Stack::operator=(const Stack & org)
{
	if (this != &org)
	{
		while (!empty())
		{
			pop();
		}

		StackNode *p = org.myTop;
		Stack T;

		while (p != 0)
		{
			T.push(p->data);
			p = p->next;
		}
		while (!T.empty())
		{
			push(T.top());
			T.pop();
		}

	}
	return *this;
}

bool Stack::empty() const
{
	return myTop == 0;
}

StackElement Stack::top() const
{
	if (!empty())
	{
		return myTop->data;
	}
	else
	{
		cout << "Stack is Empty -- return garbage\n";
		return "-1111";
	}
}

string Stack::pop()
{
	string result;
	if (!empty())
	{
		StackNode *p = myTop;
		result = myTop->data;
		myTop = myTop->next;
		delete p;
	}
	/*else
	{
		cout << "Stack is Empty -- cannot pop\n";
	}*/
	return result;
}

void Stack::push(const StackElement & value)
{
	StackNode *p = new StackNode;

	p->data = value;
	p->next = myTop;
	myTop = p;

}

ostream & operator<<(ostream & out, const Stack & org)
{
	for (StackNode *p = org.myTop; p != 0; p = p->next)
	{
		out << p->data << endl;
	}
	return out;
}
