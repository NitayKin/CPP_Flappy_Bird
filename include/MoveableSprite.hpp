#include <SFML/Graphics.hpp>

class MoveableSprite : public sf::Sprite
{
private:
	sf::Vector2f acceleration;
	sf::Vector2f velocity;
	sf::Vector2f net_force;
	float mass = 0.2;

public:
	MoveableSprite(sf::Texture);
	void tick_update();
};
