#include "Faculty.h"
#include <iostream>
#include <list>
#include <string>
using namespace std;

Faculty::Faculty() 
	:
	d_officeNumber(),
	d_tenure(),
	d_officeHours()
{}

Faculty::Faculty(string name, MyDate birthday, string phone, string email, long salary, 
	MyDate hiredate, int officenum, bool tenure, MyDate officehrs)
	:
	Employee(name, birthday, phone, email, salary, hiredate),
	d_officeNumber(officenum),
	d_tenure(tenure)
{
	d_officeHours.push_back(officehrs);
}

Faculty::Faculty(const Faculty& f) 
	:
	d_officeNumber(f.d_officeNumber),
	d_tenure(f.d_tenure),
	d_officeHours(f.d_officeHours)
{}

void Faculty::inputData() {
	int tenureVal;
	cout << "Enter Faculty Data\n";
	Employee::inputData();
	cout << "Input office number:\n";
	cin >> d_officeNumber;
	cout << "Input tenure (1 for true, 0 for false):\n";
	cin >> tenureVal;
	d_tenure = static_cast<bool>(tenureVal);
	cout << "Input office hours:\n";
	bool done = false;
	while (!done) {
		MyDate temp;
		temp.inputData();
		d_officeHours.push_back(temp);
		cout << "Input another date?  Enter y for yes, n for no\n";
		char c;
		cin >> c;
		if (c == 'y' || c == 'Y')
			done = false;
		else
			done = true;
	}
	cin.ignore(); // flush \n so that getline in other functions will work
}

void Faculty::printData() const {
	cout << "\n\nFaculty Data:";
	Employee::printData();
	cout << boolalpha; 
	cout << "\nOffice number: " << d_officeNumber << "\nTenure: " << d_tenure << "\nOffice hours: ";
	for (const MyDate& date : d_officeHours) {
		date.printData();
		cout << ", ";
	}
}