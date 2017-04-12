#include <Windows.h>
#include "Path.h"

Path::Path(const String& path)
{
	this->path = Path::normalizeSlashes(path);
}

Path::~Path()
{
	
}

String Path::normalizeSlashes(const String& path)
{
	return path.replaceAll("/", "\\");
}

bool Path::isFile() const
{
	return true;
}

bool Path::isDirectory() const
{
	return !this->isFile();
}

String Path::getRoot() const
{
	return this->path.split("\\").back();
}

const String& Path::getPath() const
{
	return this->path;
}

String Path::toString() const
{
	return this->path;
}
