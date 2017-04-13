#include "String.h"

#pragma once

#ifndef FILEFACTORY_H_
#define FILEFACTORY_H_

class FileFactory
{
public:
	static void createFile(const String& path);
	static void deleteFile(const String& path);
	static void renameFile(const String& path, const String& name);

	static bool fileExists(const String& path);

private:

	FileFactory();
};

#endif
