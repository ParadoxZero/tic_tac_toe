#include "ui.h"
#include "main_menu_events.h"



void main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Tic Tac Toe", sf::Style::Close);
	ui::MenuItem menu_items[5];
	menu_items[0].title = "Start";
	menu_items[0].action = new mm_events::StartAction;
	menu_items[1].title = "Options";
	menu_items[1].action = new mm_events::OptionsAction;
	menu_items[2].title = "Exit";
	menu_items[2].action = new mm_events::ExitAction;

	ui::Menu mainMenu(&window, std::string("Main Menu"), menu_items,3);

	mainMenu.createMenu();
}

