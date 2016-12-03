/*
*	Copyright (C) Sidhin S Thomas (sidhin.thomas@gmail.com)
*/

#include "game_controller.h"
#include "ui.h"
#include "actions.h"
#include "main_menu_events.h"


namespace game {

	/* Initializing the unique game_master object */
	GameMaster *GameMaster::game_master=nullptr;

	/* Entry point of game */
	int GameMaster::run() {
		
		
		/* Creating main menu items */
		ui::MenuItem menu_items[5];
		menu_items[0].title = "Start";
		menu_items[0].action = new mm_events::StartAction;
		menu_items[1].title = "Options";
		menu_items[1].action = new mm_events::OptionsAction;
		menu_items[2].title = "Exit";
		menu_items[2].action = new mm_events::ExitAction(window);

		ui::Menu mainMenu(window, std::string("Main Menu"), menu_items, 3);
		mainMenu.createMenu();

		return 0;
	} //run()

	GameMaster* GameMaster::getGameMaster(sf::RenderWindow *window) {
		if (game_master == nullptr)
			return new GameMaster(window);
		return game_master;
	} // getGameMaster(...)

	/* Constructors */

	GameMaster::GameMaster(sf::RenderWindow *wnd) {
		game_master = this;
		window = wnd;

	} //GameMaster(..)

} // namespace game