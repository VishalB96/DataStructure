// Test01Q02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//sort stack using another stack

#include <iostream>
using namespace std;
class Stack {
public:
	int s[100], MaxSize, tos;

	Stack(int size) {
		initStack(size);
	}

	void initStack(int size) {
		MaxSize = size;
		tos = -1;
	}

	void push(int e) {
		if (isFull())
			cout << "FULL"<<endl;
		else {
			tos++;
			s[tos] = e;
		}
	}

	bool isFull() {
		if (tos == MaxSize) {
			return 1;
		}
		else
			return 0;
	}

	int pop() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return 0;
		}	
		else {
			int temp;
			temp = s[tos];
			tos--;
			return temp;
		}
		
	}

	int isEmpty() {
		if (tos == -1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	int atTop() {
		return s[tos];
	}

	void printStack() {
		int i;
		for (i = tos; i > -1; i--) {
			cout << s[i] << endl;
		}
	}

	void sortWithStack() {
		Stack lt(this->MaxSize);

		for (int i = tos; i > 0;i--) {
			for (int j = tos; j > 0; j--) {
				if (s[j] < s[j-1])
					swap(s[j], s[j-1]);
				lt.push(this->pop());
			}
			for (int k = 0; k < MaxSize-1; k++) {
				this->push(lt.pop());
			}
		}

	}

};
int main()
{
	int n;
	cout << "Enter size : ";
	cin >> n;
	Stack s1(n);
	cout << "Enter the values" << endl;
	for (int i = 0; i < n; i++) {
		int e;
		cout << "Push : ";
		cin >> e;
		 s1.push(e);
		 cout << endl;
	}
	
	s1.printStack();
	cout << endl;
	s1.sortWithStack();
	cout << "after sort" << endl;
	s1.printStack();


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
