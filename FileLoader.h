#pragma once
#ifndef FILELOADER_H
#define FILELOADER_H

#include <iostream>
#include <pugixml.hpp>
#include <pugiconfig.hpp>
class FileLoader
{
public:
	FileLoader();

	pugi::xml_document loadFile(std::string);
};
#endif

