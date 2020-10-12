// CircularLinkedListADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next ;
};

class CircularLL {
private:
    node* root, * last;
public:
    CircularLL() {
        createCLL();
    }

    void createCLL() {
        root = last = NULL;
    }

    void insertLeft(int e) {
        struct node* n;
        n = new node;
        n->data = e;
        n->next = NULL;
        if (root == NULL) {
            root = last = n;
            last->next = root;
        }
            
        else {
            n->next = root;
            root = n;
            last->next = root;
        }
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

    void deleteLeft() {
        struct node* t;
        if (root == NULL)
            cout << "LinkedList is empty" << endl;
        else if (root->next == root) {
            delete root;
            createCLL();
        }else
        {
            t = root;
            root = root->next;
            last->next = root;
            cout << "Element " << t->data << " deleted!" << endl;
            delete t;
        }
        
    }

    void deleteRight() {
        struct node* t,*t2;
        if(root==NULL)
            cout << "LinkedList is empty" << endl;
        else if (root->next == root) {
            delete root;
            createCLL();
        }
        else
        {
            t = new node;
            t = t2 = root;
            while (t != last) {
                t2 = t;
                t = t->next;
            }
            last = t2;
            last->next = root;
            cout << "Element " << t->data << " deleted" << endl;
            delete t;
        }
        if (root == NULL||last==NULL) {
            this->createCLL();
        }
    }

    void printCLL() {
        node* t;
        if(root==NULL)
            cout << "LinkedList is empty" << endl;
        else {
            t = new node;
            t = root;
            do {
                cout << t->data << " ";
                t = t->next;
            } while (t!=root);
            cout << endl;
        }
    }
};

int main()
{
    CircularLL l1;
    int ch, e;
    do {
        cout << "Enter Choice.\n1.insertLeft\n2.insert right\n3.delete left\n4.delete right\n5.print\n6.exit." << endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element : " << endl;
            cin >> e;
            l1.insertLeft(e);
            l1.printCLL();
            break;
        case 2:
            cout << "Enter element : " << endl;
            cin >> e;
            l1.insertRight(e);
            l1.printCLL();
            break;
        case 3:
            l1.deleteLeft();
            l1.printCLL();
            break;
        case 4:
            l1.deleteRight();
            l1.printCLL();
            break;
        case 5:
            l1.printCLL();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Enter valid choice" << endl;
            
        }
    } while (ch != 6);
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
