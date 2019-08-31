#include "TextureLoader.h"
#include <iostream>

/** \brief Constructor for TextureLoader calls loadMain() function
* \param accepts no parameters
* \return returns nothing
*/
TextureLoader::TextureLoader()
{
	loadMain();
}

/** \brief Loads the essential textures into an array to reference
* \param accepts no parameters
* \return returns nothing
*/
void TextureLoader::loadMain()
{
	if(!textureArray[0].loadFromFile("../assets/winButton.png"))
		std::cout << "Failed to load __ asset" << std::endl;

	//goes through the textures and "anti-alias"es them.
	for (int i = 0; i < textureArray.size(); ++i)
	{
		textureArray[i].setSmooth(true);
	}
}