// StackAssignment5Prefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size) {
    MaxSize = size;
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
        cout << s[i];
    }
}

bool isOperand(char c) {
    if (c >= 'a' && c <= 'z')
        return true;
    else   if (c >= 'A' && c <= 'Z')
        return true;
    else if(c>='0'&&c<='9')
        return false;
}

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    else
        return 0;
}

int main()
{
    string postfix;
    cout << "Enter postFix : ";
    cin >> postfix;
    int size = postfix.length();
    initStack(size);
    int n1, n2,ans;
    for (int i = 0; i < size; i++) {
        char t = postfix.at(i);

        if (t >= '0' && t <= '9') {
            push(t);
        }
        else if (isOperator(t)) {
            n2 = pop()-'0';
            n1 = pop()-'0';
            //cout << "n1" << n1;
            switch (t) {
            case '+':
                ans = n1 + n2;
                break;
            case '-':
                ans = n1 - n2;
                break;
            case '*':
                ans = n1 * n2;
                break;
            case '/':
                ans = n1 / n2;
                break;
            default:
                ans = 0;
                break;
            }

            push((char)ans);
           

        }
    }

    cout << ans;
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
