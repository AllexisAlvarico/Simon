// Author Allexis and Niamh
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	

	void setupScene();
	void setupFontAndText();
	void setupSprite();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Font m_ImpactFont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Text m_title;
	sf::Text m_greenText;
	sf::Text m_redText;
	sf::Text m_blueText;
	sf::Text m_yellowText;
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	sf::RectangleShape m_redSquare;
	sf::RectangleShape m_yellowSquare;
	sf::RectangleShape m_greenSquare;
	sf::RectangleShape m_blueSquare;
	bool m_exitGame; // control exiting game

};

#endif // !GAME

