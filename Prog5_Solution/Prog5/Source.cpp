#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

vector<int> selectionSort(vector<int>, vector<string>&);
vector<int> promptTestScores();
vector<string> promptTestNames();
void displayScores(vector<int>);
void displayNames(vector<string>);

vector<int> autoPopulateScores();
vector<string> autoPopulateNames();
int randoGen();

void calcAverage(vector<int>);
int validityCheck(int, int);


int main() {

	vector<int> scores = promptTestScores();
	vector<string> names = promptTestNames();

	displayScores(selectionSort(scores, names));

	displayNames(names);
	calcAverage(scores);
	
	return 0;
}

vector<int> promptTestScores() {
	int userTestScore;
	vector<int> testScores;

	for (int i = 0; i < 10; i++) {
		cout << "Please enter test score number #" << (i + 1) << ":";
		cin >> userTestScore;

		if (userTestScore == 8812) {
			testScores = autoPopulateScores();
			break;
		}

		while (userTestScore < 0 || userTestScore > 100) {
			userTestScore = validityCheck(userTestScore, (i + 1));
		}

		testScores.push_back(userTestScore);

		}



	return testScores;
	
}

void displayScores(vector<int> theScores) {
	cout << endl << "The following is a list of all of the student's test scores on the semester:" << endl << endl;

	for (int i = 0; i < theScores.size(); i++) {
		cout << "Test Score #" << (i+1) <<  " = " << theScores[i] << endl;
	}
}

void displayNames(vector<string> theStudents) {
	cout << endl << "The following is a list of all of the student's names: " << endl << endl;

	for (int i = 0; i < theStudents.size(); i++) {
		cout << "Student Name #" << (i + 1) << " = " << theStudents[i] << endl;
	}
}

void swap(int& a, int& b) {
	//swap the content of a and b
	int temp;
	temp = a;
	a = b;
	b = temp;
}

vector<int> autoPopulateScores() {
	int userTestScore;
	vector<int> testScores;

	cout << endl << "Auto Populating 10 Test Scores..." << endl << endl;
	for (int i = 0; i < 10; i++) {
		testScores.push_back(randoGen());
	}

	return testScores;
}

vector<string> autoPopulateNames() {
	vector<string> autoNames;

	autoNames.push_back("0PAUL");
	autoNames.push_back("1RUDY");
	autoNames.push_back("2MARK");
	autoNames.push_back("3ASHLEY");
	autoNames.push_back("4PARIS");
	autoNames.push_back("5SARAH");
	autoNames.push_back("6DARLA");
	autoNames.push_back("7BELLE");
	autoNames.push_back("8SHARKEESHA");
	autoNames.push_back("9JUPITER");

	return autoNames;
}

vector<int> selectionSort(vector<int> scoreVector, vector<string> &nameVector) {
	cout << endl << "SELECTION SORTING..." << endl << endl;
	int i, j, iMin;

	for (i = 0; i <= scoreVector.size() - 1; i++) {
		iMin = i;   //get index of minimum data

		for (j = i + 1; j <= scoreVector.size() - 1; j++) {

			if (scoreVector[j] < scoreVector[iMin]) {
				iMin = j;
			}

		}

		if (iMin != i) {
			//placing in correct position
			swap(scoreVector[i], scoreVector[iMin]);

			//Also swap name list to correspond to grade
			swap(nameVector[i], nameVector[iMin]);


		}
	}

	return scoreVector;
}

int randoGen() {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<std::mt19937::result_type> dist6(0,100); // distribution in range [1, 6]

	return dist6(rng);

}

void calcAverage(vector<int> sortedVector) {
	int sum = 0;
	int dividend = sortedVector.size();

	for (int x = 0; x < dividend; x++) {
		sum += sortedVector[x];
	}

	cout << endl << "The class average = " << (sum / dividend) << endl << endl;

}

int validityCheck(int singleScore, int whichScore) {
	int checkThisScore = 0;

	if (singleScore == 8812) {
		return 8812;

	} else {
			cout << "STUDENT SCORE CAN NOT BE NEGATIVE OR OVER 100!! TRY AGAIN..." << endl << endl;
			cout << "Please enter test score number #" << whichScore << ":";
			cin >> checkThisScore;
	}
		return checkThisScore;

}

vector<string> promptTestNames() {
	string userStudentName;
	vector<string> studentNames;

	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout << "Please enter the name of student #" << (i + 1) << ":";
		cin >> userStudentName;

		if (userStudentName == "p") {
			studentNames = autoPopulateNames();
			break;
		}

		studentNames.push_back(userStudentName);

	}

	return studentNames;
}

/*
Part A. Write a program that dynamically allocates an array large enough to hold a user-defined
number of test scores.

* 

Once all the scores are entered, the array should be passed to a function that sorts them in
ascending order.
* 
Another function should be called that calculates the average score.
The program should display the sorted list of scores and averages with appropriate headings.
Use pointer notation rather than array notation whenever possible.
Input Validation: Do not accept negative numbers for test scores.
* 
Part B. Modify previous to allow the user to enter name–score pairs.
For each student taking a test, the user types a string representing the name of the student,
followed by an integer representing the student’s score.

* ******YOU ARE HERE**********

-Modify both the sorting and average-calculating functions so they take arrays of structures,
with each structure containing the name and score of a single student. In traversing the arrays,
use pointers rather than array indices.

*/