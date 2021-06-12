#include "DivSale_H.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const string STARS = "****************";

double displayAllDivisions(vector<DivSale>);
string chooseQuarter(int);
DivSale promptDivision(int);

string prd(const double x, const int decDigits, const int width);
string center(const string s, const int w);

int main() {
	vector<DivSale> allDivisions;
	double finalTotalSales;

	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			cout << STARS << "WELCOME TO THE COMPANY CALCULATOR!" << STARS << endl << endl;
		}

		allDivisions.push_back(promptDivision((i+1)));
		cout << endl << STARS << "NOW ENTER THE DATA FOR THE NEXT DIVISION IN THE COMPANY..." << STARS << endl << endl;
	}
	
	finalTotalSales = displayAllDivisions(allDivisions);

	cout << endl << STARS << "THE COMPANY FINAL TOTAL SALES FOR 2020 = $" << finalTotalSales << endl;

	return 0;

}

DivSale promptDivision(int whichDiv) {
	DivSale div;

	vector<double> allQuarterSales;
	double userSales;

	for (int x = 1; x <= 4; x++) {
		cout << "Please enter the " << chooseQuarter(x) << " quarter sales for Divison #" << whichDiv << ": ";
		cin >> userSales;

		allQuarterSales.push_back(userSales);
	}

	div.calculateAnnualSales(allQuarterSales[0], allQuarterSales[1], allQuarterSales[2], allQuarterSales[3]);

	return div;
}
string chooseQuarter(int quarterNum) {
	string quarterName;

	switch (quarterNum) {
	case 1: quarterName = "1st";
		break;
	case 2: quarterName = "2nd";
		break;
	case 3: quarterName = "3rd";
		break;
	case 4: quarterName = "4th";
		break;

	default: quarterName = "ERROR!";
	}

	return quarterName;
}

double displayAllDivisions(vector<DivSale> allDivs) {
	double finalTotalSales = 0;

	cout << center("Quarter 1", 10) << " | "
		<< center("Quarter 2", 10) << " | "
		<< center("Quarter 3", 10) << " | "
		<< center("Quarter 4", 10) << "\n";

	cout << string(10 * 4 + 2 * 3, '-') << "\n";

	for (int whichDiv = 0; whichDiv < 6; whichDiv++) {


		for (int whichQuarter = 0; whichQuarter < 4; whichQuarter++) {
				cout << prd(allDivs[whichDiv].retrieveQuarterSales(whichQuarter), 2, 10) << " | ";
				finalTotalSales += allDivs[whichDiv].getTotalSales();

		}
		cout << endl;
	}

	return finalTotalSales;
}

// Convert double to string with specified number of places after the decimal and left padding. 
string prd(const double x, const int decDigits, const int width) {
	stringstream ss;
	ss << fixed << right;
	ss.fill(' ');        // fill space around displayed #
	ss.width(width);     // set  width around displayed #
	ss.precision(decDigits); // set # places after decimal
	ss << x;
	return ss.str();
}

//Center-aligns string within a field of width w. Pads with blank spaces to enforce alignment.
string center(const string s, const int w) {
	stringstream ss, spaces;
	int padding = w - s.size();                 // count excess room to pad
	for (int i = 0; i < padding / 2; ++i)
		spaces << " ";
	ss << spaces.str() << s << spaces.str();    // format with padding
	if (padding > 0 && padding % 2 != 0)               // if odd #, add 1 space
		ss << " ";
	return ss.str();
}


/*

 A corporation has six divisions, each responsible for sales to different geographic locations.

 -Design a DivSales class that keeps sales data for a division, with the following members:
  * 
	.An array with four elements for holding four quarters of sales figures for the division.
	
	.A private static variable for holding the total corporate sales for all
	divisions for the entire year.
	 
	.A member function that takes four arguments, each assumed to be the sales for a quarter.
	the value of the arguments should be copied into the array that holds the sales data.
	The total of the four arguments should be added to the static variable that holds the
	total yearly corporate sales.
	
	A function that takes an integer argument within the range of 0 to 3. The argument is to
	be used as a subscript into the division quarterly sales array. The function should return
	the value of the array element with that subscript.

	Write a program that creates an array of six DivSales objects.
	The program should ask the user to enter the sales for four quarters for each division.
	After the data is entered,
		the program should display a table showing the division sales for each quarter.
			The program should then display the total corporate sales for the year.

		 *** I AM HERE ***


*/