#pragma once
#include "Person.h"

enum grade {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR};

class Student : public Person {
	grade d_grade;
	double d_gpa;
public:
	explicit Student();
	explicit Student(string name, MyDate birthday, string phone, string email, 
		double gpa, grade grade);
	explicit Student(const Student& s);
	void inputData();
	void printData() const;
};