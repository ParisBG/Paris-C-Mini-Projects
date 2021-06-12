#include "Myheader_H.h"

#include <iostream>
using namespace std;

int main() {
	Car myCar(2012, "Buick");
	
	myCar.accelerate(5);
	myCar.brake(5);

	return 0;
}



/*
Write a class named Car that has the following member variables:

year.
An int that holds the car�s model year.
make. 
A string object that holds the make of the car.

speed.
An int that holds the car�s current speed.

In addition, the class should have the following member functions.

Constructor. 
The constructor should accept the car�s year and make as arguments
and assign these values to the object�s year and make member variables.
The constructor should initialize the speed member variable to 0.

Accessors. 
Appropriate accessor functions should be created to allow values to be retrieved
from an object�s year, make, and speed member variables.

accelerate. The accelerate function should add 5 to the speed member variable each time it is called.

brake. The brake function should subtract 5 from the speed member variable each time it is called.

Demonstrate the class in a program that creates a Car object and then calls the accelerate
function five times.

After each call to the accelerate function, get the current speed of the car and display it.
Then, call the brake function five times. After each call to the brake function,
get the current speed of the car and display it.
*/