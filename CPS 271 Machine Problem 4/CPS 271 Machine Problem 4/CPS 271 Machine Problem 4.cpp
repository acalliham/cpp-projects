// CPS 271 Machine Problem 4
// Name: Amy Calliham
// Student ID: 00683394
// Purpose of Program: Create point, circle, and cylinder classes to demonstrate knowledge of inheritance and composition.  
//      Allow user to input data about each object, calculate and print data

#include <iostream>
#include <string>
#include "circleType.h"
#include "cylinderType.h"
#include "pointType.h"

using namespace std;

int main()
{

// ***** Testing classes *****

	double circ, area, vol, surf_area;
	cout << "\n\nTesting of constant Point, Circle, Cylinder objects..." << endl;

	// create and print out a const Point object
	cout << "\nPoint info..." << endl;
	const pointType center1(2, 3);
	center1.getData();

	// create and print out a const Circle object
	cout << "\nCircle info..." << endl;
	const circleType cir1(center1, 5.5);
	cir1.getData();

	circ = cir1.calcCircumference();
	cout << "Circumference: " << circ << endl;
	area = cir1.calcArea();
	cout << "Area: " << area << endl;

	// create and print out a const Cylinder object
	cout << "\nCylinder info..." << endl;
	const cylinderType cyl1(cir1, 10);
	cyl1.getData();

	circ = cyl1.calcCircumference();
	cout << "Cyl Circumference: " << circ << endl;
	area = cyl1.calcArea();
	cout << "Cyl Circle Area: " << area << endl;
	surf_area = cyl1.calcSurfaceArea();
	cout << "Cyl Surface Area: " << surf_area << endl;
	vol = cyl1.calcVolume();
	cout << "Cyl Volume: " << vol << endl;

// ***** User-entered input *****

	cout << "\n\nEnter in Point, Circle, Cylinder info..." << endl;
	pointType point;
	point.putData();
	circleType circle(point);
	circle.putData();
	cylinderType cylinder(circle);
	cylinder.putData();
	point.getData();
	circle.getData();
	cylinder.getData();
}
