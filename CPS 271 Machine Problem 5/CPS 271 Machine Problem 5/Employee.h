#pragma once
#include "Person.h"
#include "MyDate.h"
#include <string>
using namespace std;

class Employee : public Person {
	long d_salary;
	MyDate d_hireDate;
public:
	explicit Employee();
	explicit Employee(string name, MyDate birthday, string phone, string email, 
		long salary, MyDate hiredate);
	explicit Employee(const Employee& e);
	virtual void inputData();
	virtual void printData() const = 0;
	virtual ~Employee();
};