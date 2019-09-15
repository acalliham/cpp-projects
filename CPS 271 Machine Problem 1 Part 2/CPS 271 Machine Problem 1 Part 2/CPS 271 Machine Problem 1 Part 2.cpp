// CPS 271 Machine Problem 1 Part 2.cpp
// Name: Amy Calliham
// Student ID: 00683394
// Purpose of Program: read student names and test scores from an input file, write student
//		names, test scores and letter grades to an out file, along with the highest test score
//		and a list of students who achieved that score

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// struct studentData is global, which allows it to be passed to functions
struct studentData {
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

// Function prototypes
void readData(studentData data[], int& numRecords, ifstream& inData);
char assignGrade(int testScore);
void printData(studentData data[], int& numRecords, ofstream& outData);
int findHighScore(studentData data[]);
void printHighScore(studentData data[], ofstream& outData);

int main()
{
	// Declare variables
	studentData classScores[20];
	int numRecords = 0;
	ifstream inData;
	ofstream outData;

	// Open input file
	inData.open("input.txt");

	// Check if file was opened, if not, program ends
	if (!inData) {
		cout << "Input file not found, program will terminate \n";
		return 1;
	}

	// Open or create output file
	outData.open("output.txt");

	// Call functions
	readData(classScores, numRecords, inData);
	printData(classScores, numRecords, outData);
	printHighScore(classScores, outData);

	// Close input and output files
	inData.close();
	outData.close();

	// End program
	return 0;
}

// Function Definitions

// readData() - called by main()
// Paramaters: array of type studentData struct, counter numRecords int, input file, all are passed by reference
// Output: reads each student record from file and populates first name, last name, and test score
//		populates grade by passing test score to assignGrade function
// Error handling: After each student record is read, if the input file fail flag has been set,
//		function clears the input and ignores the rest of the line.  A warning message is posted to the console
//		to alert the user that line of student data may be incorrect.

void readData(studentData data[], int& numRecords, ifstream& inData) {

	for (int i = 0; i < 20; i++) {

		if (!inData.eof()) {  // Check to make sure end of file hasn't been reached

			inData >> data[i].studentFName >> data[i].studentLName >> data[i].testScore; // Read data from file

			data[i].grade = assignGrade(data[i].testScore); // Call assignGrade() to get letter grade

			numRecords++; // Counter to track the number of students and scores read from file

			// Check if an error occurred when last record was read, if so clear input stream and ignore
			//		any other data on that line, then warn user an error occurred
			if (inData.fail()) {
				inData.clear();
				inData.ignore(200, '\n');
				cout << "Warning: input file error, check line " << i + 1 << 
					" for potential bad data \n";
			}
		}
	}
}

// assignGrade() - called by readData()
// Paramaters: student test score int, passed by value
// Output: returns letter grade char

char assignGrade(int testScore) {
	char grade;
	if (testScore >= 90)
		grade = 'A';
	else if (testScore >= 80)
		grade = 'B';
	else if (testScore >= 70)
		grade = 'C';
	else if (testScore >= 60)
		grade = 'D';
	else
		grade = 'F';
	return grade;
}

// printData() - called by main()
// Paramaters: array of type studentData struct, counter numRecords int, output file, all are passed by reference
// Output: prints student names and scores to file in format
//		Last, First score grade

void printData(studentData data[], int& numRecords, ofstream& outData) {
	
	// Loop through data array using numRecords as a counter, to prevent program from trying to
	//		print missing records in case input file contains less than 20 students
	for (int i = 0; i < numRecords; i++) {
		outData << data[i].studentLName << ", " << data[i].studentFName <<
			" " << data[i].testScore << " " << data[i].grade << '\n';
	}
}

// findHighScore() - called by printHighScore()
// Paramaters: array of type studentData struct passed by reference
// Output: returns the highest testScore found in the array

int findHighScore(studentData data[]) {

	int highScore = 0; // Initialize highScore to 0

	// Loop through each testScore in array, compare to current value of highScore, if student 
	// testScore is higher than current highScore value, set highScore equal to student testScore
	for (int i = 0; i < 20; i++) {
		if (data[i].testScore > highScore)
			highScore = data[i].testScore;
	}
	return highScore;
}

// printHighScore() - called by main()
// Paramaters: array of type studentData struct passed by reference, output file passed by reference
// Output: prints highest score and list of students with that score in the format
//		Last, First

void printHighScore(studentData data[], ofstream& outData) {

	int highScore = findHighScore(data); // Get highest score in input file

	outData << '\n' << "List of students who achieved high score of " <<
		highScore << ": \n";

	// Loop through each testScore in array, if testScore equals highest score, print Last and
	//		first name of that record
	for (int i = 0; i < 20; i++) {
		if (data[i].testScore == highScore)
			outData << data[i].studentLName << ", " << data[i].studentFName << '\n';
	}
}
