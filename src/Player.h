#pragma once
#include <Platform/IPlatform.hpp>
#include "Animation.h"

class Player
{
	public:
		Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
		~Player();

		void Update(float deltaTime);

		void Draw(sf::RenderWindow& window);

	private:
		sf::RectangleShape body;
		sf::Vector2u textureIndex;
		Animation animation;
		float speed;
};