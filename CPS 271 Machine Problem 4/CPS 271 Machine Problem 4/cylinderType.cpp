#include "circleType.h"
#include "pointType.h"
#include "cylinderType.h"
#include <iostream>
using namespace std;

cylinderType::cylinderType()
	:
	d_height(1.0),
	circleType()
{}

cylinderType::cylinderType(double h, double r, double x, double y)
	:
	d_height(h),
	circleType(r, x, y)
{}

cylinderType::cylinderType(circleType c, double h)
	:
	d_height(h),
	circleType(c)
{}

cylinderType::cylinderType(const cylinderType& cylinder)
	:
	d_height(cylinder.d_height),
	circleType(cylinder)
{}

double cylinderType::calcVolume() const
{
	double vol = calcArea() * d_height;
	return vol;
}

void cylinderType::printVolume() const
{
	cout << "Volume = " << calcVolume() << endl;
}

double cylinderType::calcSurfaceArea() const
{
	double surface = (calcArea() * 2) + (calcCircumference() * d_height);
	return surface;
}

void cylinderType::printSurfaceArea() const
{
	cout << "Surface Area = " << calcSurfaceArea() << endl;
}

void cylinderType::setHeight(double h)
{
	d_height = h;
}

void cylinderType::printHeight() const
{
	cout << "Height = " << d_height << endl;
}

void cylinderType::getData() const
{
	cout << "\nOutput of cylinderType:\n";
	printCenter();
	printRadius();
	printArea();
	printCircumference();
	printHeight();
	printVolume();
	printSurfaceArea();
}

void cylinderType::putData()
{
	bool done;  // Flag to control do while loop for getting user input
	string err = "Error, please try again\n";

	do {  // Get x and y coordinates for point Type
		try
		{
			cout << "\nEnter cylinder height -- e.g. 8.0\n";
			cin >> d_height;
			if (!cin) {  // Handle case for bad data input
				cin.clear();
				cin.ignore(100, '\n');
				throw err;
			}
			done = true;  // Set variable to exit loop
		}
		catch (string s)
		{
			done = false;  // Set variable to cause loop to execute again
			cout << s;
		}
	} while (done != true);  // End of loop to get point input from user
}