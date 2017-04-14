#include <iostream>
#include <vector>
#include "File.h"
#include "Path.h"
#include "String.h"
#include "_os.h"

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


	String path = "../../Hey.txt";
    String fileName = Path::getAbsolute(path);
    /*std::vector<String> v = Path::getParentDirectories("C:/Woo/Random/Blah/Woo.lll");

    for (int i = 0; i < v.size(); i++) {
        std::cout << v.at(i) << std::endl;
    }*/

	//std::cout << OS << std::endl;

	return 0;
}