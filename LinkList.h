/*
LinkList.h
Teng Zhao 40089560
Thomas Flynn 40034877
*/

#pragma once
#include "Node.h"
#include "ourExceptions.h"

using namespace std;
template<class T>
class LinkList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int n; // number of elements in linkedlist
public:
	LinkList()
	{
		head = nullptr;
		tail = nullptr;
		n = 0;
	}

	~LinkList()
	{
	}
	void addElement(T t)
	{
		Node<T>* temp = new Node<T>(t);
		if (head == nullptr) 
		{
			head = temp; 
			tail = temp;
		}
		else 
		{
			tail->setNextNode(temp);
			tail = tail->getNextNode();
		}
		n++;
	}

	void deleteElement(T t)
	{
		//Search element position
		Node<T>* tempA = head;
		int p = 1;
		bool isFound = false;
		 
		while(tempA != nullptr){
			if (tempA->getElement() == t) {
				isFound = true;
				break;
			}
			else {
				tempA = tempA->getNextNode();
				p++;
			}
		}
		if (isFound != true) {
			notFound nf;
			throw nf;
		}
		else{
			this->removeNode(p);
		}
	}

	void insertNode(T t, int pos){ // assume pos is strictly positive, 
		if (pos <= n) {
			Node<T>* temp = new Node<T>(t); //create new node
			Node<T>* temp2 = head; // will hold node at pos
			Node<T>* temp3 = nullptr; // will hold node at pos+1
			for (int i = 1; i < pos - 1; i++) //find insert node position
				temp2 = temp2->getNextNode();
			temp3 = temp2->getNextNode();
			temp2->setNextNode(temp);//set the node position's next node to new node
			temp->setNextNode(temp3);//set the new node's next node to the original node's next node
			n++;
		}
		else {
			outOfRange oOR;
			throw oOR;
		}
	}
	void removeNode(int pos)  //remove an element located at a certain poisiton 
	{
		if (pos == 1) { // changing head
			Node<T>* tempA = head;
			Node<T>* tempB = tempA->getNextNode();
			tempA->setNextNodeNull();
			head = tempB;
			delete tempA;
			n--;
		}
		else if (pos <n) { 
			Node<T>* tempA = head; //control node pos-1
			Node<T>* tempB = nullptr; //control node pos
			Node<T>* tempC = nullptr; //control node pos+1

			for (int i = 1; i < pos - 1; i++) //find remove node position-1
				tempA = tempA->getNextNode();

			tempB = tempA->getNextNode();
			tempC = tempB->getNextNode();
			tempA->setNextNode(tempC);
			tempB->setNextNodeNull();
			delete tempB;
			n--;
		}
		else if (pos == n){ //changing tail
			Node<T>* tempA = head;
			Node<T>* tempB = nullptr;
			for (int i = 1; i < pos -1; i++) //find remove node position-1
				tempA = tempA->getNextNode();
			tempB = tempA->getNextNode();
			tail = tempA;
			tempA->setNextNodeNull();
			delete tempB;
			n--;
		}
		else {
			outOfRange oOR;
			throw oOR;
		}
	}

	T getNodeValue(int pos)
	{
		Node<T>* tempA = head;
		for (int i = 1; i < pos ; i++) 
			tempA = tempA->getNextNode();
		return tempA->getElement();
	}

	bool searchNode(T ele) //search for an element 
	{
		Node<T>* temp = head;
		while (temp != nullptr) { // crashed here, we'll fix it tomorrow 
			if (temp->getElement() == ele) {
				return true;
			}
			temp = temp->getNextNode();
		}
		return false;
	}

	friend ostream& operator<<(ostream& output, const LinkList<T>& L) {
		Node<T>* p = L.getHead(); //at pos one, node is head
		int pos = 1;
		while (p != nullptr)
		{
			cout <<"At position "<< pos<< ":" << p->getElement() << endl;
			p = p->getNextNode();
			pos++;
		}

		return output;
	}

	void printLinkList()
	{
		Node<T>* p = head; //at pos one, node is head
		int pos = 1;
		while (p != nullptr)
		{
			cout << "At position " << pos << ":" << p->getElement() << endl;
			p = p->getNextNode();
			pos++;
		}
	}

	Node<T>* getHead()const { return head; }
};

