#include "String.h"
#include "File.h"

#pragma once

#ifndef PATH_H_
#define PATH_H_

class Path
{


public:
	Path(const String& path);
	~Path();

	static String normalizeSlashes(const String& path);

	bool isFile() const;
	bool isDirectory() const;

	String getRoot() const;
	const String& getPath() const;
	String toString() const;

private:
	String path;
};

#endif