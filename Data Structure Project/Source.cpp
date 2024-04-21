#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Deque.h"

using namespace std;

void output(const vector<vector <int>>& graph) {
    // Outputing data in the array
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

/* Breadth First Search */
vector<int> bfs(vector<vector <int>>& graph, int start) {

    const int GOAL = 0;
    vector<bool> visited(graph.size(), false);
    vector<int> traversal;
    LinkQueue q;

    visited[start] = true;
    q.enqueue(start);

    while (!q.isEmpty()) {
        int current = q.peek();
        q.dequeue();
        traversal.push_back(current);

        for (int neighbor = 0; neighbor < graph[current].size(); neighbor++) {
            if (graph[current][neighbor] != 0 && !visited[neighbor]) {  // Check if edge exists and neighbor is not visited
                visited[neighbor] = true;
                q.enqueue(neighbor);
            }
        }
    }

    return traversal;
}

void ReadInputFile() {
    string firstLine;

    string FileName = "input.txt";
    ifstream inputFile;
    inputFile.open(FileName.c_str());

    if (!inputFile.is_open()) {
        cout << "Cannot locate " << FileName << endl;
    }

    // Getting the first line
    getline(inputFile, firstLine);

    // converts the string to an integer
    const int SIZE = stoi(firstLine);

    const int dimensions = SIZE * SIZE;
    cout << "Matrix Dimension: " << dimensions << endl << endl;

    // Making 2D array
    vector<vector<int>> graph(SIZE, vector<int>(SIZE));

    // Adding all the data in the array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();

    // Outputing data in the array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl << endl;

    // output(graph);

    int start = (0, 0);
    vector<int> traversal = bfs(graph, start);

    for (int node : traversal) {
        cout << node << " ";
    }

}

int main()
{
    ReadInputFile();

    return 0;
}
