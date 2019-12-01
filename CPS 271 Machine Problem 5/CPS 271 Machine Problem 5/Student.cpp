#include "Student.h"
#include "Person.h"
#include <iostream>
using namespace std;

Student::Student()
	:
	d_grade(FRESHMAN),
	d_gpa(0.0)
{}

Student::Student(string name, MyDate birthday, string phone, string email, double gpa, grade grade)
	:
	Person(name, birthday, phone, email),
	d_grade(grade),
	d_gpa(gpa)
{}

Student::Student(const Student& s) 
	:
	d_grade(s.d_grade),
	d_gpa(s.d_gpa)
{}

void Student::inputData() {
	int gradeValue;
	cout << "Enter Student Data\n";
	Person::inputData();
	cout << "Input Grade (enter corresponding number)\n0 FRESHMAN \n1 SOPHOMORE \n2 JUNIOR \n3 SENIOR\n";
	cin >> gradeValue;
	d_grade = static_cast<grade>(gradeValue);
	cout << "Enter GPA:\n";
	cin >> d_gpa;
	cin.ignore(); // flush \n so that getline in other functions will work
}

void Student::printData() const {
	cout << "\n\nStudent Data:";
	Person::printData();
	cout << "\nGrade: ";
	switch (d_grade) {
	case FRESHMAN:
		cout << "Freshman";
		break;
	case SOPHOMORE:
		cout << "Sophomore";
		break;
	case JUNIOR:
		cout << "Junior";
		break;
	case SENIOR:
		cout << "Senior";
		break;
	}
	cout << "\nGPA: " << d_gpa << "\n";
}