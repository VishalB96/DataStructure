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
		return 1;
	if (c >= 'A' && c <= 'Z')
		return 1;
	retun 0;
}

bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return 1;
	else
		return 0;
}

int precedence(char c){
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
	cout << "Enter Infix to convert into Prefix";
	cin >> infix;
	int size = infix.length;
	initStack(size);
	for (int i = size-1; i>=0; i--) {
		cout << infix.at(i);
	}
}
