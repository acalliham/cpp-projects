// Quiz 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class One
{
public:
	void print() const;   //Output the values of x and y
protected:
	void setData(int u, int v);    //Post condition: x = u; y = v;
private:
	int x;
	int y;
};

class Two : public One
{
public:
	void setData(int a, int b, int c);    //Postcondition: x = a; y = b; z = c;
	void print() const;    //Output the values of x, y, and z
private:
	int z;
};

void Two::setData(int a, int b, int c)
{
	One::setData(a, b);
	z = c;
}

void Two::print() const
{
	One::print();
	cout << z;
}

//Write the definition of the function setData of the class Two.
//Write the definition of the function print of the class Two.
//Which members of class Two are private ?

int main()
{
    std::cout << "Hello World!\n";




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
