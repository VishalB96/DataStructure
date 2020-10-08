// CircularQueueAdt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Q[100], MaxSize, Front, Rear, Count;

void initQueue(int size) {
    Front = 0;
    Rear = -1;
    MaxSize = size;
    Count = 0;
}

bool isEmpty() {
    if (Count == 0)
        return true;
    else
        return false;
}

bool isFull() {
    if (Count == MaxSize)
        return true;
    else
        return false;
}

void EnQueue(int e) {
    if (isFull())
        cout << "Queue is full"<<endl;
    else {
        Rear =(Rear+1) % MaxSize;
        Q[Rear] = e;
        Count++;
    }
}

int DeQueue() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return 0;
    }
    else {
        int temp = Q[Front];
        Front = (Front + 1) % MaxSize;
        Count--;
        return temp;
    }
}

void PrintQueue() {
    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else
    {
        cout << "[ ";
        for (int i = Front, c = 0; c < Count; i=(i+1)%MaxSize, c++)
            cout << Q[i] << " ";
        cout << " ]";
    }
}
//[12][22][43][4]
// 2    1   0  4
 
int main()
{
   
    cout << "num" << n;
    int size,ch;
    cout << "Enter the size : ";
    cin >> size;
    initQueue(size);
    
    do {
        cout << "Enter Your Choice :\n1.EnQueue.\n2.DeQueue.\n3.PrintQueue.\n4.Exit.\n";
        cin >> ch;

        switch (ch) {
        case 1:
            if (isFull())
                cout << "Queue is Full";
            else {
                int e;
                cout << "Enter elemment : ";
                cin >> e;
                EnQueue(e);
            }
            break;

        case 2:
            cout<<DeQueue()<<endl;
            break;

        case 3:
            PrintQueue();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Enter valid option!" << endl;
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
