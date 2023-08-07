#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>
#include <vector>
#include <cmath>


#include "Globals.hpp"
#include "World.hpp"
#include "MoveableSpriteBird.hpp"
#include "MoveableSpriteBar.hpp"

void draw_world(sf::RenderWindow *window, sf::Sprite *background_sprite, World& world) {
	(*window).draw(*background_sprite);
	for(auto drawable : world.get_objects())
		window->draw(*drawable);
}


void prepare_information(float values[],float is_done, World& world)
{
	std::vector<MoveableSprite*> objects = world.get_objects();
	sf::FloatRect obj_bird_bounds = objects[0]->getGlobalBounds();
	sf::FloatRect obj_up_bar_bounds = objects[1]->getGlobalBounds();
	sf::FloatRect obj_down_bar_bounds = objects[2]->getGlobalBounds();
	sf::Vector2f bird_mass_center = sf::Vector2f(obj_bird_bounds.left+obj_bird_bounds.width/2,obj_bird_bounds.top+obj_bird_bounds.height/2);
	sf::Vector2f up_bar_center_rim = sf::Vector2f(obj_up_bar_bounds.left+obj_up_bar_bounds.width/2,obj_up_bar_bounds.height);
	sf::Vector2f down_bar_center_rim = sf::Vector2f(obj_down_bar_bounds.left+obj_down_bar_bounds.width/2,obj_down_bar_bounds.top);

	values[0] = ((MoveableSpriteBar*)objects[1])->velocity.x * -1.f; //speed
	values[1] = bird_mass_center.y; //Y coordinate of the bird middle
	values[2] = obj_down_bar_bounds.top - ((BACKGROUND_HEIGHT-obj_up_bar_bounds.height-obj_down_bar_bounds.height)/2); //Y coordinate of the middle point between the bars
	values[3] = (float)g_score;

	values[4] = is_done;
}



int main() {
	float values[5];

    int client_socket = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Error creating socket\n";
        return 1;
    }

    sockaddr_un server_address;
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "/tmp/my_socket"); // Set the same socket file path as the Python server

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(client_socket);
        return 1;
    }
#ifdef ENABLE_FEATURE_GUI
	sf::RenderWindow window(sf::VideoMode(BACKGROUND_WIDTH, BACKGROUND_HEIGHT), "SFML Demo", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(40);
#endif

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

	while (true) {
		score_text.setString(std::to_string(g_score));
#ifdef ENABLE_FEATURE_GUI
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
#endif

	    if (recv(client_socket, &g_command_from_python, sizeof(g_command_from_python), MSG_WAITALL) != sizeof(g_command_from_python)) {
	        std::cerr << "Error receiving data from server\n";
	        close(client_socket);
	        return 1;
	    }

		world.tick_update();
#ifdef ENABLE_FEATURE_GUI
		draw_world(&window, &background_sprite, world);

		window.draw(score_text);
		window.display();
#endif
		if(world.check_lose()){
			prepare_information(values,1.f,world);
		    if (write(client_socket, values, sizeof(values)) != sizeof(values)) {
		        std::cerr << "Error sending data to server\n";
		        close(client_socket);
		        return 1;
		    }
#ifdef ENABLE_FEATURE_GUI
			window.close();
#endif
			return 0;
		}

		prepare_information(values,0.f,world);
	    if (write(client_socket, values, sizeof(values)) != sizeof(values)) {
	        std::cerr << "Error sending data to server\n";
	        close(client_socket);
	        return 1;
	    }
	}

	return 0;
}
