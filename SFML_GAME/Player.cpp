/*
#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(90.0f,90.0f));
	body.setPosition(406.0f, 406.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltatime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltatime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltatime;
	}

	if (movement.y > 0.0f)
	{
		row = 0;
	}
	else if (movement.x != 0.0f)
	{
		row = 1;

		if (movement.x > 0.0f)
		{
			faceRight = true;
		}
		else
		{
			faceRight = false;
		}


	}
	animation.Update(row, deltatime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
*/