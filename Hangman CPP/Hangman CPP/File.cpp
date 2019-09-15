#include "File.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>

using namespace std;

File::File()
	:
	d_fileLength(0),
	d_fileName("words.txt") // To Do: add ability to get all txt files in a folder and let user choose one
{
	inData.open(d_fileName);
	setFileLength();
}

void File::setFileLength()
{
	// Loop through each line of file and increment d_fileLength
	// until end of file is reached
	do {
		++d_fileLength;
		inData.ignore(100, '\n');
	} while (!inData.eof());
}

void File::getWord(string &word)
{
	// Pick random line to read from file
	srand(time(NULL));
	short rowNum = rand() % d_fileLength + 1;
	
	// Return to beginning of file
	inData.clear();
	inData.seekg(0);

	// Ignore all rows until random line is reached
	for (int i = 0; i < rowNum; i++)
		inData.ignore(100, '\n');

	// Read word from file
	string tmp;
	inData >> tmp;
	for (char& c : tmp)
		c = toupper(c);
	word = tmp;
}