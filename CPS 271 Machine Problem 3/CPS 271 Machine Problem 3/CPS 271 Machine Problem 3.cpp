// CPS 271 Machine Problem 3
// Name: Amy Calliham
// Student ID: 00683394
// Purpose of Program: 

#include <iostream>
#include "Fraction.h"

using namespace std;

//***FUNCTION PROTOTYPES*** Function definitions appears below main().  

// This function gets the user's choice of mathematical operation (Add, Subtract, Multiply, Divide)
// and returns an int, which is used by a switch statement in main().
int getMath();

int const NUMOPS = 23;
string const OPERATIONS[NUMOPS] {"F1 + F2", "F1 - F2", "F1 * F2", "F1 / F2", "F1 += F2", "F1 -= F2", "F1 *= F2", "F1 /= F2",
	"F1 > F2", "F1 < F2", "F1 >= F2", "F1 <= F2", "F1 == F2", "F1 != F2", "!F1", "F3 = ++F1", "F3 = F1++", "F3 = --F1", 
	"F3 = F1--", "F3 = -F1", "F3 = ~F1" , "float F1", "double F1"};

//***MAIN***

int main(void)
{
	cout << boolalpha; // set output to print true and false instead of 1 and 0 for bool values
	
	// Variables used in Do While loops
	bool quit = false; // Used in outter Do While loop, when set to true program will exit loop and end
	bool f1err; // Used in inner Do While loop, when f1 is input will be set to true
	bool f2err; // Used in inner Do While loop, when f2 is input will be set to true

	Fraction f(2, 3);
	f += 5.6;
	cout << f;

	// Loop prompts user to input two fractions and a math operation, then prints the result
	do {
		try {
			Fraction f1, f2, f3 = Fraction(); // Create three fractions initialized to 0
			
			// Get Fraction f1
			do {
				try {
					f1err = false;
					cout << "Enter fraction F1: NN/DD\n";
					cin >> f1;
				}
				catch (string s) {
					cout << s << endl;
					f1err = true;
				}
				catch (...) {
					cout << "Error, please try again!\n";
					f1err = true;
				}
			} while (f1err);
			
			// Get Fraction f2
			do {
				try {
					f2err = false;
					cout << "\nEnter fraction F2: NN/DD\n";
					cin >> f2;
				}
				catch (string s) {
					cout << s << endl;
					f2err = true;
				}
				catch (...) {
					cout << "Error, please try again!\n";
					f2err = true;
				}
			} while (f2err);

			int op = getMath(); // get user's choice of operation from the console

			cout << "Before the operation, F1 = " << f1 << " and F2 = " << f2 << endl;

			// Variables to hold output of various switch statement cases
			bool result; 
			float fl_value;
			double dbl_value;
			int int_value;

			// Switch to execute operation and print results
			switch (op) { 
			case 0: // F1+F2
				f3 = f1 + f2;
				cout << f1 << " + " << f2 << " = " << f3;
				break;
			case 1: // F1-F2
				f3 = f1 - f2;
				cout << f1 << " - " << f2 << " = " << f3;
				break;
			case 2: // F1*F2
				f3 = f1 * f2;
				cout << f1 << " * " << f2 << " = " << f3;
				break;
			case 3: // F1/F2
				f3 = f1 / f2;
				cout << f1 << " / " << f2 << " = " << f3;
				break;
			case 4: // F1+=F2
				f1 += f2;
				cout << "after " << OPERATIONS[op] << " F1 = " << f1 << " and F2 = " << f2;
				break;
			case 5: // F1-=F2
				f1 -= f2;
				cout << "after " << OPERATIONS[op] << " F1 = " << f1 << " and F2 = " << f2;
				break;
			case 6: // F1*=F2
				f1 *= f2;
				cout << "after " << OPERATIONS[op] << " F1 = " << f1 << " and F2 = " << f2;
				break;
			case 7: // F1/=F2
				f1 /= f2;
				cout << "after " << OPERATIONS[op] << " F1 = " << f1 << " and F2 = " << f2;
				break;
			case 8: // F1>F2
				result = f1 > f2;
				cout << f1 << " > " << f2 << " is " << result << endl;
				break;
			case 9: // F1<F2
				result = f1 < f2;
				cout << f1 << " < " << f2 << " is " << result << endl;
				break;
			case 10: // F1>=F2
				result = f1 >= f2;
				cout << f1 << " >= " << f2 << " is " << result << endl;
				break;
			case 11: // F1<=F2
				result = f1 <= f2;
				cout << f1 << " <= " << f2 << " is " << result << endl;
				break;
			case 12: // F1==F2
				result = f1 == f2;
				cout << f1 << " == " << f2 << " is " << result << endl;
				break;
			case 13: // F1!=F2
				result = f1 != f2;
				cout << f1 << " != " << f2 << " is " << result << endl;
				break;
			case 14: // !F1
				int_value = !f1;
				cout << "!" << f1 << " = " << int_value;
				break;
			case 15: // F3 = ++F1;
				f3 = ++f1;
				cout << "After F3 = ++F1, F1 = " << f1 << " and F3 = " << f3;
				break;
			case 16: // F3 = F1++
				f3 = f1++;
				cout << "After F3 = F1++, F1 = " << f1 << " and F3 = " << f3;   // NEED TO FIX THIS
				break;
			case 17: // F3 = --F1
				f3 = --f1;
				cout << "After F3 = --F1, F1 = " << f1 << " and F3 = " << f3;
				break;
			case 18: // F3 = F1--
				f3 = f1--;
				cout << "After F3 = F1--, F1 = " << f1 << " and F3 = " << f3;
				break;
			case 19: // F3 = -F1
				f3 = -f1;
				cout << "After F3 = -F1, F1 = " << f1 << " and F3 = " << f3;
				break;
			case 20: // F3 = ~F1
				f3 = ~f1;
				cout << "After F3 = ~F1, F1 = " << f1 << " and F3 = " << f3;
				break;
			case 21: // float F1
				fl_value = (float) f1;
				cout << "(float) " << f1 << " = " << fl_value << endl;
				break;
			case 22: // double F1
				dbl_value = (double) f1;
				cout << "(double) " << f1 << " = " << dbl_value << endl;
				break;
			default:
				throw;
			}

			// Determine if program should quit or perform a new fraction calculation
			cout << "\n\nEnter n to enter a new calculation or q to quit\n";
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

	int math; // Variable to hold user's math operation selection
	bool done = false; // Used in Do While loop, will be set to true once a valid operation is entered
	do {
		try {
			cout << "\n\nList of operations:\n";
			for (int i = 0; i < NUMOPS; i++)
				cout << i << "   " << OPERATIONS[i] << endl;
			cout << "\nEnter the number of the operation you would like to perform\n";
			cin >> math;
			cout << endl;
			if (!cin)
			{
				cin.clear();  // Call clear and ignore in case of input error
				cin.ignore(100, '\n');
				throw inputError;
			}
			else if (math < 0 || math >= NUMOPS) // Throw exception if anything other than an integer between 0 and NUMOPS-1 is entered
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

