/*
*	Copyright (C) 2016 SIDHIN S THOMAS (sidhin.thomas@gmail.com)
*
*	Headers for the Main Menu Actions.
*/


#ifndef SS_MAIN_MENU_EVENTS
#define SS_MAIN_MENU_EVENTS


/* Headers */
#include "actions.h"
#include "ui.h"
#include "SFML\Graphics.hpp"
namespace mm_events {

	class StartAction : public events::Action {
		bool start() {
			return true;
		}
	};

	class OptionsAction : public events::Action {
		bool start() {
			return true;
		}
	};

	class ExitAction : public events::Action {
	
	private:
		sf::RenderWindow *window;
		ui::Menu *dialog;
		bool confirm = false;
		bool getConfirmation();
	public:
		ExitAction(sf::RenderWindow *w) { window = w; }

		bool start();



	private:
		/* Auxilary classess to help with function */

		class ConfirmationMenuAction : public events::Action {
			bool *confirm;
		public:
			ConfirmationMenuAction(bool *val) { confirm = val; }
			bool start() { 
				*confirm = true;
				return false; 
			}
		};

		class DeclineMenuAction : public events::Action {
			bool *confirm;
		public:
			DeclineMenuAction(bool *val) { confirm = val; }
			bool start() { 
				*confirm = false;
				return false; 
			}
		};

	};


} // namespace events


#endif // !SS_MAIN_MENU_EVENTS
