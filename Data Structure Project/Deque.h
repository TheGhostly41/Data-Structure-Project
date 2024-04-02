#pragma once

#include <iostream>

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

	Node* front, * back;

public:
	// Constructor
	LinkQueue() {
		front = back = nullptr;
	}

	// Destructor
	~LinkQueue() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	//Copy Constructor
	LinkQueue(const LinkQueue& source) {
		Node* srcPtr = source.front;
		front = back = nullptr;

		while (srcPtr != nullptr) {
			enqueue(srcPtr->data);
			srcPtr = srcPtr->next;
		}
	}

	// Assignment Operator
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

	// Other operations
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
			front = back = nullptr;
		}

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
};