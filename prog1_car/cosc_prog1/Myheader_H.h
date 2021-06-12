#ifndef Myheader_H.h
#define Myheader_H

#include <iostream>
#include <string>
using namespace std;

const string END_ITERATION = "**************END OF ITERATION*****************";

class Car {
private:
	int mYear, mSpeed;
	string mMake;

public:
	Car(int year, string make) {
		mYear = year;
		mMake = make;
		mSpeed = 0;
	}

	void setYear(int year) { mYear = year; }
	void setSpeed(int speed) { mSpeed = speed; }
	void setMake(string make) { mMake = make; }

	int getYear() { return mYear; }
	int getSpeed() { return mSpeed; }
	string getMake() { return mMake; }

	void accelerate(int count) {
		for (int i = 0; i < count; i++) {
			mSpeed += 5;

			cout << "The Current Speed of your vehicle has increased to " << mSpeed << "mph" << endl;

		}

		cout << endl << END_ITERATION << endl << endl;

	}

	void brake(int count) {
		if (mSpeed > 0) {
			for (int i = 0; i < count; i++) {
				mSpeed -= 5;

				cout << "The Current Speed of your vehicle has decreased to " << mSpeed << "mph" << endl;
			}
		} else {
			mSpeed = 0;
		}

		cout << endl << END_ITERATION << endl << endl;

	}
};

#endif