#pragma once

class MyDate {
	int d_year;
	int d_month;
	int d_day;

public:
	MyDate();
	MyDate(int year, int month, int day);
	MyDate(const MyDate& d);
	void inputData();
	void printData() const;
};