// QueueUsingLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class DynamicQueue {
private:
    struct node* front, * rear;
public:
    DynamicQueue() {
        initQueue();
    }

    void initQueue() {
        front = rear = NULL;
    }

    void enQueue(int e) {
        struct node* n;
        n = new node;
        n->data = e;
        n->next = NULL;

        if (rear == NULL) {
            front = rear = n;
        }
        else {
            rear->next = n;
            rear = n;
        }
           
    }

    void deQueue() {
        struct node* n;
       
        if (rear == NULL)
            cout << "Queue Empty" << endl;
        else {
            n = front;
            front = n->next;
            cout << n->data << " Deleted" << endl;
        }
    }

    void printQueue() {
        struct node *p;
        if(rear==NULL)
            cout << "Queue Empty" << endl;
        else {
            p = front;
            while (p != NULL) {
                cout << p->data << " ";
                p = p->next;
            }
            cout << endl;
        }

    }
};

int main()
{
    int ch,e;
    DynamicQueue dq;
    do {
        cout << "Enter choice\n1.Enqueue\n2.DeQueue\n3.Print Queue\n4.Exit" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter element : ";
            cin >> e;
            dq.enQueue(e);
            dq.printQueue();
            break;
        case 2:
            dq.deQueue();
            dq.printQueue();
            break;
        case 3:
            dq.printQueue();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Not valid" << endl;


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
