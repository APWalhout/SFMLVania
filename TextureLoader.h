#pragma once
#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SFML/Graphics.hpp>
#include <array>
class TextureLoader
{
private:

public:
	TextureLoader();//constructor
	void loadMain();//loads essential textures
	int intArr[10];

	std::array<sf::Texture, 10> textureArray;
};
#endif

