// StackAssignment4InfixToPreFix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size) {
	tos = -1;
	MaxSize = size;
}

bool isEmpty() {
	if (tos == -1)
		return 1;
	else
		return 0;
}

bool isFull() {
	if (tos == MaxSize)
		return 1;
	else
		return 0;
}

void push(char e) {
	tos++;
	s[tos] = e;
}

char pop() {
	char temp = s[tos];
	tos--;
	return temp;
}

char atTop() {
	return s[tos];
}

void printStack() {
	for (int i = tos; i > -1; i--) {
		cout << s[i] << " ";
	}
}

bool isOperand(char c) {
	if (c >= 'a' && c <= 'z')
		return true;
	if (c >= 'A' && c <= 'Z')
		return true;
	else
		return false;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	else
		return 0;
}

int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else if (op == '^')
		return 3;
	else
		return 0;
}

int main() {
	string infix, prefix;
	cout << "Enter Infix to convert into Prefix : ";
	cin >> infix;
	int size = infix.length();
	initStack(size);
	for (int i = size - 1; i >= 0; i--) {
		char t = infix.at(i);
		if (t == ')') {
			push(t);//3.1
			continue;
		}
		else if (t == '(') {//3.2
			while (tos > -1) {
				if (s[tos] != ')') {
					prefix += pop();
				}
				
			}
			continue;
		}
		else if (isOperand(t)) {//3.4
			prefix += t;
			continue;
		}else if (precedence(s[tos]) <= precedence(t)) {//3.3
			push(t);
			continue;
		}
		else {
			while (!(precedence(s[tos]) <= precedence(t)) || !isEmpty()) {
				if (s[tos] != ')')
					prefix += pop();
				else
					pop();
			}
			continue;
		}

	}

	int size1 = prefix.length();
	initStack(size1);
	cout << endl << "Prefix : ";
	for (int i = size1 - 1; i >= 0; i--) {
		cout << prefix.at(i);
	}
	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
