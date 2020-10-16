// 03_binery2decimal_linkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
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
    node* getRoot() {
        return this->root;
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

    int bin2dec(node* r, int i) {
        int sum=0;
        i--;
        if (r->next == NULL) {
            sum = sum+ (r->data * (int)pow(2,i));
            return sum;
        }
            sum = (r->data * (int)pow(2, i))+ bin2dec(r->next, i);
            return sum;
        
    }

   

    
};

int main()
{
    LinkedList l;
    string bin;
    cout << "Enter the binery no : ";
    cin >> bin;
    for (int i = 0; i < bin.size();i++) {
        int c = bin.at(i)-'0';
        if (c == 0 || c == 1) {
            l.insertRight(c);
            
        }
        else {
            cout << "Enter Binery" << endl;
        }
    }

    l.printLinlkedList();
    cout << "Binary to Decimal is : "<< l.bin2dec(l.getRoot(), bin.size());
    
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
