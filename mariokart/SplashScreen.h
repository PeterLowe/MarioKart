#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date May2016
/// 
/// Simple class to display full screen texture
/// and text message and wait for anykey
/// </summary>
class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void processInput(sf::Event t_event);
	void update(sf::Time t_deltaTime);

protected:
	/// texure of diamond wallpaper square
	sf::Texture m_splashTexture;
	/// sprite tiled to create background
	sf::Sprite m_splashSprite;
	/// local refrence to font used by whole game
	sf::Font m_font;	 
	/// text to display press space message
	sf::Text m_message;
	/// used to pass intent from event processing to update loop
	bool m_proceedKeyPressed; 
};

#endif // !SPLASHSCREEN_H
