#include <vector>
#include "Path.h"

Path::Path() { }

String Path::normalizePath(const String& path)
{
	return path.replaceAll("/", "\\");
}

String Path::getRoot(const String & path)
{
	return Path::normalizePath(path).split("\\").back();
}

String Path::directoryOf(const String& path)
{
	std::vector<int> slashes = Path::normalizePath(path).indexesOf("\\");

	return path.substring(0, (slashes.size() > 0) ? (slashes.back()) : (0));
}
