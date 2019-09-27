#pragma once
#include <iostream>
#include <string>

using namespace  std;

typedef string StackElement;

class StackNode
{
public:
	StackElement data;
	StackNode *next;
};

class Stack
{
public:
	Stack();
	~Stack();
	Stack(const Stack & org);
	Stack & operator=(const Stack & org);
	bool empty() const;
	StackElement top() const;
	string pop();
	void push(const StackElement & value);
	friend ostream & operator<<(ostream & out, const Stack & org);
	
private:
	StackNode *myTop;

};