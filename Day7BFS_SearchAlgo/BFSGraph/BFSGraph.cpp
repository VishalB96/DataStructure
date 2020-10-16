// BFSGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Graph {
public:
    int AdjM[10][10], nodes, visited[10];

    Graph(int size) {
        createGraph(size);
    }

    void createGraph(int size) {
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
        visited[source] = 1;
        cout << source << " ";
        for (int i = 0; i < nodes; i++) {
            if (AdjM[source][i] == 1 && visited[i] == 0) {
                DFS(i);
            }
        }
    }

    void BFS(int source) {
        int Q[100],front=0,rear=-1,e;
        visited[source] = 1;
        Q[++rear] = source;
        while (front <= rear) {
            e = Q[front++];
            cout << e << " ";
            for (int i = 0; i < nodes; i++) {
                if (AdjM[e][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    Q[++rear] = i;
                }
            }
        }
    }

    void resetVisited() {
        for (int i = 0; i < nodes; i++)
            visited[i] = 0;
    }
};
int main()
{
    int ch,size,e;
    cout << "Enter no of nodes : ";
    cin >> size;
    Graph g1(size);
    do {
        cout << "\nEnter choice:\n1.DFS\n2.BFS\n3.Exit." << endl;
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter source : ";
            cin >> e;
            if(e>size-1){
                cout << "node not present" << endl;
                break;
            }
            g1.resetVisited();
            cout << "DFS : ";
            g1.DFS(e);
            cout << endl;
            break;

        case 2:
            cout << "Enter source : ";
            cin >> e;
            if (e > size - 1) {
                cout << "node not present" << endl;
                break;
            }
            g1.resetVisited();
            cout << "BFS : ";
            g1.BFS(e);
            cout << endl;
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (ch!=3);
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
