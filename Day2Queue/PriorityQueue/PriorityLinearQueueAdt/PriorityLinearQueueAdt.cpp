// PriorityLinearQueueAdt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Q[100], MaxSize, Front, Rear;

void initQueue(int size) {
    Front = 0;
    Rear = -1;
    MaxSize = size;
}

bool isFull() {
    return (Rear == MaxSize) ? true :false;
}

bool isEmpty() {
    return (Front > Rear) ? true : false;
}

void sortByPriority() {
    
    for (int i = Front; i < Rear; i++) {
        for (int j = i + 1; j <= Rear; j++) {
            if (Q[i] > Q[j]) {
                int temp = Q[i];
                Q[i] = Q[j];
                Q[j] = temp;
            }
        }
    }
    
}
void EnQueue(int e) {
    if (isFull())
        cout << "Queue is Full" << endl;
    else {
        Rear++;
        Q[Rear] = e;
        sortByPriority();
    }
}

int DeQueue() {
    if (isEmpty()) {
        cout << "Queue is Empty";
        return 0;
    }
    else {
        int temp = Q[Front++];
        return temp;
    }
}

void PrintQueue()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else {
        for (int i = Front; i <= Rear; i++) {
            cout << Q[i] << " ";
        }
    }
}
int main()
{
    int size;
    cout << "Enter the size ";
    cin >> size;
    initQueue(size);
    int ch;
    do {
        cout << endl;
        cout << "Enter yout choice\n1.EnQueue\n2.DeQueue\n3.PrintQueue\n4.Exit" << endl;
        cin >> ch;
        cout << endl;
        switch (ch) {
        case 1:
            if (isFull())
                cout << "Queue is full" << endl;
            else {
                int t;
                cout << "Enter the element : ";
                cin >> t;
                EnQueue(t);
            }
            break;

        case 2:
            cout<<DeQueue()<<endl;
            break;

        case 3:
            PrintQueue();
            break;

        case 4:
            cout << "Exiting...." << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
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
