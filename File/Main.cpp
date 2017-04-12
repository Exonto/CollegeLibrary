#include <iostream>
#include "File.h"
#include "FileFactory.h"
#include "Path.h"

int main()
{
	char* c = "Hey.txt";

	if (FileFactory::fileExists(c))
	{
		FileFactory::deleteFile(c);
	}
	FileFactory::createFile("Hey.txt");
	/*if (FileFactory::fileExists(c))
	{
		FileFactory::deleteFile(c);
	}*/
	//std::cout << FileFactory::fileExists(c) << std::endl;

	String path("C:\\Users\\Tyler\\workspace\\String\\Debug");
	Path p(path);

	//path = "Yes";
	//std::cout << path.indexesOf("|").at(0) << std::endl;
	//std::cout << path.replaceFirst("H", "I") << std::endl;
	std::cout << p.isFile() << std::endl;
	//Path p(path);

	if (FileFactory::fileExists(c))
	{
		//path = String(c);
	}

	//std::cout << p.getPath() << std::endl;

	return 0;
}