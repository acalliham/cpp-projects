// Hangman CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class file
{
private:
	ifstream inData;
	string d_fileName;
	short d_fileLength;
	string d_word;

public:
	file(string fileName);
	string getNewWord();

private:
	void setFileLength();
	string readRand();
};

class word
{
private:
	string d_word;
public:
	
};

class hangman
{

};

int main()
{
    cout << "Hello World!\n";
}

