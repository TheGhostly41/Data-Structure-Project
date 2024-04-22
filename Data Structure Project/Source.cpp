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

/* Check if the element is a Positive */
bool isPositive(int num) {
    if (num > 0) {
        return true;
    }
    else {
        return false;
    }
}

/* Checking Direction */
string Directions(int oldR, int oldC, int newR, int newC, int value) {
    string direction;

    if (isPositive(value)) {
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
    else if (value == 0) {
        direction = "GOAL";
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
        else if (newR > oldR && newC < oldC) {
            direction = "SW";
        }
    }

    return direction;
}

/* Motion | this sets the restrictions based on the element that is being read */
void motion(vector<vector <int>>& graph, int value) {
    if (isPositive(value)) {
        cout << "Positive" << endl;
    }
    else {
        cout << "Negative" << endl;
    }
}

/* Breadth First Search */
void bfs(vector<vector <int>>& graph, vector<vector<bool>>& vis, int row, int col) {

    // Stores indices of the matrix cells
    LinkQueue r;
    LinkQueue c;

    int SIZE = graph.size();
    bool reached_End = false;
    const int GOAL = 0;
    int distance = 0;
    string dir;

    int oldX = 0;
    int oldY = 0;

    // vector for directions
    vector<string> directions;

    // Mark the starting cell as visited and push it into the queue
    r.enqueue(row);
    c.enqueue(col);
    vis[row][col] = true;

    // Iterate while the queue is not empty
    while (!r.isEmpty()) {
        int x = r.peek();
        int y = c.peek();

        // Directions function && isPositive

        int value = graph[x][y];

        dir = Directions(oldX, oldY, x, y, value);
        directions.push_back(dir);

        oldX = x;
        oldY = y;

        cout << graph[x][y] << " ";

        r.dequeue();
        c.dequeue();

        /* Ends when it hits GOAL = 0
        if (graph[x][y] == GOAL) {
            reached_End = true;
            break;
        }
        */

        if (value == GOAL) {
            reached_End = true;
            break;
        }

        motion(graph, value);

        // Go to the adjacent cells -- Marked for change
        for (int i = 0; i < 4; i++) {
            int adjx = x + dRow[i]; // edit this to graph[x][y] to skip nodes like the trampoline
            int adjy = y + dCol[i]; // edit this to graph[x][y] to skip nodes like the trampoline

            if (isValid(vis, adjx, adjy, SIZE)) {
                r.enqueue(adjx);
                c.enqueue(adjy);

                vis[adjx][adjy] = true;
            }
        }
    }

    // Directions output
    cout << endl;
    for (auto dir : directions) {
        cout << dir << " ";
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

    // Making 2D array
    vector<vector<int>> graph(SIZE, vector<int>(SIZE));

    // Adding all the data in the array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            inputFile >> graph[i][j];
        }
    }

    inputFile.close();

    const int dimensions = SIZE * SIZE;
    cout << "Matrix Dimension: " << dimensions << endl << endl;

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