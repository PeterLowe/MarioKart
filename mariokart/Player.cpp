
#include <iostream>
#include "Player.h"
#include "Game.h"


/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
/// </summary>

Player::Player()
{
}


Player::~Player()
{
}
/// <summary>
/// @brief load & setup player sprite and roadHeight
/// </summary>
void Player::initialise()
{
	if (!m_playerTexture.loadFromFile("ASSETS/IMAGES/mario.png"))
	{
		std::cout << "error with  mario  file";
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_roadHeight = 230;
	m_position = { Game::screenWidth / 2, m_roadHeight };
	m_playerSprite.setPosition(m_position);
}
/// <summary>
/// @brief jump up 100 pixels.
/// 
/// reacting to a key press event raise the position by 100
/// </summary>
void Player::jump()
{
	m_position.y -= 100.0f;	
}

/// <summary>
/// @brief apply gravity.
/// 
/// move the player position down one so long as he is above raod
/// </summary>
void Player::fall()
{
	if (m_position.y < m_roadHeight)
	{
		m_position.y += 1.0f;
	}
}


/// <summary>
/// @ brief move the player left.
/// 
/// move the player position one pixel to left
/// if horizontal scale is +1 (facing right) the move player 188 to flip
/// sprite but keep player head in same location and set scale
/// to minus 1
/// </summary>
void Player::left()
{
	m_position.x -= 1.0f;
	if (m_playerSprite.getScale().x == 1)
	{
		m_position.x += 118.0f;		
	}
	m_playerSprite.setScale(-1, 1);
}

/// <summary>
/// @brief checks if game is over.
/// 
/// check if player position is off screen if so the return true
/// </summary>
/// <returns>game over or not</returns>
bool Player::departed()
{	
	if (m_position.x < 0 || m_position.x > Game::screenWidth)
	{
		return true;		 
	}
	else
	{
		return false;
	}

	// same as return(m_position.x < 0 || m_position.x > Game::screenWidth);
}
void Player::resetPosition()
{
	m_position = sf::Vector2f{ Game::screenWidth / 2, m_roadHeight };
}
/// <summary>
/// @ brief move the player right.
/// 
/// move the player position one pixel to right
/// if horizontal scale is -1 (facing left) the move player 188 to flip
/// sprite but keep player head in same location and set scale
/// to plus 1
/// </summary>
void Player::right()
{
	m_position.x += 1.0f;
	if (m_playerSprite.getScale().x == -1)
	{
		m_position.x -= 118.0f;
	}
	m_playerSprite.setScale(1, 1);
}

/// <summary>
/// @brief update world on player.
/// 
/// movement is iniated from the gameplay class
/// </summary>
/// <param name="t_deltaTime">update delta time</param>
void Player::update(sf::Time t_deltaTime)
{
	fall();	
}

/// <summary>
/// update the sprite position 
/// @brief draw player sprite.
/// </summary>
/// <param name="t_window">refrence to main render window</param>
void Player::render(sf::RenderWindow& t_window)
{
	m_playerSprite.setPosition(m_position);
	t_window.draw(m_playerSprite);
}