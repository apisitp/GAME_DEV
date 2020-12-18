
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <time.h>
int main()
{
	srand(time(NULL));
	int window_hight = 720;
	int window_width = 1080;
	int HP = 10;
	int enemylimit = 20;
	sf::RenderWindow window(sf::VideoMode(window_width, window_hight), "space escapea");
	window.setFramerateLimit(60);
	//background
	sf::Sprite background;
	sf::Texture backgroundTexrure;
	backgroundTexrure.loadFromFile("backgound.png");
	background.setTexture(backgroundTexrure);
	background.setScale(sf::Vector2f(1.0f, 1.0f));
	//sound background
	sf::SoundBuffer gamebuffer;
	gamebuffer.loadFromFile("gamesournd.wav");
	sf::Sound backgroundSound;
	backgroundSound.setBuffer(gamebuffer);
	backgroundSound.play();
	backgroundSound.setLoop(true);
	//sound
	sf::SoundBuffer sound;
	sound.loadFromFile("sound.wav");
	sf::Sound soundCollider;
	soundCollider.setBuffer(sound);


	//player
	sf::Sprite player;
	sf::Texture playerTexture;
	playerTexture.loadFromFile("playersprite.png");
	player.setTexture(playerTexture);
	player.setScale(sf::Vector2f(0.7f,0.7f));
	player.setPosition(sf::Vector2f(0.f, 360.0f));
	//HPbar
	sf::RectangleShape HPbar;
	HPbar.setFillColor(sf::Color::Red);
	HPbar.setSize(sf::Vector2f((float)HP * 20.f,20.f));
	HPbar.setPosition(540.f,0.f);

	//enemy
	int enemyspaentimer = 10;
	sf::Sprite enemy;
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("enemies.sprite.png");
	enemy.setTexture(enemyTexture);
	enemy.setScale(sf::Vector2f(0.09f, 0.09f));
	std::vector<sf::Sprite> enemys;
	enemys.push_back(sf::Sprite(enemy));

	
	//bullet
	while ( window.isOpen() && HP > 0)
		{
		   //player
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				player.move(0.0f, -3.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				player.move(-3.0f, 0.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				player.move(0.0f, 3.0f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				player.move(3.0f, 0.0f);
			}
			//Check collisions
			//Check for edge collisions
			//left
			if (player.getPosition().x < 0)
			{
				player.setPosition(0, player.getPosition().y);
			}
			//top
			if (player.getPosition().y < 0)
			{
				player.setPosition(player.getPosition().x, 0);
			}
			//right
			if (player.getPosition().x + player.getGlobalBounds().width > window_width)
			{
				player.setPosition(window_width - player.getGlobalBounds().width, player.getPosition().y);
			}
			//under
			if (player.getPosition().y + player.getGlobalBounds().height > window_hight)
			{
				player.setPosition(player.getPosition().x, window_hight - player.getGlobalBounds().height);	
			}
			for (size_t i = 0; i < enemys.size(); i++)
			{
				if (player.getGlobalBounds().intersects(enemys[i].getGlobalBounds()))
				{
					soundCollider.play();
					enemys.erase(enemys.begin() + i);
					HP--;
				}
			}
			HPbar.setSize(sf::Vector2f((float)HP * 20.f, 20.f));
			
			for (size_t i = 0; i < enemys.size(); i++)
			{
				enemys[i].move(-5.f, 0.f);
				if (enemys[i].getPosition().x < 0 - enemy.getGlobalBounds().width)
				{
					enemys.erase(enemys.begin() + i);
				}
			}
			if(enemyspaentimer < 10)
			{
				enemyspaentimer++;
			}
			if(enemyspaentimer >= 10)
			{
				enemyspaentimer = 0;
				enemy.setPosition(window.getSize().x,rand()%int(window.getSize().y - enemy.getGlobalBounds().height));
				enemys.push_back(sf::Sprite(enemy));
				
			}
			//draw
			window.clear();
			window.draw(background);
			window.draw(player);
			window.draw(HPbar);
	
			for (size_t i = 0; i < enemys.size(); i++)
			{
				window.draw(enemys[i]);
			}
			window.display();	
		}
	  
}
