#include "String.h"

#pragma once

#ifndef PATH_H_
#define PATH_H_

class Path
{
public:
	static String normalizePath(const String& path);

	static String getRoot(const String& path);
	static String directoryOf(const String& path);

private:
	Path();
};

#endif