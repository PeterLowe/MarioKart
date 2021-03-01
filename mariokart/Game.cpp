/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"



float Game::screenWidth = 600; // initialise static member variables
float Game::screenHeight = 400;
GameState Game::currentState = GameState::Licence;

/// <summary>
/// @brief main game constructor creating the render window with settings
/// </summary>
Game::Game() : m_Window(sf::VideoMode(static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)), "SMFL Game", sf::Style::Default)
{
	loadContent();
	m_Window.setKeyRepeatEnabled(false);
}
/// <summary>
/// @brief load the font and initialise everything else.
/// 
/// after loading the font pass a refrence to font resourse to other class iniatilisers
/// </summary>
void Game::loadContent()
{
	int m_gold;
	if (!m_arialFont.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}



	m_licenceScreen.initialise(m_arialFont); // font passed by refrence
	m_splashScreen.initialise(m_arialFont);

	m_mainMenu.initialise(m_arialFont);
	m_mainGame.initialise();
	m_helpPage.initialise(m_arialFont);

	m_gold = 0;
#ifdef STARTRICH
	m_gold = 1000;
#endif // STARTRICH


#ifdef TEST_FPS
	updateFrameCount = 0;
	drawFrameCount = 0;
	secondTime = sf::Time::Zero;
	updateFps.setFont(m_arialFont);
	updateFps.setPosition(20, 300);
	updateFps.setCharacterSize(24);
	updateFps.setFillColor(sf::Color::White);
	drawFps.setFont(m_arialFont);
	drawFps.setPosition(20, 350);
	drawFps.setCharacterSize(24);
	drawFps.setFillColor(sf::Color::White);
#endif // TEST_FPS
}

/// <summary>
/// @brief main game loop.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			processEvents();
			update(timePerFrame);
#ifdef TEST_FPS
			secondTime += timePerFrame;
			updateFrameCount++;
			if (secondTime.asSeconds() > 1)
			{
				updateFps.setString(std::to_string(updateFrameCount-1) + " UPS");
				drawFps.setString(std::to_string(drawFrameCount) + " DPS");
				updateFrameCount = 0;
				drawFrameCount = 0;
				secondTime = sf::Time::Zero;
			}
		
#endif // TEST_FPS
		}
		render();
#ifdef TEST_FPS
		drawFrameCount++;
#endif // TEST_FPS
	}
}
/// <summary>
/// @brief call the appropiate processEvents method ofr currentstate
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_Window.pollEvent(newEvent))
	{
		if (newEvent.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		switch (currentState)
		{
		case GameState::Licence:
			break;
		case GameState::Splash:
			m_splashScreen.processInput(newEvent);
			break;
		case GameState::MainMenu:
			break;
		case GameState::Help:
			m_helpPage.processInput(newEvent);
			break;
		case GameState::Game:
			m_mainGame.processInput(newEvent);
			break;
		default:
			break;
		}
	}
}
/// <summary>
/// @brief call the update method corresponding to the current game state
/// </summary>
/// <param name="time">update delta time</param>
void Game::update(sf::Time t_deltaTime)
{
	switch (currentState)
	{
	case GameState::Licence:
		m_licenceScreen.update(t_deltaTime);
		break;
	case GameState::Splash:
		m_splashScreen.update(t_deltaTime);
		break;
	case GameState::MainMenu:
		m_mainMenu.update(t_deltaTime, m_Window);
		break;
	case GameState::Help:
		m_helpPage.update(t_deltaTime);
		break;
	case GameState::Game:
		m_mainGame.update(t_deltaTime);
		break;
	default:
		break;
	}
}

/// <summary>
/// @brief call the renderer for the current game state
/// </summary>
void Game::render()
{
	m_Window.clear();
	switch (currentState)
	{
	case GameState::Licence:
		m_licenceScreen.render(m_Window);
		break;
	case GameState::Splash:
		m_splashScreen.render(m_Window);
		break;
	case GameState::MainMenu:
		m_mainMenu.render(m_Window);
		break;
	case GameState::Help:
		m_helpPage.render(m_Window);
		break;
	case GameState::Game:
		m_mainGame.render(m_Window);
		break;
	default:
		break;
	}
#ifdef TEST_FPS
	m_Window.draw(updateFps);
	m_Window.draw(drawFps);
#endif // TEST_FPS
	m_Window.display();
}