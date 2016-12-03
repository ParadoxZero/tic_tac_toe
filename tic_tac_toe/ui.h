/*
*	Copyright (C) 2016 Sidhin S Thomas (sidhin.thomas@gmail.com)
*/

#ifndef SS_USER_INTERFACE
#define SS_USER_INTERFACE



#include "actions.h"

/*--- Headers ---*/
#include <SFML\Graphics.hpp>
namespace ui {

	
	struct MenuItem {
		events::Action *action;
		std::string title;
	};

	/* Generic Menu - can be instantiated to generate a custom menu as needed over a sf::RenderWindow */
	class Menu {
	private:

		/* structures to hold the menu item informtion */
		struct {
			MenuItem *entries;
			int8_t size;
		} menu_items;

		struct coordinates {
			coordinates() { x = y = size = 0; }
			float x;
			float y;
			int size;
		} *menu_location, title_location;


		int currently_selected_item = 0;

		sf::Font MenuItemFont;
		sf::Font MenuTitleFont;
		sf::RenderWindow *window;
		std::string menu_title;

		// TODO: create an interface to set these
		float MenuTitleScaleFactor = 0.125;
		float MenuItemScaleFactor = 0.25;


		void writeText(std::string string, sf::Font font, unsigned int size, float x, float y,
			const sf::Color &color = sf::Color::White);

		void setMenu();

		void drawMenu();


	public:
		Menu(sf::RenderWindow *wnd) {
			window = wnd;
			//TODO
			if (!MenuItemFont.loadFromFile("sansation.ttf"))
				exit(0);
			MenuTitleFont.loadFromFile("sansation.ttf");
		}
		
		Menu(sf::RenderWindow *window, std::string title) : Menu(window) {
			setTitle(title);
		}
		
		Menu(sf::RenderWindow *window, std::string title, MenuItem* items, int8_t length) : Menu(window, title) {
			setMenuItems(items, length);
		}

		void setMenuItems(MenuItem *, int8_t);
		
		void setTitle(std::string title);
		
		void createMenu();


	}; // Menu

} // namespace sui
#endif