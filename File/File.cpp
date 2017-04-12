#include "File.h"
#include "String.h"

File::File()
{

}

File::File(const String& path)
{
	this->path = path;
}

File::~File()
{
}
