/*
#include <SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"Header.h"
int main()
{
	int XP = 5;
	sf::RenderWindow window(sf::VideoMode(1080, 720), "sfml",sf::Style::Close | sf::Style::Resize);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("spritedinosour.png");
	Player player(&playerTexture, sf::Vector2u(2, 3), 0.3f, 300.0f);
	float deltaTime = 0.0f;
	sf::Clock clock;

	//enemy
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("2x-trex.png");
	sf::RectangleShape enemy(sf::Vector2f(100.0f, 90.0f));
	enemy.setTexture(&enemyTexture);
	enemy.setPosition(980.0f, 406.0f);
	//loop game
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (enemy.getGlobalBounds().intersects(body.getGlobalBounds()))
		{
			XP--;
			
		}
		if (XP == 0)
		{
			window.close();
		}
		enemy.move(-0.3f, 0.0f);
		//draw
			player.Update(deltaTime);
			
			window.clear();
			window.draw(enemy);
			player.Draw(window);
		    window.display();
	}
	return 0;  
}
*/

