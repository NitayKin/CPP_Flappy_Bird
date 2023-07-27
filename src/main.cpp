#include <SFML/Graphics.hpp>
#include <iostream>
#include "MoveableSprite.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 720), "SFML Demo");
	window.setFramerateLimit(40);

	sf::Texture background_texture;
	if (!background_texture.loadFromFile("assets/background.png"))
	{
		std::cout << "Failed to load background.png" << std::endl;
		return 1;
	}

	sf::Texture birdy_texture;
	if (!birdy_texture.loadFromFile("assets/birdy.png"))
	{
		std::cout << "Failed to load background.png" << std::endl;
		return 1;
	}

	sf::Sprite background_sprite(background_texture);
	MoveableSprite birdy_sprite(birdy_texture);
	birdy_sprite.scale(sf::Vector2f(0.5,0.5));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			birdy_sprite.tick_update();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			birdy_sprite.tick_update();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			birdy_sprite.tick_update();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			birdy_sprite.tick_update();
		}

//        window.clear();
		window.draw(background_sprite);
		window.draw(birdy_sprite);
		window.display();
	}

	return 0;
}
