/*
Node.h
Teng Zhao 40089560
Thomas Flynn 40034877
*/



#pragma once
#include <iostream>

using namespace std;

using namespace std;

template<class T>
class Node {

private:
	Node* link;
	T element;
public:

	Node<T>(T t) {
		element = t;
		link = nullptr;
	}

	Node<T>(T s, Node* n1) {
		element = s;
		Node* link = n1;
	}

	T getElement() const { return element; }

	void setElement(T& t) { element = t; }

	void setNextNode(Node* prev) { link = prev; }

	Node<T>* getNextNode() const { return link; }

	void setNextNodeNull() { link = nullptr; };

	void printNodeInfo() {

		cout << "----Node Info----" << endl;
		cout << "element: " << element << endl;
		cout << "Node location: " << link << endl;

	}

};
