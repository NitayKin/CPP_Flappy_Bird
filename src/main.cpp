#include <SFML/Graphics.hpp>
#include <iostream>

#include "Globals.hpp"
#include "World.hpp"
#include "MoveableSpriteBird.hpp"
#include "MoveableSpriteBar.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(BACKGROUND_WIDTH, BACKGROUND_HEIGHT), "SFML Demo");
	window.setFramerateLimit(40);

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        return 1;
    }

    sf::Text score_text;
    score_text.setCharacterSize(24);
    score_text.setFillColor(sf::Color::Black);
    score_text.setPosition(10.f, 10.f);
    score_text.setFont(font);



	sf::Texture background_texture;
	if (!background_texture.loadFromFile("assets/background.png"))
	{
		std::cout << "Failed to load background.png" << std::endl;
	}

	sf::Sprite background_sprite(background_texture);
	World world;

	while (window.isOpen()) {
		score_text.setString("Score: " + std::to_string(score));
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.draw(background_sprite);
		world.tick_update();
		for(auto drawable : world.get_objects())
			window.draw(*drawable);
		window.draw(score_text);
		window.display();
		if(world.check_lose()){
		    score_text.setCharacterSize(50);
		    score_text.setPosition(BACKGROUND_WIDTH/2.5, BACKGROUND_HEIGHT/2);
			window.draw(score_text);
			window.display();
			while (window.isOpen()) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					window.close();
			}
		}
	}

	return 0;
}
