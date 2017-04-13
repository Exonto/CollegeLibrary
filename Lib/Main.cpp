#include <iostream>
#include <cstdlib>
#include "File.h"
#include "Path.h"
#include "String.h"

int main()
{
	char* c = "C:/Users/Tyler/Desktop/CFile/Greg.txt";

	/*if (File::fileExists(c))
	{
		File::deleteFile(c);
	}
	File::createFile(c);*/

	//File::renameFile(c, "Blah.txt");
	//std::rename(c, "C:/Users/Tyler/Desktop/CFile/Blah.txt");
	File::renameFile(c, "Blah.txt");

	return 0;
}