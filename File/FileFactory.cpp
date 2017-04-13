#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <exception>
#include "FileFactory.h"
#include "String.h"
#include "Path.h"

FileFactory::FileFactory() { }

void FileFactory::createFile(const String& path)
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
}

void FileFactory::deleteFile(const String& path)
{
	if (FileFactory::fileExists(path))
	{
		std::remove(path.toStdString().c_str());
	} else {
		std::cerr << "Error deleting file: File Doesn't Exist - " << path << std::endl;
		throw std::exception(("The file " + path.toStdString() + " does not exist").c_str());
	}
}

void FileFactory::renameFile(const String& path, const String& name)
{
	if (FileFactory::fileExists(path))
	{
		String directory = Path::directoryOf(path);
		std::rename(path.c_string(), 
				   ((directory.length() > 0) ? (directory + "\\" + name) : (name)).c_string());
	} else {
		std::cerr << "Error renaming file: File Doesn't Exist - " << path << std::endl;
		throw std::exception(("The file " + path.toStdString() + " does not exist").c_str());
	}
}

bool FileFactory::fileExists(const String& path)
{
	std::ifstream iStream(path.toStdString(), std::ios::in);

	return iStream.good();
}


