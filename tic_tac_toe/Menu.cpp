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



	/* Private function definitions */

	void Menu::writeText(std::string str, sf::Font font, unsigned int size, float x, float y,
		const sf::Color &color) {

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
			writeText(menu_title, MenuTitleFont, size, x, y);
		}

		unsigned int menu_screen_height = window->getSize().y * (1 -  MenuTitleScaleFactor);
		unsigned int block_height = menu_screen_height / menu_items.size * MenuItemScaleFactor;
		unsigned int fontSize = block_height * 3/4;
		float x = window->getSize().x / 2;
		float y = window->getSize().y - 0.75 * menu_screen_height + block_height * 1 / 8;

		sf::Color color = sf::Color::White;
		/* Populating the menu options */
		for (int8_t i = 0; i < menu_items.size; ++i) {
			if (i == currently_selected_item) {
				color = sf::Color::Yellow;
			}
			writeText(menu_items.entries[i].title, MenuItemFont, fontSize, x, y, color);
			y += block_height;
			color = sf::Color::White;
		}
	}

	void Menu::createMenu() {
		while (window->isOpen())
		{
			window->clear();
			setMenu();
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
	}
} // namespace sui