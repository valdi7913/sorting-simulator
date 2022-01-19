#include <Animation.h>

Animation::Animation(sf::Texture* texture, sf::Vector2u TextureScale, float switchTime)
{
	this->TextureScale = TextureScale;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	currentImage.y = 0;

	uvRect.width = texture->getSize().x / static_cast<float>(TextureScale.x);
	uvRect.height = texture->getSize().y / static_cast<float>(TextureScale.y);
}

Animation::~Animation()
{
}

void Animation::Update(sf::Vector2u location, float deltaTime)
{
	currentImage.y = location.y;
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= location.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.top = currentImage.y * uvRect.height;
	uvRect.left = currentImage.x * uvRect.width;
}

sf::Vector2u Animation::getTextureSize()
{
	return this->TextureScale;
}