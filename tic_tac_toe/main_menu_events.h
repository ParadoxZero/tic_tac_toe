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
	/* Exit Option */
	private:
		sf::RenderWindow *window;
		bool getConfirmation();
	public:
		ExitAction(sf::RenderWindow *w) { window = w; }

		bool start();



	private:
		/* Action Items for the Dialog  */

		class ConfirmationMenuAction : public events::Action {
			bool *confirm;
		public:
			ConfirmationMenuAction(bool *val) { confirm = val; }
			bool start() { 
				*confirm = true;
				return false;
			}
		};
		/* bool start() returns false in both case so that the dialog 
		   will be closed after the action is selected */
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
