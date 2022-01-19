#pragma once
#include <Platform/IPlatform.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u TextureScale, float switchTime);
	~Animation();

	void Update(sf::Vector2u location, float deltaTime);
	sf::Vector2u getTextureSize();
public:
	sf::IntRect uvRect;

private:
	sf::Vector2u TextureScale;
	sf::Vector2u currentImage;

	float switchTime;
	float totalTime;
};