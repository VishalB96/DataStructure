// 02_Deque_2Queue1Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Deque {
public:
    int Q[100], MaxSize, front1, front2, rear1, rear2;

    Deque(int size) {
        initQueue(size);
    }
    void initQueue(int size) {
        MaxSize = size;
        front1 = 0;
        rear1 = -1;
        front2 = MaxSize - 1;
        rear2 = MaxSize;
    }

    bool isFull() {
       return (rear2 - rear1 == 1) ? 1 :  0;
    }

    void enqueue1(int e) {
        if (isFull())
            cout << "Queue full" << endl;
        else {
            Q[++rear1] = e;
        }
    }

    void enqueue2(int e) {
        if (isFull())
            cout << "Queue full" << endl;
        else {
            Q[--rear2] = e;
        }
    }

    int dequeue1() {
        if (front1 > rear1) {
            cout << "Queue1 Empty" << endl;
            return 0;
        }
        else {
            int temp = Q[front1++];
            if (front1 > rear1) {
                front1 = 0;
                rear1 = -1;
            }
            return temp;
        }
    }

    int dequeue2() {
        if (front2 < rear2) {
            cout << "Queue2 Empty" << endl;
            return 0;
        }
        else {
            int temp = Q[front2--];
            if (front2 < rear2) {
                front2 = MaxSize - 1;
                rear2 = MaxSize;
            }
            return temp;
        }
    }

    void print1() {
        for (int i = front1; i <= rear1; i++) {
            cout << Q[i] << " ";
        }
    }

    void print2() {
        for (int i = front2; i >= rear2; i--) {
            cout << Q[i] << " ";
        }
    }

    void printBoth() {
        cout << "Queue 1 : [ ";
        print1();
        cout << " || ";
        print2();
        cout << " ] : Queue2" << endl;
    }
};

int main()
{
    int size, ch;
    cout << "Enter size : ";
    cin >> size;
    Deque d1(size);

    do {
        int e;
        cout << "Enter choice\n1.Enqueue Q1\n2.Enqueue Q2\n3.DeQueue Q1\n4.DeQueue Q2\n5.printboth\n6.Exit" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            if (d1.isFull())
                cout << "Queue1 full" << endl;
            else {
                cout << "Enter element : ";
                cin >> e;
                d1.enqueue1(e);
                d1.print1();
                cout << endl;
                d1.printBoth();
            }
            break;
        case 2:
            if (d1.isFull())
                cout << "Queue2 full" << endl;
            else {
                cout << "Enter element : ";
                cin >> e;
                d1.enqueue2(e);
                d1.print2();
                cout << endl;
                d1.printBoth();
            }
            break;
        case 3:
            cout << "Element deleted : " << d1.dequeue1() << endl;
            d1.print1();
            cout << endl;
            d1.printBoth();
            break;
        case 4:
            cout << "Element deleted : " << d1.dequeue2() << endl;
            d1.print2();
            cout << endl;
            d1.printBoth();
            break;
        case 5:
            d1.printBoth();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
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
