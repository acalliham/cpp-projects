#pragma once
#include "Employee.h"
#include <string>
using namespace std;

class Staff : public Employee {
	string d_title;
public:
	explicit Staff();
	explicit Staff(string name, MyDate birthday, string phone, string email, 
		long salary, MyDate hiredate, string title);
	explicit Staff(const Staff& s);
	void inputData();
	void printData() const;
};