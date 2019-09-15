// CPS 271 Machine Problem 1 Part 1.cpp : 
// Name: Amy Calliham
// Student ID: 00683394
// Purpose of Program: Call three functions, one to raise a number to the power of another number, 
//		two to calculate the number of seconds in HH:MM:SS, three to swap the value of two numbers

#include <iostream>

using namespace std;

// Function Prototypes
double power(double n, int p);
long hms_to_sec(int hours, int minutes, int seconds);
void swap(int& a, int& b);

int main()
{					
	// Declare variables for input to user-defined functions
	double num;  // Input to power()
	int pow;  // Input to power()
	int hrs, min, sec;  // Input to hms_to_sec()
	int a, b;  // Input to swap()

	// Implementation of power()
	cout << "To calculate n^p, enter a decimal and an integer \n";
	cin >> num >> pow;
	cout << num << "^" << pow << " = " << power(num, pow) << endl << endl;

	// Clear input stream in case there is any junk
	cin.clear();  
	cin.ignore(200, '\n');

	// Implementation of hms_to_sec()
	// Loop will repeat until a negative value is read into the hrs variable
	do {
		cout << "Enter a time in hours, minutes, and seconds, using format HH:MM:SS \n";
		cout << "If you wish to exit, enter a negative number \n";
		cin >> hrs;
		if (hrs < 0)
			break;  // Exit loop if user enters a negative number
		cin.ignore(1, ':');
		cin >> min;
		cin.ignore(1, ':');
		cin >> sec;
		cout << "There are " << hms_to_sec(hrs, min, sec) << " seconds in " << 
			hrs << ":" << min << ":" << sec << endl << endl;
		// Clear input stream in case there is any junk
		cin.clear();
		cin.ignore(200, '\n');
	} while (hrs >= 0);

	// Implementation of swap()
	cout << endl << "Enter two integers, a and b \n";
	cin >> a >> b;
	cout << "Before swap(), a = " << a << " and b = " << b << endl;
	swap(a, b);
	cout << "After swap(), a = " << a << " and b = " << b << endl;

	return 0;

}

// Function Definitions

// Power()
// Inputs: double n (base number), int p (number that n will be raised to the power of), passed by value
// Result: returns double n^p

double power(double n, int p = 2) {
	// Note - the case for 0^0 has not been handled, that should return "undefined"
	// but has not been included due to the return being of type int

	static_cast<double>(p);
	double result = 1;
	
	// case for 0^n = 0
	if (n == 0)
		result = 0;

	// case for n^0 = 1
	else if (p == 0)
		result = 1;

	// case for n^(positive power)
	else if (p > 0) {
		for (int i = 1; i <= p; i++) 
			result = result * n;
	}

	// case for n^(negative power)
	else if (p < 0) {
		for (int i = 1; i <= abs(p); i++) 
			result = result / n;
	}

	return result;
}

// hms_to_sec()
// Inputs: int hours, int minutes, int seconds, passed by value
// Result: returns the total number of seconds for the hours, minutes, and seconds values entered

long hms_to_sec(int hours, int minutes, int seconds) {
	return (hours * 60 * 60) + (minutes * 60) + seconds;
}

// swap()
// Inputs: int a, int b, both passed by reference
// Result: swaps the initial values of a and b

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

