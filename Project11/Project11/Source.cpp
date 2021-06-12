#include "Header_H.h"
#include <iostream>
using namespace std;

void staticDriver();
void dynamicDriver();
bool promptStart(string);

int main() {
	if (promptStart("Static")) {
		staticDriver();
	}

	if (promptStart("Dynamic")) {
		dynamicDriver();
	}

	return 0;
}

bool promptStart(string type) {
	string starter;

	cout << endl << "Begin " << type <<" stack driver?(y/n):";
	cin >> starter;

	if (starter == "Y" || starter == "Yes" || starter == "YES" || starter == "y" || starter == "yes" || starter == "YeS") {
		return true;
	} else {
		return false;
	}
}
void staticDriver(){
	MyStaticStack<string> mStaticStack(3);
	string popper;

	if (mStaticStack.isEmpty()) {
		cout << "MY STACK IS EMPTY! LOADING STACK..." << endl << endl;

		mStaticStack.push("Paris");
		mStaticStack.push("Brandon");
		mStaticStack.push("Garrett");

	}

	if (mStaticStack.isFull()) { cout << "MY STACK IS FULL! PRINTING STACK..." << endl << endl; }

	for (int i = 0; i < 3; i++) {
		//Tell them my name
		mStaticStack.show();

		//but not my middle name!!!
		mStaticStack.pop(popper);

	}
}
void dynamicDriver(){
	MyDynamicStack<int> mDynamicStack;
	int popper;

	if (mDynamicStack.isEmpty()) {
		cout << "MY STACK IS EMPTY! LOADING STACK..." << endl << endl;

		mDynamicStack.push(22);
		mDynamicStack.push(1000);
		mDynamicStack.push(9);

	}

	cout << "PRINTING STACK..." << endl << endl; 

		mDynamicStack.show();
		mDynamicStack.pop(popper);
		mDynamicStack.show();


	
}