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

//Determine if value is positive or negative
bool isPositive(int num) {
    bool state;
    if (num > 0) {
        return state = true;
    }
    else {
        return state = false;
    }
}

//determine if in or out of bounds
int bounds(int row, int col) {
    int min = 0, max = size;//

    if (row < 0) {
        row = min;
    }
    else if (row > max) {
        row = max;
    }
    
    if (col < 0) {
        col = min;
    }
    else if (col > max) {
        col = max;
    }
    return row, col;
}

//determine the direction
string Direction(bool state, int oldR, int oldC, int newR, int newC) {
    string direction;
    if (state == true) {
        if (newR < oldR) {
            direction = "N";
        }
        else if (newR > oldR) {
            direction = "S";
        }
        else if (newC < oldC) {
            direction = "W";
        }
        else if (newC > oldC) {
            direction = "E";
        }
    }
    else {
        if (newR < oldR && newC > oldC) {
            direction = "NE";
        }
        else if (newR < oldR && newC < oldC) {
            direction = "NW";
        }
        else if (newR > oldR && newC > oldC) {
            direction = "SE";
        }
        else if(newR > oldR && newC < oldC) {
            direction = "SW";
        }
    }

    return direction;
}

//template for motions
void moiton() {
    int value; // = vector element

    bool state = isPositive(value);

    if (state = true) {
        //vector element location
        //add value on to the vector
        bounds(); 
        Direction(); //save the directiosn into an array, vector, or q
    }
    else{
        //vector element location
        //add value on to the vector
        bounds();
        Direction(); 
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