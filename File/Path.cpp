#include <vector>
#include "Path.h"

Path::Path() { }

String Path::normalizePath(const String& path)
{
	return path.replaceAll("/", "\\");
}

String Path::getRoot(const String & path)
{
	return path.split("\\").back();
}

String Path::directoryOf(const String& path)
{
	std::vector<int> slashes = path.indexesOf("\\");

	return path.substring(0, (slashes.size() > 0) ? (path.indexesOf("\\").back()) : (0));
}

std::vector<String> Path::getParentDirectories(const String& path)
{
    return Path::normalizePath(path).split("\\");
}
