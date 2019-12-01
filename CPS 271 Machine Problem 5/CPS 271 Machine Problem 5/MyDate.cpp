#include "MyDate.h"
#include <iostream>
using namespace std;

MyDate::MyDate() 
	:
	d_year(0),
	d_month(0),
	d_day(0)
{}

MyDate::MyDate(int year, int month, int day) 
	:
	d_year(year),
	d_month(month),
	d_day(day)
{}

MyDate::MyDate(const MyDate& d) 
	:
	d_year(d.d_year),
	d_month(d.d_month),
	d_day(d.d_day)
{}

void MyDate::inputData() {
	bool done = false;
	string err = "\nInput Error! Please try again.\n\n";
	do {
		try {
			cout << "Month (MM): ";
			cin >> d_month;
			if (!cin) { throw err; }
			cout << "Day (DD): ";
			cin >> d_day;
			if (!cin) { throw err; }
			cout << "Year (YYYY): ";
			cin >> d_year;
			if (!cin) { throw err; }
			cin.ignore(); // flush \n so that getline in other functions will work
			done = true;
		}
		catch (string s)
		{
			cout << s;
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!done);
}
	
void MyDate::printData() const {
	cout << d_month << "/" << d_day << "/" << d_year;
}