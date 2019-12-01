#define _USE_MATH_DEFINES // used for pi constant
#include <cmath> // used for pi constant
#include "circleType.h"
#include "pointType.h"
#include <iostream>
using namespace std;

circleType::circleType()
	:
	d_radius(1.0),
	center()
{}

circleType::circleType(double r, double x, double y)
	:
	d_radius(r),
	center(x, y)
{}

circleType::circleType(const pointType& p, double r)
	:
	d_radius(r),
	center(p)
{}

circleType::circleType(const circleType& p)
	:
	d_radius(p.d_radius),
	center(p.center)
{}

void circleType::setRadius(double r)
{
	d_radius = r;
}

void circleType::printRadius() const
{
	cout << "Radius = " << d_radius << endl;
}

void circleType::setCenter(double x, double y)
{
	center.setCoord(x, y);
}

void circleType::printCenter() const
{
	center.printCoord();
}

double circleType::calcArea() const
{
	double area = M_PI * d_radius * d_radius;
	return area;
}

void circleType::printArea() const
{
	cout << "Area = " << calcArea() << endl;
}

double circleType::calcCircumference() const
{
	double circ = M_PI * d_radius * 2;
	return circ;
}

void circleType::printCircumference() const
{
	cout << "Circumference = " << calcCircumference() << endl;
}

void circleType::getData() const
{
	cout << "\nOutput of circleType:\n";
	printCenter();
	printRadius();
	printArea();
	printCircumference();
}

void circleType::putData()
{
	bool done;  // Flag to control do while loop for getting user input
	string err = "Error, please try again\n";

	do {  // Get x and y coordinates for point Type
		try
		{
			cout << "\nEnter circle radius length -- e.g. 3.15\n";
			cin >> d_radius;
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