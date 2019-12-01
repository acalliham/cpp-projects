#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff() 
	:
	d_title()
{}

Staff::Staff(string name, MyDate birthday, string phone, string email, 
	long salary, MyDate hiredate, string title)
	:
	Employee(name, birthday, phone, email, salary, hiredate),
	d_title(title)
{}

Staff::Staff(const Staff& s) 
	:
	d_title(s.d_title)
{}

void Staff::inputData() {
	cout << "Enter Staff Data\n";
	Employee::inputData();
	cout << "Input title:\n";
	getline(cin, d_title);  
}

void Staff::printData() const {
	cout << "\n\nStaff Data:";
	Employee::printData();
	cout << "\nTitle: " << d_title;
}