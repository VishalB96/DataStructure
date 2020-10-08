// StackAssignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size) {
    MaxSize = size;
    tos = -1;
}

int isEmpty() {
    if (tos == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (tos == MaxSize)
        return 1;
    else
        return 0;
}

void push(char c){
    tos++;
    s[tos] = c;
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
    int i;
    for (i = tos; i > -1; i--) {
        cout << s[i];
    }
}

int main()
{
    string name;
    cout << "Enter name";
    cin >> name;
    int size = name.size();
    initStack(size);
    for (int i = 0; i < size; i++) {
        push(name.at(i));
    }
   printStack();

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
