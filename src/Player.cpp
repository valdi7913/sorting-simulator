#include "Player.h"
#include "Animation.h"
#include <Platform/IPlatform.hpp>

Player:: Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this -> speed = speed;
	this -> textureIndex = sf::Vector2u(2, 0);
	body = sf::RectangleShape(sf::Vector2f(100, 100));
	body.setPosition(sf::Vector2f(800, 500));
	body.setTextureRect(animation.uvRect);
	printf("Player created\n");
}

Player::~Player(){}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	//Keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movement.x -= speed * deltaTime;
		textureIndex = sf::Vector2u(9, 5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movement.x += speed * deltaTime;
		textureIndex = sf::Vector2u(9, 7);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movement.y -= speed * deltaTime;
		textureIndex = sf::Vector2u(9, 5);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movement.y += speed * deltaTime;;
		textureIndex = sf::Vector2u(9, 4);
	}

	if (movement.x == 0.0f && movement.y == 0.0f)
	{
		textureIndex = sf::Vector2u(2, 0);
	}

	animation.Update(textureIndex, deltaTime);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	body.setTextureRect(animation.uvRect);
	window.draw(body);
}
