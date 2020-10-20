// SelectionSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void SelectionSort(int a[], int size) {
    int min,pos, i, j;
    for (i = 0; i < size; i++) {
        min = a[i];
        pos = i;
        for (j = i+1; j < size ; j++) {
            if (min > a[j]) {
                min = a[j];
                pos = j;
            }
        }
        a[pos] = a[i];
        a[i] = min;
    }
}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}

int main()
{
    int size, ch, a[100];
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

    cout << "After selection sort : ";
    SelectionSort(a, size);
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
