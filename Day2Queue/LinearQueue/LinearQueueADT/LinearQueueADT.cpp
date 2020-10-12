// LinearQueueADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int Q[100], MaxSize, front, rear;

class LinearQueue {
public:
    int Q[100], MaxSize, front, rear;

    LinearQueue(int size) {
        initQueue(size);
    }
    void initQueue(int size) {
        MaxSize = size;
        front = 0;
        rear = -1;
    }

    bool isFull() {
        if (rear == MaxSize - 1)
            return true;
        else
            return false;
    }

    bool isEmpty() {
        if (front > rear)
            return true;
        else
            return false;
    }

    void EnQueue(int e) {
        if (isFull())
            cout << "Queue is full" << endl;
        else
            Q[++rear] = e;
    }

    int DeQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return 0;
        }
        else
        {
            int temp = Q[front];
            front++;
            if (isEmpty())
                initQueue(MaxSize);
            return temp;
        }
    }

    void PrintQueue() {
        if (isEmpty())
            cout << "Queue is empty" << endl;
        else {
            for (int i = front; i <= rear; i++) {
                cout << Q[i] << " ";
            }
        }
    }

    void resetQueue(int size) {
        initQueue(size);
    }
};


int main()
{
    int size;
    cout << "Enter the size ";
    cin >> size;
    LinearQueue lq(size);
    int ch;
    do {
        cout << endl;
        cout << "Enter yout choice\n1.EnQueue\n2.DeQueue\n3.PrintQueue\n4.Exit"<<endl;
        cin >> ch;
        cout << endl;
        switch (ch) {
        case 1:
            if (lq.isFull()) 
                cout << "Queue is full"<<endl;
                
            else {
                int t;
                cout << "Enter the element : ";
                cin >> t;
                lq.EnQueue(t);
            }
            break;
            
        case 2:
            cout << lq.DeQueue() << endl;
            break;

        case 3:
            lq.PrintQueue();
            break;

        case 4:
            cout << "Exiting...."<<endl;
            break;

         default:
            cout << "Wrong choice!"<<endl;
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
