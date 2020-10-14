// StaticBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class StaticBinaryT {
public:
    int bt[100],size,count=0;

    StaticBinaryT(int size) {
        createBT(size);
    }

    void createBT(int size) {
        this->size = size;
        for (int i = 0; i < size; i++) {
            bt[i] = NULL;
        }

    }

    void insertBT(int e) {
        int i;
        if (bt[0] == NULL) {
            bt[0] = e;
            count++;
        }
            
        else {
            for ( i = 0; bt[i]!=NULL;) {
                if (e < bt[i]) {
                    i = (2 * i) + 1;
                }
                else if(bt[i]<=e) {
                    i = (2 * i) + 2;
                }
            }
            bt[i] = e;
            count++;
        }
        cout << count;
        
    }
    //INorder arrangement fro given tree
    void inorder(int p) {
        for (int i = p; bt[i] != NULL&&i<size;) {//visiting node is not empty and tree is not over
            if(bt[(2 * i) + 1]!=NULL)//if left node is not empty
                inorder((2 * i) + 1);//inorder()on left node
            cout << bt[i] << " ";//print current node
            if (bt[(2 * i) + 2] != NULL)//if right node is not empty
                inorder((2 * i) + 2);//inorder() on  right node
            break;
        }
    }

    void preorder(int p) {
        if (bt[p] != NULL && p < size) {
            cout << bt[p] << " ";
            if (bt[(2 * p) + 1] != NULL)
                preorder((2 * p) + 1);
            if (bt[(2 * p) + 2] != NULL)
                preorder((2 * p) + 2);
        }
    }
};
/*
void preorder(node* r) {
    while (r != NULL) {
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(node* r) {
    while (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
}


}*/
int main()
{
    
    int inp[] = { 50,28,60,8,2,100,75,6,4};
    StaticBinaryT bt1(9);

    for (int i = 0; i < 7; i++) {
        bt1.insertBT(inp[i]);
    }

   
    for (int i = 0; i < 9; i++) {
        cout << bt1.bt[i] << endl;
    }
    cout << "Inorder" << endl;
    bt1.inorder(0);
    cout << endl << "Preorder" << endl;
    bt1.preorder(0);
   
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
