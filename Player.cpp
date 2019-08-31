#include "Player.h"
#include <pugixml.hpp>

/** \brief Constructor for the player object. Loads stats from XML, sets texture as given.
* \param accepts a TextureLoader pointer to an array of sprites for player animations.
* \return
*/
Player::Player(TextureLoader* textures)
{
	//load player stats from the XML
	spritePlayer.setTexture(textures->textureArray[0]);//placeholder array index

	spriteFramePlayer.left   = 0;//x
	spriteFramePlayer.top    = 0;//y
	spriteFramePlayer.width  = 128;
	spriteFramePlayer.height = 128;
	//scale based on resolution???

	spritePlayer.setTextureRect(spriteFramePlayer);
	spritePlayer.setOrigin(sf::Vector2f(64.f, 64.f));
	//grab the appropriate spawn location based on resolution
	spritePlayer.setPosition(0,0);//???
	spritePlayer.setScale(1.f, 1.f);

}


int Player::getPlayerHealth()
{
	return playerHealth;
}

void Player::setPlayerHealth(int hp)
{
	playerHealth = hp;
}
