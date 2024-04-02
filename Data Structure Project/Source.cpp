#include <iostream>
#include "Deque.h"

using namespace std;

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

}