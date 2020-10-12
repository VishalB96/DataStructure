// DoublyLinkedListADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    node* left, * right;
};

class DLinkedList {
private:
    struct node* root;
public:
    DLinkedList() {
        createDLL();
    }

    void createDLL() {
        root = NULL;
    }

    void insertLeft(int e) {
        node* n;
        n = new node;
        n->data = e;
        n->left=n->right = NULL;
        if (root == NULL)
            root = n;
        else {
            root->left = n;
            n->right = root;
            root = n;
        }
    }


    void deleteLeft() {
        node* t;
        if (root == NULL)
            cout << "Empty" << endl;
        else if (root->right == NULL) {
            delete root;
            createDLL();
        }else
        {
            t = root;
            root = t->right;
            root->left = NULL;
            cout << t->data << " Delted!" << endl;
            delete t;
        }
    }

    void insertRight(int e) {
        node*n2,* n=new node;
        n->data = e;
        n->right = n->left = NULL;
        if (root == NULL)
            root = n;
        else {
            n2 = new node;
            n2 = root;
            while (n2->right != NULL)
                n2 = n2->right;
            n2->right = n;
            n->left = n2;

        }

    }

    void deleteRight() {
        node* n, * n2;
        if (root == NULL)
            cout << "Empty" << endl;
        else if (root->right == NULL) {
            delete root;
            createDLL();
        }else
        {
            n = n2 = root;
            while (n->right != NULL) {
                n2 = n;
                n = n->right;
            }
            cout << n->data << " Delted!" << endl;
            n2->right = NULL;
            delete n;
        }
    }

    void printLR() {
        node* n;
        
        if (root == NULL)
            cout << "Empty!" << endl;
        else {
            n = root;
            while (n != NULL) {
                cout << n->data << " ";
                n = n->right;
            }
            cout << endl;
        }
    }

    void printRL() {
        node* n;
        n = root;
        if (root == NULL)
            cout << "Empty" << endl;
        else {
            while (n->right != NULL)
                n = n->right;
            while (n != NULL) {
                cout << n->data << " ";
                n = n->left;
            }
            cout << endl;

        }
    }
};

int main()
{
    int ch, e;
    DLinkedList dll;
    
    do {
        cout << "Enter choice" << endl;
        cout << "1.Insert left\n2.InsertRight\n3.Delete Left\n4.Delete Right\n5.Print\n6.Print reverse\n7.exit" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter element : ";
            cin >> e;
            dll.insertLeft(e);
            dll.printLR();
            break;
        case 2:
            cout << "Enter element : ";
            cin>>e;
            dll.insertRight(e);
            dll.printLR();
            break;
        case 3:
            dll.deleteLeft();
            dll.printLR();
            break;
        case 4:
            dll.deleteRight();
            dll.printLR();
            break;
        case 5:
            dll.printLR();
            break;
        case 6:
            dll.printRL();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "invalid choice!" << endl;

        }
    } while (ch != 7);
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
