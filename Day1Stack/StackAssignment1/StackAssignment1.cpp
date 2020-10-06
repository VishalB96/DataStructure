// StackAssignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size) {
	MaxSize = size;
	tos = -1;
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
int main()
{
	
	char br;
	
	cout << "Enter braces to check wellness...:" << endl;
	initStack(100);
	
	do
	{
		cin >> br;
		if (br == '{') {
			push(br);
			
		}
		else if (br == '}') {
			pop();
			
		}
		cout << "Enter 'N' to check wellness.\n";
	} while (br != 'N');

	if (isEmpty()) {
		cout << "Your code is well formed\n";
	}
	else
	{
		cout << "\nException! : "<<tos<<" '}' needed!";
		
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
