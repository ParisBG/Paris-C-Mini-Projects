#include <iostream>
using namespace std;

string LINE = "--------------------------------------------------------------------------------------------";

int ackermann(int, int);
bool next(int&);

int main() {
	int iteration = 1;

	cout << "WELCOME TO THE ACKERMANN FUNCTION TEST!" << endl << LINE << endl;
	cout << "Ackermann\'s function is a recursive mathematical algorithm" << endl;
	cout << "that can be used to test how well a computer performs recursion." << endl << endl;

	if (next(iteration)) { cout << "The Results of \"ackermann(0, 0)\" = " << ackermann(0, 0) << endl << endl; }
	if (next(iteration)) { cout << "The Results of \"ackermann(0, 1)\" = " << ackermann(0, 1) << endl << endl; }
	if (next(iteration)) { cout << "The Results of \"ackermann(1, 1)\" = " << ackermann(1, 1) << endl << endl; }
	if (next(iteration)) { cout << "The Results of \"ackermann(1, 2)\" = " << ackermann(1, 2) << endl << endl; }
	if (next(iteration)) { cout << "The Results of \"ackermann(1, 3)\" = " << ackermann(1, 3) << endl << endl; }
	if (next(iteration)) { cout << "The Results of \"ackermann(2, 2)\" = " << ackermann(2, 2) << endl << endl; }
	if (next(iteration)) { cout << "The Results of \"ackermann(3, 2)\" = " << ackermann(3, 2) << endl << endl; }

	return 0;
}

bool next(int &it) {
	string next;

	if (it == 1) {
		cout << "Run the first algorithm?(y/n): ";
	} else {
		cout << "Run the next algorithm?(y/n): ";
	}

	cin >> next;
	it++;

	if (next == "Y" || next == "Yes" || next == "YES" || next == "yes" || next == "y") {
		cout << endl;
		return true;
	} else {
		return false;
	}
}
int ackermann(int x, int y){
	if (x == 0) {
		return y + 1;

	} else if ((x > 0) && (y == 0)) {
		return ackermann(x - 1, 1);

	} else if ((x > 0) && (y > 0)) {

		return ackermann(x - 1, ackermann(x, y - 1));
	}
}

/*
Program 8                                                                                                           EC – C14-P9 – 961

Ackermann’s function is a recursive mathematical algorithm that can be used to test 
how well a computer performs recursion. Write a function A(m, n) that solves Ackermann’s
function. Use the following logic in your function:

If m = 0 then       return n + 1
If n = 0 then        return A(m−1, 1)
Otherwise,          return A(m–1, A(m, n–1))

Test your function in a driver program that displays the following values:

A(0, 0)   A(0, 1)   A(1, 1)    A(1, 2)    A(1, 3)     A(2, 2)    A(3, 2)
*/