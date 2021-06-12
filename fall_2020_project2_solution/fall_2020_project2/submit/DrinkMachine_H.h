#ifndef DrinkMachine_H
#define DrinkMachine_H

#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

const string STARS = "*********************************************************";

class SoftDrinkType {
private:
	string mDrinkName;
	double mDrinkPrice;
	int mDrinksRemaining;
	int mSelection;


public:
	SoftDrinkType() {
		mDrinkName = "?";
		mDrinkPrice = 0;
		mDrinksRemaining = 99;
		mSelection = 99;
	}

	SoftDrinkType(string name, double price, int remaining, int selection){
		mDrinkName = name;
		mDrinkPrice = price;
		mDrinksRemaining = remaining;
		mSelection = selection;
	}

	void setName(string name) { mDrinkName = name; }
	void setPrice(double price) { mDrinkPrice = price; }
	void setRemaining(int remaining) { mDrinksRemaining = remaining; }

	string getName() { return mDrinkName; }
	double getPrice() { return mDrinkPrice; }
	int getRemaining() { return mDrinksRemaining; }
	int getSelectionNum() { return mSelection; }

	void makePurchase() {
		mDrinksRemaining -= 1;
	}
};


class DrinkMachine {
private:
	vector<SoftDrinkType> mMachineContents; 
	double mMachineTotal = 0;
	
	void setMachineTotal(double total) { mMachineTotal += total;}
	double getMachineTotal() { return mMachineTotal; }
	void clearMachineTotal() { mMachineTotal = 0; }

	void issueRefund() {
		cout << "RETURNING A TOTAL OF $" << getMachineTotal() << endl;
		clearMachineTotal();
	}

	void insertMoney() {
		double moneyInserted;
		string insertMore;

		cout << endl <<  "ENTER DOLLAR AMOUNT YOU ARE INSERTING: ";
		cin >> moneyInserted;

		setMachineTotal(moneyInserted);

		cout << endl << setprecision(2) << fixed << "$" << getMachineTotal() << " INSERTED!" << endl << endl;
		cout << "WOULD YOU LIKE TO INSERT MORE (y/n)?";
		cin >> insertMore;

		if (insertMore == "y" || insertMore == "Y" || insertMore == "yes" || insertMore == "YES" || insertMore == "Yes") {
			insertMoney();
		}
	}

	void dailyReport() {
		cout << endl << STARS << endl;
		cout << "~DAILY REPORT~" << endl;
		cout << endl << STARS << endl << endl;

		cout << left << setw(15) << setprecision(1) << fixed << setw(15) << "DRINK NAME" << " " << setw(15) << "MONEY EARNED" << " " << setw(15) << "DRINKS REMAINING" << endl << endl;

		for (int x = 0; x < mMachineContents.size(); x++) {
			cout << left << setw(15) << fixed << setprecision(2) << setw(15) << mMachineContents[x].getName() << "  $" << setw(15) << ((double) 20 - mMachineContents[x].getRemaining()) * mMachineContents[x].getPrice() << " " << setw(20) << mMachineContents[x].getRemaining() << endl;
		}
	}

public:
	DrinkMachine() {
		initialMachineLoad();
	}

	~DrinkMachine() { dailyReport(); }


	void initialMachineLoad() {
		SoftDrinkType initialDrink1("Cola", 1.00, 20, 1);
		SoftDrinkType initialDrink2("Root Beer", 1.00, 20, 2);
		SoftDrinkType initialDrink3("Orange Soda", 1.00, 20, 3);
		SoftDrinkType initialDrink4("Grape Soda", 1.00, 20, 4);
		SoftDrinkType initialDrink5("Bottled Water", 1.50, 20, 5);

		mMachineContents.push_back(initialDrink1);
		mMachineContents.push_back(initialDrink2);
		mMachineContents.push_back(initialDrink3);
		mMachineContents.push_back(initialDrink4);
		mMachineContents.push_back(initialDrink5);

	}

	void displayChoices() {
		int whichDrink;
		int autoAgain;

		cout << "This Soft Drink Machine Contains the Following Soft Drinks: " << endl << endl;
		cout << left << setw(15) << setprecision(1) << fixed <<"SELECTION" << " " << setw(15) << "DRINK NAME" << " " << setw(15) << "DRINK PRICE" << " " << setw(15) << "DRINKS IN MACHINE" << endl << endl;

		for (int x = 0; x < mMachineContents.size(); x++) {
			cout << left << setw(15) << fixed << setprecision(2) << mMachineContents[x].getSelectionNum() << setw(15) << mMachineContents[x].getName() << " " << setw(15) << mMachineContents[x].getPrice() << " " << setw(20) << mMachineContents[x].getRemaining() << endl;
		}

		insertMoney();

		cout << endl << "PLEASE ENTER THE NUMBER OF YOUR SELECTION (OR ENTER \" 0 \" TO QUIT): ";
		cin >> whichDrink;

		if (whichDrink != 0) {
			autoAgain = buyDrink(whichDrink);

			if (autoAgain == 99) {
				displayChoices();

			} else {
				promptUserAgain();
			}

		}

		issueRefund();
		//QUIT PROG!
		
	}

	int buyDrink(int whichDrink) {
		int again;
		double change;
		double moneyInserted = getMachineTotal();

		if (whichDrink < 1 || whichDrink > 5) {
			cout << endl << STARS << endl;
			cout << endl << "ERROR!!! INCORRECT SELECTION NUMBER! TRY AGAIN!!!" << endl << endl;
			cout << STARS << endl << endl << endl;

			again = 99;

		} else {
			if (mMachineContents[whichDrink - 1].getRemaining() == 0) {
				cout << "YOUR SELECTION OF " << mMachineContents[whichDrink - 1].getName() << " IS SOLD OUT!" << endl;
				
				issueRefund();
				again = -1;

			} else {

				double change = mMachineContents[whichDrink - 1].getPrice() - moneyInserted;

				if (change > 0) {
					cout << endl << STARS << endl;
					cout << endl << "INSUFFCIENT FUNDS! PLEASE TRY AGAIN!" << endl;
					cout << endl << STARS << endl << endl << endl;

					issueRefund();
					again = 99;

				} else if (change == 0) {
					cout << "1 " << mMachineContents[whichDrink - 1].getName() << " PURCHASED!" << endl << endl;
					mMachineContents[whichDrink - 1].makePurchase();

					again = -1;

				} else if (change < 0) {
					cout << endl << "1 " << mMachineContents[whichDrink - 1].getName() << " PURCHASED!" << endl;
					mMachineContents[whichDrink - 1].makePurchase();
					cout << fixed << setprecision(2) << "$" << (change * -1) << " DISPENSED!!" << endl;
					cout << "ENJOY YOUR BEVERAGE..." << endl << endl;

					again = -1;
				}

			}
		}
		
		return again;
	}

	void promptUserAgain() {
		string userAgain;

		cout << "WOULD YOU LIKE TO BUY A DRINK? (y/n): " << endl;
		cin >> userAgain;

		if (userAgain == "y" || userAgain == "Y" || userAgain == "yes" || userAgain == "YES" || userAgain == "Yes") {
			displayChoices();
		}
	}

};

#endif;