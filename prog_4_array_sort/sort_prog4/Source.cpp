#include <iostream>

using namespace std;

const string LINE = "***********************************";
const int SIZE = 8;

void displayArray(int[SIZE], string, bool);
void swap(int& a, int& b);
void selectionSort(int[SIZE], string);
void bubbleSort(int thisArray[SIZE], string whichArray);


int main() {

	int arr1[SIZE] = {22, 33, 4, 7, 8, 1, 15, 100};
	int arr2[SIZE] = {12, 16, 32, 2, 17, 6, 22, 69};
	int arr3[SIZE] = {672, 6, 68, 2, 0, 1, 1000, 100 };
	int arr4[SIZE] = {2, 99, 27, 3, 7, 11, 54, 52 };

	//1st array ORIGINAL
	displayArray(arr1,"1st", true);
	selectionSort(arr1, "1st");

	//3rd array ORIGINAL
	displayArray(arr3, "3rd", true);
	bubbleSort(arr3, "3rd");

	//2nd array ORIGINAL
	displayArray(arr2, "2nd", true);
	selectionSort(arr2, "2nd");

	//4th array ORIGINAL
	displayArray(arr4, "4th", true);
	bubbleSort(arr4, "4th");

	return 0;
}

void displayArray(int thisArray[SIZE], string whichArray, bool isOrig) {
	if (isOrig) {
		cout << LINE << endl;
		cout << "THESE ARE THE ORIGINAL CONTENTS OF THE "<< whichArray << " ARRAY!!" << endl;
		cout << LINE << endl << endl;
	}

		for (int i = 0; i < SIZE; i++) {
			cout << "The Value in the " << whichArray << " Array " << "@ position #" << i + 1 << " = " << "\"" << thisArray[i] << "\"" << endl;

			if (i == 7) {
				cout << endl;
			}
		}
	

}
void bubbleSort(int thisArray[SIZE], string whichArray) {
	cout << "BUBBLE SORTING..." << endl << endl;

	int i, j, count = 0;
	for (i = 0; i < SIZE - 1; i++) {

		// Last i elements are already in place  
		for (j = 0; j < SIZE - i - 1; j++) {
			if (thisArray[j] > thisArray[j + 1]) {
				swap(thisArray[j], thisArray[j + 1]);
			}
			cout << endl << "BUBBLE Sort Iteration #" << count + 1 << endl;
			displayArray(thisArray, whichArray, false);
			count++;
		}
	}
			cout << LINE << endl;
			cout << "THESE ARE THE CONTENTS OF THE " << whichArray << " ARRAY AFTER BUBBLE SORT!" << endl;
			cout << LINE << endl << endl;
	
}

void selectionSort(int thisArray[SIZE],string whichArray) {
	cout << "SELECTION SORTING..." << endl << endl;
	int i, j, iMin, count = 0;

	for (i = 0; i <= SIZE -1; i++){
		iMin = i;   //get index of minimum data

		for (j = i + 1; j <= SIZE - 1; j++) {
			cout << endl << "SELECTION Sort Iteration #" << count + 1 << endl;
			displayArray(thisArray, whichArray, false);

			if (thisArray[j] < thisArray[iMin]) {
				iMin = j;
			}

			count++;
		}

		if (iMin != i){
			//placing in correct position
			swap(thisArray[i], thisArray[iMin]);
		}		
		}

	cout << LINE << endl;
	cout << "THESE ARE THE CONTENTS OF THE " << whichArray << " ARRAY AFTER SELECTION SORT!" << endl;
	cout << LINE << endl << endl;
}
void swap(int& a, int& b) {         
	//swap the content of a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}
		
/*
-Write a program that uses two identical arrays of eight randomly ordered integers.

-It should display the contents of the first array,
then call a function to sort it using an ascending order bubble sort,
modified to print out the array contents after each pass of the sort.

-Next the program should display the contents of the second array,
then call a function to sort it using an ascending order selection sort,
modified to print out the array contents after each pass of the sort.
*/