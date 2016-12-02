#include "ui.h"
class StartAction : public ui::EventAction {
	void start() {

	}
};

class OptionsAction : public ui::EventAction {
	void start() {

	}
};

class ExitAction : public ui::EventAction {
	void start() {
		exit(0);
	}

};

void main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Tic Tac Toe", sf::Style::Close);
	ui::MenuItem menu_items[5];
	menu_items[0].title = "Start";
	menu_items[0].action = new StartAction;
	menu_items[1].title = "Options";
	menu_items[1].action = new OptionsAction;
	menu_items[2].title = "Exit";
	menu_items[2].action = new ExitAction;

	ui::Menu mainMenu(&window, std::string("Main Menu"), menu_items,3);

	mainMenu.createMenu();
}

