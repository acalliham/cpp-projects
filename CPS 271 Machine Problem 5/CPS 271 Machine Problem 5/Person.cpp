#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() 
	:
	d_email(),
	d_name(),
	d_phone()
{
	d_birthDate = MyDate();
}

Person::Person(string name, MyDate birthday, string phone, string email)
	:
	d_email(email),
	d_name(name),
	d_phone(phone)
{
	d_birthDate = MyDate(birthday);
}

Person::Person(const Person& p)
	:
	d_email(p.d_email),
	d_name(p.d_name),
	d_phone(p.d_phone),
	d_birthDate(p.d_birthDate)
{}

void Person::inputData() {
	cout << "Input full name\n";
	getline(cin, d_name);
	cout << "Input email address\n";
	getline(cin, d_email);
	cout << "Input phone number\n";
	getline(cin, d_phone);
	cout << "Input birth date\n";
	d_birthDate.inputData();
}

void Person::printData() const {
	cout << "\nName: " << d_name;
	cout << "\nBirthday: ";
	d_birthDate.printData();
	cout << "\nEmail address: " << d_email;
	cout << "\nPhone number: " << d_phone;
}

Person::~Person() {}