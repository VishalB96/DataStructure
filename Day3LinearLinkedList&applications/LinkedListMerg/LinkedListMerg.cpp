// LinkedListMerg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class LinkedList {
public:
    struct node* root;

    LinkedList() {
        initLinkedList();
    }

    node* getRoot() {
        
        return this->root;
    }

    void setRoot(node* root) {
        this->root=root;
    }

    void initLinkedList() {
        root = NULL;
    }

    void insertLeft(int e) {
        struct node* t = new node;
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
        struct node* t, * n = new node;
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
            cout << "Linked List Empty" << endl;
        else {
            t = root;
            root = root->next;
            cout << "data deleted : " << t->data << endl;
            delete t;
        }

    }

    void deleteRight() {
        struct node* t, * t2;
        if (root == NULL)
            cout << "Linked List Empty" << endl;
        else {
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
                    cout << "DATA DELETED : " << s->data << endl;
                    delete s;
                }
            }
            else
                cout << "Element " << key << " Not Found!" << endl;

        }
    }

    void insertInOrder(int e) {
       
    }

    void mergeLL(node* l1, node* l2) {
        struct node *n,*last=new node;
        static node* root3 = NULL;
        
        while (l1 != NULL && l2 != NULL) {
            n = new node;
            if (l1->data < l2->data) {
                n->data = l1->data;
                l1 = l1->next;
            }
            else {
                n->data = l2->data;
                l2 = l2->next;
            }
            n->next = NULL;

            if (root3 == NULL) 
                root3 = last = n;
            else
            {
                last->next = n;
                last = n;
            } 
        }
        
        while (l1 != NULL) {
            n = new node;
            n->data = l1->data;
            n->next = NULL;

            l1 = l1->next;

            last->next = n;
            last = n;


        }

        while (l2 != NULL) {
            n = new node;
            n->data = l2->data;
            n->next = NULL;

            l2 = l2->next;

            last->next = n;
            last = n;
        }
        
        this->root = root3;

       

    }

};

/*
void choices(LinkedList &ll) {
    int ch,e;
    do {

        cout << "Enter Your Choice:\n1.Insert\n2.Stop" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter Element in list: ";
            cin >> e;
            ll.insertRight(e);
            ll.printLinlkedList();
            break;

        case 2:
            cout << "Stoping..." << endl;
            break;
        default:
            cout << "enter valid option" << endl;
        }


    } while (ch != 2);
}
*/


int main()
{
    LinkedList l1;
    LinkedList l2;
    LinkedList l3;
    int ch, e;
    
    cout << "ENTER DATA IN LINKEDLIST 1 :" << endl;
    //choices(l1);
   do {

        cout << "Enter Your Choice for l1:\n1.Insert\n2.Stop" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter Element in list: ";
            cin >> e;
            l1.insertRight(e);
            l1.printLinlkedList();
            break;

        case 2:
            cout << "Stoping..." << endl;
            break;
        default:
            cout << "enter valid option"<<endl;
        }


    } while (ch != 2);


    cout << "Enter Data In linkedList 2 : " << endl;
    //choices(l2);
    do {

        cout << "Enter Your Choice for l2:\n1.Insert\n2.Stop" << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter Element in list: ";
            cin >> e;
            l2.insertRight(e);
            l2.printLinlkedList();
            break;

        case 2:
            cout << "Stoping..."<<endl;
            break;
        default:
            cout << "enter valid option"<<endl;
        }


    } while (ch != 2);

    cout << "Merged list : ";
    l3.mergeLL(l1.getRoot(),l2.getRoot());
    l3.printLinlkedList();
   
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
