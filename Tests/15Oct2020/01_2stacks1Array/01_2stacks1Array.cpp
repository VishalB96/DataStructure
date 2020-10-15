// 01_2stacks1Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Stack {
public:
     int tos1, tos2,MaxSize;
     int s[100];

    Stack(int size) {
        this->MaxSize = size;
        tos1 = -1;
        tos2 = MaxSize;
    }


    bool isFull() {
        if (tos2 - tos1 == 1)
            return 1;
        else
            return 0;
    }
    
    bool isEmpty1() {
        if (tos1 == -1)
            return 1;
        else
            return 0;
    }

    bool isEmpty2() {
        if (tos2 == MaxSize)
            return 1;
        else
            return 0;
    }

    void push1(int e) {
        if (isFull())
            cout << "Stck full"<<endl;
        else {
            s[++tos1] = e;
        }
    }

    void push2(int e) {
        if (isFull())
            cout << "Stck full"<<endl;
        else {
            s[--tos2] = e;
        }
    }

    int pop1() {
        if (isEmpty1()) {
            cout << "Stack empty"<<endl;
            return 0;
        }  
        else {
            int temp = s[tos1--];
            return temp;
        }
    }

    int pop2() {
        if (isEmpty2()) {
            cout << "Stack empty"<<endl;
            return 0;
        }
        else {
            int temp = s[tos2++];
            return temp;
        }
    }

    void print1() {
        for (int i = tos1; i > -1; i--) {
            cout << s[i] << " ";
        }
    }

    void print2() {
        for (int i = tos2; i < MaxSize; i++) {
            cout << s[i] << " ";
        }
    }
   
    void printBoth() {
        cout << "1st Stack : [";
        print1();
        cout << "|| ";
        print2();
        cout << "] : 2nd stack"<<endl;
    }


};

int main()
{
    int size,ch;
    cout << "Enter Size : ";
    cin >> size;
    Stack s1(size);
    do {
        int e;
        cout << "\nEnter Your choice:\n1.Push 1st stack.\n2.Push 2nd stack\n3.Pop 1st stack.\n4.Pop 2nd stack.\n5.Print\n6.Exit. " << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            if (s1.isFull())
                cout << "Stack Full"<<endl;
            else {
                cout << "Enter element : " << endl;
                cin >> e;
                s1.push1(e);
                s1.printBoth();
            }
            break;
        case 2:
            if (s1.isFull())
                cout << "Stack Full" << endl;
            else {
                cout << "Enter element : " << endl;
                cin >> e;
                s1.push2(e);
                s1.printBoth();
            }
            break;
        case 3:
            cout<<"Element poped : "<<s1.pop1()<<endl;
            s1.printBoth();
            break;
        case 4:
            cout<<"Element poped : "<<s1.pop2()<<endl;
            s1.printBoth();
            break;
        case 5:
            s1.printBoth();
            break;
        case 6:
            cout << "Exiting..."<<endl;
            break;
        default:
            cout << "Invalid option!!!" << endl;

        }
    } while (ch!=6);



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
