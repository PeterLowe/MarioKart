#ifndef LICENCE_H
#define LICENCE_H

#include <SFML\Graphics.hpp>

/// <summary>
/// @author Peter Lowe
/// @version 1.0
/// @date may 2016
/// 
/// \brief simple page to display Licence text for fixed period.
/// 
/// </summary>
class Licence
{
public:
	Licence();
	~Licence();
	
	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

protected:
	/// local refrence to font used by whole game
	sf::Font m_font;
	/// licience text
	sf::Text m_message;
	///  counter for pause time 
	sf::Time m_cumulativeTime;

};

#endif // !LICENCE_H