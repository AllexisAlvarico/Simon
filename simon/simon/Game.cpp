// Author Allexis and Niamh

#include "Game.h"
#include <iostream>



Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	setupScene();
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_redSquare);
	m_window.draw(m_yellowSquare);
	m_window.draw(m_greenSquare);
	m_window.draw(m_blueSquare);
	m_window.draw(m_title);
	m_window.draw(m_redText);
	m_window.draw(m_blueText);
	m_window.draw(m_yellowText);
	m_window.draw(m_greenText);

	//m_window.draw(m_welcomeMessage);
	//m_window.draw(m_logoSprite);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	if (!m_ImpactFont.loadFromFile("ASSETS\\FONTS\\impact.ttf"))
	{
		std::cout << "problem loading impact font" << std::endl;
	}
	/*m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);*/
	
	m_title.setFont(m_ArialBlackfont);
	m_title.setString("S I M O N");		
	m_title.setPosition(40.0f, 40.0f);
	m_title.setCharacterSize(48);
	m_title.setFillColor(sf::Color::White);


	m_greenText.setFont(m_ImpactFont);
	m_greenText.setString("Press green for \n an easy game");
	m_greenText.setPosition(40.0f, 130.0f);
	m_greenText.setCharacterSize(32);
	m_greenText.setFillColor(sf::Color::Green);

	m_redText.setFont(m_ImpactFont);
	m_redText.setString("Press red for \n a medium game");
	m_redText.setPosition(40.0f, 220.0f);
	m_redText.setCharacterSize(32);
	m_redText.setFillColor(sf::Color::Red);

	m_yellowText.setFont(m_ImpactFont);
	m_yellowText.setString("Press yellow for \n a hard game");
	m_yellowText.setPosition(40.0f, 300.0f);
	m_yellowText.setCharacterSize(32);
	m_yellowText.setFillColor(sf::Color::Yellow);

	m_blueText.setFont(m_ImpactFont);
	m_blueText.setString("Press blue to \n exit the game");
	m_blueText.setPosition(40.0f, 400.0f);
	m_blueText.setCharacterSize(32);
	m_blueText.setFillColor(sf::Color::Blue);




}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	if (!m_logoTexture.loadFromFile("ASSETS\\IMAGES\\SFML-LOGO.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading logo" << std::endl;
	}
	m_logoSprite.setTexture(m_logoTexture);
	m_logoSprite.setPosition(300.0f, 180.0f);
}

void Game::setupScene()

{
	m_redSquare.setSize(sf::Vector2f(200, 200));
	m_redSquare.setFillColor(sf::Color::Red);
	m_redSquare.setPosition(570, 30);

	m_yellowSquare.setSize(sf::Vector2f(200, 200));
	m_yellowSquare.setFillColor(sf::Color::Yellow);
	m_yellowSquare.setPosition(350, 250);

	m_greenSquare.setSize(sf::Vector2f(200, 200));
	m_greenSquare.setFillColor(sf::Color::Green);
	m_greenSquare.setPosition(350, 30);

	m_blueSquare.setSize(sf::Vector2f(200, 200));
	m_blueSquare.setFillColor(sf::Color::Blue);
	m_blueSquare.setPosition(570, 250);
}
