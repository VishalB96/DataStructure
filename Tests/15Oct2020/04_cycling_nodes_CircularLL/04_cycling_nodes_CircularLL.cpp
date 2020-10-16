// 04_cycling_nodes_CircularLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class CircularLL {
public:
    node* root, * last;

    CircularLL() {
        createCLL();
    }

    void createCLL() {
        root = last = NULL;
    }

    void insertRight(int e) {
        struct node* n;
        n = new node;
        n->data = e;
        n->next = NULL;
        if (root == NULL) {
            root = last = n;
            last->next = root;
        }
        else {
            last->next = n;
            last = n;
            last->next = root;
        }
    }

    void printCLL() {
        node* t;
        if (root == NULL)
            cout << "LinkedList is empty" << endl;
        else {
            t = new node;
            t = root;
            do {
                cout << t->data << " ";
                t = t->next;
            } while (t != root);
            cout << endl;
        }
    }

    void cycle(int cy) {
        int count = 0;
        node* n;
        n = root;
        do {
            count++;
            n = n->next;

        } while (n != root);
        cy = cy % count;//limiting no of cycles to no of nodes
        //cout << cy << " cy" << endl;
        for (int i = cy; cy != 0; cy--) {
            node* t;
            if (root != NULL) {
                t = root;
                while (t->next != last) {
                    t = t->next;
                }
                last = t;
                root = last->next;
            }  
        }
    }

};

int main()
{
    CircularLL l1;
    int ch, e;
    do {
        cout << "Enter Choice.\n1.insert right\n2.cycle Linked list\n3.exit." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element : " << endl;
            cin >> e;
            l1.insertRight(e);
            l1.printCLL();
            break;
        case 2:
            cout << "Enter no of cycles : ";
            cin >> e;
            cout << "Before cycle : ";
            l1.printCLL();
            l1.cycle(e);
            cout << "After cycle : ";
            l1.printCLL();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Enter valid choice" << endl;

        }
    } while (ch != 3);
   
    
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
