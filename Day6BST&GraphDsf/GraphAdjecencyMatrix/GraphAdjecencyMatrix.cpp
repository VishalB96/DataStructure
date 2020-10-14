// GraphAdjecencyMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class GraphA {
public:
    int AdjM[10][10], nodes, visited[10];

    GraphA(int size) {
        createGraph(size);
    }

    void createGraph(int size){
        nodes = size;
        int src, des;
        for (src = 0; src < nodes; src++) {
            for (des = 0; des < nodes; des++) {
                cout << "From " << src << " to " << des << " : ";
                cin >> AdjM[src][des];
            }
        }

    }

    void DFS(int source) {
        int i;
        visited[source] = 1;
        cout << source << " ";
        for (i = 0; i < nodes; i++) {
            if (AdjM[source][i] == 1 && visited[i] != 1) {
                DFS(i);
            }
        }
    }


};

int main()
{
    int size;
    cout << "Enter no of nodes : ";
    cin>>size;
    GraphA g1(size);

    g1.DFS(2);

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
