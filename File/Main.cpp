#include <iostream>
#include "FileFactory.h"
#include "Path.h"
#include "String.h"

int main()
{
	char* c = "Hey.txt";

	if (FileFactory::fileExists(c))
	{
		FileFactory::deleteFile(c);
	}
	FileFactory::createFile("Hey.txt");

	FileFactory::renameFile("Hey.txt", "Blah.txt");

	return 0;
}