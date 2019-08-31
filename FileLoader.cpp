#include "FileLoader.h"

FileLoader::FileLoader()
{}

/** \brief Loads the specified file from ../SMLVania/include/ and appends .xml
* \param accepts the name or extended path of the xml file without the .xml
* \return returns the file requested
*/
pugi::xml_document loadFile(std::string fileName)
{
	std::string filePath = "../SFMLVania/include/" + fileName + ".xml";
	int pathSize = filePath.length();
	
	//need to make a 'new' as pathSize is 'dynamic' and a non new char[] needs a const initializer
	char* charPointer = new char[pathSize + 1];

	strcpy(charPointer, filePath.c_str());


	pugi::xml_document documentXML;
	//pugi::xml_parse_result documentResult = documentXML.load_file("../SFMLVania/include/Settings.xml");
	pugi::xml_parse_result documentResult = documentXML.load_file(charPointer);

	//check if failed to load and throw error

	delete[] charPointer;

	return documentXML;
}
