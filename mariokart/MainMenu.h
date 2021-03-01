#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>

/// Number of buttons on our menu
const int OPTION_COUNT = 3;


/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
///  class to handle simple menu interaction
/// </summary>
class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime, sf::Window& t_window);

protected:
	
	/// green button background
	sf::Texture m_buttonTexture; 
	/// array of sprites used to display buttons
	sf::Sprite m_buttonSprites[OPTION_COUNT];
	/// local refrence to font used by whole game
	sf::Font m_font;
	/// array of text objects for text on buttons
	sf::Text m_buttonTexts[OPTION_COUNT];	
	
	/// top left of area usde for menu
	float m_topOffset;
	/// top left of area usde for menu
	float m_leftOffset;
	/// gap in pixels between tops of buttons
	float m_verticalSpacing;
	/// width in pixels of all buttons
	float m_buttonWidth;
	/// height of button in pixels must be less than vertical spacing
	float m_buttonHeight;
};

#endif // !MAINMENU_H