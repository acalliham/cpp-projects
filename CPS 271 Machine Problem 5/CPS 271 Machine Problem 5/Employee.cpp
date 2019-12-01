#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee() 
	:
	d_salary()
{
	d_hireDate = MyDate();
}

Employee::Employee(string name, MyDate birthday, string phone, string email, 
	long salary, MyDate hiredate)
	:
	Person(name, birthday, phone, email),
	d_salary(salary)
{
	d_hireDate = hiredate;
}

Employee::Employee(const Employee& e)
	:
	d_salary(e.d_salary),
	d_hireDate(e.d_hireDate)
{}

void Employee::inputData() {
	Person::inputData();
	cout << "Input Salary\n";
	cin >> d_salary;
	cin.ignore(); // flush \n so that getline in other functions will work
	cout << "Input Hire Date\n";
	d_hireDate.inputData();
}

void Employee::printData() const {
	Person::printData();
	cout << "\nSalary: " << d_salary << "\nHire date: ";
	d_hireDate.printData();
}

Employee::~Employee(){}