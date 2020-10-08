// StackAssignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

//checks whether the character is operand or not
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


//returns the precedence of operators
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

int main()
{
    string str,postfix;
    cout << "Enter INFIX string to convert into POSTFIX : ";
    cin >> str;
    int size = str.length();
    initStack(size);

    for (int i = 0; i < size; i++) {
        char t = str.at(i);
        if (t == '(') {
            push(t);//case3.1
            continue;
        }
        else if (t == ')') {
            while (tos > -1) {
                if (s[tos] != '(')
                    postfix += pop();//case3.2
                else
                    pop();
            }
            continue;
        }else  if (isOperand(t)) {
            postfix += t;//case 3.4 all operands copy
            //cout << "temp post" << postfix << endl;
            continue;
        }
        else if (precedence(s[tos]) <= precedence(t)) {
            push(t);//case 3.3
            continue;
        }
        else {
            while (!(precedence(s[tos]) < precedence(t)) || !isEmpty()) {
                if (s[tos] != '(')
                    postfix += pop();//case3
                else
                    pop();
            }
            continue;
        }
        
        
            
    }

    while (!isEmpty()) {
        postfix += pop();
    }

    cout <<"POSTFIX IS : "<< postfix;
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
