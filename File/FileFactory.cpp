#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <exception>
#include "FileFactory.h"
#include "File.h"
#include "String.h"

FileFactory::FileFactory() { }

File FileFactory::createFile(const String& path)
{
	if (FileFactory::fileExists(path) == false)
	{
		std::filebuf buf;
		buf.open(path.toStdString(), std::ios::out);
		buf.close();
	} else {
		std::cerr << "Error creating file: File Already Exists - " << path << std::endl;
		throw std::exception("Cannot Create Existing File");
	}

	return File(path);
}

void FileFactory::deleteFile(const String& path)
{
	bool succeeded = false;
	if (FileFactory::fileExists(path))
	{
		std::remove(path.toStdString().c_str());
	} else {
		throw std::exception(("The file " + path.toStdString() + " does not exist").c_str());
	}
}

bool FileFactory::fileExists(const String& path)
{
	std::ifstream iStream(path.toStdString(), std::ios::in);

	return iStream.good();
}


