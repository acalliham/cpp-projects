#include "pointType.h"
#include <iostream>

using namespace std;

pointType::pointType()
	:
	d_x(0.0),
	d_y(0.0)
{}

pointType::pointType(double x, double y)
	:
	d_x(x),
	d_y(y)
{}

pointType::pointType(const pointType& point)
{
	d_x = point.d_x;
	d_y = point.d_y;
}

void pointType::setCoord(double x, double y)
{
	d_x = x;
	d_y = y;
}
void pointType::printCoord() const
{
	cout << "Coordinates = " << d_x << ", " << d_y << endl;
}
double pointType::getX() const
{
	return d_x;
}
double pointType::getY() const
{
	return d_y;
}

void pointType::getData() const
{
	cout << "\nOutput of pointType:\n";
	printCoord();
}

void pointType::putData()
{
	bool done;  // Flag to control do while loop for getting user input
	string err = "Error, please try again\n";

	do {  // Get x and y coordinates for point Type
		try
		{
			cout << "\nEnter coordinates for a point on a plane in format x, y -- e.g. 1.2, 2.5\n";
			cin >> d_x;
			if (!cin) {  // Handle case for bad data input
				cin.clear();
				cin.ignore(100, '\n');
				throw err;
			}
			cin.ignore(100, ',');
			cin >> d_y;
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