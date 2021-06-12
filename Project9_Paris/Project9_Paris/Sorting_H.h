#ifndef Sorting_H
#define Sorting_H
#include <iostream>
using namespace std;

const string LINE = "**********************************************************************";

class AbstractSort {
	private: 
		int mTotalComparisons = 0;

	public:
		virtual void sort(int arr[], int size) = 0;
		int getComparisonTotal() { return mTotalComparisons; }
		void compare(int element1, int element2){
			mTotalComparisons++;
		}
		void swap(int& a, int& b) {
			int temp;
			temp = a;
			a = b;
			b = temp;
		}
};

class SortClass : AbstractSort{

	private:
		void displayArray(int arr[], int size) {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;

			if (i == (size - 1)) {
				cout << endl << endl;
			}
		}


	}

	public:
		void sort(int arr[], int size) {
			cout << LINE << endl;
			cout << "THE CONTENTS OF THIS ARRAY ARE: " << endl;
			cout << LINE << endl << endl;

			displayArray(arr, size);

			cout << "BUBBLE SORTING..." << endl << endl;

			int i, j, count = 0;

			for (i = 0; i < size - 1; i++) {

				for (j = 0; j < size - i - 1; j++) {

					if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
					}

						
						cout << endl << "BUBBLE Sort Iteration #" << (count + 1) << endl;
					
					compare(arr[j], arr[j + 1]);

					displayArray(arr, size);
					count++;
			}
		}

			cout << "The amount of times the array elements were compared = " << getComparisonTotal() << endl;

			
	}

};

#endif

