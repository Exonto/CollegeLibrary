#include <vector>
#include "Path.h"
#ifndef LINUX
	#include <Windows.h>
#else
	#include <limits.h>
	#include <stdlib.h>
#endif

Path::Path() { }

String Path::normalizePath(const String& path)
{
	return path.replaceAll("/", "\\");
}

String Path::getAbsolute(const String& path)
{
#ifndef LINUX
	TCHAR fullPath[MAX_PATH];

	GetFullPathName(path.c_string(), MAX_PATH, fullPath, NULL);

	return fullPath;
#else
	char* fullPath = realPath(path.c_string(), NULL);

	return fullPath;
#endif
}

String Path::getRoot(const String& path)
{
	return Path::normalizePath(path).split("\\").back();
}

String Path::directoryOf(const String& path)
{
	String nPath = Path::normalizePath(path);

	std::vector<int> slashes = nPath.indexesOf("\\");

	return nPath.substring(0, (slashes.size() > 0) ? (nPath.indexesOf("\\").back()) : (0));
}

String Path::getParentPath(const String& path)
{
	String nPath = Path::normalizePath(path);

	return nPath.splitRemoveEnd("\\");
}

std::vector<String> Path::getParentDirectories(const String& path)
{
	std::vector<String> directories = Path::normalizePath(path).split("\\");
	directories.pop_back();

	return directories;
}
