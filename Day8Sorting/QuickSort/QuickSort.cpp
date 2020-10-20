// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int a[100];

void QuickSort(int start, int end) {
    int i, j, pivot, t;
    i  = start;
    j = end;
    pivot = (start + end) / 2;
    while (i < j) {
        while (a[i] < a[pivot])
        {
            i++;
        }
        while (a[j] > a[pivot])
        {
            j--;
        }
        if (i < j) {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    if (i < end)
        QuickSort(i+1, end);
    if (start < j)
        QuickSort(start, j - 1);
}


void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}
int main()
{
    int size;
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

    cout << "After Quick sort : ";
    QuickSort(0, size-1);
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
