#pragma once
#include "MyDate.h"
#include <string>
using namespace std;

class Person {
	string d_name;
	MyDate d_birthDate;
	string d_phone;
	string d_email;

public:
	explicit Person();
	explicit Person(string name, MyDate birthday, string phone, string email);
	explicit Person(const Person& p);
	virtual void inputData();
	virtual void printData() const = 0;
	virtual ~Person();
};