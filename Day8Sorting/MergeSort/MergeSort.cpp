// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Array {
public:
    int a[100],size;
    
    Array(int size) {
        this->size = size;
        cout << "Enter elements : " << endl;
        for (int i = 0; i < size; i++) {
            int e;
            cin >> e;
            a[i] = e;
        }
    }

    int getSize() {
        return this->size;
    }
    void MergeSort(int start, int end) {
        int mid;
        if (start != end) {
            mid = (start + end) / 2;
            MergeSort(start, mid);
            MergeSort(mid + 1, end);

            Merger(start, mid, end);
        }
    }

    void Merger(int start, int mid, int end) {
        
        int i, j, t[100], ti;

        ti = i = start;
        j = mid + 1;

        while (i <= mid && j <= end) {
            if (a[i] < a[j])
                t[ti++] = a[i++];
            else
                t[ti++] = a[j++];
        }

        while (i <= mid) {
            t[ti++] = a[i++];
        }
        while (j <= end) {
            t[ti++] = a[j++];
        }

        for (int k = start; k <= end; k++) {
            a[k] = t[k];
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
    }
};


int main()
{
    int size;
    cout << "Enter no of elements : ";
    cin >> size;
    
    Array a(size);

    cout << "Enterd array is : ";
    a.printArray();
    cout << endl;

    cout << "After Merge sort : ";
    a.MergeSort(0, size-1);
    a.printArray();
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
