#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <exception>
#include "File.h"
#include "String.h"
#include "Path.h"

File::File() { }

void File::createFile(const String& path)
{
	if (File::fileExists(path) == false)
	{
		std::filebuf buf;
		buf.open(path.toStdString(), std::ios::out);
		buf.close();
	} else {
		std::cerr << "Error creating file: File Already Exists - " << path << std::endl;
		throw std::exception("Cannot Create Existing File");
	}
}

void File::deleteFile(const String& path)
{
	if (File::fileExists(path))
	{
		std::remove(path.toStdString().c_str());
	} else {
		std::cerr << "Error deleting file: File Doesn't Exist - " << path << std::endl;
		throw std::exception(("The file " + path.toStdString() + " does not exist").c_str());
	}
}

void File::renameFile(const String& path, const String& name)
{
	if (File::fileExists(path))
	{
		String directory = Path::directoryOf(path);
		std::rename(path.c_string(), 
				   ((directory.length() > 0) ? (directory + "\\" + name) : (name)).c_string());
	} else {
		std::cerr << "Error renaming file: File Doesn't Exist - " << path << std::endl;
		throw std::exception(("The file " + path.toStdString() + " does not exist").c_str());
	}
}

long File::fileLength(const String & path)
{
	std::ifstream file(path.c_string(), std::ios::in);

	file.seekg(0, file.end);
	long length = file.tellg();

	file.close();

	return length;
}

String File::loadFile(const String& path)
{
	std::ifstream file(path.c_string(), std::ios::in);

	String contents;

	file >> contents;

	return contents;
}

void File::overwriteText(const String& path, const String& text)
{
	std::ofstream file(path.c_string(), std::ios::out | std::ios_base::trunc);

	file << text.c_string();

	file.close();
}

void File::writeText(const String& path, const String& text)
{
	std::ofstream file(path.c_string(), std::ios::out | std::ios_base::app);

	file << text.c_string();

	file.close();
}

void File::writeTextNewLine(const String& path, const String& text)
{
	std::ofstream file(path.c_string(), std::ios::out | std::ios_base::app);

	file << std::endl << text.c_string();

	file.close();
}

void File::insertText(const String& path, const String& text, long putIdx)
{
	/*std::ofstream file(path.c_string(), std::ios::out);

	file.seekp(0, file.beg);
	file << text.c_string();

	file.close();*/
}

bool File::fileExists(const String& path)
{
	std::ifstream iStream(path.toStdString(), std::ios::in);

	return iStream.good();
}

String File::getFile(const String& path)
{
	return Path::normalizePath(path).split("\\").back();
}

String File::getFileName(const String& path)
{
	return File::getFile(path).split(".").front();
}

String File::getExtension(const String& path)
{
	std::vector<String> pathSegments = File::getFileName(path).split(".");

	// The file name, when split at '.' will have two parts
	if (pathSegments.size() >= 2)
	{
		return pathSegments.back();
	} else {
		std::cerr << "The path provided does not have a valid extension: " << path << std::endl;
		throw std::exception("Path has no valid extension");
	}
}


