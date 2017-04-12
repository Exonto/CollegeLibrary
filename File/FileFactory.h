#include "String.h"
#include "File.h"

#pragma once

#ifndef FILEFACTORY_H_
#define FILEFACTORY_H_

class FileFactory
{
public:
	static File createFile(const String& path);
	static void deleteFile(const String& path);

	static bool fileExists(const String& path);

private:
	FileFactory();
};

#endif
