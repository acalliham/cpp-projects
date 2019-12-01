#pragma once
#include "Employee.h"
#include "MyDate.h"
#include <list>

class Faculty : public Employee {
	int d_officeNumber;
	bool d_tenure;
	list <MyDate> d_officeHours;
public:
	explicit Faculty();
	explicit Faculty(string name, MyDate birthday, string phone, string email, 
		long salary, MyDate hiredate, int officenum, bool tenure, MyDate officehrs);
	explicit Faculty(const Faculty& f);
	void inputData();
	void printData() const;
};