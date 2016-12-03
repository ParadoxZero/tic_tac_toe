#include "ui.h"

#include <SFML\Graphics.hpp>
#include <iostream>
namespace ui {

		/* Public function definitions*/
	void Menu::setTitle(std::string title) {
		menu_title = title;
	}

	void Menu::setMenuItems(MenuItem *items, int8_t length) {
		menu_items.entries = items;
		menu_items.size = length;
	}

	void Menu::createMenu() {
		setMenu();
		while (window->isOpen())
		{
			window->clear();
			drawMenu();
			sf::Event event;
			while (window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window->close();
				else if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Up) {
						currently_selected_item = (currently_selected_item - 1);
						if (currently_selected_item < 0)
							currently_selected_item = menu_items.size - 1;
					}
					else if (event.key.code == sf::Keyboard::Down) {
						currently_selected_item = (currently_selected_item + 1) % (menu_items.size);
					}
					else if (event.key.code == sf::Keyboard::Return) {
						menu_items.entries[currently_selected_item].action->start();
					}
				}
			} // while( pollEvent )
			window->display();
		} // while window open
	} //create menu


	/* Private function definitions */

	void Menu::writeText(std::string str, sf::Font font, unsigned int size, float x, float y, const sf::Color &color) {
		sf::Text text;
		text.setString(str);
		text.setFont(font);
		text.setFillColor(color);
		text.setCharacterSize(size);
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.width / 2.0f,0);
		text.setPosition(sf::Vector2f(x,y));
		window->draw(text);
	}

	void Menu::setMenu() {

		/* Setting title of menu */
		{
			/* Small scope just to be able to freely use the variable names */
			float x = window->getSize().x / 2, y = 0;
			int size = window->getSize().y * MenuTitleScaleFactor;
			title_location.x = x;
			title_location.y = y;
			title_location.size = size;
		}

		unsigned int menu_screen_height = window->getSize().y * (1 -  MenuTitleScaleFactor);
		unsigned int block_height = menu_screen_height / menu_items.size * MenuItemScaleFactor;
		unsigned int fontSize = block_height * 3/4;
		float x = window->getSize().x / 2;
		float y = window->getSize().y - 0.75 * menu_screen_height + block_height * 1 / 8;
		menu_location = new cordinates[menu_items.size];
		/* Calculating Menu item locations */
		for (int8_t i = 0; i < menu_items.size; ++i) {
			menu_location[i].x = x;
			menu_location[i].y = y;
			menu_location[i].size = fontSize;
			y += block_height;
		}
		
	}

	void Menu::drawMenu() {
		writeText(menu_title, MenuTitleFont, title_location.size, title_location.x, title_location.y);
		sf::Color color = sf::Color::White;
		for (int i = 0; i < menu_items.size; ++i)
		{
			if (i == currently_selected_item) {
				color = sf::Color::Yellow;
			}
			writeText(menu_items.entries[i].title, MenuItemFont, menu_location[i].size, menu_location[i].x, menu_location[i].y, color);
			color = sf::Color::White;
		}

	}


} // namespace sui