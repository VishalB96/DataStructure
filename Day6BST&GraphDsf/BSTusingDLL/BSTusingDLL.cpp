// BSTusingDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct node {
    int data;
    node* left, * right;
};
class BSTdll {
public:
    node* root,*n;
    int count = 0;

    BSTdll() {
        createLL();
    }

    void createLL() {
        root = NULL;
    }

    node* createNode(int e) {
        n = new node;
        n->data = e;
        n->left = n->right = NULL;
        return this->n;
    }

    node* getRoot() {
        return this->root;
    }

    void insert(node* p, node* n) {
        if (root == NULL)
            root = n;
        else {
            if (n->data < p->data) {
                if (p->left == NULL)
                    p->left = n;
                else
                    return(insert(p->left, n));
            }
            else {
                if (p->right == NULL)
                    p->right = n;
                else
                    return(insert(p->right, n));
            }
        }
    }

    void inorder(node* r) {
        if (r != NULL) {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

    void preorder(node* r) {
        if (r != NULL) {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    void postorder(node* r) {
        if (r != NULL) {
            postorder(r->left);
            postorder(r -> right);
            cout << r->data << " ";
        }
    }

    void countNodes(node* r) {
        
        if (r != NULL) {
            countNodes(r->left);
            count++;
            countNodes(r->right);
            
        }
    }


};

int main()
{
    BSTdll b1;
    b1.insert(b1.getRoot(), b1.createNode(45));
    b1.insert(b1.getRoot(), b1.createNode(20));
    b1.insert(b1.getRoot(), b1.createNode(2));
    b1.insert(b1.getRoot(), b1.createNode(30));
    b1.insert(b1.getRoot(), b1.createNode(54));
    b1.insert(b1.getRoot(), b1.createNode(278));
    b1.insert(b1.getRoot(), b1.createNode(29));
    b1.insert(b1.getRoot(), b1.createNode(21));
    //b1.insert(b1.getRoot(), b1.createNode(90));
    cout <<"inorder" << endl;
    b1.inorder(b1.getRoot());
    cout << endl <<"Preorder"<< endl;
    b1.preorder(b1.getRoot());
    cout << endl << "Postorder" << endl;
    b1.postorder(b1.getRoot());
    b1.countNodes(b1.getRoot());
    cout << endl << b1.count;
   
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
