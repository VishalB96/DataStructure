// LinearLinlkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

class LinkedList {
private:
    struct node* root;
public:
    LinkedList() {
        initLinkedList();
    }

    void initLinkedList() {
        root = NULL;
    }

    void insertLeft(int e) {
        struct node* t=new node;
        t->data = e;
        t->next = NULL;
        if (root == NULL)
            root = t;
        else {
            t->next = root;
            root = t;
        }
    }

    void insertRight(int e) {
        struct node* t,*n=new node;
        n->data = e;
        n->next = NULL;
        
        if (root == NULL)
            root = n;
        else {
            t = root;
            while (t->next != NULL) {
                t = t->next;
            }
            t->next = n;
        }

        
    }

    void deleteLeft() {
        struct node* t;
        if (root == NULL)
            cout << "Linked List Empty"<<endl;
        else {
            t = root;
            root = root->next;
            cout << "data deleted : " << t->data << endl;
            delete t;
        }

    }

    void deleteRight() {
        struct node* t, * t2;
        if(root==NULL)
            cout << "Linked List Empty" << endl;
        else if (root->next == NULL) {
            delete root;
            initLinkedList();
        }else
        {
            t = t2 = root;
            while (t->next != NULL) {
                t2 = t;
                t = t->next;
            }
            t2->next = NULL;
            cout << "Data Deleted : " << t->data << endl;
            delete t;
        }
    }

    void printLinlkedList() {
        struct node* t;
        if (root == NULL)
            cout << "Lined List Empty" << endl;
        else {
            t = root;
            while (t != NULL) {
                cout << t->data << " ";
                t = t->next;
            }
        }
        cout << endl;
    }

    bool search(int key) {
        struct node* s;
        if (root == NULL) {
            cout << "Lined List is Empty" << endl;
            return false;
        }
        else {
            s = root;
            do {
                if (s->data == key)
                    return true;
                s = s->next;
            } while (s->next != NULL);
        }
    }

    void deleteElement(int key) {
        struct node* s, * t;
        if (root == NULL)
            cout << "Linked List empty" << endl;
        else
        {
            s = t = root;
            while (s != NULL && s->data != key) {
                t = s;
                s = s->next;
            }

            if (s != NULL) {
                
                if (s == root) {
                    deleteLeft();//delete root element
                }
                else if (s->next == NULL) {
                    deleteRight();//delete rightmost element
                }
                else {
                    //delete middle element
                    t->next = s->next;
                    cout << "DATA DELETED : " << s->data<<endl;
                    delete s;
                }
            }
            else
                cout << "Element " << key << " Not Found!"<<endl;

        }
    }

};

int main()
{   
    int ch,e;
    LinkedList l1;
    do {
        cout << "Enter Your Choice :\n1.Insert left\n2.Insert right\n3.delete left\n4.delete right\n5.delete element\n6.search element\n7.print linked list\n8.exit" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter Element : ";
            cin >> e;
            l1.insertLeft(e);
            l1.printLinlkedList();
            break;
        case 2:
            cout << "Enter Element : ";
            cin >> e;
            l1.insertRight(e);
            l1.printLinlkedList();
            break;
        case 3:
            l1.deleteLeft();
            l1.printLinlkedList();
            break;
        case 4:
            l1.deleteRight();
            l1.printLinlkedList();
            break;
        case 5:
            cout << "Enter element to delete : ";
            cin >> e;
            l1.deleteElement(e);
            l1.printLinlkedList();
            break;
        case 6:
            cout << "Enter element to search : "  ;
            cin >> e;
            (l1.search(e))?cout<<"Found"<<endl:cout<<"Not found"<<endl;
            break;
        case 7:
            l1.printLinlkedList();
            break;
        case 8:
            cout << "Exiting...";
            break;
        default:
            cout << "enter valid option";
        }
        
    
    } while (ch != 8);
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
