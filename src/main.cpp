#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cmath>

#include "Globals.hpp"
#include "World.hpp"
#include "MoveableSpriteBird.hpp"
#include "MoveableSpriteBar.hpp"

void draw_world(sf::RenderWindow *window, sf::Sprite *background_sprite, World *world) {
	(*window).draw(*background_sprite);
	for(auto drawable : world->get_objects())
		window->draw(*drawable);
}

int main() {
	sf::RenderWindow window(sf::VideoMode(BACKGROUND_WIDTH, BACKGROUND_HEIGHT), "SFML Demo", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(40);

    sf::Font font;
    if (!font.loadFromFile("assets/arial.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        return 1;
    }

    sf::Text score_text;
    score_text.setCharacterSize(50);
    score_text.setFillColor(sf::Color::Black);
    score_text.setPosition(10.f, 10.f);
    score_text.setFont(font);



	sf::Texture background_texture;
	if (!background_texture.loadFromFile("assets/background.png")) {
		std::cout << "Failed to load background.png" << std::endl;
	}

	sf::Sprite background_sprite(background_texture);
	World world;

	while (window.isOpen()) {
		score_text.setString(std::to_string(score));

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		world.tick_update();

		draw_world(&window, &background_sprite, &world);

		window.draw(score_text);
		window.display();

		if(world.check_lose()){
			float score_float_angle = 0.0;
			sf::Vector2f score_text_center = sf::Vector2f(score_text.getGlobalBounds().width/ 2.0f,score_text.getGlobalBounds().height/ 2.0f);
			sf::Vector2f score_text_local_bounds = score_text_center + sf::Vector2f(score_text.getLocalBounds().left,score_text.getLocalBounds().top);

		    score_text.setCharacterSize(100);
			score_text.setOrigin(score_text_local_bounds);
			score_text.setPosition(BACKGROUND_WIDTH / 2.0 - score_text.getGlobalBounds().top/ 2, BACKGROUND_HEIGHT / 2.0);

			while (window.isOpen()) {
				draw_world(&window, &background_sprite, &world);

				sf::RectangleShape mask(sf::Vector2f(BACKGROUND_WIDTH, BACKGROUND_HEIGHT));
				mask.setFillColor(sf::Color(255, 255, 255, 100));
				window.draw(mask);

				score_text.setPosition(score_text.getPosition().x, score_text.getPosition().y + sinf(score_float_angle) / 2);
				score_float_angle += 0.05;

				window.draw(score_text);
				window.display();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					window.close();
			}
		}
	}

	return 0;
}
