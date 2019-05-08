/*
testLinkList.cpp
Teng Zhao 40089560
Thomas Flynn 40034877

*/

#include <iostream>
#include "LinkList.h"
using namespace std;

int main() {
	//LinkList<int> L;  // Creates two linked lists

	try {

		LinkList<int> L;

		L.addElement(50);
		L.addElement(60);
		L.addElement(70);
		L.addElement(80);
		//L.printLinkList();

		L.removeNode(4); //removing 80
		cout << L; //used the overload constructor 

		cout << endl;


		L.insertNode(90, 2); // add 90 inbetween 50 and 60
		L.printLinkList();

		if (L.searchNode(100)) { // 100 not present in list
			cout << "found!" << endl;
		}
		else {
			cout << "not found !" << endl;
		}

		cout << endl;

		L.deleteElement(100); // delete element 50
		L.printLinkList();
	}
	catch(exception& e){
		cout << "Exception: " << e.what() << endl;
	}
	
	system("pause");
	return 0;
}

