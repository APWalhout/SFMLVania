#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"
class Player
{
private:
	int playerHealth;

public:
	sf::Sprite spritePlayer;
	sf::IntRect spriteFramePlayer;

	//needs weapon load
	//needs armor load

	//constructor
	Player(TextureLoader*);

	void drawPlayer(sf::RenderWindow& window);
	bool checkPlayerDeath();

	/**
	*GETTERS
	*/
	float getPlayerPosition();
	int getPlayerHealth();
	/**
	*SETTERS
	*/
	void setPlayerPosition(float);
	void setPlayerHealth(int);

};
#endif

