#include <iostream>
#include <fstream>
#include <string>
#include "Deque.h"

using namespace std;

void inputFile() {
	string dimensions;

	string FileName = "input.txt";
	ifstream inputFile;
	inputFile.open(FileName.c_str());

	if (inputFile.is_open()) {

		// Getting the first line
		getline(inputFile, dimensions);

		int SIZE = stoi(dimensions); // converts the string to an integer

		SIZE *= SIZE;
		cout << SIZE;


		/*
		for (int i = 0; i < SIZE; i++) {
			inputFile >> numbers[i];
			cout << numbers[i] << " ";
		}
		*/

		inputFile.close();
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
