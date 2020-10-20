// BinerySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int a[100];

int BinerySearch(int start, int end, int key) {
    if (start == end) 
        return((key == a[start]) ? 1 : -1);
    else {
        int mid = (start + end) / 2;
        if (key == a[mid])
            return mid;
        else {
            return ((key < a[mid]) ? (BinerySearch(start, mid - 1, key)) : (BinerySearch(mid + 1, end, key)));
        }
    } 
}

void Sort(int a[],int size) {
    
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int size, ch;
    cout << "Enter no of elements : ";
    cin >> size;
    cout << "Enter elements : " << endl;
    for (int i = 0; i < size; i++) {
        int e;
        cin >> e;
        a[i] = e;
    }

    cout << "Enterd array is : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    Sort(a,size);
    cout << "After sorting array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    do {
        cout << "1.search elemnt\n2.exit";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter element : ";
            int e;
            cin >> e;
            int i = BinerySearch(0,size-1,e);
            if (i == -1)
                cout << "Element " << e << " not found." << endl;
            else
                cout << "Element " << e << " found "<< endl;
        }
    } while (ch != 2);
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
