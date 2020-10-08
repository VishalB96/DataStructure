// StackAssignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;
int cBracket,sBracket,aBracket,rBracket;
char opBr[] = { '{','[','(', < };
char clBr[] = {'}'}


void initStack(int size) {
	MaxSize = size;
	tos = -1;
	cBracket = 0;
	sBracket = 0;
	aBracket = 0;
	rBracket = 0;
}

void push(char e) {
	tos++;
	s[tos] = e;
}

int isFull() {
	if (tos == MaxSize) {
		return 1;
	}
	else
		return 0;
}

char pop() {
	int temp;
	temp = s[tos];
	tos--;
	return temp;
}

int isEmpty() {
	if (tos == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

char atTop() {
	return s[tos];
}

void printStack() {
	int i;
	for (i = tos; i > -1; i--) {
		cout << s[i]<<endl;
		
	}
}

bool isOpBrackets(char b) {
	if (b == '{' || b == '[' || b == '<' || b == '(')
		return true;
	else 
		return false;
}
bool isClBrackets(char b) {
	if (b == '}' || b == ']' || b == '>' || b == ')')
		return true;
	else
		return false;
}
int main()
{
	
	string br;
	
	cout << "Enter braces to check wellness...:" << endl;
	cin >> br;
	int size = br.length();
	initStack(size);
	int i = 0;
	do
	{
		char t = br.at(i++);
		
		if (isOpBrackets(t)) {
			push(t);
			if (t == '{') cBracket++;
			else if (t == '[') sBracket++;
			else if (t == '<') aBracket++;
			else if (t == '(') rBracket++;
		}
		else if (isClBrackets(t)) {
			pop();
			if (t == '}') cBracket--;
			else if (t == ']') sBracket--;
			else if (t == '>') aBracket--;
			else if (t == ')') rBracket--;
			
		}
		
	} while (i<size);

	if (isEmpty()&& cBracket ==0&& sBracket ==0 &&aBracket ==0 &&rBracket == 0) {
		cout << "Your code is well formed\n";
	}
	else
	{
		cout << "\nException!";
		
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
