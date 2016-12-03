#include "game_controller.h"



int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Tic Tac Toe", sf::Style::Close);
	game::GameMaster &game_master = *game::GameMaster::getGameMaster(&window);
	return game_master.run();
}

