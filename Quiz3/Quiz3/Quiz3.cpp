// Quiz3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//class Rect
//
//{
//private:
//	int x;
//
//	int y;
//
//public:
//
//	Rect();
//
//	Rect(int a, int b);
//
//	Rect operator + (const Rect& r) const;
//	void setData(int a, int b);
//
//};
//
//class Square : public Rect
//{
//public:
//	Square();
//	Square(int a);
//	void setData(int a);
//};

int main()
{
	int* p;

	int* q;

	p = new int;

	q = new int;

	*p = 27;

	*q = 35;

	cout << *p << " " << *q << endl;

	q = p;

	*q = 73;

	cout << *p << " " << *q << endl;

	p = new int;

	*p = 36;

	*q = 42;

	cout << *p << " " << *q << endl;


}

//Rect Rect::operator + (const Rect& r) const
//{
//	int a = x + r.x;
//	int b = y + r.y;
//	return Rect(a, b);
//}
//
//void Rect::setData(int a, int b)
//{
//	x = a;
//	y = b;
//}
//
//Square::Square()
//{
//	Rect::setData(1, 1);
//}
//Square::Square(int a)
//{
//	Rect::setData(a, a);
//}
//void Square::setData(int a)
//{
//	Rect::setData(a, a);
//}


/*Define a class called Square derived from Rect (as seen above) which ensures x and y always have the same values in them. Meaning a Square MUST have equal length sides, where a Rectangle does not have that requirement.

Create the class definition (the header file) and implement appropriate constructor and setData functions (the cpp file) to ensure x and y are always the same value.*/