#include "String.h"

#pragma once

#ifndef FILE_H_
#define FILE_H_

class File
{
public:
	static void createFile(const String& path);
	static void deleteFile(const String& path);
	static void renameFile(const String& path, const String& name);

	static bool fileExists(const String& path);
    static String getFile(const String& path);
    static String getFileName(const String& path);
    static String getExtension(const String& path);

private:

	File();
};

#endif
