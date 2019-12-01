// CPS 271 Machine Problem 2 
// Name: Amy Calliham
// Student ID: 00683394
// Purpose of Program: Allows the user to enter in two Fractions using the Input() function and a mathematical operation. 
//		After the operation, print the Fraction result using the Print() function. The loop ends when the user enters 
//		Q or q to quit for the math operation.

#include <iostream>
#include "Fraction.h"

using namespace std;

//***FUNCTION PROTOTYPES*** Function definitions appears below main().  

// This function gets the user's choice of mathematical operation (Add, Subtract, Multiply, Divide)
// and returns an int, which is used by a switch statement in main().
int getMath();

// This function runs the tests provided by the instructor;
void testFraction();

//***MAIN***

int main(void)
{
	// Run test of Fraction class
	cout << "Before the main program starts, the instructor's tests will be executed \n";
	testFraction(); 
	
	bool quit = false; // Used in Do While loop, when set to true program will exit loop and end
	
	// Loop prompts user to input two fractions and a math operation, then prints the result
	do {
		try {
			Fraction f1, f2, f3 = Fraction(); // Create three fractions initialized to 0
			f1.Input(); // Get first fraction
			f2.Input(); // Get second fraction
			switch (getMath()) { // Get math operation to perform on f1 and f2, and switch based on integer returned
			case 1: // Addition
				f3.Add(f1, f2);
				break;
			case 2: // Subtraction
				f3.Subtract(f1, f2);
				break;
			case 3: // Multiplication
				f3.Multiply(f1, f2);
				break;
			case 4: // Division
				f3.Divide(f1, f2);
				break;
			}
			f3.Print(); // Print result

			// Determine if program should quit or perform a new fraction calculation
			cout << "Enter n to enter a new calculation or q to quit\n";
			char c;
			cin >> c;
			cout << "\n";
			if (c == 'q' || c == 'Q') // if user enters q or Q, set quit to true to exit at end of do/while loop
				quit = true;
			else {   // If any other char or input entered, continue and execute loop again.
				cin.clear();  // Call clear and ignore in case of input error
				cin.ignore(100, '\n');
				continue;
			}
		}
		// If any exception is thrown, error will be displayed to the user and the do while loop will execute again
		catch (...) {
			cout << "Error!  Please try again. \n";
		}
	} while (!quit); // Loop will end when user enters q or Q for char c
	return 0;
}

//***FUNCTION DEFINITIONS***

// This function gets the user's choice of mathematical operation (Add, Subtract, Multiply, Divide)
// and returns an int, which is used by a switch statement in main().
int getMath() {

	// Outupt messages for specific exceptions
	const string inputError = "Input error!  Please try again.\n";
	const string badMath = "Invalid selection!  Please try again.";

	int math = 0; // Variable to hold user's math operation selection
	bool done = false; // Used in Do While loop, will be set to true once a valid operation is entered
	do {
		try {
			cout << "\nEnter the number of the mathematical operation you would like to perform\n" <<
				"1   Add\n2   Subtract\n3   Multiply\n4   Divide\n";
			cin >> math;
			if (!cin) 
			{
				cin.clear();  // Call clear and ignore in case of input error
				cin.ignore(100, '\n');
				throw inputError;
			}
			else if (math < 1 || math > 4) // Throw exception if anything other than an integer between 1 and 4 is entered
				throw badMath;
			done = true;
		}
		// If any exception is thrown, error will be displayed to the user and the do while loop will execute again
		catch (string s) {
			cout << s << "\n";
		}
		catch (...) {
			cout << "Error!  Please try again";
		}
	} while (!done);
	return math;
}

// This function runs the tests provided by the instructor
void testFraction() {
	Fraction f1(1, 2);
	Fraction f2(4);
	Fraction f3(3.1415927);
	Fraction a1, a2;
	Fraction s1, s2;
	Fraction m1, m2;
	Fraction d1, d2;

	a1.Input();
	a1.Print();

	a1 = f1.Add(f2);
	a2.Add(f2, f3);

	s1 = f1.Subtract(f2);
	s2.Subtract(f2, f3);

	m1 = f1.Multiply(f2);
	m2.Multiply(f2, f3);

	d1 = f1.Divide(f2);
	d2.Divide(f2, f3);

	cout << endl << "F1: "; f1.Print();
	cout << endl << "F2: "; f2.Print();
	cout << endl << "F3: "; f3.Print();

	cout << endl;
	cout << endl << "F4 = F1+F2: "; a1.Print();
	cout << endl << "F5 = F2+F3: "; a2.Print();

	cout << endl;
	cout << endl << "F4 = F1-F2: "; s1.Print();
	cout << endl << "F5 = F2-F3: "; s2.Print();

	cout << endl;
	cout << endl << "F4 = F1*F2: "; m1.Print();
	cout << endl << "F5 = F2*F3: "; m2.Print();

	cout << endl;
	cout << endl << "F4 = F1/F2: "; d1.Print();
	cout << endl << "F5 = F2/F3: "; d2.Print();

	cout << endl << endl;
}