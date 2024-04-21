#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Deque.h"

using namespace std;

// Directions
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

void output(const vector<vector <int>>& graph) {
    // Outputing data in the array
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

/* isValid */
bool isValid(vector<vector<bool>>& vis, int row, int col, int SIZE) {
    // If cell lies out of bounds
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
        return false;
    }

    // If cell is already visited
    if (vis[row][col]) {
        return false;
    }

    // Otherwise
    return true;
}

/* Breadth First Search */
void bfs(vector<vector <int>>& graph, vector<vector<bool>>& vis, int row, int col) {

    // Stores indices of the matrix cells
    LinkQueue r;
    LinkQueue c;

    int SIZE = graph.size();

    // Mark the starting cell as visited and push it into the queue
    r.enqueue(row);
    c.enqueue(col);
    vis[row][col] = true;

    // Iterate while the queue is not empty
    while (!r.isEmpty()) {
        int x = r.peek();
        int y = c.peek();

        cout << graph[x][y] << " ";

        r.dequeue();
        c.dequeue();

        // Go to the adjacent cells
        for (int i = 0; i < 4; i++) {
            int adjx = x + dRow[i]; // edit this to graph[row][col] to skip nodes like the trampoline
            int adjy = y + dCol[i]; // edit this to graph[row][col] to skip nodes like the trampoline

            if (isValid(vis, adjx, adjy, SIZE)) {
                r.enqueue(adjx);
                c.enqueue(adjy);

                vis[adjx][adjy] = true;
            }
        }
    }
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
    // cout << graph[0][0] << endl;

    // output(graph);

    vector<vector <bool>> visited(graph.size(), vector<bool>(graph.size()));

    bfs(graph, visited, 0, 0);

}

int main()
{
    ReadInputFile();

    return 0;
}