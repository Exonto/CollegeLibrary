#include <vector>
#include "Path.h"

Path::Path() { }

String Path::normalizePath(const String& path)
{
	return path.replaceAll("/", "\\");
}

String Path::getRoot(const String& path)
{
	return Path::normalizePath(path).split("\\").back();
}

String Path::directoryOf(const String& path)
{
	std::vector<int> directories = Path::normalizePath(path).indexesOf("\\");

	return path.substring(0, (directories.size() > 0) ? (path.indexesOf("\\").back()) : (0));
}

String Path::getParentPath(const String& path)
{
	return String();
}

std::vector<String> Path::getParentDirectories(const String& path)
{
	std::vector<String> directories = Path::normalizePath(path).split("\\");
	directories.pop_back();

    return directories;
}
