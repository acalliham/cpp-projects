#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File
{
	ifstream inData;
	string const d_fileName;
	short d_fileLength;
	string d_word;

public:
	File();
	void getWord(string &word);

private:
	void setFileLength();
};