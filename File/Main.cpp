#include <iostream>
#include <vector>
#include "File.h"
#include "Path.h"
#include "String.h"

int main()
{
	//std::cout << s.removeAll(11, 16) << std::endl;

	/*char* c = "Hey.txt";

	if (File::fileExists(c))
	{
		File::deleteFile(c);
	}
	File::createFile("Hey.txt");

	File::renameFile("Hey.txt", "Blah.txt");*/

	//File::createFile("C:\\Users\\Tyler\\Desktop\\CFile\\story.txt");

	String s = File::loadFile("C:\\Users\\Tyler\\Desktop\\CFile\\story.txt");

	std::cout << s << std::endl;

	/*std::vector<String> v = Path::getParentDirectories("C:/Woo/Random/Blah/Woo.lll");

	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << std::endl;
	}*/

	//std::cout << OS << std::endl;

	return 0;
}