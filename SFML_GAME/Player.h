/*
#pragma once
#include "SFML/Graphics.hpp"
#include "Header.h"
class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);

	
private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

};
*/
