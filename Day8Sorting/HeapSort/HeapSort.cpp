// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void HeapSort(int a[], int size) {
    int i, j, pc, done, t;
    for (i = size - 1; i > 0; i--) {
        for (j = 0; j <= i; j++) {
            pc = j;
            done = 0;
            while (pc > 0 && (pc / 2) >= 0 && done != 1) {
                if (a[pc / 2] < a[pc]) {
                    t = a[pc];
                    a[pc] = a[pc / 2];
                    a[pc / 2] = t;
                    pc = pc / 2;
                }
                else
                {
                    done = 1;
                }
            }
        }

        t = a[i];
        a[i] = a[0];
        a[0] = t;

    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}


int main()
{
    int size, a[100];
    cout << "Enter no of elements : ";
    cin >> size;
    cout << "Enter elements : " << endl;
    for (int i = 0; i < size; i++) {
        int e;
        cin >> e;
        a[i] = e;
    }

    cout << "Enterd array is : ";
    printArray(a, size);
    cout << endl;

    cout << "After heap sort : ";
    HeapSort(a, size);
    printArray(a, size);
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
