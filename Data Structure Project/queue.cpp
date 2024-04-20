#pragma once

#include<iostream>

using namespace std;

typedef int Type;
const int UNDEFINED = -1;

class LinkQueue {
private:
	// Node Class
	class Node {
	public:
		Type data;
		Node* next;

		Node(Type d) {
			data = d;
			next = nullptr;
		}
	};

	// data members
	Node* front, * back;

public:
	// constructor
	LinkQueue() {
		front = back = nullptr;
	}

	// destructor
	~LinkQueue() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	// copy constructor
	LinkQueue(const LinkQueue& source) {
		Node* srcPtr = source.front;
		front = back = nullptr;

		while (srcPtr != nullptr) {
			enqueue(srcPtr->data);
			srcPtr = srcPtr->next;
		}
	}

	// overloaded assignment operator
	LinkQueue& operator=(const LinkQueue& source) {
		if (this != &source) {

			while (!isEmpty()) {
				dequeue();
			}

			Node* srcPtr = source.front;

			while (srcPtr != nullptr) {
				enqueue(srcPtr->data);
				srcPtr = srcPtr->next;
			}
		}

		return *this;
	}

	// Other Operations

	bool isEmpty() const {
		return front == nullptr;
	}

	bool isFull() const {
		Node* temp = new Node(1);

		if (!temp) {
			return true;
		}
		else {
			delete temp;
			return false;
		}
	}

	int getCount() const {
		Node* ptr = front;
		int count = 0;

		while (ptr != nullptr) {
			count++;
			ptr = ptr->next;
		}

		return count;
	}

	Type peek() const {
		if (isEmpty()) {
			return UNDEFINED;
		}
		else {
			return front->data;
		}
	}

	bool dequeue() {
		if (isEmpty()) {
			return false;
		}

		Node* ptr = front;
		front = front->next;
		delete ptr;

		if (front == nullptr) {
			// when the last node just get removed
			back = nullptr;
		}

		return true;
	}

	bool enqueue(Type d) {
		if (isFull()) {
			return false;
		}

		Node* ptr = new Node(d);

		if (back != nullptr) {
			back->next = ptr;
			back = ptr;
		}
		else {
			front = back = ptr;
		}

		return true;
	}


	bool reverse( Type* arr[]) {
		//code goes here
		return true;
	}
	void display() const {
		Node* ptr = front;

		while (ptr != nullptr) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}

		cout << endl;
	}
	
	//algorithm/////////

	//will need to mport the size of the matrix
	int totalSize = SIZE * SIZE;
	int Agecency[5] = { 0 };//list goes in here

	//function to trigger the chain reaction
	int alg(int totalSize, int g[]) {		
		front; //node
		back; //node 

		int prev = breadth(front);

		return reconsruct(front, end, prev);
	}

	//function to execute the algorithm
	int breadth(int Font) {
		//LinkQueue r;
		front;
		enqueue(front);

		//mayneed to change from an array to a vector/matrix
		bool hasVisited[totalSize] = { false };
		hasVisited[front] = true;


		// will track the shortest path; tracks parent
		int path[size] = { nullptr };

		///this may need to be a dynamic array
		int neighbours[4] = Agecency.get(spot);
		
		Node* spot;

		while (!isEmpty()) {
			//taking out top node from queue
			spot = dequeue(front); //it's suppose to be dequeue but it may have to be peek instead
			//retrieving the neighbors of the node from the adjecency list
			neighbours[i] = { find(spot) };
			//if this doesn't work would passing the entire array work?
			//the find dunction will need ot return the location on the array that the spot is on
		}

		for (auto next : neighbours) {
			//visiting unvisites nodes
			if (!hasVisited[next]) {
				enqueue(next);
				hasVisited[next] = { true };
				//saving the parent node
				path[next] = { spot }; //is accessign the top of the quwuw
				//is supose to be the node from before
			}
		}
		return path;
	}

	int reconsruct(int front, int end, int prev) {

		Type* checkPath[size];
		
		for (int i = back; i != nullptr; i = prev[i]) {
			checkPath[j] = { i };
		}
		reverse(checkPath); //create a reverse function 

		if (checkPath[0] == front) {
			return checkPath;
		}
	}

};