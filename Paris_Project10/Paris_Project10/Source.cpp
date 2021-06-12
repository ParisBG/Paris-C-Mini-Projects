#include <iostream>
#include "Header_H.h"

using namespace std;


int main() {

	MyLinkedList myOrigList;

	cout << "Adding to List:" << endl;
	myOrigList.addNode(17.5);
	myOrigList.addNode(97.9);
	myOrigList.addNode(28.6);
	myOrigList.addNode(93.7);
	myOrigList.addNode(3.5);
	cout << endl;

	//Copying list
	MyLinkedList mySecondList(myOrigList);

	cout << endl << "Contents of Original List:" << endl;
	myOrigList.print();

	cout << "Contents of Copied List:" << endl;
	mySecondList.print();

	myOrigList.remove(97.9);
	myOrigList.print();

	return 0;
}
/*
-The add function adds a new node containing x to the front (head) of the list,
while the isMember function tests to see if the list contains a node with the value x.

-Test your linked list class by adding various numbers to the list and then testing for
membership.

-List Copy Constructor Modify your list class of Previous Programming to add a copy constructor.

-Test your class by making a copy of a list and then testing membership on the copy.

-List Print Modify the list class you created in the previous programming challenges to add
a print member function. Test the class by starting with an empty list, adding some elements,
and then printing the resulting list out.

-Recursive Member Check Modify the list class you created in the previous programming challenges
to use a recursive method to check for list membership. Test your class.

-List Member Deletion Modify the list class you created in the previous programming challenges
by adding a function to remove an item from the list and by adding a destructor:
        void remove(double x);
       ~LinkedList();

-Test the class by adding a sequence of instructions that mixes operations for adding items,
removing items, and printing the list.

-List Reverse Modify the list class you created in the previous programming challenges by
adding a member function for reversing the list:
         void reverse();

-The member function rearranges the nodes in the list so that their order is reversed.
You should do this without creating or destroying nodes.
*/