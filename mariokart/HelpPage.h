#ifndef HELPPAGE_H
#define HELPPAGE_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
/// \brief simple page to display help text.
/// 
/// </summary>
class HelpPage
{
public:
	HelpPage();
	~HelpPage();
	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void processInput(sf::Event t_event);
	void update(sf::Time t_deltaTime);

protected:
	/// local refrence to font used by whole game
	sf::Font m_font;
	/// multiline text message for user help
	sf::Text m_message;
	/// boolean to control pressing escape from process to update
	bool m_exitPressed;
};

#endif // !HELPPAGE_H
