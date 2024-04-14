#include <iostream>
#include <fstream>
#include <string>
#include "Deque.h"

using namespace std;

void inputFile() {
	string myText;

	// Read text file
	ifstream MyReadFile("input.txt");

	// While loop with getline to read file line by line
	while (getline(MyReadFile, myText)) {
		cout << myText;
	}

	MyReadFile.close();
}

int main() {

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
	
	inputFile();
}
