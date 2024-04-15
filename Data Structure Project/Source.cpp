#include <iostream>
#include <fstream>
#include <string>
#include "Deque.h"

using namespace std;

const int arraySize = 64;
int numbers[arraySize];

void inputFile() {
	string dimensions;

	string FileName = "input.txt";
	ifstream inputFile;
	inputFile.open(FileName.c_str());

	if (inputFile.is_open()) {

		// Getting the first line
		getline(inputFile, dimensions);

		// converts the string to an integer
		int SIZE = stoi(dimensions);

		SIZE *= SIZE;
		cout << "Matrix Dimension: " << SIZE << endl << endl;

		// Making 2D array
		const int newSize = 8;
		int TwoDArray[newSize][newSize];

		// Adding all the data in the array
		for (int row = 0; row < newSize; row++) {
			for (int col = 0; col < newSize; col++) {
				inputFile >> TwoDArray[row][col];
			}
		}

		inputFile.close();

		// Outputing data in the array
		for (int r = 0; r < newSize; r++) {
			for (int c = 0; c < newSize; c++) {
				cout << TwoDArray[r][c] << "   ";
			}
			cout << endl;
		}

		/*
		// Goes through the entire txt file and adds it to the array
		for (int i = 0; i < arraySize; i++) {
			inputFile >> numbers[i];
			cout << i+1 << ".  " << numbers[i] << endl;
		}
		*/
	}
	else {
		cout << "Cant open file or not located, File name: " << FileName << endl;
	}
}

int main() {

	/*
	LinkQueue testing;

	testing.enqueue(1);
	testing.enqueue(4);
	testing.enqueue(1);

	auto testingPeek = testing.peek();
	cout << testingPeek << endl;

	int testingCount = testing.getCount();
	cout << testingCount << endl;

	testing.display();

	testing.dequeue();

	testing.display();
	*/
	
	inputFile();
}
