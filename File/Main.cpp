#include <iostream>
#include <vector>
#include "File.h"
#include "Path.h"
#include "String.h"

int main()
{
	/*char* c = "Hey.txt";

	if (File::fileExists(c))
	{
		File::deleteFile(c);
	}
	File::createFile("Hey.txt");

	File::renameFile("Hey.txt", "Blah.txt");*/


    String fileName = File::getFileName("C:/Woo/Random/Blah/Woo.lll");
    std::vector<String> v = Path::getParentDirectories("C:/Woo/Random/Blah/Woo.lll");

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << std::endl;
    }

    //std::cout << fileName << std::endl;

	return 0;
}