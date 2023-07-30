#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.hpp"
#include "World.hpp"
#include "MoveableSpriteBird.hpp"
#include "MoveableSpriteBar.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(BACKGROUND_WIDTH, BACKGROUND_HEIGHT), "SFML Demo");
	window.setFramerateLimit(40);

	sf::Texture background_texture;
	if (!background_texture.loadFromFile("assets/background.png"))
	{
		std::cout << "Failed to load background.png" << std::endl;
	}

	sf::Sprite background_sprite(background_texture);
	World world;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.draw(background_sprite);
		for(auto drawable : world.get_objects())
			window.draw(*drawable);

		world.tick_update();
		window.display();
		if(world.check_lose())
			window.close();
	}

	return 0;
}
