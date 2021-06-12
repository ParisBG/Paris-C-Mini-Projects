#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printAlphabet(int*);
void analyzeEachLetter(int*,string);
string introPrompt(int* alphabet);
bool continuePrompt(string);
void printFile(string fileName);

int main() {
	int alphabet[26];
	string fileName = introPrompt(alphabet);

	printFile(fileName);

	if (continuePrompt("analyze the file")) {
		analyzeEachLetter(alphabet, fileName);

		if (continuePrompt("print Letter Results")) {
			printAlphabet(alphabet);
		}
	}


	return 0;
}

string introPrompt(int* alphabet) {
	//Initializer
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}

	string fileName;

	cout << "**************Welcome to the file letter counter!**************" << endl << endl << endl;
	cout << "Please enter \" x \" to print the default file (or enter a custom .txt file with extension): ";
	cin >> fileName;

	if (fileName == "x") {
		fileName = "filename.txt";
	}

	return fileName;
}
void printFile(string fileName) {

	//Create a text string, which is used to output the text file
	string myText;

	//Read from the text file
	ifstream MyReadFile(fileName);

	//Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		cout << endl << myText;
	}

	// Close the file
	MyReadFile.close();

	cout << endl << endl << "File Printed successfully..." << endl;

}
void analyzeEachLetter(int* alpha, string fileName) {
	char rawChar;
	fstream fin(fileName, fstream::in);
	while (fin >> noskipws >> rawChar) {

		if (rawChar == 65 || rawChar == 97) {
			alpha[0]++;
		} else if (rawChar == 66 || rawChar == 98) {
			alpha[1]++;
		} else if (rawChar == 67 || rawChar == 99) {
			alpha[2]++;
		} else if (rawChar == 68 || rawChar == 100) {
			alpha[3]++;
		} else if (rawChar == 69 || rawChar == 101) {
			alpha[4]++;
		} else if (rawChar == 70 || rawChar == 102) {
			alpha[5]++;
		} else if (rawChar == 71 || rawChar == 103) {
			alpha[6]++;
		} else if (rawChar == 72 || rawChar == 104) {
			alpha[7]++;
		} else if (rawChar == 73 || rawChar == 105) {
			alpha[8]++;
		} else if (rawChar == 74 || rawChar == 106) {
			alpha[9]++;
		} else if (rawChar == 75 || rawChar == 107) {
			alpha[10]++;
		} else if (rawChar == 76 || rawChar == 108) {
			alpha[11]++;
		} else if (rawChar == 77 || rawChar == 109) {
			alpha[12]++;
		} else if (rawChar == 78 || rawChar == 110) {
			alpha[13]++;
		} else if (rawChar == 79 || rawChar == 111) {
			alpha[14]++;
		} else if (rawChar == 80 || rawChar == 112) {
			alpha[15]++;
		} else if (rawChar == 81 || rawChar == 113) {
			alpha[16]++;
		} else if (rawChar == 82 || rawChar == 114) {
			alpha[17]++;
		} else if (rawChar == 83 || rawChar == 115) {
			alpha[18]++;
		} else if (rawChar == 84 || rawChar == 116) {
			alpha[19]++;
		} else if (rawChar == 85 || rawChar == 117) {
			alpha[20]++;
		} else if (rawChar == 86 || rawChar == 118) {
			alpha[21]++;
		} else if (rawChar == 87 || rawChar == 119) {
			alpha[22]++;
		} else if (rawChar == 88 || rawChar == 120) {
			alpha[23]++;
		} else if (rawChar == 89 || rawChar == 121) {
			alpha[24]++;
		} else if (rawChar == 90 || rawChar == 122) {
			alpha[25]++;
		}
	}
	/*
		char char1 = 65;
		char char2 = 97;

		65(A)- 97 (Z)
		90(z) - 122 (z)

		cout << (65 == 'A');
	*/
	cout << endl << "File Analyzed successfully..." << endl;

	}
void printAlphabet(int* alpha) {
	char letter = 'a';
	int iterator = 0;

	while (letter >= 'a' && letter <= 'z'){
		cout << letter << " = "<< alpha[iterator] << endl;
		letter++;
		iterator++;
	}

}
bool continuePrompt(string action){
	string input;
	cout << "Enter \"y\" to " << action << " or \"n\" to quit: ";
	cin >> input;

	if (input == "y" || input == "Y" || input == "\"y\"" || input == "\"Y\"" || input == "yes" || input == "Yes" || input == "YES") {
		return true;
	} else {
		return false;
	}

}
