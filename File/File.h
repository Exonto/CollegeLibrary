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

	static long fileLength(const String& path);
	static String loadFile(const String& path);

	static void overwriteText(const String& path, const String& text);
	static void writeText(const String& path, const String& text);
	static void writeTextNewLine(const String& path, const String& text);
	static void insertText(const String& path, const String& text, long putIdx);

	static bool fileExists(const String& path);
    static String getFile(const String& path);
    static String getFileName(const String& path);
    static String getExtension(const String& path);

private:

	File();
};

#endif
