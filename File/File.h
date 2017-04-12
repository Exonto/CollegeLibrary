#include "String.h"
#pragma once

#ifndef FILE_H_
#define FILE_H_

class File
{
	friend class FileFactory;

public :
	~File();

private:
	File();
	explicit File(const String& path);

	String& path = String("");
};

#endif