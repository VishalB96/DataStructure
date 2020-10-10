// StackUsingLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node*next;
};

class DynamicStack {
private:
    struct node* tos;
public:
    DynamicStack() {
        initStack();
    }

    void initStack() {
        tos = NULL;
    }

    void push(int e) {
        struct node* t;
        t = new node;
        t->data = e;
        t->next = NULL;
        if (tos == NULL)
            tos = t;
        else
        {
            t->next = tos;
            tos = t;
        }
    }

    void pop() {
        struct node* t;
        if (tos == NULL)
            cout << "Stack empty" << endl;
        else
        {
            t = tos;
            tos = tos->next;
            cout << t->data << " Poped" << endl;
            delete t;
        }
    }

    void printStack() {
        struct node* p;
        p = tos;
        if (tos == NULL)
            cout << "Stack empty" << endl;
        else
        {
            
            while (p != NULL) {
                cout << p->data << " ";
                p = p->next;
            }

        }
    }
};

int main()
{
    DynamicStack ds;
    int ch,e;

    do {
        cout << "Enter choice:\n1.push\n2.pop\n3.print stack\n4Exit." << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter element : ";
            cin >> e;
            ds.push(e);
            ds.printStack();
            break;
        case 2:
            ds.pop();
            ds.printStack();
            break;
        case 3:
            ds.printStack();
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Enter valid choice" << endl;

        }
    } while (ch != 4);
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
