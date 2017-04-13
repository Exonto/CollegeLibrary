#include <iostream>
#include "File.h"
#include "Path.h"
#include "String.h"

int main()
{
	char* c = "Hey.txt";

	if (File::fileExists(c))
	{
		File::deleteFile(c);
	}
	File::createFile("Hey.txt");

	File::renameFile("Hey.txt", "Blah.txt");

	return 0;
}